#pragma once
#include "transform.h"

class Lockpick
{
public:
	Transform myTrans;
	vec2 right;
	int wedgeEnd1; //= rand() % 360 + 1;
	int wedgeEnd2; //= wedgeEnd1 + 30;
	bool alligned;
	Lockpick(vec2 pos, vec2 dim, float angle);
	int round = 0;
	void draw();
	void update();
	int clickFrame;

	//float timer;
};