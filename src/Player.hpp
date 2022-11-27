#pragma once

#include "Map.hpp"

class Player {
public:
	void walk(Map);
    sf::Vector2i pos;
    sf::Vector2i destiny;
};
