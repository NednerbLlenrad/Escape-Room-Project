#pragma once
#include "gameObject.h"

class Chain : public gameObject
{
public:
    Chain(sf::IntRect size, sf::Texture& objectTexture, sf::Vector2f origin, bool draggable = false) : gameObject(size, objectTexture, origin, draggable)
    {
        mObjectBody.setScale(1.0f, 1.0f);

        sf::Vector2f position(150 + origin.x, 500 + origin.y);
        mObjectBody.setPosition(position);
    }

    void interactionType(sf::IntRect shift) override
    {
        mObjectBody.setScale(0, 0);
    }

    void reset()
    {
        mObjectBody.setScale(1.0f, 1.0f);
    }
};