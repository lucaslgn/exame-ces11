#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <cmath>
#include "SFML/Graphics.hpp"
#include "graphList.hpp"

struct Position {
    int x, y;
};

double distance(Position pos1, Position pos2);

class Map : public sf::Drawable {
private:
    Graph tilesGraph_ = Graph(0);
    std::vector<Position> tiles_;
    sf::Texture backgroundImage_;
    sf::Sprite background_;

    void drawEdges(sf::RenderTarget &target, sf::RenderStates states) const;
    void drawTiles(sf::RenderTarget &target, sf::RenderStates states) const;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

public:
    std::size_t closestTile(Position pos) const;
    Position tilePosition(std::size_t tileIndex) const;

    bool readMap(const std::string &tilesFile, const std::string &imageFile);

    std::vector<std::size_t> shortestPath(std::size_t from, std::size_t to) const;
};
