#include "Vampire.h"


void Vampire::applyEncounter(Player& player) const
{
    if (player.getAttackStrength() >= VAMPIRE_POWER)
    {
        Vampire::winBattle(player);
        player.levelUp();
        printWinBattle(player.getName(),"Vampire");
    }
    else
    {
        Vampire::loseBattle(player);


    }
}
void Vampire::winBattle(Player &player) const
{
    player.addCoins(VAMPIRE_LOOT);


}
void Vampire::loseBattle(Player &player) const
{
    player.damage(VAMPIRE_DAMAGE);
    player.buff(VAMPIRE_LEVEL_REDUCTION);
    printLossBattle(player.getName(),"Vampire");


}

void Vampire::printMonster() const {
    printMonsterDetails(std::cout, VAMPIRE_POWER, VAMPIRE_DAMAGE, VAMPIRE_LOOT);
}

void Vampire::printCard(std::ostream &os) const
{
    printCardDetails(std::cout, "Vampire");
    printMonsterDetails(std::cout, VAMPIRE_POWER, VAMPIRE_DAMAGE, VAMPIRE_LOOT);
}

void Vampire::autoLose(Player &player) const {
    player.damage(VAMPIRE_DAMAGE);
    player.buff(VAMPIRE_LEVEL_REDUCTION);
    printLossBattle(player.getName(),"Dragon");

}

bool Vampire::isWin(Player &player) const {
    if (player.getAttackStrength() >= VAMPIRE_POWER) {
        return true;
    }
    return false;
}
