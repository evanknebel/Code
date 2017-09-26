#include <iostream>
#include "crenderutils.h"
#include "sfwdraw.h"
#include "Player.h"

//$(SolutionDir)Dependencies\lib\$(PlatformShortName)\$(Configuration)

int main()
{
	//create draw window
	sfw::initContext(800, 600, "SFW");

	//set background color
	sfw::setBackgroundColor(BLACK);

	//set game loop
	while (sfw::stepContext())
	{
		int P1X = 400;
		int P1Y = 300;
		//game goes here
		sfw::drawCircle(P1X, P1Y, 70);

		while (KEY_LEFT)
		{
			P1X--;
			sfw::drawCircle(P1X, P1Y, 70);
		}


	}

	//clean up
	sfw::termContext();


	system("pause");
	system("pause");
}