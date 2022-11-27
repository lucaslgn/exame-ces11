#pragma once

#include <fstream>
#include <queue>
#include <SFML/Graphics/Drawable.hpp>
#include "Map.hpp"


class Player : public sf::Drawable {
private:
	sf::Texture playerImage_;
	sf::Sprite player_;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
public:
	bool readPlayer(const std::string &saveFile, const std::string &imageFile, const Map &gameMap);
	void walk(const Map& gameMap);
	void updatePosition();

	bool isWalking = false;

	sf::Vector2i pos;
	sf::Vector2i destiny;

	std::queue<sf::Vector2i> pathPoints;
};
