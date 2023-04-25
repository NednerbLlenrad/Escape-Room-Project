#pragma once
#include <sfml\Graphics.hpp>
#include "HitboxAddition.h"
class Player
{
public:
	Player(sf::Texture& texture, sf::Vector2f position);

	void update(float deltaTime); //update function for walk animation

	void draw(sf::RenderWindow& window); //function that draws the player on screen

	void handleWallCollisions();


	bool getHasScrewDriver() const; //returns true if true
	bool getHasNailFile() const;

	void setHasScrewDriver(const bool ToF);
	void setHasNailFile(const bool ToF);

	//returns global bounds
	sf::FloatRect getHitBoxGlobalBounds() const;

	//returns position
	sf::Vector2f getPosition() const;

	//sets position
	void setPosition(const sf::Vector2f newPos);


private:
	sf::IntRect mImage;//determines which sprite from the sheet is visible
	sf::Sprite mBody;
	sf::Vector2u mSize; //width and hight of 1 sprite 
	HitboxAddition mHitBoxAdd;

	float mTotalTime;

	bool mHasScrewDriver;
	bool mHasNailFile;
};

