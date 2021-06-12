
#ifndef PAINTIT_HPP
#define PAINTIT_HPP

#include <SDL2/SDL.h>
#include <iostream>
#include <thread>
#include <memory>

#include "lib.hpp"
#include "ppm.hpp"
#include "help.hpp"
#include "viewer.hpp"
#include "color.hpp"
#include "coord.hpp"
#include "functions.hpp"
#include "processing.hpp"

namespace paintit
{
	class paintit_main
	{
	public:
		static paintit::ppm* current_image;
		static paintit::penc* pincel;

		paintit_main();
		~paintit_main();

		static bool isRunning;

		std::vector<std::string> history;

		void init();
		void execute();
		std::string executeCommand(const std::string& command);

	private:
		static viewer* view;
		SDL_Thread* viewerthread;
		static int sdlstart(void* ptr)
		{
			ptr = ptr; //Avoid unused variable warnings
			
			const int FPS = 30;
			const int frameDelay = 1000 / FPS;
			
			Uint32 frameStart;
			int frameTime;

			view = new viewer("PaintIt PPM Viewer (by Felipe Sena)", 128, 72, 600, 400, false);
			view->init();
			while(view->isRunning)
			{
				frameStart = SDL_GetTicks();
			
				view->handleEvents();
				view->update();
				view->draw();

				frameTime = SDL_GetTicks() - frameStart;

				if (frameDelay > frameTime)
				{
					SDL_Delay(frameDelay - frameTime);
				}
			}
			return 0;
		}
	};
}

#endif