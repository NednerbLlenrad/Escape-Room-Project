#pragma once
#include <sfml\Graphics.hpp>
class player
{
public:
	player(sf::Texture& texture, sf::Vector2f origin);

	void update(float deltaTime); //update function for walk animation

	void draw(sf::RenderWindow& window); //function that draws the player on screen


	bool getHasScrewDriver() const; //returns true if true
	bool getHasNailFile() const;

	void setHasScrewDriver(const bool ToF);
	void setHasNailFile(const bool ToF);


private:
	sf::IntRect mImage;//determines which sprite from the sheet is visible
	sf::Sprite mBody;
	sf::Vector2u mSize; //width and hight of 1 sprite 
	sf::Vector2f mOrigin;

	float mTotalTime;

	bool mHasScrewDriver;
	bool mHasNailFile;
};

