#include <iostream>
#include "lottoCards.h"
#include "time.h"
#include <random>

void seven()
{
	std::cout << " _______ " << std::endl;
	std::cout << "| _____ |" << std::endl;
	std::cout << "|     / |" << std::endl;
	std::cout << "|    /  |" << std::endl;
	std::cout << "|   /   |" << std::endl;
	std::cout << "|_______|" << std::endl;
}

void bar()
{
	std::cout << " _______ " << std::endl;
	std::cout << "|       |" << std::endl;
	std::cout << "| _____ |" << std::endl;
	std::cout << "||_BAR_||" << std::endl;
	std::cout << "|       |" << std::endl;
	std::cout << "|_______|" << std::endl;
}

void cherry()
{
	std::cout << " _______ " << std::endl;
	std::cout << "|       |" << std::endl;
	std::cout << "|  /^   |" << std::endl;
	std::cout << "| /  |  |" << std::endl;
	std::cout << "|() ()  |" << std::endl;
	std::cout << "|_______|" << std::endl;
}

void slotMachine()
{
	int rollOne;
	int rollTwo;
	int rollThree;
	
	std::cout << "" << std::endl;
	srand(time(NULL));
	rollOne = rand() % 3 + 1;
	std::cout << rollOne;
	srand(time(NULL) + time(NULL));
	rollTwo = rand() % 3 + 1;
	std::cout << rollTwo;
	srand(time(NULL) * time(NULL));
	rollThree = rand() % 3 + 1;
//	std::cout << rollThree << std::endl;

	if (rollOne == 1)
	{
		seven();
	}
	else if (rollOne == 2)
	{
		bar();
	}
	else if (rollOne == 3)
	{
		cherry();
	}

	if (rollTwo == 1)
	{
		seven();
	}
	else if (rollTwo == 2)
	{
		bar();
	}
	else if (rollTwo == 3)
	{
		cherry();
	}

	if (rollThree == 1)
	{
		seven();
	}
	else if (rollThree == 2)
	{
		bar();
	}
	else if (rollThree == 3)
	{
		cherry();
	}
}