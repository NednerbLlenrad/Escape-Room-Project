#pragma once
#include "gameObject.h"

class Sink : public gameObject
{
public:
    Sink(sf::IntRect size, sf::Texture& objectTexture, sf::Vector2f origin, bool draggable = false) : gameObject(size, objectTexture, origin, draggable)
    {
        mObjectBody.setScale(1.0f, 1.0f);

        sf::Vector2f position(400 + origin.x, 360 + origin.y);
        mObjectBody.setPosition(position);
    }

    void interactionType() override
    {
        mObjectBody.setTextureRect(sf::IntRect(128, 0, 128, 128));
    }

};