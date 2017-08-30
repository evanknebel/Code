#include <iostream>
#include "combat.h"
#include <chrono>
#include <thread>
#include <random>
#include <time.h>
#include <Windows.h>

/*
Parry:
Base 25% chance. 1/2 speed added to percentage. Enters 100% counterattack. 50% damage
added to counterattack.
Failing results in full damage. Enters counterattack. No attack bonus.

Block:
Base 100% chance. Recieve 60% damage. Enters counterattack.

Dodge:
Base 45% chance. 1/2 speed added to percentage.
Failing results in full damage. Enters counterattack.

Attack:
Base 100% chance. Recieve full damage. Enters 100% counterattack.

Counterattack:
Base 70% chance. 1/2 speed added to percentage.
*/
void combat(Player &p, Enemy &e)
{
	
	/*
	for (int i = 0; i < strlen("hafjdsbnfljkwanbegiudshaiuhlfew;kafhafjdsbnfljkwanbegiudshaiuhlfew;kafhafjdsbnfljkwanbegiudshaiuhlfew;kafhafjdsbnfljkwanbegiudshaiuhlfew;kaf"); i++)
	{
	std::cout << "hafjdsbnfljkwanbegiudshaiuhlfew;kafhafjdsbnfljkwanbegiudshaiuhlfew;kafhafjdsbnfljkwanbegiudshaiuhlfew;kafhafjdsbnfljkwanbegiudshaiuhlfew;kaf"[i];
	//this_thread::sleep_for(chrono::milliseconds(millisec));
	Sleep(20);
	}
	*/

	std::cout << "Your health is: " << p.HP << std::endl;
	std::cout << "Enemy health is: " << e.HP << std::endl;
	while (p.HP > 0 && e.HP > 0)
	{
		int moveChoice = 0;
		while (moveChoice < 1 || moveChoice > 4)
		{
			std::cout << "Choose a move\n1:Attack\n2:Parry\n3:Dodge\n4:Block" << std::endl;
			std::cin >> moveChoice;

			if (moveChoice == 1)
			{
				playerAttack(p, e);
			}

			else if (moveChoice == 2)
			{
				playerParry(p, e);
			}

			else if (moveChoice == 3)
			{
				playerDodge(p, e);
			}

			else if (moveChoice == 4)
			{
				playerBlock(p, e);
			}

			else
			{
				std::cout << "Please enter a number 1-4" << std::endl;
			}

		}
		std::cout << "Your health is: " << p.HP << std::endl;
		std::cout << "Enemy health is: " << e.HP << std::endl;
	}
	if (p.HP < 0)
	{
		std::cout << "You died" << std::endl;
	}
	else if (e.HP < 0)
	{
		std::cout << "You killed the enemy" << std::endl;
	}
}



///////////
int main()
{
	//Player stats
	int PSpeed = 5;
	int PAttack = 20;
	int PDefense = 5;
	int PHealth = 50;

	//Enemy stats
	int ESpeed = 5;
	int EAttack = 20;
	int EDefense = 5;
	int EHealth = 35;
	//Combat actors
	Player player = {PSpeed,PAttack,PDefense,PHealth};
	Enemy enemy = {ESpeed,EAttack,EDefense,EHealth };

	combat(player, enemy);
	while (true){}
}