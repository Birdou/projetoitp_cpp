
#ifndef UILABEL_H
#define UILABEL_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

#include "viewer.hpp"
#include "TextureManager.hpp"

class UILabel : public Component
{
private:
	int xpos, ypos;
	int alpha = 255;
	SDL_Rect position;
	SDL_Texture* labelTexture = NULL;
	std::string labelText, labelFont;
	bool aligned_left = true, aligned_center = false, aligned_right = false;

public:
	bool enabled = true;
	SDL_Color foreground;
	SDL_Color background;

	UILabel(int xpos, int ypos, const std::string& labelText, const std::string& labelFont, SDL_Color foreground) : 
		xpos(xpos), ypos(ypos), labelFont(labelFont), foreground(foreground)
	{
		position.x = xpos;
		position.y = ypos;

		background = {0, 0, 0, 255};
		SetLabelTextBlended(labelText);
	}
	
	enum Alignment
	{
		left,
		center,
		right
	};

	~UILabel()
	{
		SDL_DestroyTexture(labelTexture);
	}

	void SetAlpha(int alpha)
	{
		this->alpha = alpha;
	}

	void SetBackground(SDL_Color background)
	{
		this->background = background;
	}

	void SetPosition(int x, int y)
	{
		xpos = x;
		ypos = y;
		AdjustPosition();
	}

	void SetAlignment(Alignment alignment)
	{
		switch (alignment)
		{
		case left:
			aligned_left = true;
			aligned_center = false;
			aligned_right = false;
			break;
		case center:
			aligned_left = false;
			aligned_center = true;
			aligned_right = false;
			break;
		case right:
			aligned_left = false;
			aligned_center = false;
			aligned_right = true;
			break;
		default:
			break;
		}
	}

	void AdjustPosition()
	{
		SDL_QueryTexture(labelTexture, nullptr, nullptr, &position.w, &position.h);
		if(aligned_left)
		{
			position.x = xpos;
		}
		else if(aligned_center)
		{
			position.x = xpos - (position.w / 2);
		}
		else if(aligned_right)
		{
			position.x = xpos - (position.w);
		}
	}

	void SetLabelTextSolid(std::string text)
	{
		if(!enabled || labelText == text) 
			return;

		if(labelTexture != NULL)
			SDL_DestroyTexture(labelTexture);

		SDL_Surface* surf = TTF_RenderText_Solid(AssetManager::GetFont(labelFont), text.c_str(), foreground);
		labelTexture = SDL_CreateTextureFromSurface(paintit::viewer::renderer, surf);
		SDL_FreeSurface(surf);

		SDL_SetTextureAlphaMod(labelTexture, alpha);
		AdjustPosition();
		labelText = text;
	}
	void SetLabelTextShaded(std::string text)
	{
		if(!enabled || labelText == text) 
			return;

		if(labelTexture != NULL)
			SDL_DestroyTexture(labelTexture);

		SDL_Surface* surf = TTF_RenderText_Shaded(AssetManager::GetFont(labelFont), text.c_str(), foreground, background);
		labelTexture = SDL_CreateTextureFromSurface(paintit::viewer::renderer, surf);
		SDL_FreeSurface(surf);

		SDL_SetTextureAlphaMod(labelTexture, alpha);
		AdjustPosition();
		labelText = text;
	}
	void SetLabelTextBlended(std::string text)
	{
		if(!enabled || labelText == text) 
			return;

		if(labelTexture != NULL)
			SDL_DestroyTexture(labelTexture);

		SDL_Surface* surf = TTF_RenderText_Blended(AssetManager::GetFont(labelFont), text.c_str(), foreground);
		labelTexture = SDL_CreateTextureFromSurface(paintit::viewer::renderer, surf);
		SDL_FreeSurface(surf);

		SDL_SetTextureAlphaMod(labelTexture, alpha);
		AdjustPosition();
		labelText = text;
	}

	void draw() override
	{
		if(enabled)
		{
			TextureManager::Draw(labelTexture, position);
		}
	}
};

#endif