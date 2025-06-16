// =================================================================
//
// File: ui.h
// Author: Alexis Berthou
// Description: This file contains the implementation of the UI 
// class.
//
// Copyright (c) 2025 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
//
// =================================================================

#ifndef UI_H
#define UI_H

#include "Character.h"
#include "Level.h"
#include <ncurses.h>
#include <string>
#include <vector>
#include <utility> // for pair
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

//==================================================================
// Enum for different scenes in the game
//==================================================================

enum class Scene {
    MainMenu,
    CharacterSelector,
    CharacterCreator,
    LevelSelect,
    Battle,
    GameOver,
    Options,
    Exit
};

//==================================================================
// The definition of class UI
// This class handles the user interface for the game, including
// displaying menus, character selection, battle screens, etc.
//==================================================================

class UI {
private:
    static void drawFrame();
    static void printCentered(int row, const string& text);
    static void printCenteredTitle(int row, const string& text);
    static void printBlock(int startRow, int startCol, const vector<string>& block);
    static void printCenteredBlock(int startRow, const vector<string>& block);
    static void printBattleCard(const Character* character, int row, int col);
    static const vector<string> gameName;
    static const vector<string> SkullArt;
public:
    static void init();
    static void shutdown();
    static void clearScreen();
    
    static Scene showMainMenu();
    static Character* showCharacterSelector(const vector<Character*>& heroes);
    static Character* showCharacterCreator();
    static Level* showLevelSelector(const vector<Level*>& levels);
    static bool showBattleScreen(const Level* level);
    static Scene showGameOver();
    static Scene Options(vector<Character*>& heroes, vector<Level*>& levels);

};

const vector<string> UI::gameName = {
    " _   _       _   _                      ",
    "| \\ | |     | \\ | |                     ",
    "|  \\| | ___ |  \\| | ___  _ __ ___   ___ ",
    "| . ` |/ _ \\| . ` |/ _ \\| '_ ` _ \\ / _ \\",
    "| |\\  | (_) | |\\  | (_) | | | | | |  __/",
    "\\_| \\_/\\___/\\_| \\_/\\___/|_| |_| |_|\\___|"
};

const vector<string> UI::SkullArt = {
    "          ##############          ",   
    "      ######################      ",   
    "     ##.##+##-#.##.#.##+##+##     ",   
    "   +###########################   ",   
    "   ############################   ",   
    "  ### #.##+##-#.##.#.##+##+#.#+# ",   
    " -############################### ",   
    " .##############################+ ",   
    "  +---.    -- +.-- + -.     --.+  ",   
    "  ###          ####          ###  ",   
    "  ##           ####           ##  ",   
    "  ...          .  -           ..  ",   
    " -+##.#+#######+  ##-#######-##++ ",   
    " -#############    #############+ ",   
    "  -+#-#++-##+-+    - #+#--+#+#++  ",   
    "   +##+#.###### .- #-###+-#+##+   ",   
    "        ##################        ",   
    "         +-##.##++## ##-+         ",   
    "         -##+##+##+#++##+         ",   
    "         .#. ## ## ##  #-         ",   
    "             +  -+  #             "
};

vector<string> gameOverArt = {
    "..     +$$$$$$$                      +$$$$$     :$$$$$$XXX$$$$$$$$$;         :+$$$$$$$$$.    :$$$+.      X$$x.  ;X$$$$$$:    :X$$$$$$$$$$;   ..   ",
    "     ;X$$$$$$$$...;XXXXX:          .;X$$$$$XX .X$$$$$$$X$$$$$$$$$$$+       ..:+$$$$$$$$$: ..;x$$$x...    X$$X..;xX$$$$$$$x. :+$$$X.x$$$$$; ..  .  ",
    "   .;xXx+;;xXXX:::;XXXXX+;         ;XXXXXx+XX;+Xx;+XXXx+X$XX;::::+X;       :;+xXxx;:::xX+;;;XXXXX; .:. ;;xXx;.;XXx+;:::;xx..xXXXX+ :+;;xXx;;.     ",
    ".. ;$$$x:. xX$$:::+$$$$$$$;.       ;X$$$$;;xX$$X+ ;$$$+:xX$$     :X;       :;$$$X;.   X$$$;;X$$$$x..:  X$$x;. ;x$$+     +x..x$$$$x .:. x$$$+..    ",
    "  ;+$$$x:.  .$$:;;x$$$$$$$$$       ;$$$$$;:  $X .X$$$$+;xX$$               ;+$$$x;.   X$$$++$$$$$+..;  x$: ;: ;x$$+        .x$$$$x .:. x$$$x:  :  ",
    ":::+$$$+.      ..:+$$$;   X$$$     ;X$$$$.      :X$$$$;.::$$$$$x           ;;$$$x.    x$$$;;X$$$$+...x$$$: :. .:x$$$$$;    .xX$$$x ..  +$; ..:.   ",
    " .;+$$$+.xXXXXX;;:+$$$;   .:$$Xx   ;X$$$$.      :X$$$$;.;;$$$$$x           ;+$$$x.    X$$$+;X$$$$x...X$$$; :. .;x$$$$$;    .x$$$$x ..+X$$; ..  .  ",
    "  .;$Xx; ..xxxXXx.;xxx;     .:Xx+; .;xxxx.      .;+xxx: :;$$Xx..           ;;xXX;     xxXx::;+xXx;   +xxx.    .:xXXX;.     .;+xxxx+++xx;.         ",
    "...;X$$;  .X$$$Xx.;$$$+.......$$$x .:x$$$.      .:x$$$: .:X$$X    .        :;$$$x     X$$$:.:+$$$x.  x$$X:    .:xX$$+   ..  .+$$$$$X$$$+.         ",
    " .:+$$$;  .X$$$$X.;$$$$$$$$$$$$$$X:;x$$$$;:     .;x$$$+:;;$$$X   ;$x;.     ;x$$$x     X$$$;;;x$$$x.  x$x:    .;$$$$$+   x$+;;x$$$$X; +$$$; ..  ;  ",
    "::..;+X$$$$$$$$:. :X$$;    .xX$$$X:::x$$$;:      .+$$$+:..:;$$$$$$$x;.     .. ;$$$$$$$$$;:...;$$$$$$$x:::    .;X$$$$$$$$$$+:.;$$$$X; .;x$$$+:;.   ",
    "  ..;xX$$$$$$;::. :X$$;    .X$$$$X;;;x$$$;;      .+$&$+;..;;$&$$$$$x;.     .. ;$$$$$$$$$;:.... ..x$$$x;;;+;...;X$$$$$&$$$$+;.;$$$$$+ .;X$$$+:  :  ",
    "    ..:.     ::   .:::.     xX:;x;...  .:..      .    ......  ::.   .      .. .::..:..::..  .. .:xX; ..:;Xx:.  ...  .:..  .... .:+X;  ..;xx;.     ",
    "    ..:.     ::   .:::.    .xX:;$X...  .:..      .    ......  ::.  ..      .. .::..:..::..  .. .:xX; ..:;Xx:.  ...  .::.  ...  .:+X;  ..;xx;.     ",
    "    ..:.     ::    ::;.     xx;+$x...  ....      .    ......  :..  ..      .. .:..:;..;;:.  .  .:+X: ...:xx:.  ...  .:..  ...  .:+x; ...;xx;.  :  ",
    "..    .      ..     .:.     ::::  ...    ..           ..  ..  ..    .          .  .:. .:..      ..:. ..  .:..    .  ..    ..    ..:.  .  .:....   ",
    "      .      ..     .:.     ::::  ...    ..           ..  ..  ..    .          .  .:. .:..      ..:. ..  .:..    .  ..    ..    ..:.  .  .:..  .  ",
    "  .   .      ..      .      ::      .            .            ..           ..  .   .  .:        ...      ..         ..          ...      ..       ",
    " ..   .      ..      .      ::      .            .            ..           ..  .  ..  .:        ...      ..         ..          ...      ..       ",
    "  .   .      ..             ::    ...            ..           ..    .      ..  .  ..  ::        ...                 ..    ..     ..            :  ",
    ".            ..             ..    .              .            .     .             ..  ..          .                 ..    ..      .          .    ",
    "             ..             ..    .              .            ..   ..             ..  ..          .                 ..    ..      .               "
};

vector<string> battleCardFrame = {
    "  +-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~+",
    "  !                                !",
    "  +-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~+",
    "  |                                |",
    "  !                                !",
    "  |                                |",
    "  !                                !",
    "  |                                |",
    "  !                                !",
    "  |                                |",
    "  +-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~+"
};

//==================================================================
// Clears the screen and refreshes the display
//==================================================================

void UI::clearScreen() {
    erase();
    refresh();
}

//==================================================================
// Draws the frame around the game area
// This includes borders, corners, and horizontal lines
//==================================================================

void UI::drawFrame() {

    //TOP BORDER
    for (int x = 2; x < COLS - 2; ++x) {
        char c = (x % 2 == 0) ? '~' : '-';
        mvaddch(1, x, c);
    }

    // First horiztal border
    for (int x = 2; x < COLS - 2; ++x) {
        char c = (x % 2 == 0) ? '~' : '-';
        mvaddch(33, x, c);
    }

    // Bottom border
    for (int x = 3; x < COLS - 2; ++x) {
        char c = (x % 2 == 0) ? '~' : '-';
        mvaddch(LINES - 1, x, c);
    }
    
    // Left border
    for (int y = 2; y < LINES - 1; ++y) {
        char c = (y % 2 == 0) ? '!' : '|';
        mvaddch(y, 1, c);
    }

    // Right border
    for (int y = 2; y < LINES - 1; ++y) {
        char c = (y % 2 == 0) ? '!' : '|';
        mvaddch(y, COLS - 2, c);
    }

    mvaddch(1, 1, '+'); // Left-Top
    mvaddch(1, COLS - 2, '+'); // Right-Top
    mvaddch(33, 1, '+'); // Left-1
    mvaddch(33, COLS - 2, '+'); // Right-1
    mvaddch(LINES - 1, 1, '+'); // Bottom-left corner
    mvaddch(LINES - 1, COLS - 2, '+'); // Bottom-right corner

    refresh();
}

//==================================================================
// Prints the battle card for a character
// This includes the character's name, health bar, mana bar,
// strength, and shield values.
// The health and mana bars are represented as a series of '#' characters
// and are color-coded based on the character's health percentage.
// The card is printed at the specified row and column.
//
// @param character The character to display on the card
// @param tableStartRow The starting row for the card
// @param tableStartCol The starting column for the card
//==================================================================

void UI::printBattleCard(const Character* character, int tableStartRow, int tableStartCol) {
    if (!character) return;

    // Draw the card frame
    printBlock(tableStartRow, tableStartCol, battleCardFrame);
    // Print Name
    mvprintw(tableStartRow + 1, tableStartCol + 4, "%s", character->getName().c_str());
    
    // Print Health Bar
    float healthPercent = character->getHealthPercent();
    mvprintw(tableStartRow + 3, tableStartCol + 4, "Health:  [");
    if (healthPercent > 0.3) {
        attron(COLOR_PAIR(3)); // Green for health
    } else if (healthPercent > 0) {
        attron(COLOR_PAIR(2)); // Red for low health
    }
    for (int i = 0; i < int(20 * healthPercent); ++i) {
        mvaddch(tableStartRow + 3, tableStartCol + 14 + i, '#');
    }
    mvprintw(tableStartRow + 3, tableStartCol + 23, "%i", character->getHealth());
    if (character->isAlive()) {
        attron(COLOR_PAIR(1)); // Reset color
    } else {
        attron(COLOR_PAIR(2)); // Red
    }
    mvprintw(tableStartRow + 3, tableStartCol + 34, "]");
    attron(COLOR_PAIR(1)); // Reset color

    // Print Mana Bar
    float manaPercent = character->getManaPercent();
    mvprintw(tableStartRow + 4, tableStartCol + 4, "Mana:    [");
    attron(COLOR_PAIR(4)); // Blue for mana
    for (int i = 0; i < int(20 * manaPercent); ++i) {
        mvaddch(tableStartRow + 4, tableStartCol + 14 + i, '#');
    }
    mvprintw(tableStartRow + 4, tableStartCol + 23, "%i", character->getMana());
    attron(COLOR_PAIR(1)); // Reset color
    mvprintw(tableStartRow + 4, tableStartCol + 34, "]");

    // Print Strength and Shield
    mvprintw(tableStartRow + 5, tableStartCol + 4, "Strength: %d", character->getStrength());
    mvprintw(tableStartRow + 6, tableStartCol + 4, "Shield:   %d", character->getShield());
}

//==================================================================
// Prints a centered text at the specified row
//
// @param row The row where the text should be printed
// @param text The text to be printed
//==================================================================

void UI::printCentered(int row, const string& text) {
    // Clear the line before printing
    mvprintw(row, 4, "%s", string(COLS - 4, ' ').c_str()); 
    // Calculate the column to center the text
    int col = (COLS - text.length()) / 2;
    // Print the text at the calculated position
    mvprintw(row, col, "%s", text.c_str());
}

//==================================================================
// Prints a centered title at the specified row
// This function prints the title without clearing the line first.
//
// @param row The row where the title should be printed
// @param text The title text to be printed
//==================================================================

void UI::printCenteredTitle(int row, const string& text) {
    // Calculate the column to center the title text
    int col = (COLS - text.length()) / 2;
    // Print the title at the calculated position
    mvprintw(row, col, "%s", text.c_str());
}

//==================================================================
// Prints a block of text starting at the specified row and column
//
// @param startRow The starting row for the block
// @param startCol The starting column for the block
// @param block The block of text to be printed
//==================================================================

void UI::printBlock(int startRow, int startCol, const vector<string>& block) {
    for (size_t i = 0; i < block.size(); ++i) {
        mvprintw(startRow + i, startCol, "%s", block[i].c_str());
    }
}

//==================================================================
// Prints a centered block of text starting at the specified row
//
// @param startRow The starting row for the block
// @param block The block of text to be printed
//==================================================================

void UI::printCenteredBlock(int startRow, const vector<string>& block) {
    for (size_t i = 0; i < block.size(); ++i) {
        int col = (COLS - block[i].length()) / 2;
        mvprintw(startRow + i, col, "%s", block[i].c_str());
    }
}

//==================================================================
// Initializes the ncurses library and sets up the terminal for 
// the game.
//==================================================================

void UI::init() {
    initscr(); // Initialize ncurses
    cbreak(); // Disable line buffering
    noecho(); // Don't echo input characters
    keypad(stdscr, TRUE); // Enable function keys
    curs_set(0); // Hide the cursor
    start_color(); // Start color functionality
    init_pair(1, COLOR_WHITE, COLOR_BLACK); // Default color pair
    init_pair(2, COLOR_RED, COLOR_BLACK); // Red color pair
    init_pair(3, COLOR_GREEN, COLOR_BLACK); // Green color pair
    init_pair(4, COLOR_BLUE, COLOR_BLACK); // Blue color pair
    init_pair(5, COLOR_BLACK, COLOR_RED); // Red Black inverted
    bkgd(COLOR_PAIR(1)); // Set the background color to default
}

//==================================================================
// Shuts down the ncurses library and restores the terminal settings
//==================================================================

void UI::shutdown() {
    endwin();
}

//==================================================================
// Displays the main menu of the game
//==================================================================

Scene UI::showMainMenu() {
    // Clear the screen and draw the frame
    clearScreen();
    drawFrame();

    // Print the title, game name and skull art
    printCenteredTitle(1, "Welcome to the Game!");
    printCenteredBlock(3, UI::gameName);
    printCenteredBlock(10, UI::SkullArt);
    
    // Print the options and wait for user input
    mvprintw(36, 4, "[1] Start Game");
    mvprintw(37, 4, "[2] Options");
    mvprintw(37, 4, "[3] Exit");
    int choice = getch();
    switch (choice) {
        case '1':
            return Scene::CharacterSelector;
        case '2':
            return Scene::Options;
        case '3':
            return Scene::Exit;
        default:
            printCentered(11, "Invalid choice, please try again.");
            getch();
            return Scene::MainMenu;
    }
}

//==================================================================
// Displays the character selector screen
//
// @param heroes Vector of available Character pointers
// @return Character* pointer to the selected Character, or nullptr 
// if the user chooses to exit, or (Character*)-1 if the user 
// chooses to create a new character.
//==================================================================

Character* UI::showCharacterSelector(const vector<Character*>& heroes) {
    // Clear the screen, draw the frame and print the title
    clearScreen();
    drawFrame();

    printCenteredTitle(1, "Character Selection!");
    printCentered(5, "Choose your character:");

    // Print the list of characters    
    for (int i = 0; i < heroes.size(); ++i) {
        Character* h = heroes[i];
        int y = 10 + i;
        if (!h->isAlive()) {
            attron(COLOR_PAIR(2));
        } 
        mvprintw(y, 10, "%d) %s", i + 1, h->toString().c_str());
        attron(COLOR_PAIR(1));
    }

    // Print the create character option if there are less than 5 characters
    int optionCount = heroes.size();
    if (heroes.size() < 5) {
        mvprintw(10 + optionCount, 10, "%d) Create character [+]", optionCount + 1);
        ++optionCount;
    }

    // Evaluate user input
    mvprintw(10 + optionCount + 1, 10, "Enter your choice: ");
    while (true) {
        int key = getch();
        // Check if the user wants to exit
        if (key == '0') {
            return nullptr;
        }
        // Check if the input is a valid choice and return said choice
        int choice = key - '1';
        if (choice >= 0 && choice < (int)heroes.size()) {
            if (heroes[choice]->isAlive()) {
                return heroes[choice];
            } else {
                printCentered(36, "This character is not alive, please choose another.");
                getch();
            }
        // Check if the user wants to create a new character
        } else if (choice == heroes.size() && heroes.size() < 5) {
            // Create character option
            return (Character*)-1;
        // If the input is invalid, prompt the user to try again
        } else {
            printCentered(36, "Invalid choice, please try again.");
            getch();
        }
    } 
}

//==================================================================
// Displays the character creation screen
//
// @return A pointer to the newly created Character, or nullptr if the
// user chooses to exit or enters an invalid class choice.
//==================================================================

Character* UI::showCharacterCreator() {
    clearScreen();
    drawFrame();

    printCenteredTitle(1, "Character Creation");
    printCentered(6, "Enter your character's name: ");
    printCentered(7, "");

    // Get the character's name from user input
    char name[20] = {0};
    echo(); // Enable echoing input characters
    while (strlen(name) == 0 || strlen(name) > 20) {
        getnstr(name, sizeof(name) - 1);
    }
    noecho(); // Disable echoing input characters

    // Print the class selection options
    printCentered(8, "Choose a class:");
    printCentered(10, "[1] Warrior   [2] Archer   [3] Mage");
    int classChoice = getch();

    // Check the class choice and create the corresponding character
    Character* newHero = nullptr;
    switch (classChoice) {
        case '1':
            newHero = new Warrior(name);
            break;
        case '2':
            newHero = new Archer(name);
            break;
        case '3':
            newHero = new Mage(name);
            break;
        default:
            printCentered(10, "Invalid class choice!");
            getch();
            return nullptr;
    }

    printCentered(36, "Character created successfully!");
    getch();

    return newHero;
}

//==================================================================
// Displays the level selector screen
//
// @param levels Vector of available Level pointers
// @return A pointer to the selected Level, or nullptr if the user
// chooses to go back to the main menu or enters an invalid choice.
//==================================================================

Level* UI::showLevelSelector(const vector<Level*>& levels) {
    clearScreen();
    drawFrame();

    // Print the title and level options with their completion status
    printCenteredTitle(1, "Level Selection");
    printCentered(5, "Choose a level:");
    for (size_t i = 0; i < levels.size(); ++i) {
        string status;
        if (levels[i]->hasWon()) {
            status = "Completed";
        } else {
            status = "Not Completed";
        }
        string line = to_string(i + 1) + ") " + levels[i]->getName();
        mvprintw(10 + i, 10, "%s", line.c_str());
        mvprintw(10 + i, 100, "%s", ("Status: " + status).c_str());
    }
    mvprintw(36, 10, "[0] Back to Main Menu");

    // Print the prompt for user input
    mvprintw(10 + levels.size(), 10, "Enter your choice: ");
    while (true){
        int key = getch();
        // Back to main menu
        if (key == '0') {
            return nullptr; 
        } 
        int index = key - '1';
        // Input validation and returning the selected level
        if (index >= 0 && index < (int)levels.size()) {
            return levels[index];
        } else {
            printCentered(36, "Invalid choice, please try again.");
        }
    }
}

//==================================================================
// Displays the battle screen for a given level. 
//
// @param level The Level object containing the hero and enemy characters
// @return true if the player wins the battle, false if the player loses or exits
//==================================================================

bool UI::showBattleScreen(const Level* level) {
    clearScreen();
    drawFrame();

    // Print the title and level information
    printCenteredTitle(1, "Battle Screen");
    printCentered(3, level->getName());
    printCentered(5, level->getPrologue());
    
    // Print the options for the player
    mvprintw(36, 10, "[1] Attack");
    mvprintw(37, 10, "[2] Recover");
    mvprintw(38, 10, "[3] Exit");
    
    while (true) {
        // Print the initial battle cards for hero and enemy
        printBattleCard(level->getHero(), 10, COLS / 5 - 4);
        printBattleCard(level->getEnemy(), 10, COLS / 5 * 3 - 3);
        
        // Ask for the player's action
        int choice = getch();
        switch (choice) {
            case '1':
                //heroes attack cicle
                level->getHero()->attack(level->getEnemy());
                if ((level->getEnemy()->getShield()) > (level->getHero()->getStrength())) {
                    printCentered(28, "Your attack was absorbed by the enemy's shield!");
                } else {
                    printCentered(28, "You have attacked the enemy and dealt " + to_string(level->getHero()->getStrength()) + " damage!");
                }
                if (level->getEnemy()->isAlive()) printCentered(29, "It is now the enemy's turn");
                printCentered(30, "Press any key to continue...");
                break;
            case '2':
                //heroes recover cicle
                level->getHero()->recover();
                printCentered(28, "You have recovered some health and mana.");
                printCentered(30, "Press any key to continue...");
                break;
            case '3':
                // Exit the battle
                printCentered(10, "Exiting battle...");
                return false;
                break;
            default:
                // Invalid choice
                printCentered(10, "Invalid choice, try again.");
                getch();
                continue;
        }

        // Reprint the battle cards after player's turn
        printBattleCard(level->getHero(), 10, COLS / 5 - 4);
        printBattleCard(level->getEnemy(), 10, COLS / 5 * 3 - 3);

        // Check if the enemy is still alive and activate the enemy's turn
        if (level->getEnemy()->isAlive()) {
            getch();
            // Enemies attack cicle
            level->getEnemy()->attack(level->getHero());
            int damage = level->getEnemy()->getStrength() - level->getHero()->getShield();
            if (damage <= 0) {
                printCentered(28, "The enemy has attacked you but your shield absorbed the attack!");
            } else {
                printCentered(28, "The enemy has attacked you and dealt " + to_string(damage) + " damage!");
            }
            printCentered(29, "It is now your turn");
            printCentered(30, "Select your next action...");
            // Check if the hero is still alive
            if (!level->getHero()->isAlive()) {
                printCentered(24, "You have been defeated!");
                printCentered(28, level->getEnemy()->getName() + " has won the battle.");
                printCentered(29, level->getHero()->getName() + " is now dead!");
                printCentered(30, "Press any key to continue...");
                getch();
                return false;
                break;
            }
        // If the enemy is defeated, print the victory message
        } else {
            printCentered(24, "You have defeated the enemy!");
            printCentered(28, level->getEpilogue());
            printCentered(29, "You have won the battle!");
            printCentered(30, "Press any key to continue...");
            printBattleCard(level->getHero(), 10, COLS / 5 - 4);
            attron(COLOR_PAIR(2));
            printBattleCard(level->getEnemy(), 10, COLS / 5 * 3 - 3);
            attroff(COLOR_PAIR(1));
            getch();
            return true;
        }
    }
}

//==================================================================
// Displays the game over screen
//
// @return Scene::MainMenu to return to the main menu
//==================================================================

Scene UI::showGameOver() {
    clearScreen();
    attron(COLOR_PAIR(2));
    drawFrame();
    printCenteredTitle(1, "You have been defeated.");
    printCenteredBlock(8, gameOverArt);
    printCentered(35, "Press any key to return to the main menu...");
    getch();
    attron(COLOR_PAIR(1));
    return Scene::MainMenu;
}

//==================================================================
// Displays the options menu
// Options include: reset levels, reset characters, and exit to main 
// menu.
//
// @return Scene::MainMenu to return to the main menu
//==================================================================

Scene UI::Options(vector<Character*>& heroes, vector<Level*>& levels) {
    clearScreen();
    drawFrame();
    printCenteredTitle(1, "Options Menu");
    printCentered(5, "Choose an option:");
    mvprintw(36, 4, "[1] Reset Levels");
    mvprintw(37, 4, "[2] Reset Characters");
    mvprintw(37, 4, "[3] Exit");

    int choice = getch();
    switch (choice) {
        case '1':
            // Reset all levels and set their won status to false
            for (Level* level : levels) {
                level->setWon(false);
                level->resetEnemy();
            }
            printCentered(11, "Levels have been reset.");
            getch();
            return Scene::MainMenu;
        case '2':
            // Delete all characters and reset the heroes vector
            for (Character* hero : heroes) {
                delete hero;
            }
            printCentered(11, "Characters have been reset.");
            getch();
            return Scene::MainMenu;
        case '3':
            return Scene::MainMenu;
        default:
            printCentered(11, "Invalid choice, please try again.");
            getch();
            return Scene::Options;
    }
}

#endif
