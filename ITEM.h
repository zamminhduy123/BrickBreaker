#pragma once
#include "RACKET.h"
#include "Rectangle.h"

enum item {  reduceWidth =1, extraWidth = 2 , extraLife = 3 };


class ITEM:public Rectangle
{
private:
	float fallingSpeed;
	float curSpeed;
	int status;
public:
	void generate(RACKET brick,int);
	void fall();
	void deleteItem();
	int getStatus() {
		return status;
	}
	void setStatus(int new_stat) {
		status = new_stat;
	}
	bool isRacketCollide(RACKET);
	ITEM();
	~ITEM();
};

