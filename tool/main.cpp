
#include <functional>
#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include "../Players/Player.h"
#include "../Cards/Card.h"
#include "../Mtmchkin.h"
#include "../Cards/Vampire.h"
#include "../Cards/Barfight.h"
#include "../Cards/Dragon.h"
#include "../Cards/Fairy.h"
#include "../Cards/Goblin.h"
#include "../Cards/Merchant.h"
#include "../Cards/Pitfall.h"
#include "../Cards/Treasure.h"
#include "../Players/Rogue.h"
#include "../Players/Wizard.h"
#include "../Players/Fighter.h"
#include "../Exception.h"
#include <algorithm>
#include <sstream>
#include <random>
#include <cstdio>
#include <fstream>
#include <cstring>

int main()
{
    const int MAX_NUMBER_OF_ROUNDS = 100;
    Mtmchkin game("deck.txt");
    while(!game.isGameOver() && game.getNumberOfRounds() < MAX_NUMBER_OF_ROUNDS){
        game.playRound();
        game.printLeaderBoard();
    }
}

