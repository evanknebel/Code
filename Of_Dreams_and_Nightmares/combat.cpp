#include <iostream>
#include <chrono>
#include <thread>
#include <random>
#include <time.h>
#include <Windows.h>
#include "functionsAndThings.h"
#include "combat.h"

float SLEEP_TIME = 200;
int TEXT_SPEED_COMBAT = 10;

float BLOCK_DAMAGE_REDUCTION = 0.6;
float DODGE_INVERT_PERCENT_CHANCE = 55;
float PARRY_DAMAGE_MULTIPLYER = 1.5;
float PARRY_INVERT_PERCENT_CHANCE = 75;
float SPEED_BONUS = 0.5;
float COUNTERATTACK_DAMAGE_REDUCTION = 0.8;
float COUNTERATTACK_INVERT_PERCENT_CHANCE = 30;

// Calculates damage done
float estimateDamage(int ATK, int DEF)
{
	if (ATK - DEF < 0)
	{
		return 0;
	}
	else
	{
		return ATK - DEF;
	}
}

// Calculates results of end of turn counterattack and prints results
void counterattack(Player &p, Enemy &e)
{
	srand(time(NULL));

	int pHitChance = (rand() % 100 + 1) + (p.SPD * SPEED_BONUS);
	if (p.HP > 0)
	{
		if (pHitChance > COUNTERATTACK_INVERT_PERCENT_CHANCE)
		{
			e.HP -= estimateDamage(p.ATK, e.DEF) * COUNTERATTACK_DAMAGE_REDUCTION;
			delay(TEXT_SPEED_COMBAT, "You hit the enemy for "); std::cout << estimateDamage(p.ATK, e.DEF) * COUNTERATTACK_DAMAGE_REDUCTION; delay(TEXT_SPEED_COMBAT, " hitpoints\n");
		}
		else
		{
			delay(TEXT_SPEED_COMBAT, "You failed your counterattack\n");
		}
	}
}

// Calculates consequences of player parrying and prints results
void playerParry(Player &p, Enemy &e)
{
	srand(time(NULL));

	int pHitChance = (rand() % 100 + 1) + (p.SPD * SPEED_BONUS);
	if (pHitChance >= PARRY_INVERT_PERCENT_CHANCE)
	{
		delay(TEXT_SPEED_COMBAT, "You parried the enemy's attack\n");
		e.HP -= estimateDamage(p.ATK, e.DEF) * PARRY_DAMAGE_MULTIPLYER;
		delay(TEXT_SPEED_COMBAT, "You hit the enemy for "); std::cout << estimateDamage(p.ATK, e.DEF) * PARRY_DAMAGE_MULTIPLYER; delay(TEXT_SPEED_COMBAT, " hitpoints\n");
	}
	else
	{
		delay(TEXT_SPEED_COMBAT, "You failed your parry\n");
		p.HP -= estimateDamage(e.ATK, p.DEF);
		delay(TEXT_SPEED_COMBAT, "You were hit for "); std::cout << estimateDamage(e.ATK, p.DEF); delay(TEXT_SPEED_COMBAT, " hitpoints\n");
		counterattack(p, e);
	}
}

// Calculates consequences of player dodging and prints results
void playerDodge(Player &p, Enemy &e)
{
	srand(time(NULL));

	int pHitChance = (rand() % 100 + 1) + (p.SPD * SPEED_BONUS);
	if (pHitChance > DODGE_INVERT_PERCENT_CHANCE)
	{
		delay(TEXT_SPEED_COMBAT, "You dodged the enemy's attack\n");
	}
	else
	{
		p.HP -= estimateDamage(e.ATK, p.DEF);
		delay(TEXT_SPEED_COMBAT, "You failed to dodge\n");
		delay(TEXT_SPEED_COMBAT, "You were hit for "); std::cout << estimateDamage(e.ATK, p.DEF); delay(TEXT_SPEED_COMBAT, " hitpoints\n");
		counterattack(p, e);
	}
}

// Calculates consequences of player blocking and prints results
void playerBlock(Player & p, Enemy & e)
{
	delay(TEXT_SPEED_COMBAT, "You blocked the enemy's attack\n");
	p.HP -= estimateDamage(e.ATK, p.DEF) * BLOCK_DAMAGE_REDUCTION;
	delay(TEXT_SPEED_COMBAT, "You were hit for "); std::cout << estimateDamage(e.ATK, p.DEF) * BLOCK_DAMAGE_REDUCTION; delay(TEXT_SPEED_COMBAT, " hitpoints\n");
	counterattack(p, e);
}

// Calculates consequences of player attacking and prints results
void playerAttack(Player & p, Enemy & e)
{
	e.HP -= estimateDamage(p.ATK, e.DEF);
	delay(TEXT_SPEED_COMBAT, "You hit the enemy for "); std::cout << estimateDamage(p.ATK, e.DEF); delay(TEXT_SPEED_COMBAT, " hitpoints\n");
	if (e.HP > 0)
	{
		p.HP -= estimateDamage(e.ATK, p.DEF);
		delay(TEXT_SPEED_COMBAT, "You were hit for "); std::cout << estimateDamage(e.ATK, p.DEF); delay(TEXT_SPEED_COMBAT, " hitpoints\n");
	}
}

/*
// Calculates consequences of enemy dodging and prints results
void enemyDodge(Enemy &e, Player &p)
{
	srand(time(NULL));

	int pHitChance = rand() % 100 + 1;
	if (pHitChance > e.SPD)
	{
		e.HP -= estimateDamage(p.ATK, e.DEF);
	}
	else
	{
		std::cout << "You Missed!" << std::endl;
	}
}
*/

void combat(Player &p, Enemy &e)
{
	delay(TEXT_SPEED_COMBAT, "Your health is: "); std::cout << p.HP << std::endl;
	delay(TEXT_SPEED_COMBAT, "Enemy health is: "); std::cout << e.HP << std::endl;
	while (p.HP > 0 && e.HP > 0)
	{
		int moveChoice = 0;
		while (moveChoice < 1 || moveChoice > 4)
		{
			delay(TEXT_SPEED_COMBAT, "Choose a move\n1:Attack\n2:Parry\n3:Dodge\n4:Block\n");
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
				delay(TEXT_SPEED_COMBAT, "Please enter a number 1-4\n");
			}

		}
		delay(TEXT_SPEED_COMBAT, "Your health is: "); std::cout << p.HP << std::endl;
		delay(TEXT_SPEED_COMBAT, "Enemy health is: "); std::cout << e.HP << std::endl;
	}
	if (p.HP < 0)
	{
		delay(TEXT_SPEED_COMBAT, "You died\n");
	}
	else if (e.HP < 0)
	{
		delay(TEXT_SPEED_COMBAT, "You killed the enemy\n");
	}
	//	e.HP = 35;
}