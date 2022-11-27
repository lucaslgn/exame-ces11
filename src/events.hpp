#pragma once

#include "Player.hpp"

bool pendingEvents(sf::Window& window, sf::Event& event);
void treatEvents(sf::Window& window, const sf::Event& event, Player& player, const Map& gameMap);
bool mouseClicked(const sf::Event& event);
bool saveButtonPressed();
