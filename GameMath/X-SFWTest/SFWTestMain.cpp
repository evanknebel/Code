#include "player.h"

#include "sfwdraw.h"

int main()
{
	sfw::initContext();

	Player P1;
	P1.pos = { 400, 300 };

	while (sfw::stepContext())
	{
		P1.update();
		P1.draw();
	}
	sfw::termContext();
}

