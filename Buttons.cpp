
#include "Buttons.h"


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
