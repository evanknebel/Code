#pragma once
#include <string>

// Prints text slowly in a string
void delay(int delay, std::string text);

/*Combat*////////////////////////////////
// Player stat holders
struct Player
{
	float SPD;
	float ATK;
	float DEF;
	float HP;
	int BLOOD_VIALS;
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
float estimateDamage(int ATK, int DEF);

void playerParry(Player &p, Enemy &e);

void playerBlock(Player &p, Enemy &e);

void playerDodge(Player &p, Enemy &e);

//void enemyDodge(Enemy &e , Player &p);

void playerAttack(Player &p, Enemy &e);

void counterattack(Player &p, Enemy &e);

void combat(Player &p, Enemy &e);
/*End of combat*/////////////////////////

void openingText(Player player, Enemy enemy);