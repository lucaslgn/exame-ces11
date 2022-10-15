#pragma once

class Player {
public:
	Player(int, int, int, int);
	void walk(int, int);
private:
	int x, y;
	int vX, vY;
	bool isWalking = false;
};
