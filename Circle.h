#pragma once
#include <iostream>
#include "glew.h"
#include "glut.h"

using namespace std;

class Circle//Khai báo lớp hình tròn
{
protected:
	float x;//Hoành độ tâm
	float y;//Tung độ tâm
	float r;//Bán kính
public:
	void Draw();//Hàm vẽ hình tròn
	float getX() {
		return x;
	}
	float getY() {
		return y;
	}
	float getR() {
		return r;
	}
	void setX(float new_x) {
		x = new_x;
	}
	void setY(float new_y) {
		y = new_y;
	}
	Circle();
	~Circle();
};

