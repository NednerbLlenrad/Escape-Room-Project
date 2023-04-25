#pragma once
#include <SFML/Graphics.hpp>

class HitboxAddition
{
public:
	//constructor w/ parameters 
	HitboxAddition(sf::Sprite&, float y_offset, float x_offset, float width, float height);

	//draw 
	void draw(sf::RenderWindow& window);

	//update
	void update();

	//setters
	void setOffsets(sf::Vector2f offsets);

	void setSize(sf::Vector2f size);

	void setPosition();

	void setSpriteRef(sf::Sprite& sprite);

	//get global bounds of hitbox
	sf::FloatRect getGlobalBounds() const;

private:
	sf::RectangleShape mHitBox;
	sf::Sprite& mSprite;
	float mX_offset;
	float mY_offset;
};

