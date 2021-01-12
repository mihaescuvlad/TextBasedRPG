#include "Monster.h"
#include "Randomizer.h"

Monster Monster::getRandomMonster()		// Generates a random monster
{
	std::uniform_int_distribution monsterID (0, static_cast<int>(Type::max_monster)-1);
	Monster::Type monster{ static_cast<Type>(monsterID(mersenne)) };

	return monster;
}