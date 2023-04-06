#ifndef HW4_EXCEPTION_H
#define HW4_EXCEPTION_H
#include <string>
#include <stdexcept>
#include "Players/Player.h"
#include <string>


class DeckException: public std::runtime_error{
public:
    explicit DeckException(const std::string& what) : std::runtime_error(what){}
};

class DeckFileFormatError: public DeckException{
const int m_numOfLine;
public:
    DeckFileFormatError(const std::string& what, int num):
        DeckException(what + std::to_string(num)), m_numOfLine(num){}

};

class DeckFileNotFound: public DeckException {
public:
     DeckFileNotFound(const std::string& what): DeckException(what) {}

};

class DeckFileInvalidSize: public DeckException{
public:
     DeckFileInvalidSize(const std::string& what): DeckException(what) {}
};

#endif //HW4_EXCEPTION_H
