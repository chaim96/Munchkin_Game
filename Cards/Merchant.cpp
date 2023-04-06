#include "Merchant.h"

bool isDecisionOnlyOneChar(std::string input)
{
    if (input.size() != 1)
    {
            return false;
    }
    return true;
}



bool isDecisionOnlyDigits(std::string input)
{
    for (char const& elem: input) {
        if (!(elem >= '0' && elem <= '9')) {
            return false;
        }
    }
    return true;
}

void Merchant::applyEncounter(Player& player) const {
    std::string playerDecision;
    printMerchantInitialMessageForInteractiveEncounter(std::cout, player.getName(), player.getCoins());
    bool merchantSuccess = false;
    while (!merchantSuccess) {
        if (!getline(std::cin, playerDecision)|| !isDecisionOnlyOneChar(playerDecision) || !isDecisionOnlyDigits(playerDecision)) {
            printInvalidInput();
        }
        else
        {
            int decision = stoi(playerDecision);
            switch (decision) {
                case NO_PURCHASE: {
                    printMerchantSummary(std::cout, player.getName(), NO_PURCHASE, NO_PURCHASE_COST);
                    merchantSuccess = true;
                    break;
                }
                case BUYING_HP: {
                    if (player.getCoins() < HP_POTION_COST) {
                        printMerchantInsufficientCoins(std::cout);
                        printMerchantSummary(std::cout, player.getName(), BUYING_HP, NO_PURCHASE_COST);
                        merchantSuccess = true;
                    } else {
                        player.pay(HP_POTION_COST);
                        player.heal(HP_POTION);
                        printMerchantSummary(std::cout, player.getName(), BUYING_HP, HP_POTION_COST);
                        merchantSuccess = true;
                    }
                    break;
                }
                case BUYING_FORCE: {
                    if (player.getCoins() < FORCE_BOOST_COST) {
                        printMerchantInsufficientCoins(std::cout);
                        printMerchantSummary(std::cout, player.getName(), BUYING_FORCE, NO_PURCHASE_COST);
                        merchantSuccess = true;
                    } else {
                        player.pay(FORCE_BOOST_COST);
                        player.buff(FORCE_BOOST);
                        printMerchantSummary(std::cout, player.getName(), BUYING_FORCE, FORCE_BOOST_COST);
                        merchantSuccess = true;
                    }
                    break;
                }
                default: {
                    printInvalidInput();
                    break;
                }

            }
        }
    }
}




void Merchant::printCard(std::ostream &os) const
{
    printCardDetails(std::cout, "Merchant");
}

