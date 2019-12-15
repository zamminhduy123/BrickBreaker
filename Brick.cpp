#include "pch.h"
#include "Brick.h"

void Brick::Init() {

	int x = xStartPoint, y = yStartPoint;
	int jumpX, jumpY;
	for (int i = 0; i < maxBrick/2; i++) {
		x = xStartPoint;
		jumpY = rand() % 20 + 6;
		for (int j = 0; j < maxBrick; j++) {
			jumpX = rand() % 30 + 5;
			if (x + xJump > 1150) {
				break;
			}
			brick[i][j].setValue(x, x + xJump, y + yJump, y, 0, 0, 0);
			x += xJump + jumpX;
			isOnBrick[i][j] = false;
			isItem[i][j].setStatus(0);
		}
		y += yJump + jumpY;
		if (y > 580)
		{
			return;
		}
	}
}

void Brick::printSaveGame() {
	// In gạch
	for (int i = 0; i < maxBrick / 2; i++) {
		for (int j = 0; j < maxBrick; j++) {
			cout << (int)isOnBrick[i][j] << " ";
			brick[i][j].print();
			cout << endl;
		}
	}
	// In trạng thái gạch
	for (int i = 0; i < maxBrick / 2; i++) {
		for (int j = 0; j < maxBrick; j++) {
			cout << isItem[i][j].getStatus() << " ";
		}
		cout << endl;
	}
}

void Brick::loadBrick() {
	Init();
	// load gạch
	for (int i = 0; i < maxBrick / 2; i++) {
		for (int j = 0; j < maxBrick; j++) {
			cin >> isOnBrick[i][j];
			brick[i][j].load();
		}
	}
	int tempStat;
	// load trạng thái gạch
	for (int i = 0; i < maxBrick / 2; i++) {
		for (int j = 0; j < maxBrick; j++) {
			cin >> tempStat;
			isItem[i][j].setStatus(tempStat);
		}
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

bool Brick::isEmpty() {
	for (int i = 0; i < maxBrick / 2; i++) {
		for (int j = 0; j < maxBrick; j++) {
			if (isOnBrick[i][j] == true)
				return false;
		}
	}
	return true;
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
		case 4:
			glColor3f(1.0, 1.0, 0.0);
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
					isItem[i][j].setCurspeed(-1);
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
					int randItem = rand() % 4 + 1; // random 1 trong 3 vật phẩm  
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
