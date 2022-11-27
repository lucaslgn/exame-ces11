#pragma once

#include "Map.hpp"

class Player : public sf::Drawable {
public:
	void draw(sf::RenderTarget&, sf::RenderStates) const override;
	void walk(Map, sf::Window);
	Position pos;
	Position destiny;
};
