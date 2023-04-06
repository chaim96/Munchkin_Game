#ifndef HW4_GANG_H
#define HW4_GANG_H
#include "Battle.h"
#include <fstream>
#include <iostream>
#include <fstream>
#include <functional>
#include "Vampire.h"
#include "Dragon.h"
#include "Goblin.h"
#include "../Exception.h"

#include <deque>
#include <memory>

class Gang : public Battle {
    std::deque<std::unique_ptr<Battle>> m_gang; // cards stack

public:
        Gang() = default;
        Gang(const Gang& gang_new)= default;
        virtual ~Gang() override = default;
        Gang& operator=(const Gang& gang_new) = default;
        void applyEncounter(Player& player) const override;
        void printMonster() const override {};
        void printCard(std::ostream &os) const override;
        void addMonster(std::string nameOfNewCard, int line);
        void winBattle(Player& player) const override {};
        void loseBattle(Player& player) const override {};
        void autoLose(Player &player) const override {};
        bool isWin(Player& player) const override { return true; };
};


#endif //HW4_GANG_H
