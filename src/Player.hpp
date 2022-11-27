#pragma once

#include "Map.hpp"
#include <SFML/Graphics/Drawable.hpp>
#include <fstream>
#include <queue>


class Player : public sf::Drawable {
private:
	sf::Texture playerImage_;
	sf::Sprite player_;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
public:
	bool isWalking = false;
	bool readPlayer(const std::string &saveFile, const std::string &imageFile, const Map &gameMap);
	void walk(const Map& gameMap);
	std::queue<sf::Vector2i> pathPoints;
	void updatePosition();
	sf::Vector2i pos;
	sf::Vector2i destiny;
};
