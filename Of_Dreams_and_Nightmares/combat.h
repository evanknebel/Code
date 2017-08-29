#pragma once

struct Player
{
	float SPD;
	float ATK;
	float DEF;
	float HP;
};

struct Enemy
{
	float SPD;
	float ATK;
	float DEF;
	float HP;
};

float EstimateDamage(int Damage, int Defense);

void parry();

void block();

void Playerdodge(Player &p, Enemy &e);

void EnemyDodger(Enemy &e , Player &p);

void ATK(Player &p, Enemy &e);

void counterattack();