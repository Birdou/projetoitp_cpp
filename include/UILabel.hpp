
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
	/**
	 * @brief      { enum_description }
	 */
	enum labelType
	{
		solid,
		shaded,
		blended
	};
	/**
	 * @brief      { enum_description }
	 */
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

	/**
	 * @brief      { function_description }
	 */
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

	/**
	 * @brief      Constructs a new instance.
	 *
	 * @param[in]  xpos        The xpos
	 * @param[in]  ypos        The ypos
	 * @param[in]  labelText   The label text
	 * @param[in]  labelFont   The label font
	 * @param[in]  foreground  The foreground
	 * @param[in]  type        The type
	 */
	UILabel(int xpos, int ypos, const std::string& labelText, const std::string& labelFont, SDL_Color foreground, labelType type = blended):
		labelFont(labelFont), xpos(xpos), ypos(ypos), foreground(foreground), type(type)
	{
		position.x = xpos;
		position.y = ypos;

		background = {0, 0, 0, 255};
		SetLabelText(labelText);
	}

	/**
	 * @brief      Destroys the object.
	 */
	~UILabel()
	{
		sidelabel = nullptr;
		SDL_DestroyTexture(labelTexture);
	}

	/**
	 * @brief      Sets the label text.
	 *
	 * @param[in]  text   The text
	 * @param[in]  force  The force
	 */
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

	/**
	 * @brief      Sets the alpha.
	 *
	 * @param[in]  alpha  The alpha
	 */
	void SetAlpha(int alpha)
	{
		this->alpha = alpha;
		SDL_SetTextureAlphaMod(labelTexture, alpha);
	}

	/**
	 * @brief      Sets the background.
	 *
	 * @param[in]  background  The background
	 */
	void SetBackground(const SDL_Color& background)
	{
		if(type != shaded)
			return;

		this->background = background;
		UpdateTexture();
	}
	/**
	 * @brief      Sets the background.
	 *
	 * @param[in]  background  The background
	 */
	void SetBackground(const paintit::rgb& background)
	{
		if(type != shaded)
			return;

		this->background.r = background.getR();
		this->background.g = background.getG();
		this->background.b = background.getB();
		UpdateTexture();
	}

	/**
	 * @brief      Sets the foreground.
	 *
	 * @param[in]  foreground  The foreground
	 */
	void SetForeground(const SDL_Color& foreground)
	{
		this->foreground = foreground;
		UpdateTexture();
	}

	/**
	 * @brief      Sets the position.
	 *
	 * @param[in]  x     The new value
	 * @param[in]  y     The new value
	 */
	void SetPosition(int x, int y)
	{
		ForcePosition(x, y);
		AdjustPosition();
	}

	/**
	 * @brief      { function_description }
	 *
	 * @param[in]  x     { parameter_description }
	 * @param[in]  y     { parameter_description }
	 */
	void ForcePosition(int x, int y)
	{
		xpos = x;
		ypos = y;
	}

	/**
	 * @brief      Sets the at side.
	 *
	 * @param[in]  labelname  The labelname
	 */
	void SetAtSide(const std::string& labelname)
	{
		aligned_left = aligned_center = aligned_right = false;
		sideside = true;
		sidelabel = paintit::viewer::manager.getEntityByID(labelname);
		AdjustPosition();
	}

	/**
	 * @brief      Sets the alignment.
	 *
	 * @param[in]  alignment  The alignment
	 */
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

	/**
	 * @brief      Sets the width.
	 *
	 * @param[in]  width  The width
	 */
	void setWidth(size_t width)
	{
		position.w = width;
	}
	/**
	 * @brief      Gets the width.
	 *
	 * @return     The width.
	 */
	size_t getWidth() const
	{
		return position.w;
	}
	/**
	 * @brief      Sets the height.
	 *
	 * @param[in]  height  The height
	 */
	void setHeight(size_t height)
	{
		position.h = height;
	}
	/**
	 * @brief      Gets the height.
	 *
	 * @return     The height.
	 */
	size_t getHeight() const
	{
		return position.h;
	}

	/**
	 * @brief      { function_description }
	 */
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

	/**
	 * @brief      { function_description }
	 */
	void disable()
	{
		enabled = false;
	}

	/**
	 * @brief      { function_description }
	 */
	void enable()
	{
		enabled = true;
	}

	/**
	 * @brief      Determines if enabled.
	 *
	 * @return     True if enabled, False otherwise.
	 */
	bool isEnabled() const
	{
		return enabled;
	}

	/**
	 * @brief      { function_description }
	 */
	void draw() override
	{
		if(enabled && labelText != "")
		{
			TextureManager::Draw(labelTexture, position);
		}
	}
};

#endif