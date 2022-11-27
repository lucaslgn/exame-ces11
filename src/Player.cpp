#include "Player.hpp"

void Player::walk(Map gameMap, sf::Window window) {
	auto currentVertex = gameMap.closestTile(pos);
	auto destinyVertex = gameMap.closestTile(destiny);
	auto shortestPath = gameMap.shortestPath(currentVertex, destinyVertex);

	for (const auto& vertex : shortestPath) {
		pos = gameMap.tilePosition(vertex);
	}
}
