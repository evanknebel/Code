#include <iostream>
#include "combat.h"
#include <chrono>
#include <thread>
#include <random>
#include <time.h>
#include <Windows.h>
#include <string>

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


///////////
int main()
{
	// Player stats
	int PSpeed = 5;
	int PAttack = 20;
	int PDefense = 5;
	int PHealth = 50;

	// Enemy stats
	int ESpeed = 5;
	int EAttack = 20;
	int EDefense = 5;
	int EHealth = 35;
	
	// Combat actors
	Player player = {PSpeed,PAttack,PDefense,PHealth};
	Enemy enemy = {ESpeed,EAttack,EDefense,EHealth };

	combat(player, enemy);


	while (true){}
}