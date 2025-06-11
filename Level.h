#ifndef Level_H
#define Level_H

#include <iostream>
#include <iomanip>
#include <string>
#include "Character.h"

using namespace std;

class Level {
private: 
    string name, prologue, epilogue;
    Character* enemy;
    Character* hero;
    bool won;

public:
    Level();
    Level(string n, string p, string e, Character* en);
    Level(const Level &l);
    ~Level();

    bool hasWon() const;
    void addPrologue(string p);
    void addEpilogue(string e);
    void addEnemy(Character* en);
    void addHero(Character* h);

    string getName() const;
    string getPrologue() const;
    string getEpilogue() const;
    Character* getEnemy() const;
    Character* getHero() const;
};

Level::Level(): name(""), prologue(""), epilogue(""), enemy(nullptr), won(false) {}
Level::Level(string n, string p, string e, Character* en)
    : name(n), prologue(p), epilogue(e), enemy(en), won(false) {}
Level::Level(const Level &l)
    : name(l.name), prologue(l.prologue), epilogue(l.epilogue), enemy(l.enemy), won(l.won) {}

Level::~Level() {}

string Level::getName() const {
    return name;
}

string Level::getPrologue() const {
    return prologue;
}

string Level::getEpilogue() const {
    return epilogue;
}

Character* Level::getEnemy() const {
    return enemy;
}

Character* Level::getHero() const {
    return hero;
}

bool Level::hasWon() const {
    if (won){
        return true;
    } else {
        return false;
    }
}

void Level::addPrologue(string p) {
    prologue = p;
}

void Level::addEpilogue(string e) {
    epilogue = e;
}

void Level::addEnemy(Character* en) {
    enemy = en;
}

void Level::addHero(Character* h) {
    hero = h;
}

#endif

