#include <iostream>
#include "crenderutils.h"
#include "sfwdraw.h"
//$(SolutionDir)Dependencies\lib\$(PlatformShortName)\$(Configuration)

// sfw::getkey('')

//game window dimentions
int WINDOW_WIDTH = 1000;
int WINDOW_HEIGHT = 1000; //1400

//movement speed (lateral)
int DEFAULT_SPEED = 9;
int P1SPEED = DEFAULT_SPEED;
int P2SPEED = 3;

//p1 character properties
int P1RADIUS = 10;
int P1X = 0;
int P1Y = 0;

//p2 character properties
int P2X = 700;
int P2Y = 235;
int P2RADIUS = 70;

//jump values
int JUMP_TIMER = 0;
bool isJumping = false;
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
int PLATFORM_3_HEIGHT = 850;
int PLATFORM_3_WIDTH = 60;
int PLATFORM_3_BASE_POSITION = P1RADIUS * 2 + 1;

//item properties
int ITEM_DEFAULT_RADIUS = 4;
//item 1 properties
int ITEM_1_RADIUS = ITEM_DEFAULT_RADIUS;
int ITEM_1_X = PLATFORM_1_BASE_POSITION + (PLATFORM_1_WIDTH / 2);
int ITEM_1_Y = PLATFORM_1_HEIGHT + P1RADIUS;
bool isItem1Collected = false;
//item 2 properties
int ITEM_2_RADIUS = ITEM_DEFAULT_RADIUS;
int ITEM_2_X = PLATFORM_2_BASE_POSITION + (PLATFORM_2_WIDTH / 2);
int ITEM_2_Y = PLATFORM_2_HEIGHT + P1RADIUS;
bool isItem2Collected = false;
//item 3 properties
int ITEM_3_RADIUS = ITEM_DEFAULT_RADIUS;
int ITEM_3_X = PLATFORM_3_BASE_POSITION + (PLATFORM_3_WIDTH / 2);
int ITEM_3_Y = PLATFORM_3_HEIGHT + P1RADIUS;
bool isItem3Collected = false;

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

void canJump()
{
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

		//items
		//draw item 1 if not collected, and stop drawing when collected
		if (isItem1Collected == false)
		{
			sfw::drawCircle(ITEM_1_X, ITEM_1_Y, ITEM_1_RADIUS);
		}
		if (ITEM_1_X >= P1X - P1RADIUS && ITEM_1_X <= P1X + P1RADIUS)
		{
			if (ITEM_1_Y >= P1Y - P1RADIUS && ITEM_1_Y <= P1Y + P1RADIUS)
			{
				isItem1Collected = true;
			}
		}
		//draw item 2 if not collected, and stop drawing when collected
		if (isItem2Collected == false)
		{
			sfw::drawCircle(ITEM_2_X, ITEM_2_Y, ITEM_2_RADIUS);
		}
		if (ITEM_2_X >= P1X - P1RADIUS && ITEM_2_X <= P1X + P1RADIUS)
		{
			if (ITEM_2_Y >= P1Y - P1RADIUS && ITEM_2_Y <= P1Y + P1RADIUS)
			{
				isItem2Collected = true;
			}
		}
		//draw item 3 if not collected, and stop drawing when collected
		if (isItem3Collected == false)
		{
			sfw::drawCircle(ITEM_3_X, ITEM_3_Y, ITEM_3_RADIUS);
		}
		if (ITEM_3_X >= P1X - P1RADIUS && ITEM_3_X <= P1X + P1RADIUS)
		{
			if (ITEM_3_Y >= P1Y - P1RADIUS && ITEM_3_Y <= P1Y + P1RADIUS)
			{
				isItem3Collected = true;
			}
		}

		//debug
		std::cout << JUMP_TIMER << "           " << P1X << "           " << P1Y << "           " << isItem1Collected << "           " << isItem2Collected << "           " << isItem3Collected << std::endl;


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

		//move down
		//264 is KEY_DOWN
		if (sfw::getKey(264))
		{
			P1Y -= 0.00001;
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
					P1Y -= JUMP_SPEED;
				}
		}
		//platforms////////////////////////
		//ground
		if (P1Y - P1RADIUS >= 0 - JUMP_SPEED && P1Y + P1RADIUS <= 0 + P1RADIUS * 2)
		{
			if (P1X - P1RADIUS < 0 + WINDOW_WIDTH && P1X + P1RADIUS > 0)
			{
				canJump();
			}
		}
		
		//platform 1
		if (P1Y - P1RADIUS >= PLATFORM_1_HEIGHT - JUMP_SPEED && P1Y + P1RADIUS <= PLATFORM_1_HEIGHT + P1RADIUS * 2)
		{
			if (P1X - P1RADIUS < PLATFORM_1_BASE_POSITION + PLATFORM_1_WIDTH && P1X + P1RADIUS > PLATFORM_1_BASE_POSITION)
			{
				P1Y = PLATFORM_1_HEIGHT + P1RADIUS;
				canJump();
			}
		}

		//platform 2
		if (P1Y - P1RADIUS >= PLATFORM_2_HEIGHT - JUMP_SPEED && P1Y + P1RADIUS <= PLATFORM_2_HEIGHT + P1RADIUS * 2)
		{
			if (P1X - P1RADIUS < PLATFORM_2_BASE_POSITION + PLATFORM_2_WIDTH && P1X + P1RADIUS > PLATFORM_2_BASE_POSITION)
			{
				P1Y = PLATFORM_2_HEIGHT + P1RADIUS;
				canJump();
			}
		}

		//platform 3
		if (P1Y - P1RADIUS >= PLATFORM_3_HEIGHT - JUMP_SPEED && P1Y + P1RADIUS <= PLATFORM_3_HEIGHT + P1RADIUS * 2)
		{
			if (P1X - P1RADIUS < PLATFORM_3_BASE_POSITION + PLATFORM_3_WIDTH && P1X + P1RADIUS > PLATFORM_3_BASE_POSITION)
			{
				P1Y = PLATFORM_3_HEIGHT + P1RADIUS;
				canJump();
			}
		}
		////////end player 1 stuff

		//if (isItem3Collected == true)
		//{
		//	break;
		//}

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