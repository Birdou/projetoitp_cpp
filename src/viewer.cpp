
#include "viewer.hpp"

#include "UILabel.hpp"
#include "paintit.hpp"

SDL_Renderer* paintit::viewer::renderer = nullptr;
SDL_Event paintit::viewer::event;
bool paintit::viewer::isRunning = false;

Manager paintit::viewer::manager;
AssetManager* paintit::viewer::assetManager = new AssetManager(&manager);

paintit::viewer::viewer(const std::string& title, int xpos, int ypos, int width, int height, bool fullscreen):
title(title), xpos(xpos), ypos(ypos), width(width), height(height), fullscreen(fullscreen)
{}

paintit::viewer::~viewer()
{
	delete assetManager;

	Debug("SDL_Image: Quit" << std::endl);
	IMG_Quit();
	Debug("SDL_TTF: Quit" << std::endl);
	TTF_Quit();

	Debug("SDL: Destroy renderer" << std::endl);
	SDL_DestroyRenderer(renderer);
	Debug("SDL: Destroy window" << std::endl);
	SDL_DestroyWindow(window);
	Debug("SDL: Destroy texture" << std::endl);
	SDL_DestroyTexture(imageTexture);

	//FIXME Why this is throwing exceptions?
	/*Debug("SDL: Quit" << std::endl);
	SDL_Quit();*/

}

void paintit::viewer::init()
{
	int flags = SDL_WINDOW_RESIZABLE;
	if (fullscreen)
	{
		flags |= SDL_WINDOW_FULLSCREEN;
	}
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow(title.c_str(), xpos, ypos, width, height, flags);
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		}
		isRunning = true;
		if(TTF_Init() != 0)
		{
			std::cout << SDL_GetError() << std::endl;
		}
		if(IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF) != 0)
		{
			std::cout << SDL_GetError() << std::endl;
		}
	}
	else
	{
		std::cout << SDL_GetError() << std::endl;
	}

	assetManager->AddFont("arial_14", "assets/fonts/arial.ttf", 14);

	SDL_Color white = {255, 255, 255, 255};
	SDL_Color black = {0, 0, 0, 255};
	SDL_Color red = {255, 0, 0, 255};
	SDL_Color green = {0, 255, 0, 255};
	SDL_Color blue = {0, 0, 255, 255};

		assetManager->CreateLabel("color_label", Vector2D(10, height - 55), " ", "arial_14", black);
		auto& redlabel = assetManager->CreateLabel("red_color_label", Vector2D(10, height - 40), " ", "arial_14", black);
			redlabel.getComponent<UILabel>().SetBackground(red);
		auto& greenlabel = assetManager->CreateLabel("green_color_label", Vector2D(20, height - 40), " ", "arial_14", black);
			greenlabel.getComponent<UILabel>().SetBackground(green);
			greenlabel.getComponent<UILabel>().SetAtSide("red_color_label");
		auto& bluelabel = assetManager->CreateLabel("blue_color_label", Vector2D(30, height - 40), " ", "arial_14", black);
			bluelabel.getComponent<UILabel>().SetBackground(blue);
			bluelabel.getComponent<UILabel>().SetAtSide("green_color_label");

		assetManager->CreateLabel("pencil_mode_label", Vector2D(10, 10), "", "arial_14", white);
		auto& pencil_color_label = assetManager->CreateLabel("pencil_color_label", Vector2D(10, 30), " ", "arial_14", black);
		pencil_color_label.getComponent<UILabel>().setWidth(30);
		pencil_color_label.getComponent<UILabel>().setHeight(30);

		auto& resolution_label = assetManager->CreateLabel("resolution_label", Vector2D(width - 10, height - 40), "", "arial_14", white);
			resolution_label.getComponent<UILabel>().SetAlignment(UILabel::right);
		assetManager->CreateLabel("position_label", Vector2D(10, height - 20), "", "arial_14", white);
		auto& scale_label = assetManager->CreateLabel("scale_label", Vector2D(width - 10, height - 20), "", "arial_14", white);
			scale_label.getComponent<UILabel>().SetAlignment(UILabel::right);

}

void paintit::viewer::handleEvents()
{
	static bool leftMouseButtonDown = false;

	if(leftMouseButtonDown)
	{
		SDL_EventState(SDL_MOUSEMOTION, SDL_ENABLE);
	}
	else
	{
		SDL_EventState(SDL_MOUSEMOTION, SDL_DISABLE);
	}

	if(SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				isRunning = false;
				break;
			case SDL_WINDOWEVENT:
				if(event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED)
				{
					width = event.window.data1;
					height = event.window.data2;
				}
				break;
			case SDL_MOUSEWHEEL:
				int x, y, dx, dy;
				SDL_GetMouseState(&x, &y);

				if(event.wheel.y > 0)
				{
					xyscale *= 1.25f;

					dx = x - relative_imagex;
					dy = y - relative_imagey;

					imagex -= (dx * 1.25f) - dx;
					imagey -= (dy * 1.25f) - dy;
				}
				else if(event.wheel.y < 0)
				{
					xyscale /= 1.25f;

					dx = x - relative_imagex;
					dy = y - relative_imagey;

					imagex += (dx * 1.25f) - dx;
					imagey += (dy * 1.25f) - dy;
				}
				break;
			case SDL_MOUSEMOTION:
				if(leftMouseButtonDown)
				{
					imagex += event.motion.xrel / (1 + sqrt(xyscale));
					imagey += event.motion.yrel / (1 + sqrt(xyscale));
				}
				break;
			case SDL_MOUSEBUTTONDOWN:
				if (!leftMouseButtonDown && event.button.button == SDL_BUTTON_LEFT)
				{
					leftMouseButtonDown = true;
				}
				break;
			case SDL_MOUSEBUTTONUP:
				if (leftMouseButtonDown && event.button.button == SDL_BUTTON_LEFT)
				{
					leftMouseButtonDown = false;
				}
				break;
			case SDL_KEYDOWN:
				switch(paintit::viewer::event.key.keysym.sym)
				{
					case SDLK_SPACE:
						imagex = 0;
						imagey = 0;
						xyscale = 1.0f;
						break;
					case SDLK_UP:
						imagey += xyscale;
						break;
					case SDLK_LEFT:
						imagex += xyscale;
						break;
					case SDLK_DOWN:
						imagey -= xyscale;
						break;
					case SDLK_RIGHT:
						imagex -= xyscale;
						break;
					case SDLK_F11:
						if(fullscreen)
						{
							SDL_SetWindowFullscreen(window, SDL_FALSE);
							fullscreen = false;
						}
						else
						{
							SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
							fullscreen = true;
						}
						SDL_GL_GetDrawableSize(window, &width, &height);
						break;
					default:
						break;
				}
				break;
			default:
				break;
		}
	}
}

void paintit::viewer::update()
{
	int x, y;
	SDL_GetMouseState(&x, &y);

	relative_imagex = (width / 2) - (imagew / 2) + imagex;
	relative_imagey = (height / 2) - (imageh / 2) + imagey;

	x -= relative_imagex;
	y -= relative_imagey;
	x /= xyscale;
	y /= xyscale;

	int wx, wy;
	SDL_GetMouseState(&wx, &wy);

	auto& pencil_mode_label = manager.getEntityByID("pencil_mode_label")->getComponent<UILabel>();
	switch(paintit_main::pincel->mode)
	{
		case penc::Modes::normal:
		{
			pencil_mode_label.SetLabelTextShaded("modo: normal");
			break;
		}
		case penc::Modes::average:
		{
			pencil_mode_label.SetLabelTextShaded("modo: média");
			break;
		}
		case penc::Modes::additive:
		{
			pencil_mode_label.SetLabelTextShaded("modo: aditivo");
			break;
		}
		case penc::Modes::subtractive:
		{
			pencil_mode_label.SetLabelTextShaded("modo: subtrativo");
			break;
		}
		case penc::Modes::last_mode:
		{
			break;
		}
	}
	auto& pencil_color_label = manager.getEntityByID("pencil_color_label")->getComponent<UILabel>();
	paintit::rgb pencilColor = paintit_main::pincel->getColor();
	pencil_color_label.background.r = pencilColor.getR();
	pencil_color_label.background.g = pencilColor.getG();
	pencil_color_label.background.b = pencilColor.getB();
	pencil_color_label.updateBackground();

	if(x >= 0 && static_cast<size_t>(x) < paintit_main::current_image->getWidth() &&
		y >= 0 && static_cast<size_t>(y) < paintit_main::current_image->getHeight())
	{
		auto& redlabelcomponent = manager.getEntityByID("red_color_label")->getComponent<UILabel>();
		auto& greenlabelcomponent = manager.getEntityByID("green_color_label")->getComponent<UILabel>();
		auto& bluelabelcomponent = manager.getEntityByID("blue_color_label")->getComponent<UILabel>();
		auto& colorlabelcomponent = manager.getEntityByID("color_label")->getComponent<UILabel>();
		paintit::rgb* color = paintit_main::current_image->getColor(x, y);
		if(color != nullptr)
		{
			redlabelcomponent.SetLabelTextShaded(std::to_string(color->getR()));
			greenlabelcomponent.SetLabelTextShaded(std::to_string(color->getG()));
			bluelabelcomponent.SetLabelTextShaded(std::to_string(color->getB()));
			colorlabelcomponent.background.r = color->getR();
			colorlabelcomponent.background.g = color->getG();
			colorlabelcomponent.background.b = color->getB();
			colorlabelcomponent.updateBackground();
			colorlabelcomponent.setWidth(redlabelcomponent.getWidth() + greenlabelcomponent.getWidth() + bluelabelcomponent.getWidth());
		}
		redlabelcomponent.SetPosition(10, height - 40);
		greenlabelcomponent.AdjustPosition();
		bluelabelcomponent.AdjustPosition();
		colorlabelcomponent.SetOnlyPosition(10, height - 54);
	}

	auto resolution_label 		= manager.getEntityByID("resolution_label");
	auto position_label 		= manager.getEntityByID("position_label");
	auto scale_label 			= manager.getEntityByID("scale_label");

	position_label->getComponent<UILabel>().SetLabelTextShaded(std::to_string(x) + " " + std::to_string(y));
	position_label->getComponent<UILabel>().SetPosition(10, height - 20);

	scale_label->getComponent<UILabel>().SetLabelTextShaded("x" + std::to_string(xyscale));
	scale_label->getComponent<UILabel>().SetPosition(width - 10, height - 20);

	resolution_label->getComponent<UILabel>().SetLabelTextShaded(std::to_string(paintit_main::current_image->getWidth()) + "x" + std::to_string(paintit_main::current_image->getHeight()));
	resolution_label->getComponent<UILabel>().SetPosition(width - 10, height - 40);

	manager.refresh();
	manager.update();
}

void paintit::viewer::updateImage()
{
	if(imageTexture != NULL)
		SDL_DestroyTexture(imageTexture);

	SDL_Surface* surface = IMG_Load("editview.png");
	if(surface != NULL)
	{
		imageTexture = SDL_CreateTextureFromSurface(renderer, surface);
		SDL_FreeSurface(surface);
	}
}

void paintit::viewer::updateImage(paintit::ppm& image)
{
	if(imageTexture != NULL)
		SDL_DestroyTexture(imageTexture);

	SDL_Surface* surface = SDL_CreateRGBSurface(0, image.getWidth(), image.getHeight(), 32, 0, 0, 0, 0);
	if(surface != NULL)
	{
		unsigned char* pixels = (unsigned char*)surface->pixels;
		for(size_t x = 0; x < image.getWidth(); ++x)
		{
			for(size_t y = 0; y < image.getHeight(); ++y)
			{
				pixels[4 * (y * surface->w + x) + 2] = image[y][x].getR(); //2103
				pixels[4 * (y * surface->w + x) + 1] = image[y][x].getG(); //2103
				pixels[4 * (y * surface->w + x) + 0] = image[y][x].getB(); //2103
				pixels[4 * (y * surface->w + x) + 3] = 255; //2103
			}
		}
		imageTexture = SDL_CreateTextureFromSurface(renderer, surface);
		SDL_FreeSurface(surface);
	}
}

auto& labels = paintit::viewer::manager.getGroup(AssetManager::groupLabels);

void paintit::viewer::draw()
{
	SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 144, 144, 144, 255);

	if(imageTexture != NULL)
	{
		SDL_QueryTexture(imageTexture, nullptr, nullptr, &imagew, &imageh);

		destRect.x = relative_imagex;
		destRect.y = relative_imagey;
		destRect.w = imagew * xyscale;
		destRect.h = imageh * xyscale;

		TextureManager::Draw(imageTexture, destRect);
	}

	for(auto& label : labels)
	{
		label->draw();
	}

	SDL_RenderPresent(renderer);
}

