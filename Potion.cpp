#include "Potion.h"
#include "Randomizer.h"

std::string Potion::getPotionTypeName(PotionType type) const        // Getter for the potion type
{
    static constexpr std::array names{
      "Health",
      "Strength",
      "Poison"
    };

    return names.at(static_cast<std::size_t>(type));
}

std::string Potion::getPotionSizeName(PotionSize size) const        // Getter for the potion size
{
    static constexpr std::array names{
      "Small",
      "Medium",
      "Large"
    };

    return names.at(static_cast<std::size_t>(size));
}

std::string Potion::getName() const                                 // Getter for the potion name
{
    std::string name{ getPotionSizeName(getSize()) + " potion of " + getPotionTypeName(getType())  };

    return name;
}

Potion Potion::getRandomPotion()                                    // Random potion generator
{
    std::uniform_int_distribution randType(0, static_cast<int>(PotionType::max_potion) - 1);
    std::uniform_int_distribution randSize(0, static_cast<int>(PotionSize::max_size) - 1);

    return {
      static_cast<PotionType>(randType(mersenne)),
      static_cast<PotionSize>(randSize(mersenne))
    };
}