#ifndef HW4_MERCHANT_H
#define HW4_MERCHANT_H
#include "Card.h"
#include <string>



class Merchant : public Card {
private:
    static const int NO_PURCHASE = 0;
    static const int BUYING_HP = 1;
    static const int BUYING_FORCE = 2;
    static const int NO_PURCHASE_COST = 0;
    static const int HP_POTION_COST = 5;
    static const int FORCE_BOOST_COST = 10;
    static const int HP_POTION = 1;
    static const int FORCE_BOOST = 1;

public:
    Merchant() = default;
    Merchant(const Merchant& merchant_new)= default;
    virtual ~Merchant()  override= default;
    Merchant& operator=(const Merchant& Merchant_other) = default;
    void applyEncounter(Player& player) const override;
    void printCard(std::ostream &os) const override;
};

#endif //HW4_MERCHANT_H
