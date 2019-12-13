#include "pch.h"
#include "RACKET.h"

void RACKET::setDefaultValue(int l,int r,int t,int b,float sp,int st,int sc) {
	Left = l;
	Right = r;
	Top = t;
	Bottom = b;
	Speed = sp;
	Status = st;
	Score = sc;
}

float clamp(float value, float min, float max) {
	if (value < min) {
		return min;
	}
	else if (value > max) {
		return max;
	}
	else {
		return value;
	}
}

bool inHeight(float cy,float cr, float t, float b) {
	if (cy - cr <= t && cy > b) {
		return true;
	}
	else if (cy + cr >= b && cy < t) {
		return true;
	}
	else if (cy >= b && cy <= t) {
		return true;
	}
	return false;
}

bool inWidth(float cx, float cr, float l, float r) {
	if (cx + cr >= l && cx < r) {
		return true;
	}
	else if (cx - cr <= r && cx > l) {
		return true;
	}
	else if (cx >= l && cx <= r) {
		return true;
	}
	return false;
}

bool RACKET::intersects(BALL &ball) {
	int width = Right - Left, heigth = Top - Bottom;
	// TH đụng trên
	if (ball.getY() - ball.getR() <= Top && ball.getY() >= Bottom){
		float k = fabs(ball.getX() - (Left + Right) / 2) / width;
		if (inWidth(ball.getX(),ball.getR(),Left,Right)) {
			ball.setYDir(-ball.getYDir());
			if (ball.getX() > 0) {
				ball.setXDir(k);
			}
			else {
				ball.setXDir(-k);
			}
			return true;
		}
	} //TH đụng dưới
	else if (ball.getY() + ball.getR() >= Bottom && ball.getY() < Top) { 
		float k = fabs(ball.getX() - (Left + Right) / 2) / width;
		if (inWidth(ball.getX(), ball.getR(), Left, Right)) {
			ball.setYDir(-ball.getYDir());
			if (ball.getXDir() > 0) {
				ball.setXDir(k);
			}
			else {
				ball.setXDir(-k);
			}
			return true;
		}
	}//TH đụng trái
	else if (ball.getX() + ball.getR() >= Left && ball.getX() < Right) {
		float k = fabs(ball.getY() - (Top+Bottom) / 2) / heigth;
		if (inHeight(ball.getY(),ball.getR(),Top,Bottom)) {
			ball.setXDir(-ball.getXDir());
			if (ball.getYDir() > 0) {
				ball.setYDir(k);
			}
			else {
				ball.setYDir(-k);
			}
			return true;
		}
	}// TH đụng phải
	else if (ball.getX() > Left && ball.getX() - ball.getX() <= Right) {
		float k = fabs(ball.getY() - (Top + Bottom) / 2) / heigth;
		if (inHeight(ball.getY(), ball.getR(), Top, Bottom)) {
			ball.setXDir(-ball.getXDir());
			if (ball.getYDir() > 0) {
				ball.setYDir(k);
			}
			else {
				ball.setYDir(-k);
			}
			return true;
		}
	}
	return false;
}


RACKET::RACKET()
{
}


RACKET::~RACKET()
{
}
