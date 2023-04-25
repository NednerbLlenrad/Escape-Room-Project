#pragma once
#include <SFML/Graphics.hpp>

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


    //Draw object
    void draw(sf::RenderWindow& window)
    {
        window.draw(mObjectBody);
    }

    //Virtual function for interaction
    virtual void interaction() {}

    //Handle dragging
    void drag(sf::RenderWindow& window);

protected:
	sf::Sprite mObjectBody;
	sf::IntRect mSize; //for determining which chunk of the sprite sheet to display
	bool isDraggable;
	bool isDragging = false;
	sf::Vector2f offset;
};

