    #ifndef HW4_ROGUE_H
#define HW4_ROGUE_H



#include "Player.h"
#include "../utilities.h"

class Rogue : public Player
{
public:
    explicit Rogue (const std::string playerName) : Player(playerName) {}; // constructor
    ~Rogue() = default; // destructor
    Rogue(const Rogue &rogue) = default; //copy constructor
    void encounterPitfall() override;
    void addCoins(const int coinsToAdd) override;
    bool isRogue() const override;
    void printDetails() const override;

};
#endif //MTMCHKIN_H_ROGUE_H