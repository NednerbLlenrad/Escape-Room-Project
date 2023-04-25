#pragma once
#include "gameObject.h"

class Chair : public gameObject
{
public:
    Chair(sf::IntRect size, sf::Texture& objectTexture, sf::Vector2f origin, bool draggable = false) : gameObject(size, objectTexture, origin, draggable)
    {
        mObjectBody.setScale(1.0f, 1.0f);

        sf::Vector2f position(220 + origin.x, 350 + origin.y);
        mObjectBody.setPosition(position);
    }

    
};