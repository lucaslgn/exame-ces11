#pragma once

#include <SFML/Window.hpp>
#include "Player.hpp"

bool pendingEvents(sf::Window&, sf::Event&);
void treatEvents(sf::Window&, const sf::Event&, Player player);
bool mouseClicked(const sf::Event&);
