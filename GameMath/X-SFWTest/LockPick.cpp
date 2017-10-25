#include "LockPick.h"
#include "mat3.h"
#include "sfwdraw.h"
#include <iostream>



void Lockpick::draw()
{
	if (alligned == false)
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
	wedgeEnd1 = rand() % 350 + 1;
	wedgeEnd2 = wedgeEnd1 + 10;
	alligned = false;
}

void Lockpick::update()
{
	unsigned int font = sfw::loadTextureMap("res/fontmap.png", 16, 16);
	mat3 t = myTrans.getLocalTransform();
	right = myTrans.position + t[0].xy * 300;
	
	if (sfw::getKey(262))
	{
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
		alligned = true;
	}
	else
	{
		alligned = false;
	}
	//then checks for up if left and right are not pressed
	if (alligned == true)
	{
		if (!sfw::getKey(262) && !sfw::getKey(263))
		{
			if (sfw::getKey(265))
			{
				alligned = false;
				wedgeEnd1 = rand() % 350 + 1;
				wedgeEnd2 = wedgeEnd1 + 10;
				round++;
				sfw::drawString(font, "CLICK", 300, 330, 30, 50);
			}
		}
	}
	//completes on round 5
	if (round >= 5)
	{
		sfw::drawString(font, "You picked the lock!", 300, 500, 10, 20);
		sfw::drawString(font, "Keep going of you want, but you don't need to.", 175, 475, 10, 20);
	}
	//sfw::drawString(font, round, 10, 10, 10, 20);

	//debug
	std::cout << round << "              " << alligned << "              " << myTrans.angle << std::endl;
	//char * rounds = " " + round;
	//sfw::drawString(font, round, 300, 500, 10, 20);
}
