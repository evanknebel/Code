#include <iostream>

int runCount = 0;
int resetCount = 0;

void releaseHalfLove()
{
	while (resetCount <= 9)
	{
		runCount++;
		if (runCount >= 3)
		{
			runCount = 1;
			resetCount++;
		}
		std::cout << "The game, Half-Love " << runCount << ", was released!" << std::endl;
	}
	resetCount = 0;
	runCount = 0;
}

void callMeMaybe()
{
	while (resetCount <= 3)
	{
		runCount++;
		if (runCount = 1)
		{
			runCount++;
			resetCount++;
			std::cout << "Message number 1" << std::endl;
		}
		if (runCount = 2)
		{
			runCount++;
			resetCount++;
			std::cout << "Message 2" << std::endl;
		}
		if (runCount = 3)
		{
			runCount++;
			resetCount++;
			std::cout << "Third message" << std::endl;
		}
	}
	resetCount = 0;
	runCount = 0;
}




int main()
{
	releaseHalfLove();
	
	callMeMaybe();



	system("pause");
	system("pause");
}