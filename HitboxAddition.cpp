#include "HitboxAddition.h"

HitboxAddition::HitboxAddition(sf::Sprite& sprite, float y_offset, float x_offset, float width, float height) 
	: mX_offset(x_offset), mY_offset(y_offset), mSprite(sprite)
{
	mHitBox.setPosition(mSprite.getPosition().x + mX_offset, mSprite.getPosition().y + mY_offset);
	mHitBox.setSize(sf::Vector2f(width, height));
	mHitBox.setFillColor(sf::Color::Transparent);
	this->mHitBox.setOutlineThickness(0.5);
	this->mHitBox.setOutlineColor(sf::Color::Green);

}

void HitboxAddition::draw(sf::RenderWindow& window)
{
	window.draw(mHitBox);
}

void HitboxAddition::update()
{
	mHitBox.setPosition(mSprite.getPosition().x + mX_offset, mSprite.getPosition().y + mY_offset);
}

void HitboxAddition::setOffsets(sf::Vector2f offsets)
{
	mX_offset = offsets.x;
	mY_offset = offsets.y;
}

void HitboxAddition::setSize(sf::Vector2f size)
{
	mHitBox.setSize(size);
}

void HitboxAddition::setPosition()
{
	mHitBox.setPosition(mSprite.getPosition().x + mX_offset, mSprite.getPosition().y + mY_offset);
}

void HitboxAddition::setSpriteRef(sf::Sprite& sprite)
{
	mSprite = sprite;
}

sf::FloatRect HitboxAddition::getGlobalBounds() const
{
	return mHitBox.getGlobalBounds();
}
