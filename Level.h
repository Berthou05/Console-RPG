// =================================================================
//
// File: Level.h
// Author: Alexis Berthou
// Description: This file contains the implementation of the Level 
// class.
//
// Copyright (c) 2025 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
//
// =================================================================

#ifndef Level_H
#define Level_H

#include <iostream>
#include <iomanip>
#include <string>
#include "Character.h"

using namespace std;

// =================================================================
// Contains the definition of the Level class
// =================================================================

class Level {
private: 
    string name, prologue, epilogue;
    Character* enemy;
    Character* hero;
    Enemy* initialEnemy;
    bool won;

public:
    Level();
    Level(string n, string p, string e, Character* en);
    Level(const Level &l);
    ~Level();

    bool hasWon() const;
    void setWon(bool w);
    void setPrologue(string p);
    void setEpilogue(string e);
    void setEnemy(Character* en);
    void setHero(Character* h);
    void resetEnemy();

    string getName() const;
    string getPrologue() const;
    string getEpilogue() const;
    Character* getEnemy() const;
    Character* getHero() const;
};

// =================================================================
// Default constructor for Level
// =================================================================

Level::Level(): name(""), prologue(""), epilogue(""), enemy(nullptr), won(false) {}

// =================================================================
// Parameterized constructor for Level
//
// @param n The name of the level
// @param p The prologue of the level
// @param e The epilogue of the level
// @param en The enemy character in the level
// =================================================================

Level::Level(string n, string p, string e, Character* en)
    : name(n), prologue(p), epilogue(e), enemy(en), won(false) {
        initialEnemy = new Enemy(*dynamic_cast<Enemy*>(en));
    }

// =================================================================
// Copy constructor for Level
//
// @param l The level to copy
// =================================================================

Level::Level(const Level &l)
    : name(l.name), prologue(l.prologue), epilogue(l.epilogue), enemy(l.enemy), won(l.won) {}

// =================================================================
// Destructor for Level
// =================================================================

Level::~Level() {
    delete enemy;
    delete initialEnemy;
}

// =================================================================
// Returns the name of the level
// =================================================================

string Level::getName() const {
    return name;
}

// =================================================================
// Returns the prologue of the level
// =================================================================

string Level::getPrologue() const {
    return prologue;
}

// =================================================================
// Returns the epilogue of the level
// =================================================================

string Level::getEpilogue() const {
    return epilogue;
}

// =================================================================
// Returns the enemy character of the level
// =================================================================

Character* Level::getEnemy() const {
    return enemy;
}

// =================================================================
// Returns the hero character of the level
// =================================================================

Character* Level::getHero() const {
    return hero;
}

// =================================================================
// Checks if the level has been won
// =================================================================

bool Level::hasWon() const {
    if (won){
        return true;
    } else {
        return false;
    }
}

// =================================================================
// Sets the level as won or not
//
// @param w True if the level is won, false otherwise
// =================================================================

void Level::setWon(bool w) {
    won = w;
}

// =================================================================
// Adds a prologue to the level
//
// @param p The prologue to be added
// =================================================================

void Level::setPrologue(string p) {
    prologue = p;
}

// =================================================================
// Adds an epilogue to the level
//
// @param e The epilogue to be added
// =================================================================

void Level::setEpilogue(string e) {
    epilogue = e;
}

// =================================================================
// Adds an enemy character to the level
//
// @param en The enemy character to be added
// =================================================================

void Level::setEnemy(Character* en) {
    enemy = en;
}

// =================================================================
// Adds a hero character to the level
//
// @param h The hero character to be added
// =================================================================

void Level::setHero(Character* h) {
    hero = h;
}

// =================================================================
// Resets the enemy character to its initial state
// =================================================================

void Level::resetEnemy() {
    delete enemy;
    if (initialEnemy) {
        enemy = new Enemy(*initialEnemy);
    } else {
        enemy = nullptr;
    }
}

#endif

