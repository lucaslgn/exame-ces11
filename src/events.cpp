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
	} else if (saveButtonPressed(event)) {
		saveGame("data/save", player);
	}
}
bool mouseClicked(const sf::Event& event) {
	return (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left);
}
bool saveButtonPressed(const sf::Event &event) {
	return event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::S && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LControl);
}
void updateWindow(sf::RenderWindow& window, const Map& gameMap, const Player& player) {
	window.clear(sf::Color::Black);
	window.draw(gameMap);
	window.draw(player);
	window.display();
}
void saveGame(const std::string& nameFile, const Player& player) {
	std::ofstream os(nameFile);

	os << player.pos.x << ' ' << player.pos.y;
}
