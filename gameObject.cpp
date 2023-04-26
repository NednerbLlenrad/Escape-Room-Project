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

bool gameObject::interaction(sf::RenderWindow& window, Player player, sf::IntRect shift)
{
	// Get the bounds of the object's sprite
	sf::FloatRect bounds = mObjectBody.getGlobalBounds();
    if (distanceFromPlayer(player) < 450)
    {
        sf::Vector2i mousePositionI = sf::Mouse::getPosition(window);
        sf::Vector2f mousePositionF = window.mapPixelToCoords(mousePositionI);
        if (bounds.contains(mousePositionF))
        {
            sf::Font font;
            font.loadFromFile("Font/joystix monospace.ttf");
            sf::Text interactPrompt("Press E to Interact", font, 30);
            interactPrompt.setPosition(300, 705); // Set label position
            interactPrompt.setFillColor(sf::Color::White);
            window.draw(interactPrompt);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
            {
                interactionType(shift);
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
    // Get the bounds of the object's sprite
    sf::FloatRect bounds = mObjectBody.getGlobalBounds();

    if (distanceFromPlayer(player) < 600 && sf::Mouse::isButtonPressed(sf::Mouse::Left))
    { 
            sf::Vector2i mousePositionI = sf::Mouse::getPosition(window);
            sf::Vector2f mousePositionF = window.mapPixelToCoords(mousePositionI);
            //Check if mouse is hovering on object
            if (bounds.contains(mousePositionF))
            {
                // Set isDragging to true and calculate the offset
                isDragging = true;
                offset = mObjectBody.getPosition() - mousePositionF;
                mObjectBody.move(0, 0.1f);
            }
    }
    if (isDragging)
    {
        sf::Vector2i mousePosistion = sf::Mouse::getPosition(window);
        sf::Vector2f newPosistion = window.mapPixelToCoords(mousePosistion);
        mObjectBody.setPosition(newPosistion + offset);

        mObjectBody.move(0, 0.1f);
    }
    else
    {
        isDragging = false;
    }
}

