#include "Map.hpp"

double distance(const sf::Vector2i &pos1, const sf::Vector2i &pos2) {
    auto deltax = pos1.x - pos2.x;
    auto deltay = pos1.y - pos2.y;
    return std::sqrt(deltax * deltax + deltay * deltay);
}

bool Map::readMap(const std::string &tilesFile, const std::string &imageFile) {
    std::ifstream is(tilesFile);
    std::size_t order;
    if (!(is >> order))
        return false;
    tilesGraph_ = Graph(order);
    tiles_.resize(order);
    for (auto &tile: tiles_) {
        if (!(is >> tile.x >> tile.y))
            return false;
    }
    std::size_t from, to;
    while (is >> from >> to) {
        tilesGraph_.add_edge(from, to, distance(tiles_[from], tiles_[to]));
    }

    if (!backgroundImage_.loadFromFile(imageFile))
        return false;
    background_.setTexture(backgroundImage_);
    return true;
}

void Map::drawEdges(sf::RenderTarget &target, sf::RenderStates states) const {
    for (std::size_t tileIndex = 0; tileIndex < tilesGraph_.order(); ++tileIndex) {
        auto tile = tiles_[tileIndex];
        for (const auto &edge: tilesGraph_.edgesFrom(tileIndex)) {
            if (edge.destination > tileIndex)
                break;
            auto neighbor = tiles_[edge.destination];
            sf::VertexArray line(sf::Lines, 2);
            line[0].position = sf::Vector2f(tile);
            line[0].color = sf::Color::Red;
            line[1].position = sf::Vector2f(neighbor);
            line[1].color = sf::Color::Red;
            target.draw(line, states);
        }
    }
}

void Map::drawTiles(sf::RenderTarget &target, sf::RenderStates states) const {
    float radius = 5;
    sf::CircleShape circle(radius);
    circle.setOutlineThickness(1.f);
    circle.setFillColor(sf::Color(50, 100, 150));
    for (const auto &tile: tiles_) {
        circle.setPosition(tile.x - radius, tile.y - radius);
        target.draw(circle, states);
    }
}

void Map::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(background_, states);
    drawEdges(target, states);
    drawTiles(target, states);
}

std::size_t Map::closestTile(const sf::Vector2i &pos) const {
    double minDistance = std::numeric_limits<double>::max();
    std::size_t closestIndex = tilesGraph_.order();
    for (std::size_t tileIndex = 0; tileIndex < tilesGraph_.order(); ++tileIndex) {
        double dist = distance(tiles_[tileIndex], pos);
        if (dist < minDistance) {
            minDistance = dist;
            closestIndex = tileIndex;
        }
    }
    if (closestIndex < tilesGraph_.order()) {
        return closestIndex;
    }
    throw std::runtime_error("invalid closest tile"); // Acontece quando tiles_ está vazio, por exemplo
}

sf::Vector2i Map::tilePosition(const std::size_t &tileIndex) const {
    return tiles_[tileIndex];
}

std::vector<std::size_t> Map::shortestPath(const std::size_t &from, const std::size_t &to) const {
    return tilesGraph_.dijkstra(from, to);
}
