
#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <vector>
#include <map>

#include "ECS.hpp"
#include "Vector2D.hpp"

/**
 * @brief      This class describes an asset manager.
 */
class AssetManager
{
public:

	/**
	 * @brief      Constructs a new instance.
	 *
	 * @param      man   The man
	 */
	AssetManager(Manager * man);
	/**
	 * @brief      Destroys the object.
	 */
	~AssetManager();

	/**
	 * @brief      { enum_description }
	 */
	enum Tag
	{
		groupLabels
	};

	/**
	 * @brief      Creates a label.
	 *
	 * @param[in]  labelName  The label name
	 * @param[in]  position   The position
	 * @param[in]  text       The text
	 * @param[in]  font       The font
	 * @param[in]  color      The color
	 * @param[in]  type       The type
	 *
	 * @return     { description_of_the_return_value }
	 */
	Entity& CreateLabel(const std::string& labelName, const Vector2D& position, const std::string& text, const std::string& font, SDL_Color color, short type);

	/**
	 * @brief      Adds a texture.
	 *
	 * @param[in]  id    The identifier
	 * @param      path  The path
	 */
	void AddTexture(const std::string& id, char const * path);
	/**
	 * @brief      Adds a font.
	 *
	 * @param[in]  id        The identifier
	 * @param[in]  path      The path
	 * @param[in]  fontSize  The font size
	 */
	void AddFont(const std::string& id, const std::string& path, int fontSize);

	/**
	 * @brief      Gets the texture.
	 *
	 * @param[in]  id    The identifier
	 *
	 * @return     The texture.
	 */
	SDL_Texture* GetTexture(const std::string& id);

	/**
	 * @brief      Gets the font.
	 *
	 * @param[in]  id    The identifier
	 *
	 * @return     The font.
	 */
	static TTF_Font* GetFont(const std::string& id);

	static std::map<std::string, TTF_Font*> fonts;

private:

	Manager* manager;
	std::map<std::string, SDL_Texture*> textures;

};

#endif