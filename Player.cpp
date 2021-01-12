#include "Player.h"
void Player::levelUp()      // Upon leveling up increase the player's damage and level by 1
{
	++Player::m_level;
	++Player::m_damage;
}

bool Player::hasWon()       // The player wins upon getting to level 20
{
	return (Player::m_level == 20) ? true : false;
}

void Player::drinkPotion(const Potion& potion)  // The player drinks a randomly generated potion
{
    switch (potion.getType())
    {
    case PotionType::health:
        switch (potion.getSize())
        {
        case PotionSize::LARGE:
            m_health += 5;
            break;
        case PotionSize::MEDIUM:
            m_health += 3;
            break;
        case PotionSize::SMALL:
            m_health += 1;
            break;
        case PotionSize::max_size:
            break;
        }
        break;
    case PotionType::strength:
        switch (potion.getSize())
        {
        case PotionSize::LARGE:
            m_damage += 2;
            break;
        case PotionSize::MEDIUM:
        case PotionSize::SMALL:
            m_damage += 1;
            break;
        case PotionSize::max_size:
            break;
        }
        break;
    case PotionType::poison:
        reduceHealth(((potion.getSize() == PotionSize::LARGE) ? 2 : 1));
        break;

    case PotionType::max_potion:
        break;
    }
}