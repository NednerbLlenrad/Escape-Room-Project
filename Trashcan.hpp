#pragma once
#include "gameObject.h"

class TrashCan : public gameObject
{
public:
    TrashCan(sf::IntRect size, sf::Texture& objectTexture, sf::Vector2f origin, bool draggable = false) : gameObject(size, objectTexture, origin, draggable)
    {
        mObjectBody.setScale(.80f, .80f);

        sf::Vector2f position(57 + origin.x, 468 + origin.y);
        mObjectBody.setPosition(position);
    }

    void interactionType() override 
    {
        mObjectBody.setTextureRect(sf::IntRect(160,0,128,256));
    }

};
