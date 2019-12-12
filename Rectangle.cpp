#include "pch.h"
#include "Rectangle.h"


void Rectangle::Draw()//Hàm vẽ hình chữ nhật
{
	glBegin(GL_QUADS);//Gọi lệnh bắt đầu hàm vẽ hình chữ nhật (GL_QUADS là hình chữ nhật)
	glVertex2f(Left, Bottom);	//Vẽ 4 đỉnh của hình chữ nhật
	glVertex2f(Right, Bottom);	//
	glVertex2f(Right, Top);		//
	glVertex2f(Left, Top);		//
	glEnd();//Kết thúc thao tác vẽ
}
void Rectangle::Update(float l, float r, float t, float b)//Hàm cập nhật thông tin hình chữ nhật với 4 tham số đưa vào
{
	Left = l;	//4 tham số được gán tương ứng với tọa độ 4 cạnh của hình chữ nhật
	Right = r;	//
	Top = t;	//
	Bottom = b;	//
}
Rectangle::Rectangle()
{
}


Rectangle::~Rectangle()
{
}
