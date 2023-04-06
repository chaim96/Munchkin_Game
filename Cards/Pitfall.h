#ifndef HW4_PITFALL_H
#define HW4_PITFALL_H
#include "Card.h"

class Pitfall : public Card {
public:
    Pitfall() = default;
    Pitfall(const Pitfall& pitfall_new)= default;
    virtual ~Pitfall() override= default;
    Pitfall& operator=(const Pitfall& pitfall_other) = default;
    void applyEncounter(Player& player) const override;
    void printCard(std::ostream &os) const override;
};
#endif //HW4_PITFALL_H
