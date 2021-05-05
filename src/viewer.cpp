
#include "viewer.hpp"

#include "UILabel.hpp"
#include "paintit.hpp"

SDL_Renderer* paintit::viewer::renderer = nullptr;
SDL_Event paintit::viewer::event;
bool paintit::viewer::isRunning = false;

Manager manager;
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

	//! Why this is throwing exceptions?
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

	SDL_Color labelcolor = {255, 255, 255, 255};
	
		assetManager->CreateLabel("position_label", Vector2D(10, height - 20), "", "arial_14", labelcolor);
		assetManager->CreateLabel("window_position_label", Vector2D(10, height - 40), "", "arial_14", labelcolor);
		assetManager->CreateLabel("resolution_label", Vector2D(10, 10), "", "arial_14", labelcolor);	
		assetManager->CreateLabel("scale_label", Vector2D(width - 10, 10), "", "arial_14", labelcolor)
			.getComponent<UILabel>().SetAlignment(UILabel::right); /*Se SetAlignment fosse do tipo Entity, ajustes
																	 desse tipo poderiam ser realizados em cadeia*/

}

void paintit::viewer::handleEvents()
{
	static bool leftMouseButtonDown = false;

	if(leftMouseButtonDown)
		SDL_EventState(SDL_MOUSEMOTION, SDL_ENABLE);
	else
		SDL_EventState(SDL_MOUSEMOTION, SDL_DISABLE);

	if (SDL_PollEvent(&event))
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
					//TODO: Corrgir o zoom out
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
	
	auto position_label = manager.getEntityByID("position_label");
	position_label->getComponent<UILabel>().SetLabelTextShaded(std::to_string(x) + " " + std::to_string(y));
	position_label->getComponent<UILabel>().SetPosition(10, height - 20);

	auto window_position_label = manager.getEntityByID("window_position_label");
	window_position_label->getComponent<UILabel>().SetLabelTextShaded(std::to_string(wx) + " " + std::to_string(wy));
	window_position_label->getComponent<UILabel>().SetPosition(10, height - 40);

	auto resolution_label = manager.getEntityByID("resolution_label");
	resolution_label->getComponent<UILabel>().SetLabelTextShaded(std::to_string(width) + "x" + std::to_string(height));
	resolution_label->getComponent<UILabel>().SetPosition(10, 10);

	auto scale_label = manager.getEntityByID("scale_label");
	scale_label->getComponent<UILabel>().SetLabelTextShaded("x" + std::to_string(xyscale));
	scale_label->getComponent<UILabel>().SetPosition(width - 10, 10);

	manager.refresh();
	manager.update();
}

auto& labels = manager.getGroup(AssetManager::groupLabels);

void paintit::viewer::draw()
{
	SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 144, 144, 144, 255);

	SDL_Surface* surface = IMG_Load("editview.bmp");
	if(surface != NULL)
	{
		if(imageTexture != NULL)
			SDL_DestroyTexture(imageTexture);
		imageTexture = SDL_CreateTextureFromSurface(renderer, surface);
		SDL_QueryTexture(imageTexture, nullptr, nullptr, &imagew, &imageh);

		destRect.x = relative_imagex;
		destRect.y = relative_imagey;
		destRect.w = imagew * xyscale;
		destRect.h = imageh * xyscale;

		TextureManager::Draw(imageTexture, destRect);
		SDL_FreeSurface(surface);
	}

	for(auto& label : labels)
	{
		label->draw();
	}

	SDL_RenderPresent(renderer);
}

