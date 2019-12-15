#pragma once
#include <Windows.h>

class SoundEffect
{
public:
	void execute(int freq, int time) {
		Beep(freq, time);
	}
	void brickCollisionSound(int brickStatus) {
		switch (brickStatus) {
		case 1:
			execute(300, 10);
			break;
		case 3:
		case 2:
			execute(600, 10);
			break;
		case 4:
			execute(800, 10);
			break;
		case 0:
			execute(400, 10);
			break;
		case 5:
			execute(800, 10);
			break;
		}
	}
	void themeSong();
	SoundEffect();
	~SoundEffect();
};

