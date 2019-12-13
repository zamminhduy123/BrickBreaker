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

void Brick::setBrickColor(int order)
{
	switch (order) {
		case 1:
			glColor3f(1.0, 0.0, 0.0);
			break;
		case 2:
			glColor3f(0.0, 1.0, 0.0);
			break;
		case 3:
			glColor3f(0.0, 0.0, 1.0);
			break;
	}

}

RACKET Brick::isCollide(BALL &ball) {
	RACKET None;
	None.setTop(-1);
	for (int i = 0; i < maxBrick / 2; i++) {
		for (int j = 0; j < maxBrick; j++) {
			if (isOnBrick[i][j]) {
				if (brick[i][j].intersects(ball)) {
					DeleteABrick(i, j);
					isOnBrick[i][j] = false;
					return brick[i][j];
				}
			}
		}
	}
	return None;
}

void Brick::spawnItem()
{
	int i = rand() % (maxBrick / 2);
	int j = rand() % (maxBrick);
	if (!isItem[i][j]) {
		int randItem = rand() % 3 + 1;
		isItem[i][j] = true;
		setBrickColor(randItem);
		brick[i][j].Draw();
		glColor3f(1.0,1.0,1.0)
	}
}

Brick::Brick()
{
}


Brick::~Brick()
{
}
