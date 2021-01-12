#pragma once
#include "PlayerChoices.h"
#include "DrawGUI.h"
#include <windows.h>

void attackMonster(Player& player, Monster& monster);			// Attacks a monster
void monsterKilled(Player& player, const Monster& monster);		// Executed once the monster is dead
void attackPlayer(const Monster& monster, Player& player);		// Attacks a player