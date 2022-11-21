#include "events.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <stdexcept>
#include "Player.hpp"
#include "Map.hpp"

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 1000), "Exam");
	Player player(0, 0, 0, 0);
	Map gameMap;
	if (!gameMap.readMap("./data/map.txt", "./data/map.png"))
		throw std::runtime_error{"couldn't load map"};

	while (window.isOpen()) {
		sf::Event event;
		
		while (pendingEvents(window, event)) {
			treatEvents(window, event, player);
		}
		window.clear(sf::Color::Black);
		//draw(window);
		window.draw(gameMap);
		window.display();
	}
}
