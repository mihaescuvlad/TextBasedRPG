#include "Functions.h"

bool hasEscaped()
{
	std::uniform_int_distribution getChance (1, 100);
	short escapeChance{ static_cast<short>(getChance(mersenne)) };
	return (escapeChance > 50) ? true : false;
}

void fightMonster(Player& player)
{
	showStats(player);
	Monster monster{ Monster::getRandomMonster() };

	gotoXY(10, 6);
	std::cout << "You have encountered a " << monster.getName() << " (" << monster.getSymbol() << ")\n";
	separator(1);	// Draws a separating line in the center of the console

	while (!monster.isDead() && !player.isDead())
	{
		char option{ battleChoice() };			// Asks the player about its choice on fighting or running
		if (option == 'f' || option == 'F')
		{
			attackMonster(player, monster);
			attackPlayer(monster, player);
			clearCombatZone();
		}
		if (option == 'r' || option == 'R')		// Player runs away from the monster (50% success chance)
		{
			if (!hasEscaped())
			{
				gotoXY(18, 11);
				std::cout << "You failed to flee.";
				attackPlayer(monster, player);
				Sleep(1000);
				clearCombatZone();
			}
			else
			{
				showStats(player);
				gotoXY(16, 8);
				std::cout << "You successfully fled.";
				Sleep(1000);
				return;
			}
		}
	}
}