#include "combat.h"
#include <random>
#include <time.h>
#include <iostream>
float EstimateDamage(int Damage, int Defense)
{
	if (Damage - Defense < 0)
	{
		return 0;
	}
	else
	{
		return Damage;
	}
}
void Playerdodge(Player &p, Enemy &e)
{
	srand(time(NULL));

	int eHitChance = rand() % 100 + 1;
	if (eHitChance > p.SPD)
	{
		p.HP -= EstimateDamage(e.ATK, p.DEF);
	}
	else
	{
		std::cout << "Enemy Missed!" << std::endl;
	}


}
void EnemyDodge(Enemy &e, Player &p)
{
	srand(time(NULL));

	int pHitChance = rand() % 100 + 1;
	if (pHitChance > e.SPD)
	{
		e.HP -= EstimateDamage(p.ATK, e.DEF);
	}
	else
	{
		std::cout << "You Missed!" << std::endl;
	}

}
void ATK(Player & p, Enemy & e)
{
	



	p.HP -= EstimateDamage(e.ATK,p.DEF);
	e.HP -= EstimateDamage(p.ATK, e.DEF);

}
