#include <iostream>
#include "crenderutils.h"
#include "sfwdraw.h"
#include "Player.h"

//$(SolutionDir)Dependencies\lib\$(PlatformShortName)\$(Configuration)

// sfw::getkey('')


int main()
{
	//create draw window
	int WINDOW_WIDTH = 800;
	int WINDOW_HEIGHT = 600;
	sfw::initContext(WINDOW_WIDTH, WINDOW_HEIGHT, "SFW");

	//set background color
	sfw::setBackgroundColor(BLACK);
	int DEFAULT_SPEED = 2;
	int P1SPEED = DEFAULT_SPEED;
	int P2SPEED = 3;

	int P1X = 400;
	int P1Y = 300;
	int P1RADIUS = 70;

	int P2X = 700;
	int P2Y = 235;
	int P2RADIUS = 70;

	//set game loop
	while (sfw::stepContext())
	{
////////player 1 stuff
		//bounderies
		if (P1X + P1RADIUS > WINDOW_WIDTH)
		{
			P1X = WINDOW_WIDTH - P1RADIUS;
		}
		if (P1X - P1RADIUS < 0)
		{
			P1X = 0 + P1RADIUS;
		}
		if (P1Y + P1RADIUS > WINDOW_HEIGHT)
		{
			P1Y = WINDOW_HEIGHT - P1RADIUS;
		}
		if (P1Y - P1RADIUS < 0)
		{
			P1Y = 0 + P1RADIUS;
		}
		sfw::drawCircle(P1X, P1Y, P1RADIUS);

		//263 is KEY_LEFT
		if (sfw::getKey(263))
		{
			P1X -= P1SPEED;
		}
		//262 is KEY_RIGHT
		if (sfw::getKey(262))
		{
			P1X += P1SPEED;
		}
		//264 is KEY_DOWN
		if (sfw::getKey(264))
		{
			P1Y -= P1SPEED;
		}
		//265 is KEY_UP
		if (sfw::getKey(265))
		{
			P1Y += P1SPEED;
		}
////////end player 1 stuff
////////player 2 stuff
		//bounderies
		if (P2X + P2RADIUS > WINDOW_WIDTH)
		{
			P2X = WINDOW_WIDTH - P2RADIUS;
		}
		if (P2X - P2RADIUS < 0)
		{
			P2X = 0 + P2RADIUS;
		}
		if (P2Y + P2RADIUS > WINDOW_HEIGHT)
		{
			P2Y = WINDOW_HEIGHT - P2RADIUS;
		}
		if (P2Y - P2RADIUS < 0)
		{
			P2Y = 0 + P2RADIUS;
		}

		sfw::drawCircle(P2X, P2Y, P2RADIUS);
		//left
		if (sfw::getKey('A'))
		{
			P2X -= P2SPEED;
		}
		//right
		if (sfw::getKey('D'))
		{
			P2X += P2SPEED;
		}
		//down
		if (sfw::getKey('S'))
		{
			P2Y -= P2SPEED;
		}
		//up
		if (sfw::getKey('W'))
		{
			P2Y += P2SPEED;
		}
		////////end player 2 stuff
		
		if (P1Y == P2Y && P1X == P2X)
		{
			break;
		}
	}
	std::cout << "Congradulation" << std::endl << "a winner is you" << std::endl;

	//clean up
	sfw::termContext();


	system("pause");
	system("pause");
	system("pause");
	system("pause");
	system("pause");
	system("pause");
}