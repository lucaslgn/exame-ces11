#include "events.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <stdexcept>
#include "Player.hpp"
#include "Map.hpp"

int main() {
	sf::RenderWindow window(sf::VideoMode(1200, 800), "Exam");
	Map gameMap;
	if (!gameMap.readMap("./data/map.txt", "./data/map.jpg"))
		throw std::runtime_error{"couldn't load map"};
	Player player;
	if (!player.readPlayer("data/save", "data/zed.png", gameMap))
		throw std::runtime_error{"couldn't load save"};


	while (window.isOpen()) {
		sf::Event event;
		
		while (pendingEvents(window, event)) {
			treatEvents(window, event, player, gameMap);
		}
		window.clear(sf::Color::Black);
		window.draw(gameMap);
		window.draw(player);
		window.display();
	}
}
