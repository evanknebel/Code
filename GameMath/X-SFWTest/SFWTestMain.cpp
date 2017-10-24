#include "sfwdraw.h"
#include "transform.h"
#include "Player.h"
#include "mat3.h"
#include "LockPick.h"
#include <cmath>
#include <iostream>
#include <ctime>


double defactoAngle;

int main()
{
	srand(time(NULL));
	sfw::initContext();

	Transform myTransform;
	myTransform.position = vec2{ 300,400 };
	myTransform.dimension = vec2{ 2,2 };
	myTransform.angle = 0;
	Lockpick lock(vec2{ 400,300 }, vec2{ 1,1 }, 0);
	while (sfw::stepContext())
	{
		lock.update();
		lock.draw();

		float t = sfw::getTime();
		//rotate clockwise
		//if (sfw::getKey(262))
		//{
		//	std::cout << defactoAngle << std::endl;
		//	myTransform.angle -= sfw::getDeltaTime() * 90;
		//	if (myTransform.angle >= 360)
		//	{
		//		myTransform.angle = 0;
		//	}
		//	else if (myTransform.angle <= 0)
		//	{
		//		myTransform.angle = 360;
		//	}
		//	defactoAngle = myTransform.angle;
		//}
		////rotate counterclockwise
		//if (sfw::getKey(263))
		//{
		//	std::cout << defactoAngle << std::endl;
		//	myTransform.angle += sfw::getDeltaTime() * 90;
		//	if (myTransform.angle > 360)
		//	{
		//		myTransform.angle = 0;
		//	}
		//	else if (myTransform.angle <= 0)
		//	{
		//		myTransform.angle = 360;
		//	}
		//	defactoAngle = myTransform.angle;
		//}

		//myTransform.dimension = vec2{ sinf(t) + 2, sinf(t) + 2 };

		//DrawMatrix(myTransform.getLocalTransform(), 80);

	}

	sfw::termContext();
}