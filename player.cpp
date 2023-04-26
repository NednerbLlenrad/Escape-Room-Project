#include "player.h"
#include "InteractableClassObject.hpp"
Player::Player(sf::Texture& texture, sf::Vector2f position)
	: mHitBoxAdd(mBody, 0, 0, 128, 128)
{
	mHasScrewDriver = false;
	mHasNailFile = false;

	mIsOnTrash = false;

	mSize = texture.getSize();
	mSize.x = mSize.x / 4;
	mSize.y = mSize.y / 4;

	mImage.left = 0;
	mImage.top = 0;
	mImage.width = mSize.x;
	mImage.height = mSize.y;

	mBody.setPosition(position);
	mTotalTime = 0;

	mHitBoxAdd.setOffsets(sf::Vector2f(25, 100));
	mHitBoxAdd.setSize(sf::Vector2f(60, 20));
	mHitBoxAdd.setPosition();

	mBody.setTexture(texture);
	mBody.setTextureRect(mImage);

}

void Player::update(float deltaTime)
{
	mTotalTime += deltaTime;
	sf::Vector2f movement(0.0, 0.0);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		movement.y += -0.7;
		mImage.top = 2 * mSize.y; //swap sprite row
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		movement.y += 0.7;
		mImage.top = 0 * mSize.y;//swap sprite row

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		movement.x += 0.7;
		mImage.top = 1 * mSize.y;//swap sprite row

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		movement.x += -0.7;
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

		//update hitbox
		mHitBoxAdd.update();

}

void Player::draw(sf::RenderWindow& window)
{
	window.draw(mBody);
	mHitBoxAdd.draw(window);
}

void Player::handleWallCollisions()
{
	if (mBody.getPosition().x < -20)
	{
		mBody.setPosition(sf::Vector2f(-20, mBody.getPosition().y));
	}
	if (mBody.getPosition().x > 940)
	{
		mBody.setPosition(sf::Vector2f(940,mBody.getPosition().y));
	}
	if (mBody.getPosition().y > 648)
	{
		mBody.setPosition(sf::Vector2f(mBody.getPosition().x, 648));
	}
	if (mBody.getPosition().y < 384)
	{
		mBody.setPosition(sf::Vector2f(mBody.getPosition().x, 384));
	}

	mHitBoxAdd.update();
}

bool Player::getHasScrewDriver() const
{
	return mHasScrewDriver;
}

bool Player::getHasNailFile() const
{
	return mHasNailFile;
}

void Player::setHasScrewDriver(const bool ToF)
{
	mHasScrewDriver = ToF;
}

void Player::setHasNailFile(const bool ToF)
{
	mHasNailFile = ToF;
}

sf::FloatRect Player::getHitBoxGlobalBounds() const
{
	return mHitBoxAdd.getGlobalBounds();
}


sf::Vector2f Player::getPosition() const
{
	return mBody.getPosition();
}

void Player::setPosition(const sf::Vector2f newPos)
{
	mBody.setPosition(newPos);
}

bool Player::getIsOnTrash()
{
	return mIsOnTrash;
}

void Player::setIsOnTrash(const bool ToF)
{
	mIsOnTrash = ToF;
}

void Player::CheckFall(InteractableObject& trash)
{
	if (mIsOnTrash == true)
	{
		if (mBody.getPosition().x < trash.getPosition().x - 100 || mBody.getPosition().x >= trash.getPosition().x + 228
			|| mBody.getPosition().y > trash.getPosition().y + 128 || mBody.getPosition().y <= trash.getPosition().y + 60)
		{
			mBody.setPosition(mBody.getPosition().x, 600);
			mHitBoxAdd.update();
		}
	}
}

void Player::ClimbTrash(InteractableObject& trash)
{
	sf::Vector2f playerPos = mBody.getPosition();
	sf::Vector2f trashPos = trash.getPosition();

	float dx = trashPos.x - playerPos.x;
	float dy = trashPos.y - playerPos.y;

	float distance = std::sqrt(dx * dx + dy * dy);

	if (distance < 300)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		{
			mBody.setPosition(trash.getPosition().x, trash.getPosition().y + 100);
			mHitBoxAdd.update();
		}
	}
}
