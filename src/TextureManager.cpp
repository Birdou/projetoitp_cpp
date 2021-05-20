
#include "TextureManager.hpp"

#include <SDL2/SDL_image.h>
#include <cstring>
#include <iostream>

#include "viewer.hpp"

SDL_Texture* TextureManager::LoadTexture(const char * texture)
{
	SDL_Surface* tmpSurface = IMG_Load(texture);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(paintit::viewer::renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);
	if(strcmp(SDL_GetError(), "") != 0)
	{
		Debug("LOADTEXTURE:: " << texture << " : " << SDL_GetError() << std::endl);
		SDL_ClearError();
	}
	return tex;
}

void TextureManager::Draw(SDL_Texture* tex)
{
	if (tex == NULL)
	{
		Debug("DRAWFONT:: null texture" << std::endl);
		return;
	}
	SDL_RenderCopyEx(paintit::viewer::renderer, tex, nullptr, nullptr, 0, NULL, SDL_FLIP_NONE);
}

void TextureManager::Draw(SDL_Texture* tex, const SDL_Rect& dest)
{
	if (tex == NULL)
	{
		Debug("DRAWFONT:: null texture" << std::endl);
		return;
	}
	SDL_RenderCopyEx(paintit::viewer::renderer, tex, nullptr, &dest, 0, NULL, SDL_FLIP_NONE);
}

void TextureManager::Draw(SDL_Texture* tex, const SDL_Rect& src, const SDL_Rect& dest)
{
	if (tex == NULL)
	{
		Debug("DRAW:: null texture" << std::endl);
		return;
	}
	SDL_RenderCopyEx(paintit::viewer::renderer, tex, &src, &dest, 0, NULL, SDL_FLIP_NONE);
}

void TextureManager::Draw(SDL_Texture* tex, const SDL_Rect& src, const SDL_Rect& dest, float ang, SDL_RendererFlip flip)
{
	if (tex == NULL)
	{
		Debug("DRAW:: null texture" << std::endl);
		return;
	}
	SDL_RenderCopyEx(paintit::viewer::renderer, tex, &src, &dest, ang, NULL, flip);
}

