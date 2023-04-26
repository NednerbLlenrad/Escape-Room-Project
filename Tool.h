#pragma once
#include <SFML/Graphics.hpp>
#include "player.h"

class Tool
{
public:
	//constructor
	Tool(sf::Texture& texture, sf::Vector2f position);

	//drop -- checks if tool is picked up and draws
	void drop(sf::RenderWindow & window);

	//allows tool to be picked up 
	bool pickUp(Player &player);

	//sets is picked up
	void setIsPickedUp(const bool ToF);

private:
	bool mIsPickedUp;
	sf::Sprite mToolBody;

};

