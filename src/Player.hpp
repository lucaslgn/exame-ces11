#pragma once

#include "Map.hpp"
#include <SFML/Graphics/Drawable.hpp>
#include <fstream>


class Player : public sf::Drawable {
private:
	sf::Texture playerImage_;
	sf::Sprite player_;

    void draw(sf::RenderTarget&, sf::RenderStates) const override;
public:
	bool readPlayer(const std::string&, const std::string&, const Map&);
	void walk(const Map&);
	sf::Vector2i pos;
	sf::Vector2i destiny;
};
