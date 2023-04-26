#pragma once
#include "gameObject.h"

class Desk : public gameObject
{
public:
    Desk(sf::IntRect size, sf::Texture& objectTexture, sf::Vector2f origin, bool draggable, bool interacted) : gameObject(size, objectTexture, origin, draggable, interacted)
    {
        mObjectBody.setScale(1.1f, 1.1f);

        sf::Vector2f position(75 + origin.x, 400 + origin.y);
        mObjectBody.setPosition(position);
    }

};