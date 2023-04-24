#pragma once
#include <SFML/Graphics.hpp>
//base class for all game objects
class gameObject
{
public:
	//constructor
	gameObject(sf::IntRect size, sf::Texture &objectTexture, sf::Vector2f origin); //initialized with size, texture, and origin

	void playerInteraction();
private:
	sf::Sprite mObjectBody;
	sf::IntRect mSize; //for determining which chunk of the sprite sheet to display
};

