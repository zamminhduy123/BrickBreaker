#include "pch.h"
#include <iostream>
#include "SCREEN.h"
#define VK_ESC 27//Định nghĩa mã phím ESC

using namespace std;


SCREEN PingPong;//Khởi tạo biến PingPong thuộc lớp SCREEN
int id;//Khởi tạo biến id, id ở đây là mã của cửa sổ game

void Display()//Định nghĩa hàm Display
{
	PingPong.DisplayScreen();//Gọi lại Hàm DisplayScreen trong lớp SCREEN
}

void Update(int value)//Định nghĩa hàm Update với 1 giá trị value kiểu int, sở dĩ có value kiểu int là để phù hợp với hàm glutTimerFunc()
{
	PingPong.UpdateScreen();//Gọi lại hàm UpdateScreen trong lớp SCREEN
	glutTimerFunc(1, Update, 1);//Gọi hàm glutTimerFunc, hàm này có chức năng gọi lại hàm Update trong 1 milisecond, nhờ đó mà ta có thể tạo được ảnh động
}

void Resize(int w, int h)//Định nghĩa hàm Resize
{
	PingPong.ResizeScreen();//Gọi lại hàm Resize
}

void EscapePingPongGame(unsigned char key, int x, int y)//Định nghĩa hàm EscapePongGame, với chức năng khi ta ấn 1 phím thì chương trình sẽ thoát
{
	if (PingPong.getterStage() == 4 && GetAsyncKeyState(VK_ESC))//Khi stage=4, tức là khi ta đã chọn QUIT GAME, và ấn phím ESC thì chương trình sẽ thoát
	{
		glutDestroyWindow(id);//Đóng cửa sổ game
		exit(0);
	}
}

void init(int argc, char **argv) {
	PingPong.SetUpDefaultStartValue();												//Khởi tạo các giá trị ban đầu của các đối tượng trong game
	glutInit(&argc, argv);															//Mở chế độ đồ họa
	glutInitWindowSize(PingPong.getterWidth(), PingPong.getterHeight());			//Khởi tạo cửa sổ với kích thước là (Width,Height)
	glutInitWindowPosition(10, 10);													//Mở cửa sổ ở tọa độ (10,10) trên màn hình máy tính
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);						//Khởi tạo chế độ vẽ Double buffer, Depth buffer, hệ màu RGB 
	id = glutCreateWindow("Brick Breaker Game");
}


void main(int argc, char **argv)
{
	init(argc, argv);																			//khoi tao game
	//
	glClear(GL_COLOR_BUFFER_BIT);													//Xóa mọi pixels
	glLoadIdentity();
	glClearColor(0.4, 0.3, 0.9, 0.1);												//Đặt màu nền là màu tím
	//
	glutDisplayFunc(Display);														//Gọi hàm vẽ là hàm Display
	glutTimerFunc(1, Update, 1);													//Gọi hàm để lặp lại thao tác cập nhật thông tin các đối tượng trong 1 miliseconds
	glutReshapeFunc(Resize);														//Gọi hàm cập nhật thông tin màn hình
	glutKeyboardFunc(EscapePingPongGame);											//Gọi hàm bắt phím để khi ấn phím ESC ta thoát game
	glutMainLoop();																	//Bắt đầu chu trình lặp thể hiện vẽ
}