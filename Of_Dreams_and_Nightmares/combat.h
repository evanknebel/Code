#pragma once

// Player stat holders
struct Player
{
	float SPD;
	float ATK;
	float DEF;
	float HP;
};

// Enemy stat holders
struct Enemy
{
	float SPD;
	float ATK;
	float DEF;
	float HP;
};

// Calculates damage done
float estimateDamage(int Damage, int Defense);

void playerParry(Player &p, Enemy &e);

void playerBlock(Player &p, Enemy &e);

void playerDodge(Player &p, Enemy &e);

//void enemyDodge(Enemy &e , Player &p);

void playerAttack(Player &p, Enemy &e);

void counterattack(Player &p, Enemy &e);