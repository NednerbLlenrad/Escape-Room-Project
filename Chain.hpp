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

    void interactionType() override
    {
        mObjectBody.setScale(0, 0);
    }

};