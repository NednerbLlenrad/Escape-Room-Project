
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

