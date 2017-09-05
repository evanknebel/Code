#include <iostream>
#include <chrono>
#include <thread>
#include <random>
#include <time.h>
#include <Windows.h>
#include "functionsAndThings.h"
#include "combat.h"

//int TEXT_SPEED_CONVERSATION = 35;
//
//void openingText()
//{
//	int moveChoice = 0;
//	delay(TEXT_SPEED_CONVERSATION, "You find an enemy. Do you fight it?\n");
//	while (moveChoice < 1 || moveChoice > 2)
//	{
//		delay(TEXT_SPEED_CONVERSATION, "Choose\n1:Fight\n2:Run away");
//		std::cin >> moveChoice;
//
//		if (moveChoice == 1)
//		{
//			combat(player, enemy);
//		}
//		else if (moveChoice == 2)
//		{
//			delay(TEXT_SPEED_CONVERSATION, "You ran away like a big coward\n");
//		}
//		else
//		{
//			delay(TEXT_SPEED_CONVERSATION, "Please enter a number 1-2\n");
//		}
//	}
//}
