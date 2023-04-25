#pragma once
#include <SFML/Graphics.hpp>
#include "player.h"

//base class for all game objects
class gameObject
{
public:
    //constructor
    gameObject(sf::IntRect size, sf::Texture& objectTexture, sf::Vector2f origin, bool draggable = false)
    {
        mObjectBody.setTexture(objectTexture);
        mObjectBody.setTextureRect(size);
        mObjectBody.setOrigin(origin);
        isDraggable = draggable;
    }

    //Set Draggable
    void setDraggable(bool draggable)
    {
        isDraggable = draggable;
    }

    //Get Draggable
    bool getDraggable()
    {
        return isDraggable;
    }
    //Set position
    void setPosition(sf::Vector2f position)
    {
        mObjectBody.setPosition(position);
    }

    //Get position
    sf::Vector2f getPosition()
    {
        return mObjectBody.getPosition();
    }

    //Set Size
    void setSize(sf::IntRect nSize)
    {
        mObjectBody.setTextureRect(nSize);
    }

    //Draw object
    void draw(sf::RenderWindow& window)
    {
        window.draw(mObjectBody);
    }

    //Check if player is close enough
    float distanceFromPlayer(Player player);

    //Virtual function for interaction
    bool interaction(sf::RenderWindow& window, Player player, sf::IntRect shift);
    virtual void interactionType(sf::IntRect shift){}
   
    //Handle dragging
    void drag(sf::RenderWindow& window, Player player);

protected:
	sf::Sprite mObjectBody;
	sf::IntRect mSize; //for determining which chunk of the sprite sheet to display
	bool isDraggable;
	bool isDragging = false;
	sf::Vector2f offset;
};

