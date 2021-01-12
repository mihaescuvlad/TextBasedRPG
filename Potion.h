#pragma once
#include <string>
#include <array>

enum class PotionType	// All of the potions in the game
{
	health,
	strength,
	poison,
	max_potion
};

enum class PotionSize	// The sizes in which the potions come
{
	SMALL,
	MEDIUM,
	LARGE,
	max_size
};

class Potion
{
private:
	PotionType m_type{};
	PotionSize m_size{};
public:
	Potion(PotionType type, PotionSize size) :
		m_type{ type }, m_size{ size }
	{
	}

	static Potion getRandomPotion();	// Generates a random potion from the potion list with a random size

	// Getters
	std::string getPotionTypeName(PotionType type) const;
	std::string getPotionSizeName(PotionSize size) const;
	std::string getName() const;

	PotionType getType() const { return m_type; }
	PotionSize getSize() const { return m_size; }
};