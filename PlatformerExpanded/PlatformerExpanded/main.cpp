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
//int P2SPEED = 3;

//p1 character properties
int P1RADIUS = 10;
int P1X = 0;
int P1Y = 0;

////p2 character properties
//int P2X = 700;
//int P2Y = 235;
//int P2RADIUS = 70;

//jump values
int JUMP_TIMER = 0;
bool isJumping = false;
int JUMP_SPEED = 10;
int JUMP_HEIGHT = 450;



/*
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
*/
/*
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
*/

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

class Platform
{
public:
	int basePosition;
	int width;
	int height;
};
Platform platform1, platform2, platform3;

struct Item
{
	int radius;
	int X;
	int Y;
	bool isCollected;
};
Item item1, item2, item3;

int main()
{
	//platform 1
	platform1.basePosition = 80;
	platform1.width = 400;
	platform1.height = 300;
	//platform 2
	platform2.basePosition = 600;
	platform2.width = 250;
	platform2.height = 600;
	//platform 3
	platform3.basePosition = P1RADIUS * 2 + 1;
	platform3.width = 60;
	platform3.height = 850;

	//item 1
	item1.radius = 4;
	item1.X = platform1.basePosition + (platform1.width / 2);
	item1.Y = platform1.height + P1RADIUS;
	item1.isCollected = false;
	//item 2
	item2.radius = 4;
	item2.X = platform2.basePosition + (platform2.width / 2);
	item2.Y = platform2.height + P1RADIUS;
	item2.isCollected = false;
	//item 3
	item3.radius = 4;
	item3.X = platform3.basePosition + (platform3.width / 2);
	item3.Y = platform3.height + P1RADIUS;
	item3.isCollected = false;

	//create draw window
	sfw::initContext(WINDOW_WIDTH, WINDOW_HEIGHT, "SFW");

	//set background color
	sfw::setBackgroundColor(BLACK);



	//set game loop
	while (sfw::stepContext())
	{
		//build platforms
		sfw::drawLine(platform1.basePosition, platform1.height, platform1.basePosition + platform1.width, platform1.height);
		sfw::drawLine(platform2.basePosition, platform2.height, platform2.basePosition + platform2.width, platform2.height);
		sfw::drawLine(platform3.basePosition, platform3.height, platform3.basePosition + platform3.width, platform3.height);

		//items
		//draw item 1 if not collected, and stop drawing when collected
		if (item1.isCollected == false)
		{
			sfw::drawCircle(item1.X, item1.Y, item1.radius);
		}
		if (item1.X >= P1X - P1RADIUS && item1.X <= P1X + P1RADIUS)
		{
			if (item1.Y >= P1Y - P1RADIUS && item1.Y <= P1Y + P1RADIUS)
			{
				item1.isCollected = true;
			}
		}
		//draw item 2 if not collected, and stop drawing when collected
		if (item2.isCollected == false)
		{
			sfw::drawCircle(item2.X, item2.Y, item2.radius);
		}
		if (item2.X >= P1X - P1RADIUS && item2.X <= P1X + P1RADIUS)
		{
			if (item2.Y >= P1Y - P1RADIUS && item2.Y <= P1Y + P1RADIUS)
			{
				item2.isCollected = true;
			}
		}
		//draw item 3 if not collected, and stop drawing when collected
		if (item3.isCollected == false)
		{
			sfw::drawCircle(item3.X, item3.Y, item3.radius);
		}
		if (item3.X >= P1X - P1RADIUS && item3.X <= P1X + P1RADIUS)
		{
			if (item3.Y >= P1Y - P1RADIUS && item3.Y <= P1Y + P1RADIUS)
			{
				item3.isCollected = true;
			}
		}

		//debug
		std::cout << JUMP_TIMER << "           " << P1X << "           " << P1Y << "           " << item1.isCollected << "           " << item1.isCollected << "           " << item3.isCollected << std::endl;


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
		if (P1Y - P1RADIUS >= platform1.height - JUMP_SPEED && P1Y + P1RADIUS <= platform1.height + P1RADIUS * 2)
		{
			if (P1X - P1RADIUS < platform1.basePosition + platform1.width && P1X + P1RADIUS > platform1.basePosition)
			{
				P1Y = platform1.height + P1RADIUS;
				canJump();
			}
		}

		//platform 2
		if (P1Y - P1RADIUS >= platform2.height - JUMP_SPEED && P1Y + P1RADIUS <= platform2.height + P1RADIUS * 2)
		{
			if (P1X - P1RADIUS < platform2.basePosition + platform2.width && P1X + P1RADIUS > platform2.basePosition)
			{
				P1Y = platform2.height + P1RADIUS;
				canJump();
			}
		}

		//platform 3
		if (P1Y - P1RADIUS >= platform3.height - JUMP_SPEED && P1Y + P1RADIUS <= platform3.height + P1RADIUS * 2)
		{
			if (P1X - P1RADIUS < platform3.basePosition + platform3.width && P1X + P1RADIUS > platform3.basePosition)
			{
				P1Y = platform3.height + P1RADIUS;
				canJump();
			}
		}
		////////end player 1 stuff

		//if (item3.isCollected == true)
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