#include "Gang.h"


void Gang::addMonster(std::string nameOfNewCard, int line) {
    if (nameOfNewCard == "Dragon") {
        m_gang.push_back(std::unique_ptr<Battle>(new Dragon()));
    }
    if (nameOfNewCard == "Goblin") {
        m_gang.push_back(std::unique_ptr<Battle>(new Goblin()));
    }
    if (nameOfNewCard == "Vampire") {
        m_gang.push_back(std::unique_ptr<Battle>(new Vampire()));
    }
    if(!(nameOfNewCard == "Dragon" || nameOfNewCard == "Vampire" || nameOfNewCard == "Goblin" ))
    {
        throw DeckFileFormatError("Deck File Error: File format error in line ", line);
    }
}


void Gang::applyEncounter(Player& player) const
{
    bool playerLost= false;

    for (const std::unique_ptr<Battle> &elem: m_gang)
    {
        if(!(elem->isWin(player)))
        {
            playerLost= true;
        }
        if(playerLost)
        {
            elem->loseBattle(player);
        }
        else
        {
            elem->winBattle(player);
        }
    }
    if(!playerLost)
    {
        printWinBattle(player.getName(),"Gang");
        player.levelUp();
    }
}


void Gang::printCard(std::ostream &os) const
{
    printCardDetails(std::cout, "Gang");
}
