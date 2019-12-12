#include "pch.h"
#include "Brick.h"

void Brick::Init() {

	int x = xStartPoint, y = yStartPoint;
	for (int i = 0; i < maxBrick/2; i++) {
		x = xStartPoint;
		for (int j = 0; j < maxBrick; j++) {
			brick[i][j].setDefaultValue(x, x + xJump, y + yJump, y, 0, 0, 0);
			x += xJump + space;
			isOnBrick[i][j] = false;
		}
		y += yJump + space;
	}
}

void Brick::InitRandomMatch() {
	srand(time(NULL));
	for (int i = 0; i < maxBrick / 2; i++) {
		for (int j = 0; j < maxBrick; j++) {
			if ((rand() % 2 + 1) % 2 == 0) {
				isOnBrick[i][j] = true;
			}
		}
	}
}

void Brick::Draw() {
	for (int i = 0; i < maxBrick / 2; i++) {
		for (int j = 0; j < maxBrick; j++) {
			if (isOnBrick[i][j] == true) {
				brick[i][j].Draw();
			}
		}
	}
}

void Brick::DeleteABrick(int i, int j) {
	glColor3f(0.0, 0.0, 0.0);//Đặt màu vẽ là mau den
	brick[i][j].Draw();
	glColor3f(1.0, 1.0, 1.0); // dat lai mau trang
}

RACKET Brick::isCollide(int x, int y) {
	for (int i = 0; i < maxBrick / 2; i++) {
		for (int j = 0; j < maxBrick; j++) {
			if (isOnBrick[i][j]) {
				if (x > brick[i][j].getLeft() && x < brick[i][j].getRight() && y > brick[i][j].getBottom() && y < brick[i][j].getTop()) {
					DeleteABrick(i, j);
					isOnBrick[i][j] = false;
					return brick[i][j];
				}
			}
		}
	}
	return {};
}

Brick::Brick()
{
}


Brick::~Brick()
{
}
