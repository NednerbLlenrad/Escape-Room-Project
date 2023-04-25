#include "player.h"

player::player(sf::Texture& texture, sf::Vector2f origin)
{
	mHasScrewDriver = false;
	mHasNailFile = false;

	mSize = texture.getSize();
	mSize.x = mSize.x / 4;
	mSize.y = mSize.y / 4;

	mImage.left = 0;
	mImage.top = 0;
	mImage.width = mSize.x;
	mImage.height = mSize.y;

	mOrigin = origin;
	mBody.setOrigin(origin);
	mTotalTime = 0;

	mBody.setTexture(texture);
	mBody.setTextureRect(mImage);
}

void player::update(float deltaTime)
{
	mTotalTime += deltaTime;
	sf::Vector2f movement(0.0, 0.0);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		movement.y += -0.5;
		mImage.top = 2 * mSize.y; //swap sprite row
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		movement.y += 0.5;
		mImage.top = 0 * mSize.y;//swap sprite row

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		movement.x += 0.5;
		mImage.top = 1 * mSize.y;//swap sprite row

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		movement.x += -0.5;
		mImage.top = 3 * mSize.y;//swap sprite row

	}

	if (mTotalTime >= 0.20) //switch to next sprite in row
	{
		mTotalTime -= 0.20f;
		if (movement.x != 0 || movement.y != 0) //update column if there is movement
		{
			mImage.left += mSize.x;
		}
	}
	if ((unsigned)mImage.left >= mSize.x * 4 || (movement.x == 0 && movement.y == 0))
	{
		mImage.left = 0; //reset to beginning of row
	}

	mBody.setTextureRect(mImage); //update texture
	mBody.move(movement); //move

}

void player::draw(sf::RenderWindow& window)
{
	window.draw(mBody);
}

bool player::getHasScrewDriver() const
{
	return mHasScrewDriver;
}

bool player::getHasNailFile() const
{
	return mHasNailFile;
}

void player::setHasScrewDriver(const bool ToF)
{
	mHasScrewDriver = ToF;
}

void player::setHasNailFile(const bool ToF)
{
	mHasNailFile = ToF;
}
