#include "TextPopup.h"

TextPopup::TextPopup()
{
	isActive = true;
}

void TextPopup::setFont(sf::Font& font)
{
	mText.setFont(font);
}

void TextPopup::setString(std::string str)
{
	mText.setString(str);
}

void TextPopup::setBG(sf::RectangleShape rect)
{
	mTextBG = rect;
	mTextBG.setFillColor(sf::Color::Transparent);
	mTextBG.setOutlineColor(sf::Color::White);
	mTextBG.setOutlineThickness(5.0);
}

void TextPopup::setPosition(sf::Vector2f position)
{
	mText.setPosition(position);
	mTextBG.setPosition(position);
}

void TextPopup::setActive(bool ToF)
{
	isActive = ToF;
}

bool TextPopup::getActive()
{
	return isActive;
}

void TextPopup::draw(sf::RenderWindow& window)
{
	if (isActive) // will only draw to window if isActive is True
	{
		window.draw(mTextBG);
		window.draw(mText);
	}
}
