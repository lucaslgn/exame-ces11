#include "Player.hpp"

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	target.draw(player_, states);
}
bool Player::readPlayer(const std::string& saveFile, const std::string& imageFile, const Map& gameMap) {
	std::ifstream is(saveFile);
	int x, y;
	if (!(is >> x >> y))
		return false;
	auto index = gameMap.closestTile(sf::Vector2i{x, y});
	pos = gameMap.tilePosition(index);

	if (!playerImage_.loadFromFile(imageFile))
		return false;
	player_.setTexture(playerImage_);
	player_.setPosition(pos.x, pos.y);
	//player_.setOrigin();
	return true;
}
void Player::walk(const Map& gameMap) {
	auto currentVertex = gameMap.closestTile(pos);
	auto destinyVertex = gameMap.closestTile(destiny);
	auto shortestPath = gameMap.shortestPath(currentVertex, destinyVertex);

	for (const auto& vertex : shortestPath) {
		pos = gameMap.tilePosition(vertex);
		player_.setPosition(pos.x, pos.y);
	}
	pos = gameMap.tilePosition(destinyVertex);
	player_.setPosition(pos.x, pos.y);
}
