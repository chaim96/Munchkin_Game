#ifndef HW4_FIGHTER_H
#define HW4_FIGHTER_H

#include "Player.h"
#include "../utilities.h"

class Fighter : public Player
{
public:
    explicit Fighter (const std::string playerName) : Player(playerName) {}; // constructor
    virtual ~Fighter() override = default; // destructor
    Fighter(const Fighter &fighter) = default; //copy constructor
    void encounterBarfight() override;
    int getAttackStrength() const override;
    bool isFighter() const override;
    void printDetails() const override;
};

#endif //HW4_FIGHTER_H
