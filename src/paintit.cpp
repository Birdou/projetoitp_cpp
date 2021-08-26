
#include "paintit.hpp"

#include <sstream>
#include <algorithm>
#include <sys/stat.h>
#include <sys/types.h>

//#include <windows.h>

#if defined(_WIN32)
#define CreateDir(x) system("mkdir " #x)
#elif defined(unix) | defined(__unix)
#define CreateDir(x) system("mkdir -p " #x)
#endif

#include "viewer.hpp"
#include "color.hpp"

paintit::ppm *paintit::paintit_main::current_image = nullptr;
paintit::penc *paintit::paintit_main::pincel = nullptr;
paintit::viewer *paintit::paintit_main::view = nullptr;

bool paintit::paintit_main::isRunning = false;

paintit::paintit_main::paintit_main()
{
}

paintit::paintit_main::~paintit_main()
{
	DebugMessage("destroying image...");
	delete current_image;
	DebugMessage("destroying pencil...");
	delete pincel;
	DebugMessage("destroying viewer...");
	delete view;

	DebugMessage("destroying temporary files...");
	for (int i = 1; i <= maxinteraction; ++i)
	{
		std::string path("./history/image" + std::to_string(i) + ".png");
		DebugMessage("removing " << path << "...");
		remove(path.c_str());
	}
	DebugMessage("removing editview.png...");
	remove("editview.png");

	int threadReturnValue;
	DebugMessage("waiting for thread...");
	SDL_WaitThread(viewerthread, &threadReturnValue);
	DebugMessage("thread returned " << threadReturnValue);
}

void paintit::paintit_main::init()
{
	current_image = new paintit::ppm();
	pincel = new paintit::penc(paintit::rgb(0, 0, 0), 1);

	DebugLog("creating viewer thread...");
	viewerthread = SDL_CreateThread(sdlstart, "sdlstart", (void *)NULL);

	this->isRunning = true;
}

void paintit::paintit_main::execute()
{
	SDL_Delay(1000);
	std::cout << "Digite \"help\" para ver lista de comandos" << std::endl;

	while (this->isRunning)
	{
		std::vector<std::string> command_whitelist =
			{
				"size", "color", "help", "scolor", "mode", "save", "listcolor",
				"purge", "history", "exit", "math", "update"};
		std::string line;

		std::cout << "$ ";

		std::cin.clear();
		colorspace(getline(std::cin, line), fLIGHT_BLUE);
		std::string command, error;
		std::stringstream linestream(line);
		linestream >> command;

		error = executeCommand(line);
		if (error != noerror)
		{
			std::cout << error << std::endl;
		}
		else
		{
			if (find(command_whitelist.begin(), command_whitelist.end(), command) == command_whitelist.end())
			{
				if (current_image->getWidth() != 0 && current_image->getHeight() != 0)
				{
					std::string error;
					error = current_image->savePng("editview.png");
					DebugLog("savePng(\"editview.png\"):" << error);

					if (lib::cstrcmp(command, "undo") != 0 && lib::cstrcmp(command, "redo") != 0)
					{
						if (interaction < maxinteraction)
						{
							for (int i = interaction + 1; i <= maxinteraction; ++i)
							{
								std::string path("./history/image" + std::to_string(i) + ".png");
								DebugLog(path << " is now unreachable");
								remove(path.c_str());
							}
							maxinteraction = interaction;
						}
						std::string path("./history/image" + std::to_string(interaction + 1) + ".png");

						int errorlevel = CreateDir("./history/");
						if (errorlevel == 0 || errorlevel == 1)
						{
							error = current_image->savePng(path);
							DebugLog("savePng(" << path << "):" << error);
							interaction++;
						}
						else
						{
							interaction = 0;
							DebugError("couldn't create/access history directory.");
						}
					}
					maxinteraction = std::max(interaction, maxinteraction);
					view->updateImage();
				}
			}
			history.emplace_back(line);
		}
	}
}

std::string paintit::paintit_main::undo()
{
	if (interaction <= 1)
		return noerror;

	std::string error, path("./history/image" + std::to_string(interaction - 1) + ".png");

	error = current_image->open(path.c_str());
	DebugLog("open(" << path << "):" << error);
	if (error == noerror)
	{
		interaction--;
	}

	return noerror;
}

std::string paintit::paintit_main::redo()
{
	if (interaction == maxinteraction)
		return noerror;

	std::string error, path("./history/image" + std::to_string(interaction + 1) + ".png");

	error = current_image->open(path.c_str());
	DebugLog("open(" << path << "):" << error);
	if (error == noerror)
	{
		interaction++;
	}

	return noerror;
}

std::string paintit::paintit_main::executeCommand(const std::string &line, bool isFor)
{
	std::stringstream commandLine(line);
	do
	{
		std::string command;
		commandLine >> command;
		if (line.find("/?") != std::string::npos)
		{
			paintit::command_help(command);
			return noerror;
		}
		if (lib::cstrcmp(command, "for") == 0)
		{
			std::string var, aux, line;
			std::map<std::string, lib::var> variables;
			while (!commandLine.eof())
			{
				commandLine >> var;
				if (var == "do")
					break;

				ssize_t start, end, step;
				commandLine >> aux; //from
				commandLine >> start;

				commandLine >> aux; //to
				commandLine >> end;

				commandLine >> aux; //by
				commandLine >> step;

				if (commandLine.fail())
				{
					return invalid_syntax_exception;
				}

				lib::var tmp(start, end, step);
				variables.emplace(var, tmp);
			}
			getline(commandLine, line);
			bool stop = false;
			while (!stop)
			{
				stop = true;
				std::string tmpLine = line;
				for (auto &variable : variables)
				{
					lib::replaceWhole(tmpLine, variable.first, std::to_string(variable.second.value));
					variable.second.increment();
					stop &= variable.second.finished;
				}
				std::string error = executeCommand(tmpLine, true);
				DebugMessage(tmpLine << "... " << error);
				return_iferror(error);
			}
		}
		else if (lib::cstrcmp(command, "update") == 0)
		{
			this->updateImage(*current_image);
		}
		else if (lib::cstrcmp(command, "undo") == 0)
		{
			if (!isFor)
			{
				this->undo();
				DebugLog("exitting undo");
			}
			else
			{
				return "Não é permitido o uso do \'undo\' dentro de laços";
			}
		}
		else if (lib::cstrcmp(command, "redo") == 0)
		{
			if (!isFor)
			{
				this->redo();
			}
			else
			{
				return "Não é permitido o uso do \'redo\' dentro de laços";
			}
		}
		else if (lib::cstrcmp(command, "math") == 0)
		{
			std::string sentence, result;
			getline(commandLine, sentence);
			result = lib::smath<float>(sentence);
			lib::remove_trailling(result);
			std::cout << " = " << std::fixed << result << std::endl;
		}
		else if (lib::cstrcmp(command, "plot") == 0)
		{
			std::string sentence;
			getline(commandLine, sentence);
			functions::plot(*current_image, *pincel, sentence);
		}
		else if (lib::cstrcmp(command, "shell") == 0)
		{
			std::string command;
			getline(commandLine, command);
			int errorlevel;
			if ((errorlevel = system(command.c_str())) != 0)
			{
				std::cout << "Returned " << errorlevel << std::endl;
			}
		}
		else if (lib::cstrcmp(command, "image") == 0)
		{
			int largura, altura;
			commandLine >> largura >> altura;
			if (!commandLine.fail())
				return_iferror(current_image->image(largura, altura));
		}
		else if (lib::cstrcmp(command, "color") == 0)
		{
			int r, g, b;
			commandLine >> r >> g >> b;
			if (!commandLine.fail())
				pincel->setColor(paintit::rgb(r, g, b));
		}
		else if (lib::cstrcmp(command, "mode") == 0)
		{
			int mode = pincel->mode;
			mode++;
			if (mode == penc::Modes::last_mode)
			{
				mode = 0;
			}
			pincel->mode = static_cast<penc::Modes>(mode);
			switch (pincel->mode)
			{
			case penc::Modes::normal:
			{
				std::cout << "modo atual: normal" << std::endl;
				break;
			}
			case penc::Modes::average:
			{
				std::cout << "modo atual: média" << std::endl;
				break;
			}
			case penc::Modes::additive:
			{
				std::cout << "modo atual: aditivo" << std::endl;
				break;
			}
			case penc::Modes::subtractive:
			{
				std::cout << "modo atual: subtrativo" << std::endl;
				break;
			}
			case penc::Modes::last_mode:
			{
				break;
			}
			}
		}
		else if (lib::cstrcmp(command, "size") == 0)
		{
			int tamanho;
			commandLine >> tamanho;
			if (!commandLine.fail())
				pincel->setSize(tamanho);
		}
		else if (lib::cstrcmp(command, "guev") == 0)
		{
			double escala;
			commandLine >> escala;
			if (!commandLine.fail())
				return_iferror(paintit::processing::guev(*current_image, escala));
		}
		else if (lib::cstrcmp(command, "clear") == 0)
		{
			short r, g, b;
			commandLine >> r >> g >> b;
			if (!commandLine.fail())
				return_iferror(current_image->clear(paintit::rgb(r, g, b)));
		}
		else if (lib::cstrcmp(command, "global") == 0)
		{
			ssize_t x, y;
			commandLine >> x >> y;
			if (!commandLine.fail())
				return_iferror(paintit::functions::global(*current_image, *pincel, paintit::coord(x, y)));
		}
		else if (lib::cstrcmp(command, "line") == 0)
		{
			paintit::coord inicio, fim;
			commandLine >> inicio.x >> inicio.y >> fim.x >> fim.y;
			if (!commandLine.fail())
				return_iferror(paintit::functions::line(*current_image, *pincel, inicio, fim));
		}
		else if (lib::cstrcmp(command, "crop") == 0)
		{
			paintit::coord inicio, fim;
			commandLine >> inicio.x >> inicio.y >> fim.x >> fim.y;
			if (!commandLine.fail())
				return_iferror(paintit::functions::crop(*current_image, inicio, fim));
		}
		else if (lib::cstrcmp(command, "polygon") == 0)
		{
			size_t lados;
			ssize_t x, y;
			std::vector<paintit::coord> pontos;
			commandLine >> lados;

			for (size_t i = 0; i < lados; i++)
			{
				commandLine >> x >> y;
				pontos.emplace_back(paintit::coord(x, y));
			}
			if (!commandLine.fail())
				return_iferror(paintit::functions::polygon(*current_image, *pincel, pontos));
		}
		else if (lib::cstrcmp(command, "rect") == 0)
		{
			size_t largura, altura;
			ssize_t x, y;
			commandLine >> x >> y >> largura >> altura;
			if (!commandLine.fail())
				return_iferror(paintit::functions::rect(*current_image, *pincel, paintit::coord(x, y), largura, altura));
		}
		else if (lib::cstrcmp(command, "circle") == 0)
		{
			int raio, p, x, y;
			commandLine >> x >> y >> raio >> p;
			if (!commandLine.fail())
				return_iferror(paintit::functions::circle(*current_image, *pincel, paintit::coord(x, y), raio, p));
		}
		else if (lib::cstrcmp(command, "fill") == 0)
		{
			int x, y;
			commandLine >> x >> y;
			if (!commandLine.fail())
				return_iferror(paintit::functions::fill(*current_image, *pincel, paintit::coord(x, y)));
		}
		else if (lib::cstrcmp(command, "save") == 0)
		{
			std::string arquivo, formato;
			commandLine >> formato;

			commandLine.ignore(); //espaço em branco
			getline(commandLine, arquivo);

			if (!commandLine.fail())
				return_iferror(current_image->save(formato.c_str(), arquivo.c_str()));
		}
		else if (lib::cstrcmp(command, "open") == 0)
		{
			std::string arquivo;
			commandLine.ignore(); //espaço em branco
			getline(commandLine, arquivo);

			if (!commandLine.fail())
				return_iferror(current_image->open(arquivo.c_str()));
		}
		else if (lib::cstrcmp(command, "scolor") == 0)
		{
			std::string cor;
			commandLine >> cor;
			if (!commandLine.fail())
				return_iferror(pincel->scolor(cor));
		}
		else if (lib::cstrcmp(command, "sclear") == 0)
		{
			std::string cor;
			commandLine >> cor;
			if (!commandLine.fail())
				return_iferror(paintit::functions::sclear(*current_image, cor));
		}
		else if (lib::cstrcmp(command, "rotate") == 0)
		{
			if (!commandLine.fail())
				return_iferror(current_image->rotate());
		}
		else if (lib::cstrcmp(command, "invert") == 0)
		{
			if (!commandLine.fail())
				return_iferror(current_image->invert());
		}
		else if (lib::cstrcmp(command, "grayscale") == 0)
		{
			if (!commandLine.fail())
				return_iferror(paintit::processing::grayscale(*current_image));
		}
		else if (lib::cstrcmp(command, "sepia") == 0)
		{
			if (!commandLine.fail())
				return_iferror(paintit::processing::sepia(*current_image));
		}
		else if (lib::cstrcmp(command, "negative") == 0)
		{
			if (!commandLine.fail())
				return_iferror(paintit::processing::negative(*current_image));
		}
		else if (lib::cstrcmp(command, "glitch") == 0)
		{
			int deslocamento;
			double angulo;
			commandLine >> deslocamento >> angulo;
			if (!commandLine.fail())
				return_iferror(paintit::processing::glitch(*current_image, deslocamento, angulo));
		}
		else if (lib::cstrcmp(command, "rbglitch") == 0)
		{
			int deslocamento;
			double angulo;
			commandLine >> deslocamento >> angulo;
			if (!commandLine.fail())
				return_iferror(paintit::processing::rbglitch(*current_image, deslocamento, angulo));
		}
		else if (lib::cstrcmp(command, "pixelize") == 0)
		{
			int pixels;
			commandLine >> pixels;
			if (!commandLine.fail())
				return_iferror(paintit::processing::pixelize(*current_image, pixels));
		}
		else if (lib::cstrcmp(command, "darken") == 0)
		{
			double porcentagem;
			commandLine >> porcentagem;
			if (!commandLine.fail())
				return_iferror(paintit::processing::darken(*current_image, porcentagem));
		}
		else if (lib::cstrcmp(command, "brighten") == 0)
		{
			double porcentagem;
			commandLine >> porcentagem;
			if (!commandLine.fail())
				return_iferror(paintit::processing::brighten(*current_image, porcentagem));
		}
		else if (lib::cstrcmp(command, "vibrancy") == 0)
		{
			double porcentagem;
			commandLine >> porcentagem;
			if (!commandLine.fail())
				return_iferror(paintit::processing::vibrancy(*current_image, porcentagem));
		}
		else if (lib::cstrcmp(command, "intensity") == 0)
		{
			double vermelho, verde, azul;
			commandLine >> vermelho >> verde >> azul;
			if (!commandLine.fail())
				return_iferror(paintit::processing::intensity(*current_image, vermelho, verde, azul));
		}
		else if (lib::cstrcmp(command, "redequal") == 0)
		{
			double vermelho, verde, azul;
			commandLine >> vermelho >> verde >> azul;
			if (!commandLine.fail())
				return_iferror(paintit::processing::redequal(*current_image, vermelho, verde, azul));
		}
		else if (lib::cstrcmp(command, "greenequal") == 0)
		{
			double vermelho, verde, azul;
			commandLine >> vermelho >> verde >> azul;
			if (!commandLine.fail())
				return_iferror(paintit::processing::greenequal(*current_image, vermelho, verde, azul));
		}
		else if (lib::cstrcmp(command, "blueequal") == 0)
		{
			double vermelho, verde, azul;
			commandLine >> vermelho >> verde >> azul;
			if (!commandLine.fail())
				return_iferror(paintit::processing::blueequal(*current_image, vermelho, verde, azul));
		}
		else if (lib::cstrcmp(command, "desaturate") == 0)
		{
			double vermelho, verde, azul;
			commandLine >> vermelho >> verde >> azul;
			if (!commandLine.fail())
				return_iferror(paintit::processing::desaturate(*current_image, vermelho, verde, azul));
		}
		else if (lib::cstrcmp(command, "makenoise") == 0)
		{
			return_iferror(paintit::processing::makenoise(*current_image));
		}
		else if (lib::cstrcmp(command, "listcolor") == 0)
		{
			listcolor();
		}
		else if (lib::cstrcmp(command, "curve") == 0)
		{
			int ordem, x, y;
			std::vector<paintit::coord> pontos;
			commandLine >> ordem;
			for (int i = 0; i < ordem; i++)
			{
				commandLine >> x >> y;
				pontos.emplace_back(paintit::coord(x, y));
			}
			if (!commandLine.fail())
				return_iferror(paintit::functions::curve(*current_image, *pincel, pontos));
		}
		else if (lib::cstrcmp(command, "elipse") == 0)
		{
			int largura, altura, x, y, p;
			double angulo;
			commandLine >> x >> y >> largura >> altura >> angulo >> p;
			if (!commandLine.fail())
				return_iferror(paintit::functions::elipse(*current_image, *pincel, paintit::coord(x, y), largura, altura, angulo, p));
		}
		else if (lib::cstrcmp(command, "help") == 0)
		{
			unsigned page;
			commandLine >> page;
			if (!commandLine.fail())
			{
				help(page);
			}
			else
			{
				help();
			}
			return noerror;
		}
		else if (lib::cstrcmp(command, "purge") == 0)
		{
			CLS;
		}
		else if (lib::cstrcmp(command, "history") == 0)
		{
			for (auto &command : history)
			{
				std::cout << command << std::endl;
			}
		}
		else if (lib::cstrcmp(command, "exit") == 0)
		{
			view->isRunning = false;
			this->isRunning = false;
			return noerror;
		}
		else
		{
			return "Commando não encontrado, digite \"help\" para ver lista de comandos.";
		}

		if (commandLine.fail())
		{
			return command_sintax(command);
		}
	} while (!commandLine.eof() && isFor);

	return noerror;
}