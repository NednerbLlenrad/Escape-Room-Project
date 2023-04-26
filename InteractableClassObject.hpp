#pragma once
#include "gameObject.h"

class InteractableObject : public gameObject
{
public:
    //Initializes the object
    InteractableObject(sf::IntRect size, sf::Texture& objectTexture, sf::Vector2f origin, bool draggable, int xOffset, int yOffset, float scale, bool interacted) : gameObject(size, objectTexture, origin, draggable, interacted)
    {
        mObjectBody.setScale(scale, scale);

        sf::Vector2f position(xOffset + origin.x, yOffset + origin.y);
        mObjectBody.setPosition(position);
        this->xOffset = xOffset;
        this->yOffset = yOffset;
        this->spritePos = size;
    }
    //Override of interactionType 
    //In this override, the texture is shifted to the next sprite
    void interactionType(sf::IntRect shift) override
    {
        mObjectBody.setTextureRect(shift);
    }
    //Reset resets the posistion and the texture of the draggability to false.
    void reset()
    {
        mObjectBody.setTextureRect(spritePos);
        sf::Vector2f position(xOffset + 267, yOffset + 468);
        mObjectBody.setPosition(position);
        setDraggable(false);
        setInteracted(false);
    }

private:
    int xOffset;
    int yOffset;
    sf::IntRect spritePos;

};