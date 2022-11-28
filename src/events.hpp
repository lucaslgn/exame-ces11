#pragma once

#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "Map.hpp"

bool pendingEvents(sf::RenderWindow& window, sf::Event& event);
void treatEvents(sf::Window& window, const sf::Event& event, Player& player, const Map& gameMap);
bool mouseClicked(const sf::Event& event);
bool saveButtonPressed(const sf::Event &event);
void updateWindow(sf::RenderWindow& window, const Map& gameMap, const Player& player);
void saveGame(const std::string& nameFile, const Player& player);
