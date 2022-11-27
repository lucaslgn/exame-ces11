#pragma once

#include "Player.hpp"

bool pendingEvents(sf::Window&, sf::Event&);
void treatEvents(sf::Window&, const sf::Event&, Player, Map);
bool mouseClicked(const sf::Event&);
bool saveButtonPressed();
