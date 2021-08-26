
#ifndef TEXTUREMANAGER_HPP
#define TEXTUREMANAGER_HPP

#include <SDL2/SDL.h>

struct TextureManager
{

	static SDL_Texture *LoadTexture(const char *fileName);

	static void Draw(SDL_Texture *tex);

	static void Draw(SDL_Texture *tex, const SDL_Rect &dest);

	static void Draw(SDL_Texture *tex, const SDL_Rect &src, const SDL_Rect &dest);

	static void Draw(SDL_Texture *tex, const SDL_Rect &src, const SDL_Rect &dest, float ang, SDL_RendererFlip flip);
};

#endif