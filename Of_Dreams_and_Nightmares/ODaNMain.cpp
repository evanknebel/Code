#include <iostream>
#include "combat.h"
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
	
	std::cout << "Your health is: " << p.HP << std::endl;
	std::cout << "Enemy health is: " << e.HP << std::endl;
	int moveChoice= 9;
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



///////////
int main()
{
	Player player = {5,20,5,50};
	Enemy enemy = {5,20,5,50};

	combat(player, enemy);
	while (true) {}
}