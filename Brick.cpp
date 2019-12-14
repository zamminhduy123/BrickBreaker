#include "pch.h"
#include "Brick.h"

void Brick::Init() {

	int x = xStartPoint, y = yStartPoint;
	for (int i = 0; i < maxBrick/2; i++) {
		x = xStartPoint;
		for (int j = 0; j < maxBrick; j++) {
			brick[i][j].setValue(x, x + xJump, y + yJump, y, 0, 0, 0);
			x += xJump + space;
			isOnBrick[i][j] = false;
			isItem[i][j].setStatus(0);
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
				setBrickColor(isItem[i][j].getStatus());
				brick[i][j].Draw();
			}
		}
	}
}

void Brick::DeleteABrick(int i, int j) {
	glColor3f(0.0, 0.0, 0.0);//Đặt màu vẽ là mau den
	brick[i][j].Draw();
	itemTime[i][j] = 0;
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
		case 0:
			glColor3f(1.0, 1.0, 1.0);
			break;
	}

}

/*
	Hàm kiểm tra banh có chạm vào gạch không
*/

ITEM Brick::isCollide(BALL &ball) {
	for (int i = 0; i < maxBrick / 2; i++) 
	{
		for (int j = 0; j < maxBrick; j++) 
		{
			if (isOnBrick[i][j]) 
			{
				if (brick[i][j].intersects(ball))
				{
					DeleteABrick(i, j);
					isOnBrick[i][j] = false;
					return isItem[i][j];
				}
			}
		}
	}
	return ITEM();
}

void Brick::spawnItem()
{
	// random gạch có vật phẩm
	for (int k = 0; k < maxBrick/2; k++) {
		for (int l = 0; l < maxBrick; l++) {
			if (isOnBrick[k][l]) {
				int r = rand() % 2 + 1;
				if (r % 2 == 0) {
					int randItem = rand() % 3 + 1; // random 1 trong 3 vật phẩm  
					setBrickColor(randItem);   // đổi màu gạch theo vật phẩm
					brick[k][l].Draw();
					itemTime[k][l] = 3000;
					glColor3f(1.0, 1.0, 1.0);   //set lại màu trắng
					isItem[k][l].generate(brick[k][l], randItem);
					return;
				}
			}
		}
	}
}

void Brick::reduceItemTime() {
	for (int i = 0; i < maxBrick / 2; i++) {
		for (int j = 0; j < maxBrick; j++) {
			if (itemTime[i][j] > 0) {
				itemTime[i][j]--;
			}
			else if (itemTime == 0) {
				if (isOnBrick[i][j]) {
					glColor3f(1.0, 1.0, 1.0);
					brick[i][j].Draw();
				} 
			}
		}
	}
} //giảm thời gian của item


Brick::Brick()
{
}


Brick::~Brick()
{
}
