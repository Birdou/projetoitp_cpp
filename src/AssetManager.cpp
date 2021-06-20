
#include "AssetManager.hpp"

#include <exception>

#include "TextureManager.hpp"
#include "UILabel.hpp"

std::map<std::string, TTF_Font*> AssetManager::fonts;

AssetManager::AssetManager(Manager* man): manager(man)
{}

AssetManager::~AssetManager()
{
	DebugMessage("destroying textures...");
	for(auto t : textures)
	{
		SDL_DestroyTexture(t.second);
	}
	DebugMessage("closing fonts...");
	for(auto t : fonts)
	{
		TTF_CloseFont(t.second);
	}
}

Entity& AssetManager::CreateLabel(const std::string& labelName, const Vector2D& pos, const std::string& text, const std::string& font, SDL_Color color, short type)
{
	if(fonts.find(font) == fonts.end())
	{
		DebugError("couldn't find a font called " << font << ".");
	}
	auto& label(manager->addEntity(labelName));
	label.addComponent<UILabel>(pos.x, pos.y, text, font, color, static_cast<UILabel::labelType>(type));
	label.addGroup(groupLabels);

	return label;
}

void AssetManager::AddTexture(const std::string& id, char const * path)
{
	SDL_Texture* texture = TextureManager::LoadTexture(path);
	if(texture == NULL)
	{
		DebugError("couldn't open " << path << ".");
	}
	textures.emplace(id, texture);
}

SDL_Texture* AssetManager::GetTexture(const std::string& id)
{
	if(textures.find(id) == textures.end())
	{
		DebugWarning("returning null on " << id << " request");
		return NULL;
	}
	return textures[id];
}

void AssetManager::AddFont(const std::string& id, const std::string& path, int fontSize)
{
	TTF_Font* font = TTF_OpenFont(path.c_str(), fontSize);
	if(font == NULL)
	{
		DebugError(TTF_GetError());
		return;
	}
	fonts.emplace(id, font);
}

TTF_Font* AssetManager::GetFont(const std::string& id)
{
	if(fonts.find(id) == fonts.end())
	{
		DebugWarningS("returning null on " << id << " request");
		return NULL;
	}
	return fonts[id];
}