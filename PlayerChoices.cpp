#include "PlayerChoices.h"

char battleChoice()		// Asks the player if he wants to fight the monster or run away from it
{
	char option;
	while (true)
	{
		gotoXY(4, 19);
		std::cout << "ATTEMPT TO RUN [R]";

		gotoXY(30, 19);
		std::cout << "ATTACK  CREATURE [F]";

		//std::cout << "Take your action:\n\t[R]Run or [F]Fight\n";
		option = static_cast<char>(_getch());

		if (option == 'f' || option == 'F')
		{
			return option;
		}
		if (option == 'r' || option == 'R')
		{
			return option;
		}
		else
		{
			//std::cout << "Invalid input, please try again.";
			continue;
		}
	}
}

void drinkChoice(Player& player, const Potion& potion)	// Asks the player if he wants to drink a mysterious potion or not
{
	while (true)
	{
		char option{ static_cast<char>(_getch()) };

		if (option == 'y' || option == 'Y')
		{
			player.drinkPotion(potion);

			// system("cls");		// Clear the console
			showStats(player);	// Show the Info Panel

			gotoXY(11, 8);
			std::cout << "You drank a " << potion.getName() << '\n';
			Sleep(2000);
			return;
		}

		if (option == 'n' || option == 'N')
		{
			showStats(player);	// Show the Info Panel
			return;
		}

		else
		{
			// std::cout << "Invalid input, please try again.\n";
			continue;
		}
	}
}

bool playAgain()	// Asks the player if he wants to play again
{
	Sleep(3000);	// Sleep for 3000 miliseconds
	clearGUI();
	// system("cls");	// Then clear the console

	gotoXY(17,8);
	std::cout << "Thanks for playing!";

	while (true)
	{
		gotoXY(13, 12);
		std::cout << "Would you like to play again?";

		gotoXY(3, 19);
		std::cout << "DO NOT PLAY AGAIN [N]";

		gotoXY(32, 19);
		std::cout << "PLAY   AGAIN [Y]";

		char option{ static_cast<char>(_getch()) };
		if (option == 'y' || option == 'Y')
		{
			system("cls");
			return true;
		}

		if (option == 'n' || option == 'N')
		{
			return false;
		}

		else
		{
			//system("cls");
			//std::cout << "Invalid input, please try again.\n";
			continue;
		}
	}

}