#ifndef HW4_BARFIGHT_H
#define HW4_BARFIGHT_H

#include "Card.h"

class Barfight : public Card {
public:
    Barfight() = default;
    Barfight(const Barfight& barfight_new)= default;
    virtual ~Barfight() override = default;
    Barfight& operator=(const Barfight& barfight_other) = default;
    void applyEncounter(Player& player) const override;
    void printCard(std::ostream &os) const override;
};
#endif //HW4_BARFIGHT_H
