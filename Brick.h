#pragma once
#include "BALL.h"
#include "ITEM.h"
#include <iostream>
#include <vector>
#include <time.h>
#include <random>
using namespace std;

#define maxBrick 12
#define xJump 75
#define yJump 25
#define xStartPoint 5
#define yStartPoint 375
#define space 25
#define maxYBrick 6

class Brick
{
private:
	RACKET brick[maxYBrick][maxBrick]; //mang chua cac vien gach
	bool isOnBrick[maxYBrick][maxBrick]; // mang xet xem vien gach co duoc xuat hien hay khong
	ITEM isItem[maxYBrick][maxBrick]; // mang xet xem vien gach co chua vat pham khong
	int itemTime[maxYBrick][maxBrick]; // mảng giữ thời gian của Item
public:
	void Init(); // khoi tao cac vien gach
	void InitRandomMatch(); // khoi tao cac vien gach ngau nhien
	void Draw(); // ve cac vien gach
	void DeleteABrick(int i,int j); // xoa 1 vien gach
	void setBrickColor(int);   // đổi màu gạch
	ITEM isCollide(BALL &ball);	
	void spawnItem();			// xuất hiện ngẫu nhiên vật phẩm
	void reduceItemTime();
	void printSaveGame();
	void loadBrick();
	bool isEmpty();
	Brick();
	~Brick();
};

