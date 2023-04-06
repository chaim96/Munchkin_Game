#ifndef HW4_BATTLE_H
#define HW4_BATTLE_H

#include "Card.h"

class Battle : public Card {
protected:
    static const int DRAGON_POWER = 25;
    static const int DRAGON_LOOT = 1000;
    static const int DRAGON_DAMAGE = 1;
    static const int GOBLIN_POWER = 6;
    static const int GOBLIN_LOOT = 2;
    static const int GOBLIN_DAMAGE = 10;
    static const int VAMPIRE_POWER = 10;
    static const int VAMPIRE_LOOT= 2;
    static const int VAMPIRE_DAMAGE = 10;
    static const int VAMPIRE_LEVEL_REDUCTION = -1;

public:
    Battle() = default;
    Battle(const Battle& battle_new)= default;
    virtual ~Battle() = default;
    Battle& operator=(const Battle& battle_other) = default;
    virtual void applyEncounter(Player& player) const = 0;
    virtual void winBattle(Player& player) const = 0;
    virtual void loseBattle(Player& player) const = 0;
    virtual void printMonster() const = 0;
    virtual void printCard(std::ostream &os) const = 0;
    virtual void autoLose(Player &player) const = 0;
    virtual bool isWin(Player& player) const = 0;



};
#endif //HW4_BATTLE_H