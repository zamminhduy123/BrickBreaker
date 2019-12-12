#pragma once
#include <iostream>
#include "glew.h"
#include "glut.h"

using namespace std;

class Rectangle//Khai báo lớp hình chữ nhật
{
protected:
	float Left;//Tọa độ cạnh bên trái
	float Right;//Tọa độ cạnh bên phải
	float Top;//Tọa độ cạnh bên trên
	float Bottom;//Tọa độ cạnh bên dưới
public:
	void Draw();//Hàm vẽ hình chữ nhật
	void Update(float, float, float, float);//Hàm cập nhật thông tin hình chữ nhật với 4 biến đưa vào tương ứng với Left,Right,Top,Bottom
	float getLeft() {
		return Left;
	}
	float getRight() {
		return Right;
	}
	float getTop() {
		return Top;
	}
	float getBottom() {
		return Bottom;
	}
	Rectangle();
	~Rectangle();
};

