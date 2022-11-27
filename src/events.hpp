#pragma once

#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "Map.hpp"

bool pendingEvents(sf::Window& window, sf::Event& event);
void treatEvents(sf::Window& window, const sf::Event& event, Player& player, const Map& gameMap);
bool mouseClicked(const sf::Event& event);
bool saveButtonPressed();
void updateWindow(sf::RenderWindow& window, const Map& gameMap, const Player& player);
