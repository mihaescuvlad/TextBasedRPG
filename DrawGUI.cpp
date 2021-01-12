#include "DrawGUI.h"

void showStats(Player player)
{
	const short length{ 54 }, height{ 22 };

	// Creating the main Status Box
	for (short iii = 0; iii < height; iii++)
		for (short jjj = 0; jjj < length; jjj++)
		{
			if (iii == 4 || iii == 17)
			{
			gotoXY(jjj, iii);
			std::cout << '#';
			}
			else if(iii > 17 && jjj == 26)
			{
				gotoXY(jjj, iii);
				std::cout << '#';
			}
			else if((iii > 0 && iii < height - 1) && (jjj > 0 && jjj < length - 1))
			{
				gotoXY(jjj, iii);
				std::cout << ' ';
			}
			else
			{
				gotoXY(jjj, iii);
				std::cout << '#';
			}
		}
	gotoXY(4, 1);
	std::cout << "Player Name:";
	gotoXY(4, 2);
	std::cout << player.getName();

	gotoXY(23, 1);
	std::cout << "Health:";
	gotoXY(25, 2);
	std::cout << player.getHealth();

	gotoXY(35, 1);
	std::cout << "Level:";
	gotoXY(37, 2);
	std::cout << player.getLevel();

	gotoXY(45, 1);
	std::cout << "Gold:";
	gotoXY(45, 2);
	std::cout << player.getGold();


	gotoXY(0, height+1);
}

void separator(bool setting)	// If the setting is true it will display a line, if its false it will delete the line
{
	if (setting)
	{
		for (short lin = 1; lin < 53; lin++)
		{
			gotoXY(lin, 8);
			std::cout << '=';
		}
	}
	else
		for (short lin = 1; lin < 53; lin++)
		{
			gotoXY(lin, 8);
			std::cout << ' ';
		}
}

void updateStats(Player player)
{
	for (short col = 25; col < 53; col++)
	{
		gotoXY(col, 2);
		std::cout << ' ';
	}

	gotoXY(25, 2);
	std::cout << player.getHealth();

	gotoXY(37, 2);
	std::cout << player.getLevel();

	gotoXY(45, 2);
	std::cout << player.getGold();
}

void clearGUI()
{
	for (short iii = 5; iii < 17; iii++)
		for (short jjj = 1; jjj < 53; jjj++)
		{
			gotoXY(jjj, iii);
			std::cout << ' ';
		}
}

void clearCombatZone()
{
	for (short iii = 9; iii < 17; iii++)
		for (short jjj = 1; jjj < 53; jjj++)
		{
			gotoXY(jjj, iii);
			std::cout << ' ';
		}
}