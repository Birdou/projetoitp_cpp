
#ifndef UILABEL_H
#define UILABEL_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

#include "viewer.hpp"
#include "TextureManager.hpp"

class UILabel : public Component
{
public:
	
	enum labelType
	{
		solid,
		shaded,
		blended
	};
	
	enum Alignment
	{
		left,
		center,
		right
	};

private:
	std::string labelText, labelFont;

	int xpos = 0;
	int ypos = 0;
	int alpha = 255;

	bool aligned_left = true, aligned_center = false, aligned_right = false;

	bool sideside = false;
	Entity* sidelabel = nullptr;

	SDL_Rect position;
	SDL_Texture* labelTexture = NULL;
	SDL_Color foreground = {255, 255, 255, 255};
	SDL_Color background = {0, 0, 0, 255};

	labelType type;

	bool enabled = true;

	
	void UpdateTexture()
	{
		if(labelTexture != NULL)
			SDL_DestroyTexture(labelTexture);

		SDL_Surface* surf = NULL;
		switch(type)
		{
			case solid:
			{
				surf = TTF_RenderUTF8_Solid(AssetManager::GetFont(labelFont), labelText.c_str(), foreground);
				break;
			}
			case shaded:
			{
				surf = TTF_RenderUTF8_Shaded(AssetManager::GetFont(labelFont), labelText.c_str(), foreground, background);
				break;
			}
			case blended:
			{
				surf = TTF_RenderUTF8_Blended(AssetManager::GetFont(labelFont), labelText.c_str(), foreground);
				break;
			}
		}

		labelTexture = SDL_CreateTextureFromSurface(paintit::viewer::renderer, surf);
		SDL_FreeSurface(surf);

		SDL_SetTextureAlphaMod(labelTexture, alpha);
	}

public:

	
	UILabel(int xpos, int ypos, const std::string& labelText, const std::string& labelFont, SDL_Color foreground, labelType type = blended):
		labelFont(labelFont), xpos(xpos), ypos(ypos), foreground(foreground), type(type)
	{
		position.x = xpos;
		position.y = ypos;

		background = {0, 0, 0, 255};
		SetLabelText(labelText);
	}

	
	~UILabel()
	{
		sidelabel = nullptr;
		SDL_DestroyTexture(labelTexture);
	}

	
	void SetLabelText(const std::string& text, bool force = false)
	{
		if(!enabled || (labelText == text && !force))
		{
			return;
		}

		labelText = text;

		UpdateTexture();
		AdjustPosition();
	}

	
	void SetAlpha(int alpha)
	{
		this->alpha = alpha;
		SDL_SetTextureAlphaMod(labelTexture, alpha);
	}

	
	void SetBackground(const SDL_Color& background)
	{
		if(type != shaded)
			return;

		this->background = background;
		UpdateTexture();
	}
	
	void SetBackground(const paintit::rgb& background)
	{
		if(type != shaded)
			return;

		this->background.r = background.getR();
		this->background.g = background.getG();
		this->background.b = background.getB();
		UpdateTexture();
	}

	
	void SetForeground(const SDL_Color& foreground)
	{
		this->foreground = foreground;
		UpdateTexture();
	}

	
	void SetPosition(int x, int y)
	{
		ForcePosition(x, y);
		AdjustPosition();
	}

	
	void ForcePosition(int x, int y)
	{
		xpos = x;
		ypos = y;
	}

	
	void SetAtSide(const std::string& labelname)
	{
		aligned_left = aligned_center = aligned_right = false;
		sideside = true;
		sidelabel = paintit::viewer::manager.getEntityByID(labelname);
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

	
	void setWidth(size_t width)
	{
		position.w = width;
	}
	
	size_t getWidth() const
	{
		return position.w;
	}
	
	void setHeight(size_t height)
	{
		position.h = height;
	}
	
	size_t getHeight() const
	{
		return position.h;
	}

	
	void AdjustPosition()
	{
		if(labelTexture == NULL) 
			return;

		SDL_QueryTexture(labelTexture, nullptr, nullptr, &position.w, &position.h);
		if(sideside && sidelabel != nullptr)
		{
			position.y = sidelabel->getComponent<UILabel>().position.y;
			position.x = sidelabel->getComponent<UILabel>().position.x + sidelabel->getComponent<UILabel>().position.w;
		}
		else
		{ 
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
				position.x = xpos - position.w;
			}
			position.y = ypos;
		}
	}

	
	void disable()
	{
		enabled = false;
	}

	
	void enable()
	{
		enabled = true;
	}

	
	bool isEnabled() const
	{
		return enabled;
	}

	
	void draw() override
	{
		if(enabled && labelText != "")
		{
			TextureManager::Draw(labelTexture, position);
		}
	}
};

#endif