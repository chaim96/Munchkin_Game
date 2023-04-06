#include "Card.h"

std::ostream& operator<<(std::ostream& os, const Card& card) {
    card.printCard(std::cout);
    printEndOfCardDetails(std::cout);
    return os;
}
