#pragma once
#include "Rectangle.h"
#include "BALL.h"

class RACKET:public Rectangle//Khai báo lớp RACKET là con (kế thừa) lớp Rectangle
{
protected:
	float Speed;//Tốc độ của vợt
	int Status;//Tình trạng của vợt: 1 hoặc -1 tương ứng với đi lên hoặc đi xuống (ban đầu mặc định là 1)
	int Score;//Điểm của người chơi sử dụng vợt
public:
	friend class SCREEN;//Khai báo lớp SCREEN là friend của lớp RACKET
	void setValue(int l, int r, int t, int b, float sp, int st, int sc);
	void setTop(float new_top) {
		Top = new_top;
	}
	void setLeft(float new_l) {
		Left = new_l;
	}
	void setRight(float new_r) {
		Right = new_r;
	}
	bool intersects(BALL &ball);
	RACKET();
	~RACKET();
};

