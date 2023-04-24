#include "gameObject.h"

void gameObject::drag(sf::RenderWindow& window)
{
	if (!isDraggable)
	{
		return;
	}
	else 
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			sf::Vector2i mousePosistion = sf::Mouse::getPosition(window);
			sf::Vector2f newPosistion = window.mapPixelToCoords(mousePosistion);
			mObjectBody.setPosition(newPosistion);
		}
		else
		{
			isDragging = false;
		}
	}
}
