#pragma once
#include "Brick.h"
#include "Rectangle.h"


class ITEM:public Rectangle
{
private:
	float fallingSpeed;
	int status;
public:
	void generate(RACKET brick,int);
	void fall();
	friend class Brick;
	ITEM();
	~ITEM();
};

