#pragma once
#include "gameObject.h"

class InteractableObject : public gameObject
{
public:
    InteractableObject(sf::IntRect size, sf::Texture& objectTexture, sf::Vector2f origin, bool draggable, int xOffset, int yOffset, float scale) : gameObject(size, objectTexture, origin, draggable)
    {
        mObjectBody.setScale(scale, scale);

        sf::Vector2f position(xOffset + origin.x, yOffset + origin.y);
        mObjectBody.setPosition(position);
        this->xOffset = xOffset;
        this->yOffset = yOffset;
        this->spritePos = size;
    }

    void interactionType(sf::IntRect shift) override
    {
        mObjectBody.setTextureRect(shift);
    }

    void reset()
    {
        mObjectBody.setTextureRect(spritePos);
        sf::Vector2f position(xOffset + 267, yOffset + 468);
        mObjectBody.setPosition(position);
        setDraggable(false);
    }

private:
    int xOffset;
    int yOffset;
    sf::IntRect spritePos;
};