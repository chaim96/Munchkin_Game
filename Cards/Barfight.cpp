#include "Barfight.h"

void Barfight::applyEncounter(Player& player) const
{
    printBarfightMessage(player.isFighter());
    player.encounterBarfight();
}


void Barfight::printCard(std::ostream &os) const
{
    printCardDetails(std::cout, "Barfight");
}
