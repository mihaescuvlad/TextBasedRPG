#pragma once
#include <iostream>
#include <conio.h>
#include <windows.h>
#include "Creature.h"
#include "Player.h"
#include "Monster.h"
#include "Randomizer.h"
#include "DrawGUI.h"

char battleChoice();										// Asks the player if he/she wants to fight or flee
void drinkChoice(Player& player, const Potion& potion);		// Asks the player if they wish to drink a mysterious potion
bool playAgain();