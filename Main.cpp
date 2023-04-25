
#include <SFML/Graphics.hpp>
#include <iostream>
#include "player.h"
#include "tests.h"
#include "Chain.hpp"
#include "Desk.hpp"
#include "InteractableClassObject.hpp"

//Temp place for functions
// Function to reset the game state
void resetGame(float& countdownTime, Player& player, sf::Clock& clock, InteractableObject& trash, InteractableObject& bed,
    Chain& chain, InteractableObject& toilet, InteractableObject& sink, InteractableObject& chair, InteractableObject& vent, bool checkT, bool checkC) {
    countdownTime = 61;
    player.setPosition(sf::Vector2f(500, 500)); // Reset player position
    // Reset other game elements as needed
    trash.reset();
    checkT = false;
    bed.reset();
    toilet.reset();
    sink.reset();
    chair.reset();
    vent.reset();
    chain.reset();
    checkC = false;
    clock.restart(); // Restart the countdown clock
}

int main()
{
    
    // Run test cases
    //testSpriteLoading();
    //testPlayerMovement();
    //testWinCondition();
    //testObjectInteraction();
    //testInventorySystem();


    // create a window
    sf::RenderWindow window(sf::VideoMode(1000, 750), "EscapeRoom");

    //player instantiation
    // player texture
    sf::Texture texture;
    texture.loadFromFile("images/player.png");
    Player player(texture, sf::Vector2f(500, 500));



    //-----------------------------------OBJECT INITIALIZATION-----------------------------------\\
    //TrashCan
    sf::Texture trashtex;
    trashtex.loadFromFile("images/bins.png");
    InteractableObject trashcan(sf::IntRect(0, 0, 128, 256), trashtex, sf::Vector2f(267, 468),false,57,468,.80f);
    bool trashCheck = false;
    //Bed
    sf::Texture BedTex;
    BedTex.loadFromFile("images/bed.png");
    InteractableObject bed(sf::IntRect(0, 0, 512, 512), BedTex, sf::Vector2f(267, 468),false, 550,240,0.8);
    //Desk
    sf::Texture DeskTex;
    DeskTex.loadFromFile("images/desk.png");
    Desk desk(sf::IntRect(0, 0, 256, 256), DeskTex, sf::Vector2f(267, 468), false);
    //Toilet
    sf::Texture toiletTex;
    toiletTex.loadFromFile("images/Toilet.png");
    InteractableObject toilet(sf::IntRect(0, 0, 128, 256), toiletTex, sf::Vector2f(267, 468),false,510,275,1.0);
    //Sink
    sf::Texture sinkTex;
    sinkTex.loadFromFile("images/sink.png");
    InteractableObject sink(sf::IntRect(0, 0, 128, 256), sinkTex, sf::Vector2f(267, 468),false,400,360,1.0);
    //Chair
    sf::Texture chairTex;
    chairTex.loadFromFile("images/chair.png");
    InteractableObject chair(sf::IntRect(0, 0, 128, 256), chairTex, sf::Vector2f(267, 468),false,220,350,1.0);
    bool chairCheck = false;
    //Chain
    sf::Texture chainTex;
    chainTex.loadFromFile("images/chain.png");
    Chain chain(sf::IntRect(0, 0, 128, 128), chainTex, sf::Vector2f(267, 468));
    chain.setDraggable(false); // Set isDraggable to false
    //Vent
    sf::Texture ventTex;
    ventTex.loadFromFile("images/vent.png");
    InteractableObject vent(sf::IntRect(0, 0, 192, 128), ventTex, sf::Vector2f(267, 468),false,350,50,1.0);
    //--------------------------------------------------------------------------------------------------\\
    
 
 
    //Countdown
    sf::Font font;
    font.loadFromFile("Font/joystix monospace.ttf");
    sf::Text countdownTxt("", font, 50);
    countdownTxt.setPosition(0, 0);
    //Create clock for countdown
    sf::Clock clock;
    //Countdown Value
    float countdownTime = 61;

    // Create a boolean variable to track whether the game is over or not
    bool isGameOver = false;

    // Create an sf::Text object for the "GAME OVER" message
    sf::Text gameOverText("GAME OVER", font, 80);
    gameOverText.setPosition(200, 300); // Set the position of the "GAME OVER" text
    gameOverText.setFillColor(sf::Color::Red); // Set the color of the text

    // Create a button for restarting the game
    sf::RectangleShape restartButton(sf::Vector2f(200, 50));
    restartButton.setFillColor(sf::Color(128, 128, 128)); // Set button color
    restartButton.setPosition(412, 400); // Set button position

    // Create a text label for the restart button
    sf::Text restartButtonText("RESTART", font, 30);
    restartButtonText.setPosition(440, 405); // Set label position

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

        // Check for mouse clicks on the restart button
        if (isGameOver && event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                if (restartButton.getGlobalBounds().contains(mousePos)) {
                    // Restart the game
                    isGameOver = false;
                    resetGame(countdownTime, player, clock, trashcan, bed, chain, toilet, sink, chair, vent, trashCheck, chairCheck);
                }
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
        //draw background
        window.draw(background);

        // Update player and handle collisions only if the game is not over
        if (!isGameOver) {

            //Object Interactions
            // 
            // Drag the trash can if it's draggable
            if (trashcan.interaction(window, player, sf::IntRect(160, 0, 128, 256)) == true)
            {
                trashcan.setDraggable(true);//allows chair to be dragged
                trashCheck = true;
            }
            if (trashcan.getDraggable())
            {
                trashcan.drag(window, player);
            }
            bool flippedCheck = trashcan.interaction(window, player, sf::IntRect(160, 0, 128, 256));
            //Unmake the bed
            bed.interaction(window, player, sf::IntRect(512, 0, 512, 512));
            //Open toilet
            toilet.interaction(window, player, sf::IntRect(128, 0, 128, 256));
            //Turn on sink
            sink.interaction(window, player, sf::IntRect(128, 0, 128, 128));
            //Chain Breaking
            if (chain.interaction(window, player, sf::IntRect()) == true)
            {
                chair.setDraggable(true);//allows chair to be dragged
                chairCheck = true;
            }
            //Makes chair draggable
            if (chair.getDraggable())
            {
                chair.drag(window, player);
            }
            //Vent
            if (trashCheck == true && chairCheck == true)//Checks that the garbage has been flipped and chair is draggable,
            {                                              //Would also check for screwdriver once implemented.
                vent.interaction(window, player, sf::IntRect(192, 0, 192, 128));
            }
            //-------------------------------------------------------------\\

            player.update(animationTime);
            player.handleWallCollisions();

            //Draw Objects
            vent.draw(window);
            bed.draw(window);
            desk.draw(window);
            toilet.draw(window);
            sink.draw(window);
            chair.draw(window);
            chain.draw(window);
            trashcan.draw(window);
            //draws the countdown
            window.draw(countdownTxt);
            ;
            // draw the sprite in the window
            player.draw(window);
        }

        // If the game is over, draw the "GAME OVER" message and restart button // Add Menu Button when there is a menu
        if (isGameOver) {
            window.draw(gameOverText);
            window.draw(restartButton);
            window.draw(restartButtonText);
        }

        // Display the window (only once per frame)
        window.display();
        //// If the game is over, you can close the window, return to the menu, or implement any other behavior
        //if (isGameOver) {
        //    // Close the game window
        //    window.close();
        //    // Additional behavior can be implemented here, such as returning to the menu or displaying a fail screen
        //}

        // Restart the clocks after updating and rendering
        clockA.restart();
    }

    return EXIT_SUCCESS;
}