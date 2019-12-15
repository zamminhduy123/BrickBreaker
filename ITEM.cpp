#include "pch.h"
#include "ITEM.h"



void ITEM::generate(RACKET brick,int itemOrder) {
	Top = brick.getBottom();
	Bottom = Top - 30;
	Left = (brick.getRight() + brick.getLeft()) / 2;
	Right = Left + 30;
	fallingSpeed = (float)(rand() % 10 + 1) / 10;
	status = itemOrder;
}

void ITEM::print() {
	if (Top > 0)
	cout << Left << " " << Right << " " << Top << " " << Bottom << " " << fallingSpeed <<" " <<  status << endl;
}
void ITEM::load() {
	cin >> Left >> Right >> Top >> Bottom >> fallingSpeed >> status;
}

bool ITEM::isRacketCollide(RACKET racket) {
	if (Left >= racket.getLeft() && Right <= racket.getRight()) {
		if (Bottom <= racket.getTop() && Bottom >= racket.getBottom()) {
			return true;
		}
		else if (Top <= racket.getTop() && Top >= racket.getBottom()) {
			return true;
		}
		else if (Top > racket.getTop() && Bottom < racket.getBottom()) {
			return true;
		}
	}
	else if ((Left < racket.getLeft() && Right > racket.getLeft()) || (Left<racket.getRight() && Right > racket.getRight())) {
		if (Bottom <= racket.getTop() && Bottom >= racket.getBottom()) {
			return true;
		}
		else if (Top <= racket.getTop() && Top >= racket.getBottom()) {
			return true;
		}
		else if (Top > racket.getTop() && Bottom < racket.getBottom()) {
			return true;
		}
	}
	return false;
}

void ITEM::deleteItem() {
	glColor3f(0.0, 0.0, 0.0);
	Draw();
}

void ITEM::fall() {
	glColor3f(0.0, 0.0, 0.0);
	Draw();
	//curSpeed += curSpeed * fallingSpeed;
	Top -= fallingSpeed;
	Bottom -= fallingSpeed;
	switch(status) {
	case 1:
		glColor3f(1.0, 0.0, 0.0);
		break;
	case 2:
		glColor3f(0.0, 1.0, 0.0);
		break;
	case 3:
		glColor3f(0.0, 0.0, 1.0);
		break;
	case 4:
		glColor3f(1.0, 1.0, 0.0);
		break;

	}
	Draw();
}

ITEM::ITEM()
{
	curSpeed = -2;
	status = 0;
}


ITEM::~ITEM()
{
}
