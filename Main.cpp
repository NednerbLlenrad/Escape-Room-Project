
#include <SFML/Graphics.hpp>
#include <iostream>
#include "player.h"
#include "Trashcan.hpp"
#include "tests.h"


int main()
{
    
    // Run test cases
    //testSpriteLoading();
    //testPlayerMovement();
    //testWinCondition();
    //testObjectInteraction();
    //testInventorySystem();


    // create a window
    sf::RenderWindow window(sf::VideoMode(1024, 768), "EscapeRoom");

    //player instantiation
    // player texture
    sf::Texture texture;
    texture.loadFromFile("images/player.png");
    Player player(texture, sf::Vector2f(500, 500));



    //TrashCan
    sf::Texture trashTex;
    trashTex.loadFromFile("images/bins.png");
    TrashCan trashcan(sf::IntRect(0, 0, 128, 256), trashTex, sf::Vector2f(32.0f, 32.0f));
    trashcan.setDraggable(true); // Set isDraggable to true

    // Create a boolean variable to track whether the game is over or not
    bool isGameOver = false;

    //Countdown
    sf::Font font;
    font.loadFromFile("Font/joystix monospace.ttf");
    sf::Text countdownTxt("", font, 50);
    countdownTxt.setPosition(0, 0);
    //Create clock for countdown
    sf::Clock clock;
    //Countdown Value
    float countdownTime = 61;

    // Create an sf::Text object for the "GAME OVER" message
    sf::Text gameOverText("GAME OVER", font, 80);
    gameOverText.setPosition(200, 300); // Set the position of the "GAME OVER" text
    gameOverText.setFillColor(sf::Color::Red); // Set the color of the text


    //clock+ time for animation
    sf::Clock clockA;
    float animationTime = 0;
        
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
        // Update the Countdown only if the game is not over
        if (!isGameOver) {
            sf::Time elapsed = clock.restart(); // Get elapsed time and restart the clock
            countdownTime -= elapsed.asSeconds();
            int countdownInt = static_cast<int>(countdownTime);
            countdownTxt.setString(std::to_string(countdownInt));

            // If the countdown reaches zero or less, set isGameOver to true
            if (countdownTime <= 0) {
                isGameOver = true;
            }
        }
        //clear window
        window.clear();

        // Drag the trash can if it's draggable
        if (trashcan.getDraggable())
        {
            trashcan.drag(window);
        }

        //draw background
        window.draw(background);

        
       
        
        //update player
        player.update(animationTime);

        //check for collisions with walls
        player.handleWallCollisions();
     
        //check for object collisions

        // draw the sprite in the window
        player.draw(window);

        //Draw Trash
        trashcan.draw(window);

        // Draw the countdown
        window.draw(countdownTxt);


        // If the game is over, draw the "GAME OVER" message
        if (isGameOver) {
            window.draw(gameOverText);
        }
        // Display the window (only once per frame)
        window.display();
        // If the game is over, you can close the window, return to the menu, or implement any other behavior
        if (isGameOver) {
            // Close the game window
            //window.close();
            // Additional behavior can be implemented here, such as returning to the menu or displaying a fail screen
        }

        // Restart the clocks after updating and rendering
        clockA.restart();
    }

    return EXIT_SUCCESS;
}