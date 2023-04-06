#include "Dragon.h"


void Dragon::applyEncounter(Player& player) const
{
    if (player.getAttackStrength() >= DRAGON_POWER)
    {
        Dragon::winBattle(player);
        player.levelUp();
    }
    else
    {
        Dragon::loseBattle(player);

    }
}
void Dragon::winBattle(Player &player) const
{

    player.addCoins(DRAGON_LOOT);
    printWinBattle(player.getName(),"Dragon");



}
void Dragon::loseBattle(Player &player) const
{
    player.damage(player.getMaxHP());
    printLossBattle(player.getName(),"Dragon");


}

void Dragon::printMonster() const {
    printMonsterDetails(std::cout, DRAGON_POWER, DRAGON_DAMAGE, DRAGON_LOOT, true);
}


void Dragon::printCard(std::ostream &os) const
{
    printCardDetails(std::cout, "Dragon");
    printMonsterDetails(std::cout, DRAGON_POWER, DRAGON_DAMAGE, DRAGON_LOOT, true);
}

void Dragon::autoLose(Player &player) const {
    player.damage(player.getMaxHP());
    printLossBattle(player.getName(),"Dragon");

}

bool Dragon::isWin(Player &player) const {
    if (player.getAttackStrength() >= DRAGON_POWER) {
        return true;
    }
    return false;
}
