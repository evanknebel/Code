#include <iostream>
#include "crenderutils.h"
#include "sfwdraw.h"
//$(SolutionDir)Dependencies\lib\$(PlatformShortName)\$(Configuration)

// sfw::getkey('')

int WINDOW_WIDTH = 800;
int WINDOW_HEIGHT = 600;

int DEFAULT_SPEED = 2;
int P1SPEED = DEFAULT_SPEED;
int P2SPEED = 3;

int P1X = 400;
int P1Y = 71;
int P1RADIUS = 70;

int P2X = 700;
int P2Y = 235;
int P2RADIUS = 70;

int JUMP_TIMER = 0;
bool isJumping = false;
bool isFalling = false;
int FALL_TIMER = 0;
int JUMP_SPEED = 10;
int JUMP_HEIGHT = 100;

void detectCollisionBoundries()
{

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
}
int main()
{
	//create draw window
	sfw::initContext(WINDOW_WIDTH, WINDOW_HEIGHT, "SFW");

	//set background color
	sfw::setBackgroundColor(BLACK);

	//set game loop
	while (sfw::stepContext())
	{


		////////player 1 stuff
		//bounderies
		detectCollisionBoundries();
		
		sfw::drawCircle(P1X, P1Y, P1RADIUS);

		//move left
		//263 is KEY_LEFT
		if (sfw::getKey(263))
		{
			P1X -= P1SPEED;
		}

		//move right
		//262 is KEY_RIGHT
		if (sfw::getKey(262))
		{
			P1X += P1SPEED;
		}

		////move down
		////264 is KEY_DOWN
		//if (sfw::getKey(264))
		//{
		//	P1Y -= P1SPEED;
		//}

		//jump/////////////////////////////
		//265 is KEY_UP
		if (isJumping == false)
		{
			if (JUMP_TIMER == 0)
			{
				if (sfw::getKey(265))
				{
					JUMP_TIMER = JUMP_HEIGHT;
					isJumping = true;
				}
			}
		}
		//rising motion
		if (isJumping == true)
		{
			if (JUMP_TIMER <= JUMP_HEIGHT)
			{
				if (JUMP_TIMER > 0)
				{
					P1Y += JUMP_SPEED;
					JUMP_TIMER -= JUMP_SPEED;
				}
			}
		//fall/////////////////////////////
		//clamping at 0 to prevent errors
			if (JUMP_TIMER <= 0)
			{
				JUMP_TIMER = 0;
				isJumping = false;
			}
		}
		if (isJumping == false)
		{
			if (P1Y > 0)
			{
				P1Y -= 5;
			}
		}
		////////end player 1 stuff
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