
#include <SFML/Graphics.hpp>

int main()
{
    // create a window
    sf::RenderWindow window(sf::VideoMode(1000, 750), "EscapeRoom");

    // create a texture and load an image from a file
    sf::Texture texture;
    if (!texture.loadFromFile("Assets.png")) {
        // error handling
        return EXIT_FAILURE;
    }

    // create a sprite and set its texture
    sf::Sprite sprite(texture);

    // draw the sprite in the window
    window.draw(sprite);

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
