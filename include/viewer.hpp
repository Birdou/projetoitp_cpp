
#ifndef VIEWER_H
#define VIEWER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <map>

#include "ppm.hpp"
#include "ECS.hpp"
#include "AssetManager.hpp"

class UILabel;

namespace paintit
{
    class viewer
    {
    private:
        SDL_Window* window = NULL;
        std::string title;
        int xpos, ypos, width, height;
        bool fullscreen;

        SDL_Texture* imageTexture = NULL;
        SDL_Rect destRect = {0, 0, 0, 0};
        int imagew = 0, imageh = 0;
        float imagex = 0, imagey = 0;
        int relative_imagex = 0, relative_imagey = 0;
        float xyscale = 1.0f;

        static AssetManager* assetManager;

    public:
        /**
         * @brief      Constructs a new instance.
         *
         * @param[in]  title       The title
         * @param[in]  xpos        The xpos
         * @param[in]  ypos        The ypos
         * @param[in]  width       The width
         * @param[in]  height      The height
         * @param[in]  fullscreen  The fullscreen
         */
        viewer(const std::string& title, int xpos, int ypos, int width, int height, bool fullscreen);
        /**
         * @brief      Destroys the object.
         */
        ~viewer();

        static Manager manager;
        static SDL_Renderer* renderer;
        static SDL_Event event;
        static bool isRunning;

        /**
         * @brief      Initializes the object.
         */
        void init();

        /**
         * @brief      { function_description }
         */
        void updateImage();
        /**
         * @brief      { function_description }
         *
         * @param      <unnamed>  { parameter_description }
         */
        void updateImage(paintit::ppm*);

        /**
         * @brief      { function_description }
         */
        void handleEvents();
        /**
         * @brief      Updates the object.
         */
        void update();
        /**
         * @brief      { function_description }
         */
        void draw();
    };
}
#endif