#include "Rogue.h"

void Rogue::encounterPitfall(){} //does nothing


void Rogue::addCoins(const int coinsToAdd)
{
    Player::addCoins(2*coinsToAdd);
}

bool Rogue::isRogue() const { return true; }

void Rogue::printDetails() const
{
    printPlayerDetails(std::cout, m_name, "Rogue", m_level, m_force, m_HP, m_coins);
}