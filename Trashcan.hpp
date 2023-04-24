#pragma once
#include "gameObject.h"

class TrashCan : public gameObject
{
public:
    TrashCan(sf::IntRect size, sf::Texture& objectTexture, sf::Vector2f origin, bool draggable = false) : gameObject(size, objectTexture, origin, draggable)
    {
        mObjectBody.setScale(0.5f, 0.5f);
    }

    void interaction()
    {
        //flip over the trash can
        mObjectBody.setRotation(180);
    }
};
