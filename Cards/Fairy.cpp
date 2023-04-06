#include "Fairy.h"

void Fairy::applyEncounter(Player& player) const
{
    printFairyMessage(player.isWizard());
    player.encounterFairy();
}


void Fairy::printCard(std::ostream &os) const
{
    printCardDetails(std::cout, "Fairy");
}

