#pragma once
#include <string>
using namespace std;

class PLAYER
{
private:
	string name;
	int score;
public:
	void setName(string new_name) {
		name = new_name;
	}
	string getName() { return name; }

	friend class SCREEN;
	PLAYER();
	~PLAYER();
};

