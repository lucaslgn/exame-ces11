#pragma once

#include "Map.hpp"

class Player {
public:
	void walk(Map);
	Position pos;
	Position destiny;
};
