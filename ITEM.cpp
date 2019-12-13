#include "pch.h"
#include "ITEM.h"

void ITEM::generate(RACKET brick,int itemOrder) {
	Top = brick.getBottom();
	Bottom = Top - 30;
	Left = (brick.getRight() + brick.getLeft()) / 2;
	Right = Left + 30;
	fallingSpeed = (rand() % 10 + 1) / 10;
	status = itemOrder;
}

void ITEM::fall() {
	glColor3f(0.0, 0.0, 0.0);
	Draw();
	Top -= Top * fallingSpeed;
	Bottom -= Bottom * fallingSpeed;
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
	}
	Draw();
}

ITEM::ITEM()
{
}


ITEM::~ITEM()
{
}
