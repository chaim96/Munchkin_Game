#ifndef HW4_DRAGON_H
#define HW4_DRAGON_H
#include "Battle.h"


class Dragon: public Battle{
public:
    Dragon()= default;
    Dragon(const Dragon& dragon_new)= default;
    virtual ~Dragon() override = default;
    Dragon& operator=(const Dragon& dragon_new) = default;
    void applyEncounter(Player& player) const override;
    void winBattle(Player& player) const override;
    void loseBattle(Player& player) const override;
    void printMonster() const override;
    void printCard(std::ostream &os) const override;
    void autoLose(Player &player) const override;
    bool isWin(Player& player) const override;

};


#endif //HW4_DRAGON_H
