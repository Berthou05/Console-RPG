// =================================================================
//
// File: Character.h
// Author: Pedro Perez
// Description: This file contains the implementation of the classes
// character, Warrior, Mage, Archer and enemy.
//
// Copyright (c) 2025 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
//
// =================================================================

#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

// =================================================================
// Contains the definition of the Character class
// =================================================================

class Character {
protected:
    string name;
    int health, mana, strength, shield;

public:
    Character();
    Character(const Character &c);
    Character(string n, int h, int m, int s, int d);
    virtual ~Character();

    // Getters
    string getName() const;
    int getHealth() const;
    int getMana() const;
    int getStrength() const;
    int getShield() const;
    
    // Other methods
    bool isAlive() const;
    void takeDamage(int damage);
    void consumeMana(int amount);

    virtual void attack(Character* target) = 0;
    virtual void recover() = 0;
    virtual string toString() const = 0;
};

// =================================================================
// Default constructor
// =================================================================

Character::Character() : name(""), health(100), mana(50), strength(10), shield(5) {}

// =================================================================
// Copy constructor
//
// @param c The character to copy
// =================================================================

Character::Character(const Character &c) 
    : name(c.name), health(c.health), mana(c.mana), strength(c.strength), shield(c.shield) {}

// =================================================================
// Parameterized constructor
//
// @param n The name of the character
// @param h The health of the character
// @param m The mana of the character
// @param s The strength of the character
// @param d The shield of the character
// =================================================================

Character::Character(string n, int h, int m, int s, int d)
    : name(n), health(h), mana(m), strength(s), shield(d) {}


// =================================================================
// Destructor
// =================================================================

Character::~Character() {}

// =================================================================
// Returns the name of the character
// =================================================================

string Character::getName() const {
    return name;
}

// =================================================================
// Returns the health of the character
// =================================================================

int Character::getHealth() const {
    return health;
}

// =================================================================
// Returns the mana of the character
// =================================================================

int Character::getMana() const {
    return mana;
}

// =================================================================
// Returns the strength of the character
// =================================================================

int Character::getStrength() const {
    return strength;
}

// =================================================================
// Returns the shield of the character
// =================================================================

int Character::getShield() const {
    return shield;
}

// =================================================================
// Checks if the character is alive
// =================================================================

bool Character::isAlive() const {
    return health > 0;
}

// =================================================================
// Takes damage from the character
//
// @param damage The amount of damage to take
// If the damage is greater than the shield, health is reduced by 
// the difference
// =================================================================

void Character::takeDamage(int damage) {
    if (damage > shield) {
        health -= (damage - shield);
        if (health < 0) health = 0;
    }
}

// =================================================================
// Warrior class inherits from Character
// =================================================================

class Warrior : public Character {
public:
    Warrior();
    Warrior(const Warrior &w);
    Warrior(string n);

    void attack(Character* target) override;
    void recover() override;
    string toString() const override;
};

// =================================================================
// Default constructor for Warrior
// =================================================================

Warrior::Warrior() : Character("Warrior", 80, 30, 40, 20) {}

// =================================================================
// Copy constructor for Warrior
// =================================================================

Warrior::Warrior(const Warrior &w): Character(w) {}

// =================================================================
// Parameterized constructor for Warrior
//
// @param n The name of the warrior
// =================================================================

Warrior::Warrior(string n) : Character(n, 80, 30, 40, 20) {}

// =================================================================
// Warrior attacks the target character
//
// If the warrior has 10 or more mana, it deals double damage
//
// @param target The character to attack
// =================================================================

void Warrior::attack(Character* target) {
    if (isAlive() && target != nullptr && target->isAlive()) {
        if (mana >= 10) {
            target->takeDamage(strength * 2);
            mana -= 10;
        } else {
            target->takeDamage(strength);
        }
    }
}

// =================================================================
// Function that recovers health and mana for the Warrior
// =================================================================

void Warrior::recover() {
    if (isAlive()) {
        if (health < 80) {
            health += 20;
            if (health > 80) health = 80;
        }
        if (mana < 30) {
            mana += 10;
            if (mana > 30) mana = 30;
        }
    }
}

// =================================================================
// Returns a string representation of the Warrior
// =================================================================

string Warrior::toString() const {
    stringstream ss;
    ss << getName() << "\t Warrior Stats: "
       << "\t/\t HEALTH: " << getHealth()
       << "\t/\t MANA: " << getMana()
       << "\t/\t STRENGTH: " << getStrength()
       << "\t/\t SHIELD: " << getShield();
    return ss.str();
}

// =================================================================
// Archer class inherits from Character
// =================================================================

class Archer : public Character {
public:
    Archer();
    Archer(const Archer &a);
    Archer(string n);

    void attack(Character* target) override;
    void recover() override;
    string toString() const override;
};

// =================================================================
// Default constructor for Archer
// =================================================================

Archer::Archer() : Character("Archer", 60, 50, 30, 15) {}

// =================================================================
// Copy constructor for Archer
// 
// @param a The archer to copy
// =================================================================

Archer::Archer(const Archer &a) : Character(a) {}

// =================================================================
// Parameterized constructor for Archer
//
// @param n The name of the archer
// =================================================================

Archer::Archer(string n) : Character(n, 60, 50, 30, 15) {}

// =================================================================
// Archer attacks the target character
//
// If the archer has 20 or more mana, it deals double damage
// @param target The character to attack
// =================================================================

void Archer::attack(Character* target) {
    if (isAlive() && target != nullptr && target->isAlive()) {
        if (mana >= 20) {
            target->takeDamage(strength*2);
            mana -= 20;
        } else {
            target->takeDamage(strength);
        }
    }
}

// =================================================================
// Function recovers health and mana for the Archer
// =================================================================

void Archer::recover() {
    if (isAlive()) {
        if (health < 60) {
            health += 15;
            if (health > 60) health = 60;
        }
        if (mana < 50) {
            mana += 10;
            if (mana > 50) mana = 50;
        }
    }
}

// =================================================================
// Returns a string representation of the Archer
// =================================================================

string Archer::toString() const {
    stringstream ss;
    ss << getName() << "\t Archer Stats: "
       << "\t/\t HEALTH: " << getHealth()
       << "\t/\t MANA: " << getMana()
       << "\t/\t STRENGTH: " << getStrength()
       << "\t/\t SHIELD: " << getShield();
    return ss.str();
}

// =================================================================
// Mage class inherits from Character
// =================================================================

class Mage : public Character {
public:
    Mage();
    Mage(const Mage &m);
    Mage(string n);

    void attack(Character* target) override;
    void recover() override;
    string toString() const override;
};

// =================================================================
// Default constructor for Mage
// =================================================================

Mage::Mage() : Character("Mage", 65, 100, 20, 10) {}

// =================================================================
// Copy constructor for Mage
// 
// @param m The mage to copy
// =================================================================

Mage::Mage(const Mage &m) : Character(m) {}

// =================================================================
// Parameterized constructor for Mage
//
// @param n The name of the mage
// =================================================================

Mage::Mage(string n) : Character(n, 60, 100, 20, 10) {}

// =================================================================
// Mage attacks the target character
// If the mage has 30 or more mana, it deals double damage
//
// @param target The character to attack
// =================================================================

void Mage::attack(Character* target) {
    if (isAlive() && target != nullptr && target->isAlive()) {
        if (mana >= 30) {
            target->takeDamage(strength * 2);
            mana -= 30;
        } else {
            target->takeDamage(strength);
        }
    }
}

// =================================================================
// Function that recovers health and mana for the Mage
// =================================================================

void Mage::recover() {
    if (isAlive()) {
        if (health < 65) {
            health += 10;
            if (health > 65) health = 65;
        }
        if (mana < 100) {
            mana += 20;
            if (mana > 100) mana = 100;
        }
    } 
}

// =================================================================
// Returns a string representation of the Mage
// =================================================================

string Mage::toString() const {
    stringstream ss;
    ss << getName() << "\t Mage Stats: "
       << "\t/\t HEALTH: " << getHealth()
       << "\t/\t MANA: " << getMana()
       << "\t/\t STRENGTH: " << getStrength()
       << "\t/\t SHIELD: " << getShield();
    return ss.str();
}

// =================================================================
// Enemy class inherits from Character
// =================================================================

class Enemy : public Character {
public:
    Enemy();
    Enemy(const Enemy &e);
    Enemy(string n, int h, int m, int s, int d);

    void attack(Character* target) override;
    void recover() override;
    string toString() const override;
};

// =================================================================
// Default constructor for Enemy
// =================================================================

Enemy::Enemy() : Character("Enemy", 30, 0, 15, 5) {}

// =================================================================
// Copy constructor for Enemy
//
// @param e The enemy to copy
// =================================================================

Enemy::Enemy(const Enemy &e) : Character(e) {}

// =================================================================
// Parameterized constructor for Enemy
//
// @param n The name of the enemy
// @param h The health of the enemy
// @param s The strength of the enemy
// @param d The shield of the enemy
// ==================================================================

Enemy::Enemy(string n, int h, int m, int s, int d) 
    : Character(n, h, m, s, d) {}

// =================================================================
// Enemy attacks the target character
//
// @param target The character to attack
// =================================================================

void Enemy::attack(Character* target) {
    target->takeDamage(getStrength());
}

// =================================================================
// Function that recovers health and mana for the Enemy
// =================================================================

void Enemy::recover() {
    if (isAlive()) {
        if (health < 30) {
            health += 20;
            if (health > 30) health = 30;
        }
    } 
}

// =================================================================
// Returns a string representation of the Enemy
// =================================================================

string Enemy::toString() const {
    stringstream ss;
    ss << getName() << "\t Enemy Stats: "
       << "\t/\t HEALTH: " << getHealth()
       << "\t/\t MANA: " << getMana()
       << "\t/\t STRENGTH: " << getStrength()
       << "\t/\t SHIELD: " << getShield();
    return ss.str();
}

#endif