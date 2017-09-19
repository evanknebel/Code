#include <iostream>
#include <chrono>
#include <thread>
#include <random>
#include <time.h>
#include <Windows.h>
#include "functionsAndThings.h"
#include "combat.h"
#include <fstream>
#include <string>

int SLEEP_TIME_COMMA = 200;
int SLEEP_TIME_DRAMA = 1000;
int TEXT_SPEED_CONVERSATION = 35;

void openingText(Player player, Enemy enemy)
{
	int moveChoice = 0;
////// INTRO
	delay(TEXT_SPEED_CONVERSATION, "You awaken in a field."); Sleep(SLEEP_TIME_COMMA); delay(TEXT_SPEED_CONVERSATION, " Thick grasses of gold and green surround you; flowers of\nred, yellow and purple are spotted throughout."); Sleep(500); delay(TEXT_SPEED_CONVERSATION, " After quick observation of the\nsurrounding area,"); Sleep(100);  delay(TEXT_SPEED_CONVERSATION, " a winding dirt path can be seen leading towards an impossibly\ntall mountain.\n"); Sleep(SLEEP_TIME_DRAMA); delay(TEXT_SPEED_CONVERSATION, "Standing up, you notice your neck is painfully sore, and you find you have been\nsleeping against an old wooden chest.\n"); Sleep(500); delay(TEXT_SPEED_CONVERSATION, "It appears to be unlocked.\n");
	delay(TEXT_SPEED_CONVERSATION, "Do you open it?\n\n");
	while (moveChoice < 1 || moveChoice > 2)
	{
////////// OPEN THE STARTING CHEST?	
		
		delay(TEXT_SPEED_CONVERSATION, "Choose\n1:Open the chest\n2:Leave that chest the hell alone. Shit's spooky.\n");
		std::cin >> moveChoice;
		//player.BLOOD_VIALS += 1;
		if (moveChoice == 1)
		{
			delay(TEXT_SPEED_CONVERSATION, "You open the chest"); delay(500, "...\n");
			Sleep(SLEEP_TIME_DRAMA);
			delay(TEXT_SPEED_CONVERSATION, "Inside the chest are two items: A spiked gauntlet, and a small dagger.\n");
			delay(TEXT_SPEED_CONVERSATION, "Which do you take?\n\n");
////////////// WHICH WEAPON TO TAKE?			
			moveChoice = 0;
			delay(TEXT_SPEED_CONVERSATION, "Choose\n1:The gauntlet. (HP +5, DEF +5)\n2:The dagger. (ATK +5, SPD +5)\n");
			while (moveChoice < 1 || moveChoice > 2)
			{
				std::cin >> moveChoice;
				if (moveChoice == 1)
				{
					delay(TEXT_SPEED_CONVERSATION, "You put on the gauntlet, still unsure how you got here or what this place is,\nbut happy to know that you have at least some protection.\n");
					player.HP += 5;
					player.MAX_HP += 55;
					player.DEF += 5;
				}
				else if (moveChoice == 2)
				{
					delay(TEXT_SPEED_CONVERSATION, "You pocket the dagger. You may not know how you got here or what this place is,\nbut if anybody knocked you out and brought you here, it's certainly not going\nto happen again.\n");
					player.ATK += 5;
					player.MAX_HP += 50;
					player.SPD += 5;
				}
				else
				{
					delay(TEXT_SPEED_CONVERSATION, "Please enter a number 1-2\n");
				}
				//delay(TEXT_SPEED_CONVERSATION, "You also grab a mysterious vial of blood.\n\n");
////////////////// FIRST FIGHT
				Sleep(SLEEP_TIME_DRAMA);
				delay(TEXT_SPEED_CONVERSATION, "A tiger-like creature, nearly the size of a horse leaps out of the tall grass.\n"); Sleep(300);  delay(TEXT_SPEED_CONVERSATION, "It has long saber-teeth, and three"); delay(550, "..."); Sleep(SLEEP_TIME_COMMA); delay(TEXT_SPEED_CONVERSATION, "axes? "); Sleep(400); delay(TEXT_SPEED_CONVERSATION, "Horns? "); Sleep(SLEEP_TIME_COMMA); delay(TEXT_SPEED_CONVERSATION, "On it's head. "); Sleep(300); delay(TEXT_SPEED_CONVERSATION, "Two on either\nside,"); Sleep(100); delay(TEXT_SPEED_CONVERSATION, " one on top running the length of it's skull, "); Sleep(100); delay(TEXT_SPEED_CONVERSATION, "and all evidently more than\nsharp enough to easily cut you in half.\n\n");
				delay(TEXT_SPEED_CONVERSATION, "How do you proceed?\n");
				moveChoice = 0;
				delay(TEXT_SPEED_CONVERSATION, "Choose\n1:Fight the beast\n2:Attempt to run away\n");
				while (moveChoice < 1 || moveChoice > 2)
				{
					std::cin >> moveChoice;
					if (moveChoice == 1)
					{
						enemy.ATK = 60;
						enemy.HP = 100;
						delay(TEXT_SPEED_CONVERSATION, "Here goes nothing\n\n");
						combat(player, enemy);
					}
					else if (moveChoice == 2)
					{
						delay(TEXT_SPEED_CONVERSATION, "You attempt to run, but the creature is too fast.\n");
					}
					else
					{
						delay(TEXT_SPEED_CONVERSATION, "Please enter a number 1-2\n");
					}
					delay(TEXT_SPEED_CONVERSATION, "As you fall to the ground, you notice something..."); Sleep(500); delay(TEXT_SPEED_CONVERSATION, " A small, "); Sleep(300); delay(TEXT_SPEED_CONVERSATION, "dead, "); Sleep(300); delay(TEXT_SPEED_CONVERSATION, "white mouse.\n");
					delay(TEXT_SPEED_CONVERSATION, "The beast rears back, and slices down hard, "); Sleep(SLEEP_TIME_COMMA); delay(TEXT_SPEED_CONVERSATION, "cutting you clean in half.\n");
					delay(TEXT_SPEED_CONVERSATION, "Done with you, "); Sleep(SLEEP_TIME_COMMA); delay(TEXT_SPEED_CONVERSATION, "and perhaps a bit prideful, "); Sleep(SLEEP_TIME_COMMA); delay(TEXT_SPEED_CONVERSATION, "it wanders away.\n");
					Sleep(SLEEP_TIME_DRAMA);
					delay(700, "...\n");
					delay(TEXT_SPEED_CONVERSATION, "");
					return;
				}
			}
		}
////////// LEAVE CHEST ALONE
		else if (moveChoice == 2)
		{
			delay(TEXT_SPEED_CONVERSATION, "You leave the chest alone. You don't even know where you are, how could you\nknow there isn't anything dangerous inside?\n");
			player.MAX_HP += 50;
		}
		else
		{
			delay(TEXT_SPEED_CONVERSATION, "Please enter a number 1-2\n");
		}
		Sleep(SLEEP_TIME_DRAMA);
		delay(TEXT_SPEED_CONVERSATION, "A tiger-like creature, nearly the size of a horse leaps out of the tall grass.\n"); Sleep(300);  delay(TEXT_SPEED_CONVERSATION, "It has long saber-teeth, and three"); delay(550, "..."); Sleep(SLEEP_TIME_COMMA); delay(TEXT_SPEED_CONVERSATION, "axes? "); Sleep(400); delay(TEXT_SPEED_CONVERSATION, "Horns? "); Sleep(SLEEP_TIME_COMMA); delay(TEXT_SPEED_CONVERSATION, "On it's head. "); Sleep(300); delay(TEXT_SPEED_CONVERSATION, "Two on either\nside,"); Sleep(100); delay(TEXT_SPEED_CONVERSATION, " one on top running the length of it's skull, "); Sleep(100); delay(TEXT_SPEED_CONVERSATION, "and all evidently more than\nsharp enough to easily cut you in half.\n\n");
		delay(TEXT_SPEED_CONVERSATION, "How do you proceed?\n");
		moveChoice = 0;
		delay(TEXT_SPEED_CONVERSATION, "Choose\n1:Fight the beast\n2:Attempt to run away\n");
		while (moveChoice < 1 || moveChoice > 2)
		{
			std::cin >> moveChoice;
///////////// FIRST FIGHT (WITHOUT WEAPON)
			if (moveChoice == 1)
			{
				enemy.ATK = 60;
				enemy.HP = 100;
				delay(TEXT_SPEED_CONVERSATION, "Brave as you may be, attempting to fight the creature with nothing but your\nbare fists doesn't accomplish much.\n");
			}
			else if (moveChoice == 2)
			{
				delay(TEXT_SPEED_CONVERSATION, "You attempt to run, but the creature is too fast.\n");
			}
			else
			{
				delay(TEXT_SPEED_CONVERSATION, "Please enter a number 1-2\n");
			}
			delay(TEXT_SPEED_CONVERSATION, "As you fall to the ground, you notice something..."); Sleep(500); delay(TEXT_SPEED_CONVERSATION, " A small, "); Sleep(300); delay(TEXT_SPEED_CONVERSATION, "dead, "); Sleep(300); delay(TEXT_SPEED_CONVERSATION, "white mouse.\n");
			delay(TEXT_SPEED_CONVERSATION, "The beast rears back, and slices down hard, "); Sleep(SLEEP_TIME_COMMA); delay(TEXT_SPEED_CONVERSATION, "cutting you clean in half.\n");
			delay(TEXT_SPEED_CONVERSATION, "Done with you, "); Sleep(SLEEP_TIME_COMMA); delay(TEXT_SPEED_CONVERSATION, "and perhaps a bit prideful, "); Sleep(SLEEP_TIME_COMMA); delay(TEXT_SPEED_CONVERSATION, "it wanders away.\n");
			Sleep(SLEEP_TIME_DRAMA);
			delay(700, "...\n");
			delay(TEXT_SPEED_CONVERSATION, "");
		}
	}
}
