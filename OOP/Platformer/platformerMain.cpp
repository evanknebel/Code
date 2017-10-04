#include <iostream>
#include "crenderutils.h"
#include "sfwdraw.h"
//$(SolutionDir)Dependencies\lib\$(PlatformShortName)\$(Configuration)

// sfw::getkey('')

//game window dimentions
int WINDOW_WIDTH = 1000;
int WINDOW_HEIGHT = 1800;

//movement speed (lateral)
int DEFAULT_SPEED = 10;
int P1SPEED = DEFAULT_SPEED;
int P2SPEED = 3;

//p1 character properties
int P1X = 400;
int P1Y = 71;
int P1RADIUS = 10;

//p2 character properties
int P2X = 700;
int P2Y = 235;
int P2RADIUS = 70;

//jump values
int JUMP_TIMER = 0;
bool isJumping = false;
bool isFalling = true;
int FALL_TIMER = 0;
int JUMP_SPEED = 10;
int JUMP_HEIGHT = 450;

//platform 1 properties
int PLATFORM_1_HEIGHT = 300;
int PLATFORM_1_WIDTH = 400;
int PLATFORM_1_BASE_POSITION = 80;
//platform 2 properties
int PLATFORM_2_HEIGHT = 600;
int PLATFORM_2_WIDTH = 250;
int PLATFORM_2_BASE_POSITION = 600;
//platform 3 properties
int PLATFORM_3_HEIGHT = 900;
int PLATFORM_3_WIDTH = 60;
int PLATFORM_3_BASE_POSITION = P1RADIUS * 2 + 1;

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
		//build platforms
		sfw::drawLine(PLATFORM_1_BASE_POSITION, PLATFORM_1_HEIGHT, PLATFORM_1_BASE_POSITION + PLATFORM_1_WIDTH, PLATFORM_1_HEIGHT);
		sfw::drawLine(PLATFORM_2_BASE_POSITION, PLATFORM_2_HEIGHT, PLATFORM_2_BASE_POSITION + PLATFORM_2_WIDTH, PLATFORM_2_HEIGHT);
		sfw::drawLine(PLATFORM_3_BASE_POSITION, PLATFORM_3_HEIGHT, PLATFORM_3_BASE_POSITION + PLATFORM_3_WIDTH, PLATFORM_3_HEIGHT);

		//debug
		std::cout << JUMP_TIMER << "                    " << FALL_TIMER << std::endl;


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
			if (isFalling == true)
			{
				if (JUMP_TIMER == 0)
				{
					if (FALL_TIMER == 0)
					{
						if (sfw::getKey(265))
						{
							JUMP_TIMER = JUMP_HEIGHT;
							isJumping = true;
						}
					}
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
				isFalling = true;
				FALL_TIMER = JUMP_HEIGHT;
			}
		}
		if (isJumping == false)
		{
			if (isFalling == true)
			{
				//
				if (FALL_TIMER <= JUMP_HEIGHT)
				{
					if (FALL_TIMER > 0)
					{
						P1Y -= JUMP_SPEED / 2;
						FALL_TIMER -= JUMP_SPEED;
					}
				}
				//
				if (P1Y > 0)
				{
					P1Y -= JUMP_SPEED / 2;
				}
			}
		}
		//platforms////////////////////////
		//platform 1
		if (P1Y - P1RADIUS >= PLATFORM_1_HEIGHT - JUMP_SPEED && P1Y + P1RADIUS <= PLATFORM_1_HEIGHT + P1RADIUS * 2)
		{
			if (P1X - P1RADIUS < PLATFORM_1_BASE_POSITION + PLATFORM_1_WIDTH && P1X + P1RADIUS > PLATFORM_1_BASE_POSITION)
			{
				P1Y = PLATFORM_1_HEIGHT + P1RADIUS;
			}
		}

		//platform 2
		if (P1Y - P1RADIUS >= PLATFORM_2_HEIGHT - JUMP_SPEED && P1Y + P1RADIUS <= PLATFORM_2_HEIGHT + P1RADIUS * 2)
		{
			if (P1X - P1RADIUS < PLATFORM_2_BASE_POSITION + PLATFORM_2_WIDTH && P1X + P1RADIUS > PLATFORM_2_BASE_POSITION)
			{
				P1Y = PLATFORM_2_HEIGHT + P1RADIUS;
			}
		}

		//platform 3
		if (P1Y - P1RADIUS >= PLATFORM_3_HEIGHT - JUMP_SPEED && P1Y + P1RADIUS <= PLATFORM_3_HEIGHT + P1RADIUS * 2)
		{
			if (P1X - P1RADIUS < PLATFORM_3_BASE_POSITION + PLATFORM_3_WIDTH && P1X + P1RADIUS > PLATFORM_3_BASE_POSITION)
			{
				P1Y = PLATFORM_3_HEIGHT + P1RADIUS;
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