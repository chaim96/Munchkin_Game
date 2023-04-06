#ifndef HW4_MTMCHKIN_H
#define HW4_MTMCHKIN_H

#include <fstream>
#include <iostream>
#include <fstream>
#include "Cards/Card.h"
#include <functional>
#include "Players/Player.h"
#include "Players/Rogue.h"
#include "Players/Wizard.h"
#include "Players/Fighter.h"
#include "Cards/Fairy.h"
#include "Cards/Battle.h"
#include "Cards/Barfight.h"
#include "Cards/Dragon.h"
#include "Cards/Goblin.h"
#include "Exception.h"
#include "Cards/Merchant.h"
#include "Cards/Pitfall.h"
#include "Cards/Treasure.h"
#include "Cards/Vampire.h"
#include "Cards/Gang.h"
#include <deque>
#include <memory>

class Mtmchkin{

private:
    std::deque<std::unique_ptr<Card>> m_cards; // cards stack
    std::deque<std::unique_ptr<Player>> m_players; // players queue (winners & losers won't appear here)
    std::deque<std::unique_ptr<Player>> m_winners; // winners queue
    std::deque<std::unique_ptr<Player>> m_losers; // losers queue
    int m_teamSize; // amount of players in the game
    int m_playersSize; // size of m_players
    int m_cardPlaying; // index of card played
    int m_roundCount; // current round
    static const int MAX_TEAM_SIZE = 6; // max size for a team to play
    static const int MIN_TEAM_SIZE = 2; // min size for a team to play
    static const char PLAYER_INPUT_DIVIDER = ' '; // char that divides between player name & role in input

    /*
     * sub-constructor method to create the card stack
     */
    void cardStackConstructor(std::string fileName);

    /*
     * helper method for cardStackConstructor
     */
    bool isValidName(const std::string);

    /*
     * sub-constructor method to create the players game queue
     */
    void playersConstructor();

    /*
     * helper method for playersConstructor
     */
    void buildPlayers();

    /*
     * updates the winners and losers queue and deletes them from the players queue
     * returns true if an update occurred
     * returns false otherwise
     */
    bool updateLeaderboard(std::unique_ptr<Player>& player, int index);

public:

    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    explicit Mtmchkin(const std::string &fileName);

    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();

    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;

    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;

    int getTeamSize() const {return m_teamSize;};

    /*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;


    ~Mtmchkin() = default; // default destructor

    Mtmchkin(const Mtmchkin& other) = delete; // deleting copy constructor so the game won't be copyable

    Mtmchkin& operator=(const Mtmchkin& other) = delete; // deleting '=' operator so the game won't be copyable
};

#endif //HW4_MTMCHKIN_H
