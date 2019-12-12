#pragma once
#include "RACKET.h"
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
public:
	void Init(); // khoi tao cac vien gach
	void InitRandomMatch(); // khoi tao cac vien gach ngau nhien
	void Draw(); // ve cac vien gach
	void DeleteABrick(int i,int j); // xoa 1 vien gach
	RACKET isCollide(int x, int y);
	Brick();
	~Brick();
};

