#include "events.hpp"

bool pendingEvents(sf::Window& window, sf::Event& event) {
	return window.pollEvent(event);
}
void treatEvents(sf::Window& window, const sf::Event& event, Player player) {
	if (event.type == sf::Event::Closed) {
		window.close();
	} else if (mouseClicked(event)) {
		//TODO
		std::vector way = dijkstra();
		player.walk(way);
	}
}
bool mouseClicked(const sf::Event& event) {
	return (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left);
}
