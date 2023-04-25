#pragma once
#include "gameObject.h"

class Bed : public gameObject
{
public:
    Bed(sf::IntRect size, sf::Texture& objectTexture, sf::Vector2f origin, bool draggable = false) : gameObject(size, objectTexture, origin, draggable)
    {
        mObjectBody.setScale(.80f, 1.0f);

        sf::Vector2f position(550 + origin.x, 240 + origin.y);
        mObjectBody.setPosition(position);
    }

    void interactionType() override
    {
        mObjectBody.setTextureRect(sf::IntRect(512, 0, 512, 512));
    }

};