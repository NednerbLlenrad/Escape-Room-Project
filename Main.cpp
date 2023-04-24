
#include <SFML/Graphics.hpp>
#include "Trashcan.hpp"

int main()
{
    // create a window
    sf::RenderWindow window(sf::VideoMode(1000, 750), "EscapeRoom");

    //TrashCan
    sf::Texture trashTex;
    trashTex.loadFromFile("images/bins.png");
    TrashCan trashcan(sf::IntRect(0, 0, 128, 256), trashTex, sf::Vector2f(32.0f, 32.0f));
    trashcan.setDraggable(true); // Set isDraggable to true



    //Countdown
    sf::Font font;
    font.loadFromFile("Font/joystix monospace.ttf");
    sf::Text countdownTxt("", font, 50);
    countdownTxt.setPosition(0, 0);
    //Create clock for countdown
    sf::Clock clock;
    //Countdown Value
    float countdownTime = 61;



    //Player
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

    


    // wait for the window to be closed
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

        }
        // Update the Countdown
        sf::Time elapsed = clock.restart();
        countdownTime -= elapsed.asSeconds();
        int countdownInt = static_cast<int>(countdownTime); // Convert the float to an integer
        countdownTxt.setString(std::to_string(countdownInt)); // Set the text to the integer string

        // Drag the trash can if it's draggable
        if (trashcan.getDraggable())
        {
            trashcan.drag(window);
        }

        //draw background
        window.draw(background);

        // draw the sprite in the window
        window.draw(player);

        //Draw Trash
        trashcan.draw(window);

        //draws the countdown
        window.draw(countdownTxt);
;
        // display the window
        window.display();

        //Countdown reached result presumably due to a failed attempt
        if (countdownTime <= 0)
        {
            //Close the game? Return to menu? Fail screen?
            window.close();
        }
    }

    return EXIT_SUCCESS;
}
