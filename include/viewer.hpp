
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
        viewer(const std::string& title, int xpos, int ypos, int width, int height, bool fullscreen);
        ~viewer();

        static SDL_Renderer* renderer;
        static SDL_Event event;
        static bool isRunning;
    
        void init();
        
        void handleEvents();
        void update();
        void draw();
    };
}
#endif