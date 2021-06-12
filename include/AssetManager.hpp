
#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <vector>
#include <map>

#include "ECS.hpp"
#include "Vector2D.hpp"

class AssetManager
{
public:
	AssetManager(Manager * man);
	~AssetManager();

	enum Tag
	{
		groupLabels
	};

	Entity& CreateLabel(const std::string& labelName, const Vector2D& position, const std::string& text, const std::string& font, SDL_Color color);

	void AddTexture(const std::string& id, char const * path);
	void AddFont(const std::string& id, const std::string& path, int fontSize);

	SDL_Texture* GetTexture(const std::string& id);
	
	static std::map<std::string, TTF_Font*> fonts;
	static TTF_Font* GetFont(const std::string& id);

private:
	Manager* manager;
	std::map<std::string, SDL_Texture*> textures;

	
};

#endif