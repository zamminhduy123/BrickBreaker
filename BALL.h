#pragma once
#include "Circle.h"


class BALL:public Circle//Khai báo lớp BALL là con (kế thừa) lớp Circle
{
private:
	float FirstSpeed;	//Tốc độ lúc mới bắt đầu di chuyển
	float CurrentSpeed;	//Tốc độ hiện đang di chuyển
	float IncreaseSpeed;//Độ tăng tốc độ sau mỗi lần chạm vợt
	float xDirection;	//Hướng di chuyển theo phương ngang
	float yDirection;	//Hướng di chuyển theo phương dọc
public:
	friend class SCREEN;//Khai báo lớp SCREEN là friend của lớp BALL
	void setXDir(float new_xDir) {
		xDirection = new_xDir;
	}
	void setYDir(float new_yDir) {
		yDirection = new_yDir;
	}
	float getXDir() { return xDirection; }
	float getYDir() { return yDirection; }
	BALL();
	~BALL();
};

