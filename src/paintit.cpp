
#include "paintit.hpp"

#include <sstream>

#include "viewer.hpp"

paintit::ppm* paintit::paintit_main::current_image = nullptr;
paintit::viewer* paintit::paintit_main::view = nullptr;

paintit::paintit_main::paintit_main()
{}

paintit::paintit_main::~paintit_main()
{
	delete current_image;
	delete pincel;
	delete view;
}

void paintit::paintit_main::init()
{
	current_image = new paintit::ppm(0, 0, nullptr);
	pincel = new paintit::penc(paintit::rgb(0, 0, 0), 1);

	viewerthread = SDL_CreateThread(sdlstart, "sdlstart", (void*)NULL);

	std::cout << "Digite \"help\" para ver lista de commands" << std::endl;
}

void paintit::paintit_main::execute()
{
	std::vector<std::string> history;
	
	int threadReturnValue;

	while(1)
	{
		std::string line, command, error;
		std::cout << "> ";
		std::cin.clear();
		getline(std::cin, line);
		std::stringstream commandLine(line);
		commandLine >> command;

		if(lib::cstrcmp(command, "image") == 0)
		{
			int largura, altura;
			commandLine >> largura >> altura;
			if(!commandLine.fail())
				error = current_image->image(largura, altura);
		}
		else if(lib::cstrcmp(command, "color") == 0)
		{
			int r, g, b;
			commandLine >> r >> g >> b;
			if(!commandLine.fail())
				pincel->setColor(paintit::rgb(r, g, b));
		}
		else if(lib::cstrcmp(command, "size") == 0)
		{
			int tamanho;
			commandLine >> tamanho;
			if(!commandLine.fail())
				pincel->setSize(tamanho);
		}
		else if(lib::cstrcmp(command, "guev") == 0)
		{
			double escala;
			commandLine >> escala;
			if(!commandLine.fail())
				error = paintit::processing::guev(*current_image, escala);
		}
		else if(lib::cstrcmp(command, "clear") == 0)
		{
			short r, g, b;
			commandLine >> r >> g >> b;
			if(!commandLine.fail())
				error = current_image->clear(paintit::rgb(r, g, b));
		}
		else if(lib::cstrcmp(command, "global") == 0)
		{
			ssize_t x, y;
			commandLine >> x >> y;
			if(!commandLine.fail())
				error = paintit::functions::global(*current_image, *pincel, paintit::coord(x, y));
		}
		else if(lib::cstrcmp(command, "line") == 0)
		{
			paintit::coord inicio, fim;
			commandLine >> inicio.x >> inicio.y >> fim.x >> fim.y;
			if(!commandLine.fail())
				error = paintit::functions::line(*current_image, *pincel, inicio, fim);
		}
		else if(lib::cstrcmp(command, "polygon") == 0)
		{
			size_t lados;
			ssize_t x, y;
			std::vector<paintit::coord> pontos;
			commandLine >> lados;

			for(size_t i = 0; i < lados; i++)
			{
				commandLine >> x >> y;
				pontos.emplace_back(paintit::coord(x, y));
			}
			if(!commandLine.fail())
				error = paintit::functions::polygon(*current_image, *pincel, pontos);
		}
		else if(lib::cstrcmp(command, "rect") == 0)
		{
			size_t largura, altura;
			ssize_t x, y;
			commandLine >> x >> y >> largura >> altura;
			if(!commandLine.fail())
				error = paintit::functions::rect(*current_image, *pincel, paintit::coord(x, y), largura, altura);
		}
		else if(lib::cstrcmp(command, "circle") == 0)
		{
			int raio, p, x, y;
			commandLine >> x >> y >> raio >> p;
			if(!commandLine.fail())
				error = paintit::functions::circle(*current_image, *pincel, paintit::coord(x, y), raio, p);
		}
		else if(lib::cstrcmp(command, "fill") == 0)
		{
			int x, y;
			commandLine >> x >> y;
			if(!commandLine.fail())
				error = paintit::functions::fill(*current_image, *pincel, paintit::coord(x, y));
		}
		else if(lib::cstrcmp(command, "save") == 0)
		{
			std::string arquivo, formato;
			commandLine >> formato;
			getline(commandLine, arquivo);
			if(!commandLine.fail())
				error = current_image->save(formato, arquivo);
		}
		else if(lib::cstrcmp(command, "open") == 0)
		{
			std::string arquivo;
			//getline(commandLine, arquivo);
			commandLine >> arquivo;
			if(!commandLine.fail())
				error = current_image->open(arquivo);
		}
		else if(lib::cstrcmp(command, "scolor") == 0)
		{
			std::string cor;
			commandLine >> cor;
			if(!commandLine.fail())
				pincel->scolor(cor);
		}
		else if(lib::cstrcmp(command, "sclear") == 0)
		{
			std::string cor;
			commandLine >> cor;
			if(!commandLine.fail())
				error = paintit::functions::sclear(*current_image, cor);
		}
		else if(lib::cstrcmp(command, "rotate") == 0)
		{
			if(!commandLine.fail())
				error = current_image->rotate();
		}
		else if(lib::cstrcmp(command, "invert") == 0)
		{
			if(!commandLine.fail())
				error = current_image->invert();
		}
		else if(lib::cstrcmp(command, "grayscale") == 0)
		{
			if(!commandLine.fail())
				error = paintit::processing::grayscale(*current_image);
		}
		else if(lib::cstrcmp(command, "sepia") == 0)
		{
			if(!commandLine.fail())
				error = paintit::processing::sepia(*current_image);
		}
		else if(lib::cstrcmp(command, "negative") == 0)
		{
			if(!commandLine.fail())
				error = paintit::processing::negative(*current_image);
		}
		else if(lib::cstrcmp(command, "glitch") == 0)
		{
			int deslocamento;
			double angulo;
			commandLine >> deslocamento >> angulo;
			if(!commandLine.fail())
				error = paintit::processing::glitch(*current_image, deslocamento, angulo);
		}
		else if(lib::cstrcmp(command, "rbglitch") == 0)
		{
			int deslocamento;
			double angulo;
			commandLine >> deslocamento >> angulo;
			if(!commandLine.fail())
				error = paintit::processing::rbglitch(*current_image, deslocamento, angulo);
		}
		else if(lib::cstrcmp(command, "pixelize") == 0)
		{
			int pixels;
			commandLine >> pixels;
			if(!commandLine.fail())
				error = paintit::processing::pixelize(*current_image, pixels);
		}
		else if(lib::cstrcmp(command, "darken") == 0)
		{
			double porcentagem;
			commandLine >> porcentagem;
			if(!commandLine.fail())
				error = paintit::processing::darken(*current_image, porcentagem);
		}
		else if(lib::cstrcmp(command, "brighten") == 0)
		{
			double porcentagem;
			commandLine >> porcentagem;
			if(!commandLine.fail())
				error = paintit::processing::brighten(*current_image, porcentagem);
		}
		else if(lib::cstrcmp(command, "vibrancy") == 0)
		{
			double porcentagem;
			commandLine >> porcentagem;
			if(!commandLine.fail())
				error = paintit::processing::vibrancy(*current_image, porcentagem);
		}
		else if(lib::cstrcmp(command, "intensity") == 0)
		{
			double vermelho, verde, azul;
			commandLine >> vermelho >> verde >> azul;
			if(!commandLine.fail())
				error = paintit::processing::intensity(*current_image, vermelho, verde, azul);
		}
		else if(lib::cstrcmp(command, "redequal") == 0)
		{
			double vermelho, verde, azul;
			commandLine >> vermelho >> verde >> azul;
			if(!commandLine.fail())
				error = paintit::processing::redequal(*current_image, vermelho, verde, azul);
		}
		else if(lib::cstrcmp(command, "greenequal") == 0)
		{
			double vermelho, verde, azul;
			commandLine >> vermelho >> verde >> azul;
			if(!commandLine.fail())
				error = paintit::processing::greenequal(*current_image, vermelho, verde, azul);
		}
		else if(lib::cstrcmp(command, "blueequal") == 0)
		{
			double vermelho, verde, azul;
			commandLine >> vermelho >> verde >> azul;
			if(!commandLine.fail())
				error = paintit::processing::blueequal(*current_image, vermelho, verde, azul);
		}
		else if(lib::cstrcmp(command, "desaturate") == 0)
		{
			double vermelho, verde, azul;
			commandLine >> vermelho >> verde >> azul;
			if(!commandLine.fail())
				error = paintit::processing::desaturate(*current_image, vermelho, verde, azul);
		}
		else if(lib::cstrcmp(command, "listcolor") == 0)
		{
			listcolor();
		}
		else if(lib::cstrcmp(command, "curve") == 0)
		{
			int ordem, x, y;
			std::vector<paintit::coord> pontos;
			commandLine >> ordem;
			for(int i = 0; i < ordem; i++)
			{
				commandLine >> x >> y;
				pontos.emplace_back(paintit::coord(x, y));
			}
			if(!commandLine.fail())
				error = paintit::functions::curve(*current_image, *pincel, pontos);
		}
		else if(lib::cstrcmp(command, "elipse") == 0)
		{
			int largura, altura, x, y, p;
			double angulo;
			commandLine >> x >> y >> largura >> altura >> angulo >> p;
			if(!commandLine.fail())
				error = paintit::functions::elipse(*current_image, *pincel, paintit::coord(x, y), largura, altura, angulo, p);
		}
		else if(lib::cstrcmp(command, "help") == 0)
		{
			help();
		}
		else if(lib::cstrcmp(command, "purge") == 0)
		{
			CLS;
		}
		else if(lib::cstrcmp(command, "history") == 0)
		{
			for(auto& command : history)
			{
				std::cout << command << std::endl;
			}
			continue;
		}
		else if(lib::cstrcmp(command, "exit") == 0)
		{
			view->isRunning = false;
			break;
		}
		else
		{
			std::cout << "Command não encontrado, digite \"help\" para ver lista de commands." << std::endl;
			continue;
		}
		if(commandLine.fail())
		{
			std::cout << "Sintaxe do command incorreta." << std::endl;
		}
		else
		{
			if(error.size() != 0)
				std::cout << error << std::endl;

			current_image->saveBmp("editview.bmp");
			history.emplace_back(line);
		}
	}
	remove("editview.bmp");
	SDL_WaitThread(viewerthread, &threadReturnValue);
}