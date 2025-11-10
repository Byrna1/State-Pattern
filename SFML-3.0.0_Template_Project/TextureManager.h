#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <unordered_map>

using namespace std;

class SpriteTexture
{
public:
	string fileName;
	sf::IntRect rect;
};

class TextureManager
{
	// singleton which manages textures
	unordered_map< string, sf::Texture> textures;
	unordered_map< string, SpriteTexture> sprites;
	TextureManager() {} // private constructor
	void addTextureFile(const string& fileName);
public:
	void addTexture(const string& fileName, const sf::IntRect& rect, const string& alias);
	static TextureManager& instance()
	{
		static TextureManager instance; // static variable, only initialized once
		return instance;
	}
	void setTextureFiltering(const string& fileName, bool filteringOn)
	{
		textures[fileName].setSmooth(filteringOn);
	}
	sf::Sprite getSprite(const string& alias)
	{
		// look for the alias
		if (sprites.find(alias) == sprites.end())
		{
			throw std::runtime_error("Sprite alias not found: " + alias);
		}
		sf::Sprite spr = sf::Sprite(textures[sprites[alias].fileName]);
		spr.setTextureRect(sprites[alias].rect);
		return spr;
	}
};