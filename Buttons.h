#ifndef BUTTONS_H
#define BUTTONS_H
#include "player.h"
#include "tests.h"
#include "Chain.hpp"
#include "Desk.hpp"
#include "InteractableClassObject.hpp"
void resetGame(float& countdownTime, Player& player, sf::Clock& clock, InteractableObject& trash, InteractableObject& bed,
    Chain& chain, InteractableObject& toilet, InteractableObject& sink, InteractableObject& chair, InteractableObject& vent, bool checkT, bool checkC);
#endif // BUTTONS_H