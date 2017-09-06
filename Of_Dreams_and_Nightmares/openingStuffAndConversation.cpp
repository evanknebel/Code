#include <iostream>
#include <chrono>
#include <thread>
#include <random>
#include <time.h>
#include <Windows.h>
#include "functionsAndThings.h"
#include "combat.h"

float SLEEP_TIME = 1000;
int TEXT_SPEED_CONVERSATION = 35;

void openingText(Player player, Enemy enemy)
{
	int moveChoice = 0;
// INTRO
	delay(TEXT_SPEED_CONVERSATION, "You awaken in a field of long grasses.\n"); Sleep(SLEEP_TIME); delay(TEXT_SPEED_CONVERSATION, "Your neck is painfully sore, and you find you have been sleeping against\nan old wooden chest.\nIt appears to be unlocked.\n");
	delay(TEXT_SPEED_CONVERSATION, "Do you open it?\n");
	while (moveChoice < 1 || moveChoice > 2)
	{
// OPEN THE STARTING CHEST?	
		delay(TEXT_SPEED_CONVERSATION, "Choose\n1:Open the chest\n2:Leave that chest the hell alone. Shit's spooky.\n");
		std::cin >> moveChoice;
		player.BLOOD_VIALS += 1;
		if (moveChoice == 1)
		{
			delay(TEXT_SPEED_CONVERSATION, "You open the chest"); delay(500, "...\n");
			Sleep(SLEEP_TIME);
			delay(TEXT_SPEED_CONVERSATION, "Inside the chest are two items: A spiked gauntlet, and a small dagger.\n");
			delay(TEXT_SPEED_CONVERSATION, "Which do you take?\n");
// WHICH WEAPON TO TAKE?			
			moveChoice = 0;
			delay(TEXT_SPEED_CONVERSATION, "Choose\n1:The gauntlet. (HP +5, DEF +5)\n2:The dagger. (ATK +5, SPD +5)\n");
			while (moveChoice < 1 || moveChoice > 2)
			{
				std::cin >> moveChoice;
				if (moveChoice == 1)
				{
					delay(TEXT_SPEED_CONVERSATION, "You put on the gauntlet, still unsure how you got here or what this place is,\nbut happy to know that you have at least some protection.\nYou also grab a mysterious vial of blood.\n");
					player.HP += 5;
					player.DEF += 5;
				}
				else if (moveChoice == 2)
				{
					delay(TEXT_SPEED_CONVERSATION, "You pocket the dagger. You may not know how you got here or what this place is,\nbut if anybody knocked you out and brought you here, it's certainly not going\nto happen again.\nYou also grab a mysterious vial of blood.\n");
					player.ATK += 5;
					player.SPD += 5;
				}
				else
				{
					delay(TEXT_SPEED_CONVERSATION, "Please enter a number 1-2\n");
				}
// FIRST FIGHT
				delay(TEXT_SPEED_CONVERSATION, "You see a large tiger running at you.\n");
				delay(TEXT_SPEED_CONVERSATION, "How do you proceed?\n");
				moveChoice = 0;
				delay(TEXT_SPEED_CONVERSATION, "Choose\n1:Fight the beast\n2:Run away\n");
				while (moveChoice < 1 || moveChoice > 2)
				{
					std::cin >> moveChoice;
					if (moveChoice == 1)
					{
						delay(TEXT_SPEED_CONVERSATION, "Here goes nothing\n\n");
						combat(player, enemy);
					}
					else if (moveChoice == 2)
					{
						delay(TEXT_SPEED_CONVERSATION, "You attempt to run, but the tiger is too fast. It catches you.\nADVENTURE OVER\n");
					}
					else
					{
						delay(TEXT_SPEED_CONVERSATION, "Please enter a number 1-2\n");
					}
				}
			}
		}
// COWARD OUT
		else if (moveChoice == 2)
		{
			delay(TEXT_SPEED_CONVERSATION, "You ran away like a big coward, never to be seen again.\nADVENTURE OVER\n");
		}
		else
		{
			delay(TEXT_SPEED_CONVERSATION, "Please enter a number 1-2\n");
		}
	}
}
