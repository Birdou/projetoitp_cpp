
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
	/**
	 * @brief      This class describes a paintit main.
	 */
	class paintit_main
	{
	public:
		static paintit::ppm* current_image;
		static paintit::penc* pincel;

		/**
		 * @brief      Constructs a new instance.
		 */
		paintit_main();
		/**
		 * @brief      Destroys the object.
		 */
		~paintit_main();

		static bool isRunning;

		std::vector<std::string> history;

		/**
		 * @brief      Initializes the object.
		 */
		void init();
		/**
		 * @brief      { function_description }
		 */
		void execute();
		/**
		 * @brief      { function_description }
		 */
		void updateImage()
		{
			view->updateImage();
		}
		/**
		 * @brief      { function_description }
		 *
		 * @param      image  The image
		 */
		void updateImage(paintit::ppm& image)
		{
			view->updateImage(image);
		}
		/**
		 * @brief      { function_description }
		 *
		 * @param[in]  command  The command
		 *
		 * @return     { description_of_the_return_value }
		 */
		std::string executeCommand(const std::string& command);

	private:
		static viewer* view;
		SDL_Thread* viewerthread;
		/**
		 * @brief      { function_description }
		 *
		 * @param      ptr   The pointer
		 *
		 * @return     { description_of_the_return_value }
		 */
		static int sdlstart(void* ptr)
		{
			ptr = ptr; //Avoid unused variable warnings
			
			const int FPS = 30;
			const int frameDelay = 1000 / FPS;
			
			Uint32 frameStart;
			int frameTime;

			DebugLogS("creating an instance of viewer at " << FPS << " FPS...");
			view = new viewer("PaintIt PPM Viewer (by Felipe Sena)", 128, 72, 600, 400, false);
			DebugLogS("initializing viewer...");
			view->init();
			DebugLogS("entering viewer main loop...");
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