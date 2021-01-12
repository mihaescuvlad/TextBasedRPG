#pragma once
#include "Creature.h"
#include "Potion.h"

class Player :
    public Creature
{
private:
    short m_level{1};
public:
    Player(const std::string& name):
        Creature(name, '@', 10, 1, 0)
    {
    }

    void levelUp();     // Player levels up after killing one monster
                        // If the player levels up it's Damage and Level increase by 1
    bool hasWon();      // Checks to see if the player ahs won (reached level 20)

    void drinkPotion(const Potion& potion);     // Drinks a randomly geSnerated potion from a monster
    
    // Level Getter
    short getLevel() { return m_level; }
};

