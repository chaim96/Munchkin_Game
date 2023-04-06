#include "Goblin.h"


void Goblin::applyEncounter(Player& player) const
{
    if(player.getAttackStrength() >= GOBLIN_POWER)
    {
        Goblin::winBattle(player);
        player.levelUp();
        printWinBattle(player.getName(),"Goblin");

    }
    else
    {
        Goblin::loseBattle(player);



    }
}
void Goblin::winBattle(Player &player) const
{
    player.addCoins(GOBLIN_LOOT);


}
void Goblin::loseBattle(Player &player) const
{
    player.damage(GOBLIN_DAMAGE);
    printLossBattle(player.getName(),"Goblin");


}
void Goblin::printMonster() const {
    printMonsterDetails(std::cout, GOBLIN_POWER, GOBLIN_DAMAGE, GOBLIN_LOOT);
}

void Goblin::printCard(std::ostream &os) const
{
    printCardDetails(std::cout, "Goblin");
    printMonsterDetails(std::cout, GOBLIN_POWER, GOBLIN_DAMAGE, GOBLIN_LOOT);
}

void Goblin::autoLose(Player &player) const {
    player.damage(GOBLIN_DAMAGE);
    printLossBattle(player.getName(),"Dragon");

}

bool Goblin::isWin(Player &player) const {
    if (player.getAttackStrength() >= GOBLIN_POWER) {
        return true;
    }
    return false;
}
