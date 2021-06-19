
#include "AssetManager.hpp"

#include "TextureManager.hpp"
#include "UILabel.hpp"

std::map<std::string, TTF_Font*> AssetManager::fonts;

AssetManager::AssetManager(Manager* man) : manager(man)
{}

AssetManager::~AssetManager()
{
	Debug("AssetManager:: Destroy textures..." << std::endl);
	for(auto t : textures) SDL_DestroyTexture(t.second);
	Debug("AssetManager:: Close fonts..." << std::endl);
	for(auto t : fonts) TTF_CloseFont(t.second);
}

Entity& AssetManager::CreateLabel(const std::string& labelName, const Vector2D& pos, const std::string& text, const std::string& font, SDL_Color color)
{
	auto& label(manager->addEntity(labelName));
	label.addComponent<UILabel>(pos.x, pos.y, text, font, color);
	label.addGroup(groupLabels);

	return label;
}

/*Entity* AssetManager::Label(const std::string& labelName)
{
	return labels[labelName];
}*/

void AssetManager::AddTexture(const std::string& id, char const * path)
{
	textures.emplace(id, TextureManager::LoadTexture(path));
}

SDL_Texture* AssetManager::GetTexture(const std::string& id)
{
	return textures[id];
}

void AssetManager::AddFont(const std::string& id, const std::string& path, int fontSize)
{
	fonts.emplace(id, TTF_OpenFont(path.c_str(), fontSize));
}

TTF_Font* AssetManager::GetFont(const std::string& id)
{
	return fonts[id];
}