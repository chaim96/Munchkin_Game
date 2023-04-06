#include "Mtmchkin.h"


Mtmchkin::Mtmchkin (const std::string &fileName) : m_teamSize(0), m_playersSize(0), m_cardPlaying(0), m_roundCount(0)
{
    printStartGameMessage();
    cardStackConstructor(fileName);
    playersConstructor();
}


bool Mtmchkin::isValidName(const std::string cardType) {
    if (cardType == "Gang") {
        m_cards.push_back(std::unique_ptr<Card>(new Gang()));
        return true;
    }
    if (cardType == "Fairy") {
        m_cards.push_back(std::unique_ptr<Card>(new Fairy()));
        return true;
    }
    if (cardType == "Goblin") {
        m_cards.push_back(std::unique_ptr<Card>(new Goblin()));
        return true;
    }
    if (cardType == "Vampire") {
        m_cards.push_back(std::unique_ptr<Card>(new Vampire()));
        return true;
    }
    if (cardType == "Barfight") {
        m_cards.push_back(std::unique_ptr<Card>(new Barfight()));
        return true;
    }
    if (cardType == "Dragon") {
        m_cards.push_back(std::unique_ptr<Card>(new Dragon()));
        return true;
    }
    if (cardType == "Treasure") {
        m_cards.push_back(std::unique_ptr<Card>(new Treasure()));
        return true;
    }
    if (cardType == "Merchant") {
        m_cards.push_back(std::unique_ptr<Card>(new Merchant()));
        return true;
    }
    if (cardType == "Pitfall") {
        m_cards.push_back(std::unique_ptr<Card>(new Pitfall()));
        return true;
    }
    return false;
}

void Mtmchkin::cardStackConstructor(const std::string fileName) {
    std::ifstream source(fileName);
    if(!source)
    {
        throw DeckFileNotFound( "Deck File Error: File not found");
    }
    int m_line=0; // count lines in "deck.txt"
    string cardType;
    while (getline(source,cardType)) {
        m_line++;
        if (!isValidName(cardType)) {
            throw DeckFileFormatError("Deck File Error: File format error in line ", m_line);
        }
        if (cardType == "Gang") {
            getline(source, cardType);
            m_line++;
            while (cardType != "EndGang") {
                if (!(cardType == "Dragon" || cardType == "Vampire" || cardType == "Goblin")) {
                    throw DeckFileFormatError("Deck File Error: File format error in line ", m_line);
                }
                dynamic_cast<Gang&>(*m_cards.back()).addMonster(cardType, m_line);
                getline(source, cardType);
                m_line++;
            }
        }
    }
    if (m_cards.size() < 5)
    {
        throw DeckFileInvalidSize("Deck File Error: Deck size is invalid");
    }
    source.close();
}


bool isPlayerNameValid(string name)
{
    for (char const& elem: name)
    {
        if (name.length() > 15)
        {
            return false;
        }
        if (!(((elem >= 'a') && (elem <='z')) ||  ((elem >= 'A') && (elem <='Z')))) {
            return false;
        }

    }
    return true;
}


bool isTeamOnlyOneChar(std::string input)
{
    if (input.size() > 1)
    {
        return false;
    }
    return true;
}



void Mtmchkin::playersConstructor()
{
    string strTemp;
    printEnterTeamSizeMessage();
    int inputValid = 0;
    while (inputValid == 0)
    {

        try {
            if(!getline(std::cin, strTemp)|| !isTeamOnlyOneChar(strTemp) )
            {
                throw std::invalid_argument("bad getline");
            }
            if (stoi(strTemp) < MIN_TEAM_SIZE || stoi(strTemp) > MAX_TEAM_SIZE) {
                throw std::invalid_argument("bad getline");
            }
            inputValid = 1;
        }
        catch (...) {
            printInvalidTeamSize();
            printEnterTeamSizeMessage();
        }
    }
    m_teamSize = stoi(strTemp);
    m_playersSize = m_teamSize;
    buildPlayers();
}


void Mtmchkin::buildPlayers()
{
    int inputValid = 0;
    string playerName, playerType, strTemp;
    printInsertPlayerMessage();
    while (inputValid != m_teamSize) {
        getline(std::cin, strTemp);
        playerName = strTemp.substr(0, strTemp.find(PLAYER_INPUT_DIVIDER));
        playerType = strTemp.substr(strTemp.find(PLAYER_INPUT_DIVIDER) + 1, strTemp.length());
        if (!isPlayerNameValid(playerName)) {
            printInvalidName();
        } else {
            if (std::cin.fail() || (playerType != "Rogue" && playerType != "Wizard" && playerType != "Fighter")) {
                printInvalidClass();
            } else {
                if (playerType == "Rogue") {
                    m_players.push_back(std::unique_ptr<Player>(new Rogue(playerName)));
                }
                if (playerType == "Wizard") {
                    m_players.push_back(std::unique_ptr<Player>(new Wizard(playerName)));
                }
                if (playerType == "Fighter") {
                    m_players.push_back(std::unique_ptr<Player>(new Fighter(playerName)));
                }
                inputValid++;
                if (inputValid < m_teamSize) {
                    printInsertPlayerMessage();
                }
            }
        }
    }
}


void Mtmchkin::playRound()
{
    if (isGameOver())
    {
        printGameEndMessage();
    }
    else
    {
        m_roundCount++;
        printRoundStartMessage(m_roundCount);
        int index = 0;
        while (index < m_playersSize) {
            printTurnStartMessage((*m_players[index]).getName());
            (m_cards[(m_cardPlaying%m_cards.size())])->applyEncounter(*m_players[index]);
            m_cardPlaying++;
            if (updateLeaderboard(m_players[index], index))
            {
                m_playersSize--;
            }
            else
            {
                index++;
            }
            if (isGameOver() == true)
            {
                printGameEndMessage();
            }
        }
    }
}


bool Mtmchkin::updateLeaderboard(std::unique_ptr<Player>& player, int index)
{
    if ((*player).isWinner())
    {
        m_winners.push_back(move(player));
        m_players.erase(m_players.begin() + index);
        return true;
    }
    else
    {
        if ((*player).isKnockedOut())
        {
            m_losers.push_front(move(player));
            m_players.erase(m_players.begin() + index);
            return true;
        }
    }
    return false;
}


void Mtmchkin::printLeaderBoard() const
{
    printLeaderBoardStartMessage();
    int ranking = 0;
    for (const std::unique_ptr<Player>& elem : m_winners)
    {
        printPlayerLeaderBoard(++ranking, (*elem));
    }
    for (const std::unique_ptr<Player>& elem : m_players)
    {
        printPlayerLeaderBoard(++ranking, (*elem));
    }
    for (const std::unique_ptr<Player>& elem : m_losers)
    {
        printPlayerLeaderBoard(++ranking, (*elem));
    }
}


int Mtmchkin::getNumberOfRounds() const
{
    return m_roundCount;
}


bool Mtmchkin::isGameOver() const
{
    if (m_players.empty() && m_roundCount > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

