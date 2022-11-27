#include "events.hpp"

bool pendingEvents(sf::RenderWindow& window, sf::Event& event) {
	return window.pollEvent(event);
}
void treatEvents(sf::Window& window, const sf::Event& event, Player& player, const Map& gameMap) {
	if (event.type == sf::Event::Closed) {
		window.close();
	} else if (mouseClicked(event)) {
		player.destiny = sf::Mouse::getPosition(window);
		player.walk(gameMap);
	} else if (saveButtonPressed()) {
		//TODO
		//save game
	}
}
bool mouseClicked(const sf::Event& event) {
	return (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left);
}
bool saveButtonPressed() {
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LControl);
}
void updateWindow(sf::RenderWindow& window, const Map& gameMap, const Player& player) {
	window.clear(sf::Color::Black);
	window.draw(gameMap);
	window.draw(player);
	window.display();
}
