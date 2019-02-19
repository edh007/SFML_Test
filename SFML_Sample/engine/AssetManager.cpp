#include <SFML/Graphics.hpp>
#include "AssetManager.h"

NS_DHL_BEGIN

void AssetManager::LoadTexture(std::string name, std::string filename)
{
    sf::Texture tex;
    if (tex.loadFromFile(filename))
        _textures[name] = tex;
}

sf::Texture& AssetManager::GetTexture(std::string name)
{
    return _textures.at(name);
}

void AssetManager::LoadFont(std::string name, std::string filename)
{
    sf::Font font;
    if (font.loadFromFile(filename))
        _fonts[name] = font;
}

sf::Font& AssetManager::GetFont(std::string name)
{
    return _fonts.at(name);
}

NS_DHL_END
