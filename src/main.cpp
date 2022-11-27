#include "events.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <stdexcept>
#include "Player.hpp"
#include "Map.hpp"
#include <thread>

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
		window.clear(sf::Color::Black);
		window.draw(gameMap);
		if (player.isWalking) {
			while (!player.pathPoints.empty()) {
				player.pos = player.pathPoints.front();
				player.player_.setPosition(player.pos.x, player.pos.y);
				player.pathPoints.pop();
				window.clear();
				window.draw(gameMap);
				window.draw(player);
				window.display();
				std::this_thread::sleep_for(std::chrono::milliseconds(300));
			}
		}
		window.draw(player);
		window.display();
	}
}
