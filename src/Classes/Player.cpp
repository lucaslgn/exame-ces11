#include "Player.hpp"

Player::Player(int x, int y, int vX, int vY) {
	this->x = x;
	this->y = y;
	this->vX = vX;
	this->vY = vY;
}

void Player::walk(int x, int y) {
	isWalking = true;
	while (isWalking) {
		//TODO
	}
}
