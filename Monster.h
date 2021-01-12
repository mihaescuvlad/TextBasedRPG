#pragma once
#include <array>
#include "Creature.h"
class Monster :
    public Creature
{
public:
    // A list of the monsters in the game
    enum class Type
    {
        slime,
        wolf,
        bandit,
        zombie,
        skeleton,
        orc,
        wyvern,
        dragon,
        max_monster
    };

private:
    // Providing a full stat block to the monsters with an initializer list
    static const Creature& getDefaultCreature(Type type)
    {
        static std::array<Creature, static_cast<std::size_t>(Type::max_monster)> monsterData{
            // N = Name
            // S = Symbol
            // H = Health
            // D = Damage
            // G = Gold
            //    N        S    H  D   G
           { { "slime",   's',  1, 1,  10 },
             { "wolf",    'w',  2, 1,  15 },
             { "bandit",  'b',  2, 2, 105 },
             { "zombie",  'z',  7, 2,  25 },
             { "skeleton",'S',  4, 3,  30 },
             { "orc",     'o', 14, 4,  50 },
             { "wyvern",  'w', 18, 5,  70 },
             { "dragon",  'D', 25, 6, 250 }     }
        };

        return monsterData.at(static_cast<std::size_t>(type));
    }
public:
    Monster(Type type) :
        Creature{ getDefaultCreature(type) }
    {
    }

    static Monster getRandomMonster();  // Generates a random monster using it's stat block
};

