
#include <SFML/Graphics.hpp>
#include <iostream>
#include "player.h"
#include "tests.h"
#include "Chain.hpp"
#include "Desk.hpp"
#include "InteractableClassObject.hpp"
#include "Buttons.h"
#include "Tool.h"
#include "TextPopup.h"
//Temp place for functions


int main()
{
    
    //------------------------------Run test cases--------------------------------------------\\
    
    void testPlayerMovement();
    void testObjectInteraction();
    void testResetGame();
    void testCountdown();
    void testGameOver();
    void testSpriteLoading();
    void testWinCondition();
    void testInventorySystem();
    //------------------------------------Test End----------------------------------------------\\

    // create a window
    sf::RenderWindow window(sf::VideoMode(1000, 750), "EscapeRoom");

    //player instantiation
    // player texture
    sf::Texture Playertexture;
    Playertexture.loadFromFile("images/player.png");
    Player player(Playertexture, sf::Vector2f(500, 500));



    //-----------------------------------OBJECT INITIALIZATION-----------------------------------\\
    // Each Object is initialized with a texture from a png, a location, being able to be dragged, and a scale modifier, 
    // Also included is a bool for the interact prompt and to remove interactibility from the objects after E is pressed.
    //TrashCan
    sf::Texture trashtex;
    trashtex.loadFromFile("images/bins.png");
    InteractableObject trashcan(sf::IntRect(0, 0, 128, 256), trashtex, sf::Vector2f(267, 468),false,57,468,.80f, false);
    bool trashCheck = false;
    //Bed
    sf::Texture BedTex;
    BedTex.loadFromFile("images/bed.png");
    InteractableObject bed(sf::IntRect(0, 0, 512, 512), BedTex, sf::Vector2f(267, 468),false, 550,240,0.8, false);
    //Desk
    sf::Texture DeskTex;
    DeskTex.loadFromFile("images/desk.png");
    Desk desk(sf::IntRect(0, 0, 256, 256), DeskTex, sf::Vector2f(267, 468), false, false);
    //Toilet
    sf::Texture toiletTex;
    toiletTex.loadFromFile("images/Toilet.png");
    InteractableObject toilet(sf::IntRect(0, 0, 128, 256), toiletTex, sf::Vector2f(267, 468),false,510,275,1.0, false);
    //Sink
    sf::Texture sinkTex;
    sinkTex.loadFromFile("images/sink.png");
    InteractableObject sink(sf::IntRect(0, 0, 128, 256), sinkTex, sf::Vector2f(267, 468),false,400,360,1.0, false);
    //Chair
    sf::Texture chairTex;
    chairTex.loadFromFile("images/chair.png");
    InteractableObject chair(sf::IntRect(0, 0, 128, 256), chairTex, sf::Vector2f(267, 468),false,220,350,1.0, false);
    bool chairCheck = false;
    //Chain
    sf::Texture chainTex;
    chainTex.loadFromFile("images/chain.png");
    Chain chain(sf::IntRect(0, 0, 128, 128), chainTex, sf::Vector2f(267, 468), false, false);
    //Vent
    sf::Texture ventTex;
    ventTex.loadFromFile("images/vent.png");
    InteractableObject vent(sf::IntRect(0, 0, 192, 128), ventTex, sf::Vector2f(267, 468),false,350,50,1.0, false);
    //--------------------------------------------------------------------------------------------------\\
    
    //-----------------------------------TOOL INSTANTIATION-----------------------------------\\

    sf::Texture screwDriverTex, nailFileTex;
    screwDriverTex.loadFromFile("images/screwDriver.png");
    nailFileTex.loadFromFile("images/nailFile.png");
    Tool screwDriver(screwDriverTex, sf::Vector2f(500, 500));
    Tool nailFile(nailFileTex, sf::Vector2f(650, 600));
    bool screwDriverFound = false;
    bool nailFileFound = false;
    //--------------------------------------------------------------------------------------------------\\
    //Countdown Loads a font from a file. This font was a free font taken from Dafont.com
    //Countdown uses a clock from SFML and a float countdown time of 61 seconds.
    //Countdown
    sf::Font font;
    font.loadFromFile("Font/joystix monospace.ttf");
    sf::Text countdownTxt("", font, 50);
    countdownTxt.setPosition(0, 0);
    //Create clock for countdown
    sf::Clock clock;
    //Countdown Value
    float countdownTime = 61;

    //--------------------------------------GAME MENU BUTTONS ----------------------------------------------\\

    bool isMenu = true;

    // Create an sf::Text object for game title
    sf::Text titleText("THE ESCAPE ROOM", font, 70);
    titleText.setPosition(50, 100); // Set the position of the text

    // Create a button for starting the game
    sf::RectangleShape startButton(sf::Vector2f(200, 50));
    startButton.setFillColor(sf::Color(128, 128, 128)); // Set button color
    startButton.setPosition(412, 400); // Set button position

    // Create a text label for the restart button
    sf::Text startButtonText("START", font, 30);
    startButtonText.setPosition(440, 405); // Set label position

    //--------------------------------------END GAME BUTTONS ----------------------------------------------\\ 

    // Create a boolean variable to track whether the game is over or not
    bool isGameOver = true;

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

      // Create a button for quitting the game
    sf::RectangleShape quitButton(sf::Vector2f(200, 50));
    quitButton.setFillColor(sf::Color(128, 128, 128)); // Set button color
    quitButton.setPosition(412, 460); // Set button position

        // Create a text label for the quit button
    sf::Text quitButtonText("QUIT", font, 30);
    quitButtonText.setPosition(470, 465); // Set label position

        // Create a button for returning to the menu
    sf::RectangleShape menuButton(sf::Vector2f(200, 50));
    menuButton.setFillColor(sf::Color(128, 128, 128)); // Set button color
    menuButton.setPosition(412, 520); // Set button position

        // Create a text label for the menu button
    sf::Text menuButtonText("MENU", font, 30);
    menuButtonText.setPosition(460, 525); // Set label position

//------------------------------------------------------------------------------------------------------------\\
    //clock+ time for animation
    sf::Clock clockA;
    float animationTime = 0;
 
//------------------------------------------------------------------------------------------------------------\\
    //Textpopup
    TextPopup playerText;
    playerText.setFont(font);
    playerText.setActive(false);
    sf::Clock textClock; // not sure if this is the best way of doing this
    float playerTextRem = 0; // time left for the text to be displayed
//------------------------------------------------------------------------------------------------------------\\
    //background setup
    sf::RectangleShape background(sf::Vector2f(1000, 750));
    sf::Texture backgroundTexture; 
    backgroundTexture.loadFromFile("images/background.png");
    background.setTexture(&backgroundTexture);
    //---------------------------------------YOU WIN----------------------------------------------------------------\\
        
    bool hasWon = false;
    bool isRestart = false;
    bool isQuit = false;
    


    // wait for the window to be closed
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

        }

        // detects mousebutton press events for game
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

                if (isMenu)
                {
                    // Check for mouse clicks on the restart button
                    if (startButton.getGlobalBounds().contains(mousePos)) {
                        // start the game
                        isGameOver = false;
                        isMenu = false;
                        resetGame(countdownTime, player, clock, trashcan, bed, chain, toilet, sink, chair, vent, trashCheck, chairCheck);
                    }
                }

                else if (!isMenu && isGameOver)
                {
                    // Check for mouse clicks on the restart button
                    if (restartButton.getGlobalBounds().contains(mousePos)) {
                        // Restart the game
                        isGameOver = false;
                        resetGame(countdownTime, player, clock, trashcan, bed, chain, toilet, sink, chair, vent, trashCheck, chairCheck);
                    }
                    // Check for mouse clicks on the quit button
                    else if (quitButton.getGlobalBounds().contains(mousePos)) {
                        // Quit the game
                        window.close();
                    }
                    // Check for mouse clicks on the menu button
                    else if (menuButton.getGlobalBounds().contains(mousePos)) { //comented out for testing

                        isGameOver = true;
                        isMenu = true;
                    }
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

        if (!isGameOver && playerText.getActive()) // game not over and playerText is active
        {
            sf::Time elapsed = textClock.restart();
            playerTextRem -= elapsed.asSeconds();
            if (playerTextRem <= 0)
                playerText.setActive(false);
        }

        // Restart the clocks after updating and rendering
        animationTime = clockA.restart().asSeconds();
       

        //clear window
        window.clear();
        //draw background
        window.draw(background);

        // Update player and handle collisions only if the game is not over
        if (!isGameOver) {

            //Object Interactions
            // 
            // Drag the trash can if it's draggable
            if(trashcan.getInteracted() == false)
            {
                if (trashcan.interaction(window, player, sf::IntRect(160, 0, 128, 256)) == true)
                {
                    trashcan.setDraggable(true);//allows trash to be dragged
                    trashCheck = true;
                    trashcan.setInteracted(true);
                }
            }
            if (trashcan.getDraggable())
            {
                if(player.getIsOnTrash() == false) //dont allow trash to be dragged if player is on it
                {
                    trashcan.drag(window, player);
                }
            }
            //Unmake the bed
            if (bed.getInteracted() == false)
            {
                if (bed.interaction(window, player, sf::IntRect(512, 0, 512, 512)) == true)
                {
                    nailFileFound = true;
                    bed.setInteracted(true);
                }
            }
            //Open toilet
            if (toilet.getInteracted() == false)
            {
                if (toilet.interaction(window, player, sf::IntRect(128, 0, 128, 256)) == true)
                {
                    screwDriverFound = true;
                    toilet.setInteracted(true);
                }
            }
            //Turn on sink
            if (sink.getInteracted() == false)
            {
                if(sink.interaction(window, player, sf::IntRect(128, 0, 128, 128))==true) sink.setInteracted(true);;
            }
            //Chain Breaking
            if(player.getHasNailFile() == true)
            {
                if(chain.getInteracted() == false)
                {
                    if (chain.interaction(window, player, sf::IntRect()) == true)
                    {
                        chair.setDraggable(true);//allows chair to be dragged
                        chairCheck = true;
                        chair.setInteracted(true);
                    }
                }
            }
            //Makes chair draggable
            if (chair.getDraggable())
            {
                chair.drag(window, player);
            }
            //Vent
            if (trashCheck == true && chairCheck == true && screwDriverFound == true && player.getIsOnTrash() == true)//Checks that the garbage has been flipped and chair is draggable,
            {                                                                                                         //Would also check for screwdriver once implemented.
                if(vent.distanceY(player) > 250)
                {
                    if(vent.interaction(window, player, sf::IntRect(192, 0, 192, 128))==true)
                    {
                        hasWon = true;
                    }
                }
            }
            //-------------------------------------------------------------\\

            
            //player movement controls
            player.update(animationTime);
            player.handleWallCollisions(); //prevent wall collisions
           
            if(trashCheck == true)
            {
                player.ClimbTrash(trashcan); //allow player to clim trash
            }
           
            player.CheckFall(); //checks if player should fall off trash


            //Draw Objects
            vent.draw(window);
            bed.draw(window);
            desk.draw(window);
            toilet.draw(window);
            sink.draw(window);
            chair.draw(window);
            chain.draw(window);
            trashcan.draw(window);

            //Draw playerText
            playerText.draw(window);
            playerText.setPosition(player.getPosition() + sf::Vector2f(0, -30));
            

           
            //draw tools and allow for pickup-- only if found
            if (screwDriverFound == true)
            {
                screwDriver.drop(window);
                if (screwDriver.pickUp(player) && !player.getHasScrewDriver())
                {
                    player.setHasScrewDriver(true);

                    // displays a popup for a duration
                    playerText.setString("+ Screwdriver");
                    playerText.setActive(true);
                    playerTextRem = 3;
                    textClock.restart();
                }
            }
            if (nailFileFound == true)
            {
                nailFile.drop(window);
                if (nailFile.pickUp(player) && !player.getHasNailFile())
                {
                    player.setHasNailFile(true);

                    // displays popup for a duration
                    playerText.setString("+ Nail File");
                    playerText.setActive(true);
                    playerTextRem = 3;
                    textClock.restart();
                }
            }
          

            //draws the countdown
            window.draw(countdownTxt);
            
            // draw the sprite in the window
            player.draw(window);
        }

        // if the menu is true, draw the menu elements
        if (isMenu)
        {
            window.draw(titleText);
            window.draw(startButton);
            window.draw(startButtonText);
        }

        // If the game is over, draw the "GAME OVER" message, restart button, quit button, and menu button
        else if (isGameOver) {
            window.draw(gameOverText);
            window.draw(restartButton);
            window.draw(restartButtonText);

            
            window.draw(quitButton);
            window.draw(quitButtonText);
            window.draw(menuButton);
            window.draw(menuButtonText);

            screwDriverFound = false;
            nailFileFound = false;
            player.setHasNailFile(false);
            player.setHasScrewDriver(false);
            screwDriver.setIsPickedUp(false);
            nailFile.setIsPickedUp(false);
        }

        else if (hasWon) {
            sf::Text winText("You Win!", font, 80);
            winText.setPosition(200, 300);
            winText.setFillColor(sf::Color::Green);

            sf::RectangleShape restartButton(sf::Vector2f(200, 50));
            restartButton.setFillColor(sf::Color(128, 128, 128));
            restartButton.setPosition(412, 400);

            sf::Text restartButtonText("RESTART", font, 30);
            restartButtonText.setPosition(440, 405);

            sf::RectangleShape quitButton(sf::Vector2f(200, 50));
            quitButton.setFillColor(sf::Color(128, 128, 128));
            quitButton.setPosition(412, 460);

            sf::Text quitButtonText("QUIT", font, 30);
            quitButtonText.setPosition(470, 465);

            sf::RectangleShape menuButton(sf::Vector2f(200, 50));
            menuButton.setFillColor(sf::Color(128, 128, 128));
            menuButton.setPosition(412, 520);

            sf::Text menuButtonText("MENU", font, 30);
            menuButtonText.setPosition(460, 525);

            bool isRestart = false;
            bool isQuit = false;
            bool isMenu = false;

            while (window.isOpen()) {
                sf::Event event;
                while (window.pollEvent(event)) {
                    if (event.type == sf::Event::Closed) {
                        window.close();
                    }
                    else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                        sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

                        if (restartButton.getGlobalBounds().contains(mousePos)) {
                            // Perform restart action
                            resetGame(countdownTime, player, clock, trashcan, bed, chain, toilet, sink, chair, vent, trashCheck, chairCheck);
                            isGameOver = false;
                            hasWon = false;
                            isRestart = true;
                            screwDriverFound = false;
                            nailFileFound = false;
                            player.setHasNailFile(false);
                            player.setHasScrewDriver(false);
                            screwDriver.setIsPickedUp(false);
                            nailFile.setIsPickedUp(false);
                            break; // Exit the nested loop
                        }
                        else if (quitButton.getGlobalBounds().contains(mousePos)) {
                            // Perform quit action
                            isQuit = true;
                            window.close();
                            break; // Exit the nested loop
                        }
                        else if (menuButton.getGlobalBounds().contains(mousePos) && !isGameOver) {
                            // Perform menu action
                            isGameOver = true;
                            hasWon = false;
                            isMenu = true;
                            screwDriverFound = false;
                            nailFileFound = false;
                            player.setHasNailFile(false);
                            player.setHasScrewDriver(false);
                            screwDriver.setIsPickedUp(false);
                            nailFile.setIsPickedUp(false);
                            break; // Exit the nested loop
                        }
                    }
                }

                if (isRestart || isQuit || isMenu) {
                    break; // Exit the outer loop
                }

                window.clear();
                window.draw(background);
                window.draw(winText);
                window.draw(restartButton);
                window.draw(restartButtonText);
                window.draw(quitButton);
                window.draw(quitButtonText);
                window.draw(menuButton);
                window.draw(menuButtonText);
                window.display();
            }
        }

        if (isQuit) {
            window.close();
            break;
        }


        // Display the window (only once per frame)
        window.display();

        
    }

    return EXIT_SUCCESS;
}