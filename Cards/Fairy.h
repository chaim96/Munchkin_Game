#ifndef HW4_FAIRY_H
#define HW4_FAIRY_H
#include "Card.h"

class Fairy : public Card {
public:
    Fairy() = default;
    Fairy(const Fairy& fairy_new)= default;
    virtual ~Fairy() override = default;
    Fairy& operator=(const Fairy& fairy_other) = default;
    void applyEncounter(Player& player) const override;
    void printCard(std::ostream &os) const override;
};
#endif //HW4_FAIRY_H
