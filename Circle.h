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
	Circle();
	~Circle();
};

