#ifndef HW4_VAMPIRE_H
#define HW4_VAMPIRE_H
#include "Battle.h"

class Vampire: public Battle {
public:
    Vampire() = default;
    Vampire(const Vampire& goblin_new)= default;
    virtual ~Vampire() override= default;
    Vampire& operator=(const Vampire& goblin_new) = default;
    void applyEncounter(Player& player) const override ;
    void winBattle(Player& player) const override;
    void loseBattle(Player& player) const override;
    void printMonster() const override;
    void printCard(std::ostream &os) const override;
    void autoLose(Player &player) const override;
    bool isWin(Player& player) const override;

};


#endif //HW4_VAMPIRE_H
