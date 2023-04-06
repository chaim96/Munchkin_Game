#ifndef HW4_GOBLIN_H
#define HW4_GOBLIN_H
#include "Battle.h"

class Goblin: public Battle {
public:
    Goblin() = default;
    Goblin(const Goblin& goblin_new)= default;
    virtual ~Goblin() override = default;
    Goblin& operator=(const Goblin& goblin_new) = default;
    void applyEncounter(Player& player) const override;
    void winBattle(Player& player) const override ;
    void loseBattle(Player& player) const override;
    void printMonster() const override;
    void printCard(std::ostream &os) const override;
    void autoLose(Player &player) const override;
    bool isWin(Player& player) const override;


};


#endif //HW4_GOBLIN_H
