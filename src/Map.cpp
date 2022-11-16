#include "Map.hpp"
#include <fstream>
#include <cmath>

double distance(Tile tile1, Tile tile2) {
    auto deltax = tile1.x - tile2.x;
    auto deltay = tile1.y - tile2.y;
    return std::sqrt(deltax * deltax + deltay * deltay);
}

bool Map::readMap(const std::string &tilesFile, const std::string &imageFile) {
    std::ifstream is(tilesFile);
    std::size_t order;
    if(!(is >> order))
        return false;
    tilesGraph_ = Graph(order);
    tiles_.resize(order);
    for (auto & tile : tiles_) {
        if(!(is >> tile.x >> tile.y))
            return false;
    }
    std::size_t from, to;
    while (is >> from >> to) {
        tilesGraph_.add_edge(from, to);
    }

    if (!backgroundImage_.loadFromFile(imageFile))
        return false;
    background_.setTexture(backgroundImage_);
    background_.setScale(sf::Vector2f(2.f, 2.f));
    return true;
}

void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(background_, states);
    for (std::size_t tileIndex = 0; tileIndex < tilesGraph_.order(); ++tileIndex) {
        auto tile = tiles_[tileIndex];
        for (const auto & neighborIndex: tilesGraph_.neighbors(tileIndex)) {
            if (neighborIndex > tileIndex)
                break;
            auto neighbor = tiles_[neighborIndex];
            sf::VertexArray line(sf::Lines, 2);
            line[0].position = sf::Vector2f(tile.x, tile.y);
            line[0].color = sf::Color::Red;
            line[1].position = sf::Vector2f(neighbor.x, neighbor.y);
            line[1].color = sf::Color::Red;
            target.draw(line, states);
        }
    }
    float radius = 5;
    sf::CircleShape circle(radius);
    circle.setOutlineThickness(1.f);
    circle.setFillColor(sf::Color(50, 100, 150));
    for (const auto &tile : tiles_) {
        circle.setPosition(tile.x - radius, tile.y - radius);
        target.draw(circle, states);
    }
}
