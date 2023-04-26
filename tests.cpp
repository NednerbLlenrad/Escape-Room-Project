// tests.cpp
#include "tests.h"
#include "player.h"
#include "InteractableClassObject.hpp"
#include "Chain.hpp"
#include "Desk.hpp"
#include <iostream>
#include <cassert>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "Tool.h"
#include "gameObject.h"


// Define the test cases 
void testSpriteLoading() {
    // Define the file paths for the textures to be loaded
    const std::string playerTexturePath = "images/player.png";
    const std::string trashTexturePath = "images/bins.png";
    const std::string bedTexturePath = "images/bed.png";
    // Add more texture file paths as needed

    // Create texture objects
    sf::Texture playerTexture;
    sf::Texture trashTexture;
    sf::Texture bedTexture;
    // Add more texture objects as needed

    // Attempt to load the textures from their respective image files
    bool isPlayerTextureLoaded = playerTexture.loadFromFile(playerTexturePath);
    bool isTrashTextureLoaded = trashTexture.loadFromFile(trashTexturePath);
    bool isBedTextureLoaded = bedTexture.loadFromFile(bedTexturePath);
    // Add more texture loading attempts as needed

    // Print the results
    if (isPlayerTextureLoaded && isTrashTextureLoaded && isBedTextureLoaded) {
        std::cout << "All textures loaded successfully!" << std::endl;
    }
    else {
        std::cout << "Texture loading test failed." << std::endl;
    }
}

void testPlayerMovement() {
    sf::Texture texture;
    texture.loadFromFile("images/player.png");
    Player player(texture, sf::Vector2f(500, 500));

    // Test setting and getting player position
    player.setPosition(sf::Vector2f(600, 400));
    assert(player.getPosition().x == 600);
    assert(player.getPosition().y == 400);

    player.setPosition(sf::Vector2f(300, 200));
    assert(player.getPosition().x == 300);
    assert(player.getPosition().y == 200);

    std::cout << "testPlayerMovement passed" << std::endl;
}

void testWinCondition() {
    // Create a player object and set up the game environment
    sf::Texture playerTexture;
    playerTexture.loadFromFile("images/player.png");
    Player player(playerTexture, sf::Vector2f(500, 500));

    // Create a tool object
    sf::Texture toolTexture;
    toolTexture.loadFromFile("images/tool.png");
    Tool tool(toolTexture, sf::Vector2f(650, 600));

    // Set the initial state of the win condition
    bool hasWon = false;

    // Simulate the win condition
    // Check if the player picks up the tool
    if (tool.pickUp(player)) {
        // Check if the win condition is met
        // For example, checking if the player has a specific combination of items or completed certain tasks
        if (player.getHasScrewDriver() && player.getHasNailFile()) {
            // The player wins the game
            hasWon = true;
        }
    }

    // Print the result of the win condition
    if (hasWon) {
        std::cout << "Win condition test passed." << std::endl;
    }
    else {
        std::cout << "Win condition test failed." << std::endl;
    }
}

void testObjectInteraction() {
    // Create a player object
    sf::Texture playerTexture;
    playerTexture.loadFromFile("images/player.png");
    Player player(playerTexture, sf::Vector2f(500, 500));

    // Create an interactable object (e.g., trash can)
    sf::Texture trashTex;
    trashTex.loadFromFile("images/bins.png");
    InteractableObject trashcan(sf::IntRect(0, 0, 128, 256), trashTex, sf::Vector2f(267, 468), false, 57, 468, 0.80f, false);

    // Set the trash can to be draggable
    trashcan.setDraggable(true);

    // Store the initial position of the trash can
    sf::Vector2f initialPosition = trashcan.getPosition();

    // Simulate dragging the trash canbool chairCheck
    // Note: In a real scenario, this would involve user input and window events
    trashcan.setPosition(sf::Vector2f(300, 300)); // Simulate dragging to a new position

    // Check that the trash can's position has changed
    assert(trashcan.getPosition() != initialPosition);

    std::cout << "testObjectInteraction passed" << std::endl;
}

void testInventorySystem() {
    // Instantiate the player and the tools
    sf::Texture playerTexture, screwDriverTexture, nailFileTexture;
    // Load the textures for the player, screwdriver, and nail file

    Player player(playerTexture, sf::Vector2f(0, 0));
    Tool screwDriver(screwDriverTexture, sf::Vector2f(0, 0));
    Tool nailFile(nailFileTexture, sf::Vector2f(0, 0));

    // Initially, the player should not have any tools
    if (player.getHasScrewDriver() || player.getHasNailFile()) {
        // Handle the test failure
        std::cout << "Test failed: Player has tools before picking them up." << std::endl;
    }

    // Pick up the screwdriver
    player.setHasScrewDriver(true);

    // Check if the player has the screwdriver
    if (!player.getHasScrewDriver()) {
        // Handle the test failure
        std::cout << "Test failed: Player did not pick up the screwdriver." << std::endl;
    }

    // Pick up the nail file
    player.setHasNailFile(true);

    // Check if the player has the nail file
    if (!player.getHasNailFile()) {
        // Handle the test failure
        std::cout << "Test failed: Player did not pick up the nail file." << std::endl;
    }

    // Reset the player's inventory
    player.setHasScrewDriver(false);
    player.setHasNailFile(false);

    // Check if the player's inventory is empty after resetting
    if (player.getHasScrewDriver() || player.getHasNailFile()) {
        // Handle the test failure
        std::cout << "Test failed: Player's inventory was not reset." << std::endl;
    }

    // The test passed if no failures were detected
    std::cout << "Inventory system test passed." << std::endl;
}


void testCountdown() {
    sf::Clock clock;
    float countdownTime = 3.0f; // Set a short countdown for testing

    sf::Time elapsed = clock.restart();
    countdownTime -= elapsed.asSeconds();

    // Simulate a delay
    sf::sleep(sf::seconds(3));

    elapsed = clock.getElapsedTime();
    countdownTime -= elapsed.asSeconds();

    assert(std::fabs(countdownTime) <= 0.1f); // Expect countdown to be near zero

    std::cout << "testCountdown passed" << std::endl;
}


void testGameOver() {
    // Create an sf::Text object for the "GAME OVER" message
    sf::Font font;
    font.loadFromFile("Font/joystix monospace.ttf");
    sf::Text gameOverText("GAME OVER", font, 80);
    gameOverText.setPosition(200, 300);
    gameOverText.setFillColor(sf::Color::Red);

    // Countdown Value
    float countdownTime = 61;

    // Create a boolean variable to track whether the game is over or not
    bool isGameOver = false;

    // Simulate countdown reaching zero
    countdownTime = 0;

    // If the countdown reaches zero or less, set isGameOver to true
    if (countdownTime <= 0) {
        isGameOver = true;
    }

    // Assertions to check if the "GAME OVER" message is displayed when the game is over
    if (isGameOver) {
        assert(gameOverText.getString() == "GAME OVER");
    }
    else {
        assert(gameOverText.getString() != "GAME OVER");
    }
}
// Forward declaration of resetGame function (if not already declared)
void resetGame(float& countdownTime, Player& player, sf::Clock& clock, InteractableObject& trash, InteractableObject& bed,
    Chain& chain, InteractableObject& toilet, InteractableObject& sink, InteractableObject& chair, InteractableObject& vent, bool checkT, bool checkC);

void testResetGame() {
    // Load textures using loadFromFile(...)
    sf::Texture trashTex;
    trashTex.loadFromFile("images/bins.png");
    InteractableObject trashcan(sf::IntRect(0, 0, 128, 256), trashTex, sf::Vector2f(267, 468), false, 57, 468, 0.8f, false);
    sf::Texture BedTex;
    BedTex.loadFromFile("images/bed.png");
    InteractableObject bed(sf::IntRect(0, 0, 512, 512), BedTex, sf::Vector2f(550, 240), false, 0, 0, 0.8f, false);
    sf::Texture chairTex;
    chairTex.loadFromFile("images/chair.png");
    sf::Texture chainTex;
    chainTex.loadFromFile("images/chain.png");
    Chain chain(sf::IntRect(0, 0, 128, 128), chainTex, sf::Vector2f(267, 468), false, false);
    sf::Texture toiletTex;
    toiletTex.loadFromFile("images/Toilet.png");
    InteractableObject toilet(sf::IntRect(0, 0, 128, 256), toiletTex, sf::Vector2f(510, 275), false, 0, 0, 1.0f, false);
    sf::Texture sinkTex;
    sinkTex.loadFromFile("images/sink.png");
    InteractableObject sink(sf::IntRect(0, 0, 128, 128), sinkTex, sf::Vector2f(400, 360), false, 0, 0, 1.0f, false);
    InteractableObject chair(sf::IntRect(0, 0, 128, 256), chairTex, sf::Vector2f(220, 350), false, 0, 0, 1.0f, false);
    sf::Texture ventTex;
    ventTex.loadFromFile("images/vent.png");
    InteractableObject vent(sf::IntRect(0, 0, 192, 128), ventTex, sf::Vector2f(350, 50), false, 0, 0, 1.0f, false);
    // Player
    sf::Texture playerTexture;
    playerTexture.loadFromFile("images/player.png");
    Player player(playerTexture, sf::Vector2f(500, 500));

    // Countdown and Clock
    float countdownTime = 61;
    sf::Clock clock;

    // Reset game state
    resetGame(countdownTime, player, clock, trashcan, bed, chain, toilet, sink, chair, vent, false, false);

    // Assertions to check if the game state has been reset correctly
    assert(countdownTime == 61); // Check if the countdown time is reset
    assert(player.getPosition() == sf::Vector2f(500, 500)); // Check if the player's position is reset
    // Add any other necessary assertions to check other game elements
}
