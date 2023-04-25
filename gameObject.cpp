#include "gameObject.h"
#include <iostream>

float gameObject::distanceFromPlayer(Player player)
{
	sf::Vector2f objectPos = mObjectBody.getPosition();
	sf::Vector2f playerPos = player.getPosition();

	float dx = objectPos.x - playerPos.x;
	float dy = objectPos.y - playerPos.y;

	return std::sqrt(dx * dx + dy * dy);
}

bool gameObject::interaction(sf::RenderWindow& window, Player player)
{
	// Get the bounds of the object's sprite
	sf::FloatRect bounds = mObjectBody.getGlobalBounds();
    if (distanceFromPlayer(player) < 750)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
        {
            sf::Vector2i mousePositionI = sf::Mouse::getPosition(window);
            sf::Vector2f mousePositionF = window.mapPixelToCoords(mousePositionI);
            if (bounds.contains(mousePositionF))
            {
                interactionType();
                return true;
            }
            else
            {
                return false;
            }
        }
    }
	else
	{
		return false;
	}
}

void gameObject::drag(sf::RenderWindow& window, Player player)
{
    if (!isDraggable)
    {
        return;
    }
    else
    {
        // Get the bounds of the object's sprite
        sf::FloatRect bounds = mObjectBody.getGlobalBounds();
        if (distanceFromPlayer(player) < 600)
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                sf::Vector2i mousePositionI = sf::Mouse::getPosition(window);
                sf::Vector2f mousePositionF = window.mapPixelToCoords(mousePositionI);
                if (bounds.contains(mousePositionF))
                {
                    // Set isDragging to true and calculate the offset
                    isDragging = true;
                    offset = mObjectBody.getPosition() - mousePositionF;
                }

                if (isDragging)
                {
                    sf::Vector2i mousePosistion = sf::Mouse::getPosition(window);
                    sf::Vector2f newPosistion = window.mapPixelToCoords(mousePosistion);
                    mObjectBody.setPosition(newPosistion + offset);
                }
            }
        }
        else
        {
            isDragging = false;
        }

        // Debugging output
        std::cout << "Dragging object: " << mObjectBody.getPosition().x << ", " << mObjectBody.getPosition().y << std::endl;
    }
}

