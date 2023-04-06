#include "Wizard.h"

void Wizard::encounterFairy()
{
    Wizard::heal(HP_ADD);
}

void Wizard::heal(const int healPoints)
{
    Player::heal(2*healPoints);
}

bool Wizard::isWizard() const { return true; }

void Wizard::printDetails() const
{
    printPlayerDetails(std::cout, m_name, "Wizard", m_level, m_force, m_HP, m_coins);
}