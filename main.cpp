#include <SFML/Window.hpp>
#include <SFML/Window/Event.hpp>
#include "events.hpp"

int main() {
	sf::Window window;
	window.create(sf::VideoMode(200, 200), "Exame");

	while (window.isOpen()) {
		sf::Event event;

		while (pendingEvents(window, event)) {
			treatEvents(window, event);
		}
	}
}
