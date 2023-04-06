#include "Player.h"


Player::Player(const std::string playerName)
        : m_name(playerName),
          m_maxHP(DEFAULT_MAX_HP),
          m_force(DEFAULT_FORCE),
          m_level(DEFAULT_LEVEL),
          m_HP(DEFAULT_MAX_HP),
          m_coins(DEFAULT_COINS)
{}


void Player::encounterBarfight()
{
    damage(HP_SUB);
}


void Player::encounterPitfall()
{
    damage(HP_SUB);
}


int Player::getAttackStrength() const {
    return this->m_level + this->m_force;
}


void Player::addCoins(const int coinsToAdd) {
    if (coinsToAdd >= 0) {
        this->m_coins += coinsToAdd;
    }
}


void Player::heal(const int healPoints) {
    if (healPoints >= 0) {
        this->m_HP += healPoints;
        if (this->m_HP > this->m_maxHP) {
            this->m_HP = this->m_maxHP;
        }
    }
}


bool Player::isWizard() const { return false; }


bool Player::isRogue() const { return false; }


bool Player::isFighter() const { return false; }


void Player::levelUp() {
    if (this->m_level < MAX_LEVEL) {
        this->m_level++;
    }
}


int Player::getLevel() const {
    return this->m_level;
}


void Player::buff(const int buffPoints) {
    if (m_force + buffPoints < 0)
    {
        this->m_force = 0;
    }
    else
    {
        this->m_force += buffPoints;
    }
}


void Player::damage(const int damagePoints) {
    if (damagePoints >= 0) {
        this->m_HP -= damagePoints;
        if (this->m_HP < 0) {
            this->m_HP = 0;
        }
    }
}

bool Player::isKnockedOut() const {
    if (this->m_HP == 0) {
        return true;
    }
    return false;
}

bool Player::isWinner() const
{
    return (m_level == MAX_LEVEL);
}

bool Player::pay(const int cost) {
    if (cost < 0) {
        return true;
    }
    if (this->m_coins - cost >= 0) {
        this->m_coins -= cost;
        return true;
    }
    return false;
}

std::ostream& operator<<(std::ostream& os, const Player& player) {
    player.printDetails();
    return os;
}



