#pragma once
#include "gameObject.h"

class Vent : public gameObject
{
public:
    Vent(sf::IntRect size, sf::Texture& objectTexture, sf::Vector2f origin, bool draggable = false) : gameObject(size, objectTexture, origin, draggable)
    {
        mObjectBody.setScale(1.0f, 1.0f);

        sf::Vector2f position(350 + origin.x, 50 + origin.y);
        mObjectBody.setPosition(position);
    }

    void interactionType() override
    {
        mObjectBody.setTextureRect(sf::IntRect(192, 0, 192, 128));
    }

};