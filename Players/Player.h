#ifndef HW4_PLAYER_H
#define HW4_PLAYER_H

#include <stdio.h>
#include <string>
#include <iostream>



class Player {
private:
    static const int DEFAULT_FORCE = 5; // default force value for Constructor
    static const int DEFAULT_COINS = 10; // default coins value for Constructor
    static const int DEFAULT_LEVEL = 1; // default start level for Constructor

protected:
    std::string m_name; // player's name
    int m_maxHP; // player's max health points
    int m_force; // player's force
    int m_level; // player's level
    int m_HP; // player's current health points
    int m_coins; // player's current money
    static const int HP_ADD = 10; // HP points to add when encountering a relevant card
    static const int HP_SUB = 10; // HP points to subtract when encountering a relevant card
    static const int DEFAULT_MAX_HP = 100; // default max HP value for Constructor, needed as protected for other classes
    static const int MAX_LEVEL = 10; // level to reach for winning, needed as protected for other classes

public:
    Player() = default; // default constructor for Queue constructing
    explicit Player(const std::string playerName); // constructor
    virtual ~Player() = default; // destructor
    Player(const Player &player) = default; //copy constructor:
    Player& operator=(const Player& other) = default; // = operator
    std::string getName() const {return m_name;}; // getter for player's name
    int getCoins() const {return m_coins;}; // getter for player's coins
    int getMaxHP() const {return DEFAULT_MAX_HP;}; // getter for player's max HP

    friend std::ostream& operator<<(std::ostream &os, const  Player& player);


    /*
     * default - does nothing. (there for no implementation in cpp)
     * Wizard - adds 10 points to HP
     */
    virtual void encounterFairy() {};

    /*
     * default - subtracts 10 points from HP
     * Fighter - does nothing.
     */
    virtual void encounterBarfight();

    /*
     * default - subtracts 10 points from HP
     * Rogue - does nothing.
     */
    virtual void encounterPitfall();

    /*
    * default - @return (player's level) + (player's force)
    * Fighter - @return (player's level) + 2*(player's force)
    */
    virtual int getAttackStrength() const;

    /**
    * default - add value of coins to player's coins
    * Rogue - add twice the amount of coins
    * note: add only non-negative values
    */
    virtual void addCoins(const int coinsToAdd);

    /**
    * default - add value of HP to player's health
    * Wizard - add twice the amount of HP
    * note: cant heal more than Player's Max HP
    * note: add only non-negative values
    */
    virtual void heal(const int healPoints);

    /*
     * default - return false
     * Wizard - return true
     */
    virtual bool isWizard() const;

    /*
     * default - return false
     * Rogue - return true
     */
    virtual bool isRogue() const;

    /*
     * default - return false
     * Fighter - return true
     */
    virtual bool isFighter() const;

    /*
     * calls for the default print function in Utilities with the player's unique values
     */
    virtual void printDetails() const = 0;

    /*
    * add one to player lv if possible
    * if lv player is MAX_LEVEL does nothing
    */
    void levelUp();

    /**
     * @return player current level
     */
    int getLevel() const;

    /**
    * add value of buff to player's force
    * note: can also receive negative values
    */
    void buff(const int buffPoints);

    /**
    * sub value of damage taken in battle from player's health
    * note: lowest player's hp can be 0
    * note: sub only non-negative values
    */
    void damage(const int damagePoints);

    /**
    * Check if player's hp is 0
    * @return true when player's hp is zero
    * @return false otherwise
    */
    bool isKnockedOut() const;

    /**
     * checks if player has reached level 10
     * @return true when player's level is 10
     * @return false otherwise
     */
    bool isWinner() const;

    /**
     * sub value of cost from player's coins
     * @return true if succeed
     * @return false if failed
     * note: added coins can only be non-negative
    */
    bool pay(const int cost);
};


#endif //HW4_PLAYER_H