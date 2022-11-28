#include "Player.hpp"

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	target.draw(player_, states);
}
void Player::loadPlayer(const std::string& saveFile, const std::string& imageFile, const Map& gameMap) {
	std::ifstream is(saveFile);
	int x, y;
	if (!(is >> x >> y))
        throw std::runtime_error{"couldn't load save"};
	auto index = gameMap.closestTile(sf::Vector2i{x, y});
	pos = gameMap.tilePosition(index);

	if (!playerImage_.loadFromFile(imageFile))
        throw std::runtime_error{"couldn't load save"};
	player_.setTexture(playerImage_);
	player_.setPosition(sf::Vector2f(pos));
	auto size = playerImage_.getSize();
	player_.setOrigin(size.x * 0.68, size.y);
}
void Player::walk(const Map& gameMap) {
    if (!pathPoints.empty()) {
        return;
    }
	auto currentVertex = gameMap.closestTile(pos);
	auto destinyVertex = gameMap.closestTile(destiny);
	auto shortestPath = gameMap.shortestPath(currentVertex, destinyVertex);

	for (const auto& vertex : shortestPath)
		pathPoints.push(gameMap.tilePosition(vertex));

	pathPoints.push(gameMap.tilePosition(destinyVertex));
}
void Player::updatePosition(float dt) {
    if (!pathPoints.empty()) {
        deltaTime += dt;
        while (deltaTime > 0.3f) {
            deltaTime -= 0.3f;
            pos = pathPoints.front();
            player_.setPosition(sf::Vector2f(pos));
            pathPoints.pop();
        }
    }
}
