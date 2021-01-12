#include "Randomizer.h"

std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };