#include "Fighter.h"


void Fighter::encounterBarfight() {} // does nothing


int Fighter::getAttackStrength() const
{
    return this->m_level + 2*this->m_force;
}

bool Fighter::isFighter() const { return true; }

void Fighter::printDetails() const
{
    printPlayerDetails(std::cout, m_name, "Fighter", m_level, m_force, m_HP, m_coins);
}