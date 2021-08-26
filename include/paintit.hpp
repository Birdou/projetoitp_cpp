
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
#include "rgb.hpp"
#include "coord.hpp"
#include "functions.hpp"
#include "processing.hpp"

namespace paintit
{

	class paintit_main
	{
	public:
		static paintit::ppm *current_image;
		static paintit::penc *pincel;

		paintit_main();

		~paintit_main();

		static bool isRunning;

		std::vector<std::string> history;

		void init();

		void execute();

		void updateImage()
		{
			view->updateImage();
		}

		void updateImage(paintit::ppm &image)
		{
			view->updateImage(&image);
		}

		std::string executeCommand(const std::string &command, bool isFor = false);

		std::string undo();
		std::string redo();

	private:
		int interaction = 0;
		int maxinteraction = 0;

		static viewer *view;
		SDL_Thread *viewerthread;

		static int sdlstart(void *ptr)
		{
			ptr = ptr; //Avoid unused variable warnings

			const int FPS = 30;
			const int frameDelay = 1000 / FPS;

			Uint32 frameStart;
			int frameTime;

			DebugLogS("creating an instance of viewer at " << FPS << " FPS...");
			view = new viewer("PaintIt Viewer (by Felipe Sena)", 128, 72, 600, 400, false);
			DebugLogS("initializing viewer...");
			view->init();
			DebugLogS("entering viewer main loop...");
			while (view->isRunning)
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