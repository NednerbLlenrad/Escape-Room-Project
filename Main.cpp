
#include <SFML/Graphics.hpp>

int main()
{
    // create a window
    sf::RenderWindow window(sf::VideoMode(1000, 750), "EscapeRoom");

    // create a texture and load an image from a file
    sf::Texture texture;
    if (!texture.loadFromFile("images/player.png")) {
        // error handling
        return EXIT_FAILURE;
    }

    // create a sprite and set its texture
    sf::Sprite player(texture);
    player.setTextureRect(sf::IntRect(0, 0, 128, 128)); //set visible texture to only first sprite on sheet

    //set player origin
    player.setOrigin(sf::Vector2f(-400, -500));

    //background setup
    sf::RectangleShape background(sf::Vector2f(1000, 750));
    sf::Texture backgroundTexture; 
    backgroundTexture.loadFromFile("images/background.png");
    background.setTexture(&backgroundTexture);

    //draw background
    window.draw(background);

    // draw the sprite in the window
    window.draw(player);

    // display the window
    window.display();

    // wait for the window to be closed
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
    }

    return EXIT_SUCCESS;
}
