#include "Creature.h"

void Creature::reduceHealth(int hitpoints)
{
	Creature::m_health -= hitpoints;
}

void Creature::addGold(short loot)
{
	Creature::m_gold += loot;
}

/// <summary>
/// returneaza ceva creatura
/// </summary>
/// <returns></returns>
bool Creature::isDead() const
{
	return (Creature::m_health <= 0) ? true : false; 
}