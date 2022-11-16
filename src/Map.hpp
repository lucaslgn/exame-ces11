#pragma once

#include <string>
#include <vector>
#include "SFML/Graphics.hpp"
#include "graphList.hpp"

struct Tile {
    int x, y;
};

double distance(Tile tile1, Tile tile2);

class Map : public sf::Drawable {
private:
    Graph tilesGraph_ = Graph(0);
    std::vector<Tile> tiles_;
    sf::Texture backgroundImage_;
    sf::Sprite background_;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
public:
    bool readMap(const std::string &tilesFile, const std::string &imageFile);
    std::vector<Tile> dijkstra(Tile from, Tile to) const;
};