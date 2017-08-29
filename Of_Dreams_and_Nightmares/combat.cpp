#include "combat.h"
#include <random>
#include <time.h>
#include <iostream>

float BLOCK_DAMAGE_REDUCTION = 0.6;
float COUNTERATTACK_INVERT_PERCENT_CHANCE = 30;
float DODGE_INVERT_PERCENT_CHANCE = 55;
float PARRY_DAMAGE_MULTIPLYER = 1.5;
float PARRY_INVERT_PERCENT_CHANCE = 75;
float SPEED_BONUS = 0.5;

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

// Calculates results of end of turn counterattack
void counterattack(Player &p, Enemy &e)
{
	srand(time(NULL));

	int pHitChance = (rand() % 100 + 1) + (p.SPD * SPEED_BONUS);
	if (pHitChance > COUNTERATTACK_INVERT_PERCENT_CHANCE)
	{
		e.HP -= estimateDamage(p.ATK, e.DEF);
		std::cout << "You hit the enemy for " << estimateDamage(p.ATK, e.DEF) << " hitpoints" << std::endl;
	}
	else
	{
		std::cout << "You failed your counterattack" << std::endl;
	}
}

// Calculates consequences of player parrying and prints results
void playerParry(Player &p, Enemy &e)
{
	srand(time(NULL));

	int pHitChance = (rand() % 100 + 1) + (p.SPD * SPEED_BONUS);
	if (pHitChance >= PARRY_INVERT_PERCENT_CHANCE)
	{
		std::cout << "You parried the enemy's attack" << std::endl;
		e.HP -= estimateDamage(p.ATK, e.DEF) * PARRY_DAMAGE_MULTIPLYER;
		std::cout << "You hit the enemy for " << estimateDamage(p.ATK, e.DEF) * PARRY_DAMAGE_MULTIPLYER << " hitpoints" << std::endl;
	}
	else
	{
		std::cout << "You failed your parry" << std::endl;
		p.HP -= estimateDamage(e.ATK, p.DEF);
		std::cout << "You were hit for " << estimateDamage(e.ATK, p.DEF) << " hitpoints" << std::endl;
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
		std::cout << "You dodged the enemy's attack" << std::endl;
	}
	else
	{
		p.HP -= estimateDamage(e.ATK, p.DEF);
		std::cout << "You failed to dodge" << std::endl;
		std::cout << "You were hit for " << estimateDamage(e.ATK, p.DEF) << " hitpoints" << std::endl;
		counterattack(p, e);
	}
}

// Calculates consequences of player blocking and prints results
void playerBlock(Player & p, Enemy & e)
{
	std::cout << "You blocked the enemy's attack" << std::endl;
	p.HP -= estimateDamage(e.ATK, p.DEF) * BLOCK_DAMAGE_REDUCTION;
	std::cout << "You were hit for " << estimateDamage(e.ATK, p.DEF) * BLOCK_DAMAGE_REDUCTION << " hitpoints" << std::endl;
	counterattack(p, e);
}

// Calculates consequences of player attacking and prints results
void playerAttack(Player & p, Enemy & e)
{
	e.HP -= estimateDamage(p.ATK, e.DEF);
	std::cout << "You hit the enemy for " << estimateDamage(p.ATK, e.DEF) << " hitpoints" << std::endl;
	p.HP -= estimateDamage(e.ATK, p.DEF);
	std::cout << "You were hit for " << estimateDamage(e.ATK, p.DEF) << " hitpoints" << std::endl;
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
