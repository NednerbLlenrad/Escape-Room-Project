#include "Tool.h"
#include <iostream>

Tool::Tool(sf::Texture& texture, sf::Vector2f position)
{
	mToolBody.setTexture(texture);
	mToolBody.setTextureRect(sf::IntRect(0, 0, 64, 64));
	mToolBody.setPosition(position);
	mIsPickedUp = false;
}

void Tool::drop(sf::RenderWindow& window)
{
	if (mIsPickedUp == false)
	{
		window.draw(mToolBody);
	}
}

bool Tool::pickUp(Player& player)
{
	sf::Vector2f objectPos = mToolBody.getPosition();
	sf::Vector2f playerPos = player.getPosition();

	float dx = objectPos.x - playerPos.x;
	float dy = objectPos.y - playerPos.y;

	float distance = std::sqrt(dx * dx + dy * dy);

	if (distance < 160)
	{
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::X))
		{
			mIsPickedUp = true;
			return true;
		}
	}
}

