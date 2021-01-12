#include "PlayerDetails.h"

std::string getPlayerName()			// Gets the player's name and returns it
{
	std::string playerName{};
	do
	{
		std::cout << "Enter your name: ";
		std::cin >> playerName;

		if (!std::all_of(playerName.begin(), playerName.end(), std::isalpha) || static_cast<int>(playerName.size()) > 16)
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Invalid input, please try again.\n";
			playerName = "";
			continue;
		}
	} while (static_cast<int>(playerName.size()) < 3 || static_cast<int>(playerName.size()) > 16);

	return playerName;
}