#include <iostream>
#include "combat.h"
/*
Parry:
Base 25% chance. 1/2 speed added to percentage. Enters 100% counterattack. 15% damage
added to counterattack.
Failing results in full damage. Enters counterattack. No attack bonus.

Block:
Base 100% chance. Recieve 20% damage. Enters counterattack.

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
	std::cout << p.HP << std::endl;
	int userInput;
	std::cout << "Choose a move \n1:Attack\n2:Dodge" << std::endl;
	std::cin >> userInput;

	if (userInput == 1)
	{
		ATK(p, e);
	}
	std::cout << p.HP << std::endl;
}



///////////
int main()
{
	Player dave = {5,20,5,50};
	Enemy kyle = { 5,20,5,50 };

	combat(dave, kyle);
	while (true) {}
}