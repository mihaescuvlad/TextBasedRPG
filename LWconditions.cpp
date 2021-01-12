#include "LWconditions.h"

void hasLostOrWon(Player player)
{
	if (player.isDead())
	{
		showStats(player);
		gotoXY(8, 8);
		std::cout << "You died at level " << player.getLevel() << " and with " << player.getGold() << " gold.";
		gotoXY(9, 11);
		std::cout << "Too bad you can't take it with you!";
	}

	if (player.hasWon())				// Player wins once getting to level 20
	{
		showStats(player);
		gotoXY(12, 10);
		std::cout << "You won the game with " << player.getGold() << " gold!\n";
	}
}
