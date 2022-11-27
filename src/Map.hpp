#pragma once

#include <string>
#include <vector>
#include "SFML/Graphics.hpp"
#include "graphList.hpp"

double distance(sf::Vector2i pos1, sf::Vector2i pos2);

class Map : public sf::Drawable {
private:
    Graph tilesGraph_ = Graph(0);
    std::vector<sf::Vector2i> tiles_;
    sf::Texture backgroundImage_;
    sf::Sprite background_;

    void drawEdges(sf::RenderTarget &target, sf::RenderStates states) const;
    void drawTiles(sf::RenderTarget &target, sf::RenderStates states) const;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

public:
    std::size_t closestTile(sf::Vector2i pos) const;
    sf::Vector2i tilePosition(std::size_t tileIndex) const;

    bool readMap(const std::string &tilesFile, const std::string &imageFile);

    std::vector<std::size_t> shortestPath(std::size_t from, std::size_t to) const;
};
