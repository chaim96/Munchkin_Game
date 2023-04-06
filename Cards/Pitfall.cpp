#include "Pitfall.h"


void Pitfall::applyEncounter(Player& player) const
{
    printPitfallMessage(player.isRogue());
    player.encounterPitfall();
}


void Pitfall::printCard(std::ostream &os) const
{
    printCardDetails(std::cout, "Pitfall");
}
