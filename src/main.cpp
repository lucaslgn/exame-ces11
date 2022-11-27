#include "events.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <stdexcept>
#include "Player.hpp"
#include "Map.hpp"

int main() {
	sf::RenderWindow window(sf::VideoMode(1200, 800), "Exam");
	Player player;
	Map gameMap;
	if (!gameMap.readMap("./data/map.txt", "./data/map.jpg"))
		throw std::runtime_error{"couldn't load map"};

	while (window.isOpen()) {
		sf::Event event;
		
		while (pendingEvents(window, event)) {
			treatEvents(window, event, player, gameMap);
		}
		window.clear(sf::Color::Black);
		//draw(window);
		window.draw(gameMap);
		window.display();
	}
}
