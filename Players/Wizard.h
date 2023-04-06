#ifndef HW4_WIZARD_H
#define HW4_WIZARD_H


#include "Player.h"
#include "../utilities.h"

class Wizard : public Player
{
public:
    explicit Wizard (const std::string playerName) : Player(playerName) {}; // constructor
    ~Wizard() = default; // destructor
    Wizard(const Wizard &wizard) = default; //copy constructor
    void encounterFairy() override;
    void heal(const int healPoints) override;
    bool isWizard() const override;
    void printDetails() const override;
};

#endif //MTMCHKIN_H_WIZARD_H