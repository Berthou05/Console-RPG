// =================================================================
//
// File: SaveManager.h
// Author: Alexis Berthou
// Description: This file contans the implementation of the 
// SaveManager class.
//
// Copyright (c) 2025 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
//
// =================================================================

#ifndef SAVEMANAGER_H
#define SAVEMANAGER_H

#include "Character.h"
#include "Level.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// =================================================================
// SaveManager class for handling save and load operations
// =================================================================

class SaveManager {
private:
    string saveFileName;
    static void saveGame(const vector<Character*>& heroes, const vector<Level*>& levels, const string& filename);
    static void loadGame(vector<Character*>& heroes, vector<Level*>& levels, const string& filename);
};

void SaveManager::saveGame(const vector<Character*>& heroes, const vector<Level*>& levels, const string& filename) {
    ofstream out(filename, ios::binary);
    if (!out) return;

    // Save heroes
    int heroCount = heroes.size();
    out.write((char*)&heroCount, sizeof(int));
    for (Character* c : heroes) {
        string type;

        if (dynamic_cast<Warrior*>(c)) type = "Warrior";
        else if (dynamic_cast<Archer*>(c)) type = "Archer";
        else if (dynamic_cast<Mage*>(c)) type = "Mage";

        int len = type.size();
        out.write((char*)&len, sizeof(int));
        out.write(type.c_str(), len);

        string name = c->getName();
        len = name.size();
        out.write((char*)&len, sizeof(int));
        out.write(name.c_str(), len);

        int stats[] = { c->getHealth(), c->getMana(), c->getStrength(), c->getShield() };
        out.write((char*)stats, sizeof(stats));
    }

    // Save level status
    int levelCount = levels.size();
    file.write((char*)&levelCount, sizeof(int));

    for (Level* level : levels) {
        bool won = level->hasWon();
        file.write((char*)&won, sizeof(bool));
    }

    out.close();
}

void SaveManager::loadGame(vector<Character*>& heroes, vector<Level*>& levels, const string& filename) {
    ifstream in(filename, ios::binary);
    if (!in) return;

    heroes.clear();

    // Read heroes
    int heroCount;
    in.read((char*)&heroCount, sizeof(int));
    for (int i = 0; i < heroCount; ++i) {
        int len;
        in.read((char*)&len, sizeof(int));
        string type(len, ' ');
        in.read(&type[0], len);

        in.read((char*)&len, sizeof(int));
        string name(len, ' ');
        in.read(&name[0], len);

        int stats[4];
        in.read((char*)stats, sizeof(stats));

        Character* c = nullptr;
        if (type == "Warrior")
            c = new Warrior(name, stats[0], stats[1], stats[2], stats[3]);
        else if (type == "Archer")
            c = new Archer(name, stats[0], stats[1], stats[2], stats[3]);
        else if (type == "Mage")
            c = new Mage(name, stats[0], stats[1], stats[2], stats[3]);

        if (c) heroes.push_back(c);
    }

    // Read level status
    int levelCount;
    in.read((char*)&levelCount, sizeof(int));

    for (int i = 0; i < levelCount; ++i) {
        bool won;
        in.read((char*)&won, sizeof(bool));
        levels[i]->setWon(won);
    }

        in.close();
    }

#endif

