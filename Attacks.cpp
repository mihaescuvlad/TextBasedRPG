#include "Attacks.h"

void attackMonster(Player& player, Monster& monster)		// Used by the player to attack a monster
{
	if (monster.isDead())
		return;

	monster.reduceHealth(player.getDamage());

	gotoXY(11, 11);
	std::cout << "You hit the " << monster.getName() << " for " << player.getDamage() << " damage.";

	if (monster.isDead())
	{
		Sleep(2000);
		showStats(player);
		monsterKilled(player, monster);
	}
}

void monsterKilled(Player& player, const Monster& monster)	// The result of the monster's death
{
	gotoXY(16, 7);
	std::cout << "You killed the " << monster.getName() << '.';

	player.levelUp();

	gotoXY(16, 10);
	std::cout << "You are now level " << player.getLevel() << '.';
	gotoXY(18, 13);
	std::cout << "You found " << monster.getGold() << " gold.";
	player.addGold(monster.getGold());

		constexpr int potionChance{ 40 };	// 40% chance of dropping a potion then randomly generating a potion

		std::uniform_int_distribution dropChance(1, 100);
		if (dropChance(mersenne) <= potionChance && player.hasWon() == 0)
		{
			Sleep(2000);
			showStats(player);

			auto potion{ Potion::getRandomPotion() };

			gotoXY(12, 7);
			std::cout << "You found a mythical potion!";
			gotoXY(14, 10);
			std::cout << "Do you want to drink it?";
			gotoXY(2, 19);
			std::cout << "DO NOT DRINK POTION [N]";
			gotoXY(32, 19);
			std::cout << "DRINK  POTION [Y]";

			drinkChoice(player, potion);	// Asks the player about it's choice on drinking the potion or not
			updateStats(player);
		}
		else
		{
			updateStats(player);
			Sleep(2000);
		}
	
}

void attackPlayer(const Monster & monster, Player & player)	// Used by the monster to attack the player
{
	if (player.isDead())
		return;
	if (!monster.isDead())
	{
		player.reduceHealth(monster.getDamage());

		gotoXY(11, 14);
		std::cout << "The " << monster.getName() << " hit you for " << monster.getDamage() << " damage.";

		updateStats(player);
		Sleep(2000);
	}
}