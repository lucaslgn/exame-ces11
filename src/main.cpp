#include <thread>
#include <stdexcept>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "events.hpp"
#include "Player.hpp"
#include "Map.hpp"

int main() {
	sf::RenderWindow window(sf::VideoMode(1200, 800), "Exam");
	Map gameMap;
	if (!gameMap.readMap("data/map.txt", "data/map.jpg"))
		throw std::runtime_error{"couldn't load map"};
	Player player;
	if (!player.readPlayer("data/save", "data/leona.png", gameMap))
		throw std::runtime_error{"couldn't load save"};

	while (window.isOpen()) {
		sf::Event event;
		
		while (pendingEvents(window, event)) {
			treatEvents(window, event, player, gameMap);
		}
		if (player.isWalking) {
			while (!player.pathPoints.empty()) {
				player.pos = player.pathPoints.front();
				player.updatePosition();
				player.pathPoints.pop();
				updateWindow(window, gameMap, player);
				std::this_thread::sleep_for(std::chrono::milliseconds(300));
			}
		}
		updateWindow(window, gameMap, player);
	}
}
