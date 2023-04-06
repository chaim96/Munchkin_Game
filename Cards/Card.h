#ifndef HW4_CARD_H
#define HW4_CARD_H


#include <string>
#include "../Players/Player.h"
#include "../utilities.h"
#include <iostream>


class Card {

public:
    /*
     * C'tor of Card class
     *
     * @param type - The type of the card.
     * @param stats - The numeral stats of the card.
     * @return
     *      A new instance of Card.
    */
    Card() = default;

    /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    virtual void applyEncounter(Player& player) const = 0;


    /*
     * Prints the card info:
     *
     * @return
     *      void
    */
    virtual void printCard(std::ostream& os) const = 0;


    Card(const Card& card_new)= default;

    virtual ~Card() = default;

    Card& operator=(const Card& card_other) = default;

    friend std::ostream& operator<<(std::ostream &os, const  Card& card);
};


#endif //HW4_CARD_H