#include "pch.h"
#include "Circle.h"


void Circle::Draw()//Hàm vẽ hình tròn bằng cách vẽ 1 đa giác đều có 40 đỉnh
{
	glBegin(GL_POLYGON);//Gọi lệnh bắt đầu vẽ 1 đa giác (GL_POLYGON là đa giác)
	for (float i = x - r; i < x + r; i += r / 20)//Vòng lặp để tính tọa độ từng đỉnh ở nửa trên
	{
		glVertex2f(i, y + sqrtf(r*r - (i - x)*(i - x)));//Vẽ từng đỉnh
	}
	for (float i = x + r; i > x - r; i -= r / 20)//Vòng lặp để tính tọa độ từng đỉnh ở nửa dưới
	{
		glVertex2f(i, y - sqrtf(r*r - (i - x)*(i - x)));//Vẽ từng đnhr
	}
	glEnd();//Kết thúc lệnh vẽ
}
Circle::Circle()
{
}


Circle::~Circle()
{
}
