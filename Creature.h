#pragma once
#include <string>

class Creature
{
protected:
	std::string m_name;
	char		m_symbol;

	int			m_health, m_damage;

	short		m_gold;
public:
	Creature(const std::string& name, const char symbol, int health, int damage, short gold) :
		m_name{ name }, 
		m_symbol{ symbol }, 
		m_health{ health }, 
		m_damage{ damage }, 
		m_gold{ gold }
	{
	}

	void reduceHealth(int hitpoints);	// Reduces the health of the creature
	void addGold(short loot);			// Adds gold to the creature
	bool isDead() const;				// Checks if the creature is Dead, returns 1 if true

	// Getters
	const std::string& getName() const { return m_name; }
	char getSymbol() const { return m_symbol; }
	int getHealth() const { return m_health; }
	int getDamage() const { return m_damage; }
	short getGold() const { return m_gold; }
};

