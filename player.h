#pragma once
#include <sfml\Graphics.hpp>
class player
{
public:
	void update(); //update function for walk animation
private:
	sf::IntRect currenImage;
	sf::Sprite body;

	bool mHasScrewDriver;
	bool mHasNailFile;
};

