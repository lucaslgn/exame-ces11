#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "events.hpp"
#include "Player.hpp"
#include "Map.hpp"

int main() {
	sf::RenderWindow window(sf::VideoMode(1200, 800), "Exam");
	window.setFramerateLimit(60);
	Map gameMap;
	gameMap.loadMap("data/map.txt", "data/map.jpg");
	Player player;
	player.loadPlayer("data/save", "data/leona.png", gameMap);
    sf::Clock deltaClock;

	while (window.isOpen()) {
		sf::Event event;
		
		while (pendingEvents(window, event)) {
			treatEvents(window, event, player, gameMap);
		}
        player.updatePosition(deltaClock.restart().asSeconds());
		updateWindow(window, gameMap, player);
	}
}
