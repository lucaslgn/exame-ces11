#include "events/events.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <stdexcept>
#include "../include/Player.hpp"

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 1000), "Exam");
	std::vector<Player> entities;
	readEntities(entities, "entities.txt");
	Map gameMap;
	if (!readMap(gameMap, "map.txt"))
		throw std::runtime_error{"couldn't load map"};

	while (window.isOpen()) {
		sf::Event event;
		
		while (pendingEvents(window, event)) {
			treatEvents(window, event, entities);
		}
		window.clear(sf::Color::Black);
		//draw(window);
		window.draw(gameMap);
		window.display();
	}
}
