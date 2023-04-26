#include "gameObject.h"
//#include "InteractableClassObject.hpp"
#include <iostream>


//Calculates the distance from an object to the player in order to disable/enable interaction or dragging
float gameObject::distanceFromPlayer(Player player)
{
	sf::Vector2f objectPos = mObjectBody.getPosition();//Object POS
	sf::Vector2f playerPos = player.getPosition();//get PlayerPOS

	float dx = objectPos.x - playerPos.x;//find the x distance between
	float dy = objectPos.y - playerPos.y;//find the y distance between

	return std::sqrt(dx * dx + dy * dy);//use pythagoream theorem to calculate distance
}


//Commented out working code for distance between objects
//float gameObject::distanceFromObject(InteractableObject& objectTarget)
//{
//    sf::Vector2f objectPos = mObjectBody.getPosition();
//    sf::Vector2f playerPos = objectTarget.getPosition();
//
//    float dx = objectPos.x - playerPos.x;
//    float dy = objectPos.y - playerPos.y;
//
//    return std::sqrt(dx * dx + dy * dy);
//}

//Base interaction that uses a a interactionType virtual function to allow for different types of objects to be interacted with differently
bool gameObject::interaction(sf::RenderWindow& window, Player player, sf::IntRect shift)
{
	// Get the bounds of the object's sprite
	sf::FloatRect bounds = mObjectBody.getGlobalBounds();
    if (distanceFromPlayer(player) < 550)//If player is close enough and the mouse is hovering on the object area, then prompt appears
    {                                    //This tells the player to press E to interact, calling the virtual interactionType function based on the object type.
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

//Allows the object to be clicked and dragged around the window
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
        {                                    //Similarly to the interaction, if the player is close enough, they can drag the object while clicking on it.

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                sf::Vector2i mousePositionI = sf::Mouse::getPosition(window);
                sf::Vector2f mousePositionF = window.mapPixelToCoords(mousePositionI);
                if (bounds.contains(mousePositionF))
                {
                    // Set isDragging to true and calculate the offset
                    isDragging = true;
                    offset = mObjectBody.getPosition() - mousePositionF;//Offsets the object from the mouse
                }

                if (isDragging)
                {
                    sf::Vector2i mousePosistion = sf::Mouse::getPosition(window);//Gets both posistions and updates the object to the new mouse posistion while dragging is true.
                    sf::Vector2f newPosistion = window.mapPixelToCoords(mousePosistion);
                    mObjectBody.setPosition(newPosistion + offset);
                }
            }
        }
        else
        {
            isDragging = false;
        }
    }
}

