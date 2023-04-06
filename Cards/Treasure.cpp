#include "../Players/Player.h"
#include "Treasure.h"
#define TREASURE_SIZE 10


void Treasure::applyEncounter(Player& player) const
{
    printTreasureMessage();
    player.addCoins(TREASURE_SIZE);
}

void Treasure::printCard(std::ostream &os) const
{
    printCardDetails(std::cout, "Treasure");
}
