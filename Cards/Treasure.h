#ifndef HW4_TREASURE_H
#define HW4_TREASURE_H
#include "Card.h"
#include <string>
using  std::string;

class Treasure : public Card {
public:
    Treasure() = default;
    Treasure(const Treasure& treasure_new)= default;
    virtual ~Treasure()  override= default;
    Treasure& operator=(const Treasure& treasure_other) = default;
    void applyEncounter(Player& player) const override;
    void printCard(std::ostream &os) const override;
};
#endif //HW4_TREASURE_H
