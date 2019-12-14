#pragma once
#include "BALL.h"
#include "ITEM.h"
#include <iostream>
#include <vector>
#include <time.h>
#include <random>
using namespace std;

#define maxBrick 10
#define xJump 75
#define yJump 25
#define xStartPoint 85
#define yStartPoint 375
#define space 25

class Brick
{
private:
	RACKET brick[maxBrick/2][maxBrick]; //mang chua cac vien gach
	bool isOnBrick[maxBrick / 2][maxBrick]; // mang xet xem vien gach co duoc xuat hien hay khong
	ITEM isItem[maxBrick / 2][maxBrick]; // mang xet xem vien gach co chua vat pham khong
	int itemTime[maxBrick / 2][maxBrick]; // mảng giữ thời gian của Item
public:
	void Init(); // khoi tao cac vien gach
	void InitRandomMatch(); // khoi tao cac vien gach ngau nhien
	void Draw(); // ve cac vien gach
	void DeleteABrick(int i,int j); // xoa 1 vien gach
	void setBrickColor(int);   // đổi màu gạch
	ITEM isCollide(BALL &ball);	
	void spawnItem();			// xuất hiện ngẫu nhiên vật phẩm
	void reduceItemTime();
	Brick();
	~Brick();
};

