#pragma once

#include <fstream>
#include <queue>
#include <SFML/Graphics/Drawable.hpp>
#include "Map.hpp"

class Player : public sf::Drawable {
private:
	sf::Texture playerImage_;
	sf::Sprite player_;

    std::queue<sf::Vector2i> pathPoints;
    float deltaTime;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
public:
	void loadPlayer(const std::string &saveFile, const std::string &imageFile, const Map &gameMap);
	void walk(const Map& gameMap);
	void updatePosition(float dt);
    sf::Vector2i pos;
    sf::Vector2i destiny;

};
