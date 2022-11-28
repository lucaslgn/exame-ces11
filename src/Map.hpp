#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "graphList.hpp"

double distance(const sf::Vector2i &pos1, const sf::Vector2i &pos2);

class Map : public sf::Drawable {
private:
    Graph tilesGraph_;
    std::vector<sf::Vector2i> tiles_;
    sf::Texture backgroundImage_;
    sf::Sprite background_;

    void drawEdges(sf::RenderTarget &target, sf::RenderStates states) const;
    void drawTiles(sf::RenderTarget &target, sf::RenderStates states) const;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

public:
    std::size_t closestTile(const sf::Vector2i &pos) const;
    sf::Vector2i tilePosition(const std::size_t &tileIndex) const;

    void loadMap(const std::string &tilesFile, const std::string &imageFile);

    std::vector<std::size_t> shortestPath(const std::size_t &from, const std::size_t &to) const;
};
