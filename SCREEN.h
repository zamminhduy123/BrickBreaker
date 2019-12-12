#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include "BALL.h"
#include "Brick.h"
#include "RACKET.h"

#define VK_S 83		//Định nghĩa mã của phím S
#define VK_W 87		//Định nghĩa mã của phím W
#define VK_ENTER 13	//Định nghĩa mã của phím ENTER
//#define VK_RIGHT 77
//#define VK_LEFT 75

using namespace std;

class SCREEN
{
private:
	int Width;				//Chiều rộng của cửa sổ trò chơi
	int Height;				//Chiều cao của của sổ trò chơi
	float TopBar;			//Thanh giới hạn trên (nơi cao nhất quả bóng có thể di chuyển đến)
							//Giới hạn trái và giới hạn dưới mặc định bằng 0, giới hạn phải mặc định bằng Width
	BALL ball;				//Quả bóng 
	RACKET LeftRacket;		//Vợt phía bên trái
	RACKET RightRacket;		//Vợt phía bên phải
	RACKET racketForBrickGame;
	Brick brick;
	int stage;				//Giai đoạn của màn hình, của trò chơi
							//Gồm 5 giai đoạn (đánh số từ 0 đến 4):
							//0: trò chơi chưa bắt đầu, hiện màn hình Menu trò chơi
							//1: chế độ 1 người chơi
							//2: chế độ 2 nguời chơi
							//3: sau khi chơi xong và đã tìm ra người chiến thắng, hiển thị người thắng và hỏi người chơi muốn chơi tiếp hay thoát trò chơi
							//4: trò chơi kết thúc, hiển thị màn hình kết thúc và thoát trò chơi
	float SelectionArrow;	//Tọa độ đỉnh trên cùng của mũi tên chọn chức năng (ở đây sẽ có 1 mũi tên hiển thị để chọn chức năng)
	int WinScore;			//Số điểm người chơi cần đạt đến để thắng trò chơi, ở đây đặt mặc định là 5
public:
	int getterWidth();		//Hàm lấy thông tin chiều rộng
	int getterHeight();		//Hàm lấy thông tin chiều cao
	int getterStage();		//Hàm lấy thông tin giai đoạn của trò chơi
	void PrintText(float x, float y, string text);	//Hàm hiển thị 1 chuỗi kí tự text ra màn hình ở tọa độ (x,y)
	void DisplayScreen();							//Hàm vẽ màn hình ở tất cả các giai đoạn
	void ResizeScreen();							//Hàm thay đổi lại các thông tin của màn hình sau mỗi lần hiển thị
	void UpdateBall();								//Hàm cập nhật thông tin của quả bóng (tọa độ bóng, xử lí va chạm) và số điểm người chơi sau mỗi lượt chạm bóng
	void UpdateLeftRacket();						//Hàm cập nhật thông tin của vợt bên trái (vợt di chuyển lên hay xuống)
	void UpdateRightRacket();						//Hàm cập nhật thông tin của vợt bên phải (vợt di chuyển lên hay xuống)
	void UpdateAutoRacket();						//Hàm cập nhật thông tin của vợt tự động hứng bóng (ở đây mặc định là vợt bên trái)
	void UpdateScreen();							//Hàm cập nhật lại toàn bộ thông tin trên màn hình (gồm các hàm Update phía trên)
	void SetUpDefaultStartValue();					//Hàm khởi tạo thông tin ban đầu của tất cả các đối tượn
	void DisplayPlayScreen(class Rectangle &b);		//Hàm vẽ màn hình chơi cho giai đoạn 1 2 và đầu 3
	void DisplayWinner();
	void DisplayBrickGameScreen(class Rectangle &b);
	void UpdateBrickGameRacket();
	void UpdateBallForBrickGame();
	void CollideCheck();
	SCREEN();
	~SCREEN();
};

