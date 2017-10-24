#include "LockPick.h"
#include "mat3.h"
#include "sfwdraw.h"
#include <iostream>

void Lockpick::draw()
{
	if (Picked == false)
	{
		sfw::drawCircle(myTrans.position.x, myTrans.position.y, 300, 48, WHITE);
	}
	else
	{
		sfw::drawCircle(myTrans.position.x, myTrans.position.y, 300, 48,GREEN);
	}
	
	
	sfw::drawLine(myTrans.position.x, myTrans.position.y, right.x, right.y, MAGENTA);
	
}

Lockpick::Lockpick(vec2 pos, vec2 dim, float angle)
{
	myTrans.position = pos;
	myTrans.dimension = dim;
	myTrans.angle = angle;
	wedgeEnd1 = rand() % 330 + 1;
	wedgeEnd2 = wedgeEnd1 + 30;
	Picked = false;
}

void Lockpick::update()
{
	mat3 t = myTrans.getLocalTransform();
	right = myTrans.position + t[0].xy * 300;
	
	if (sfw::getKey(262))
	{
		std::cout << myTrans.angle << std::endl;
		myTrans.angle -= sfw::getDeltaTime() * 90;
		if (myTrans.angle >= 360)
		{
			myTrans.angle = 0;
		}
		else if (myTrans.angle <= 0)
		{
			myTrans.angle = 360;
		}
		//defactoAngle = myTransform.angle;
	}
	//rotate counterclockwise
	if (sfw::getKey(263))
	{
		std::cout << myTrans.angle << std::endl;
		myTrans.angle += sfw::getDeltaTime() * 90;
		if (myTrans.angle > 360)
		{
			myTrans.angle = 0;
		}
		else if (myTrans.angle <= 0)
		{
			myTrans.angle = 360;
		}
		//defactoAngle = myTransform.angle;
	}

	if (myTrans.angle > wedgeEnd1 && myTrans.angle < wedgeEnd2)
	{
		Picked = true;
	}
	else
	{
		Picked = false;
	}

}
