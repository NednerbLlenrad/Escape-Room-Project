#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class TextPopup
{
private:
	sf::Text mText; // text
	sf::RectangleShape mTextBG; // text background, may want to change to a texture in the future

	bool isActive;
public:
	TextPopup();
	//~TextPopup();

	void setFont(sf::Font& font);
	void setString(std::string str);
	void setBG(sf::RectangleShape rect);
	void setPosition(sf::Vector2f position);

	void setActive(bool);

	void draw(sf::RenderWindow& window);
};