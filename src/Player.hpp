#pragma once

#include "Map.hpp"
#include <SFML/Graphics/Drawable.hpp>
#include <fstream>
#include <queue>


class Player : public sf::Drawable {
private:
	sf::Texture playerImage_;

    void draw(sf::RenderTarget&, sf::RenderStates) const override;
public:
	sf::Sprite player_;
	bool readPlayer(const std::string&, const std::string&, const Map&);
	bool isWalking = false;
	void walk(const Map&);
	sf::Vector2i pos;
	std::queue<sf::Vector2i> pathPoints;
	sf::Vector2i destiny;
};
