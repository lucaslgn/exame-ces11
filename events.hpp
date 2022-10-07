#pragma once

#include <SFML/Window.hpp>
#include <SFML/Window/Event.hpp>

bool pendingEvents(sf::Window&, sf::Event&);
void treatEvents(sf::Window&, const sf::Event&);
bool mouseClicked(const sf::Event&);
