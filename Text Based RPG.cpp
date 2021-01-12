#include "Libraries.h"		// the default libraries used
#include "PlayerDetails.h"	// used to get the player stats at the start of the game
#include "Functions.h"		// includes the main combat system
#include "LWconditions.h"	// includes the Loose or Win conditions

int main()
{
	while(true)
	{
		// Getting the player's stats
		Player mainPlayer{ getPlayerName() };
		std::cout << "Welcome " << mainPlayer.getName() << '\n';
		std::cout << "You have " << mainPlayer.getHealth() << " health and are carrying " << mainPlayer.getGold() << " gold.\n";
		
		Sleep(2000);

		// Starting an enemy encounter
		while (!mainPlayer.isDead() && !mainPlayer.hasWon())
		{
			fightMonster(mainPlayer);

			hasLostOrWon(mainPlayer);
		}

		if (playAgain())
			continue;
		else break;
	}
	return 0;
}
