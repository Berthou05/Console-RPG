#ifndef UI_H
#define UI_H

#include "Character.h"
#include <ncurses.h>
#include <string>
#include <vector>
#include <utility> // for std::pair
#include <iostream>
#include <cstring>

enum class Scene {
    MainMenu,
    CharacterSelector,
    CharacterCreator,
    LevelSelect,
    Prologue,
    Battle,
    Epilogue,
    GameOver,
    Victory,
    Exit
};

class UI {
private:
    static void drawFrame();
    static void printCentered(int row, const std::string& text);
    static void printBlock(int startRow, int startCol, const std::vector<std::string>& block);
    static void printCenteredBlock(int startRow, const std::vector<std::string>& block);
    static const std::vector<std::string> gameName;
    static const std::vector<std::string> SkullArt;
public:
    static void init();
    static void shutdown();
    static void clearScreen();
    
    static Scene showMainMenu();
    static std::pair<Scene, Character*> showCharacterSelector(const std::vector<Character*>& heroes);
    static std::pair<Scene, Character*> showCharacterCreator();
    // static Scene showLevelSelector();
    // static Scene showPrologue(const std::string& text);
    // static Scene showBattleScreen(const std::string& playerStats, const std::string& enemyStats);
    // static Scene showEpilogue(const std::string& text);
    // static Scene showGameOver();
    // static Scene showVictory();
  
};

const std::vector<std::string> UI::gameName = {
    " _   _       _   _                      ",
    "| \\ | |     | \\ | |                     ",
    "|  \\| | ___ |  \\| | ___  _ __ ___   ___ ",
    "| . ` |/ _ \\| . ` |/ _ \\| '_ ` _ \\ / _ \\",
    "| |\\  | (_) | |\\  | (_) | | | | | |  __/",
    "\\_| \\_/\\___/\\_| \\_/\\___/|_| |_| |_|\\___|"
};

const std::vector<std::string> UI::SkullArt = {
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

void UI::clearScreen() {
    erase();
    refresh();
}

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

void UI::printCentered(int row, const std::string& text) {
    int col = (COLS - text.length()) / 2;
    mvprintw(row, col, "%s", text.c_str());
}

void UI::printBlock(int startRow, int startCol, const std::vector<std::string>& block) {
    for (size_t i = 0; i < block.size(); ++i) {
        mvprintw(startRow + i, startCol, "%s", block[i].c_str());
    }
}

void UI::printCenteredBlock(int startRow, const std::vector<std::string>& block) {
    for (size_t i = 0; i < block.size(); ++i) {
        int col = (COLS - block[i].length()) / 2;
        mvprintw(startRow + i, col, "%s", block[i].c_str());
    }
}


void UI::init() {
    initscr();            // Initialize ncurses
    cbreak();             // Disable line buffering
    noecho();             // Don't echo input characters
    keypad(stdscr, TRUE); // Enable function keys
    curs_set(0);          // Hide the cursor
    start_color();        // Start color functionality
    init_pair(1, COLOR_WHITE, COLOR_BLACK); // Default color pair
    bkgd(COLOR_PAIR(1));
}

void UI::shutdown() {
    endwin();
}

Scene UI::showMainMenu() {
    clearScreen();
    drawFrame();
    printCentered(1, "Welcome to the Game!");
    printCenteredBlock(3, UI::gameName);
    printCenteredBlock(10, UI::SkullArt);
    
    mvprintw(36, 4, "[1] Start Game");
    mvprintw(37, 4, "[2] Exit");
    int choice = getch();
    switch (choice) {
        case '1':
            return Scene::CharacterSelector;
        case '2':
            return Scene::Exit;
        default:
            printCentered(11, "Invalid choice, please try again.");
            getch();
            return Scene::MainMenu;
    }
}

std::pair<Scene, Character*> UI::showCharacterSelector(const vector<Character*>& heroes) {
    clearScreen();
    drawFrame();

    printCentered(1, "Character Selection!");
    printCentered(5, "Choose your character:");

    
    for (int i = 0; i < heroes.size(); ++i) {
        Character* h = heroes[i];
        int y = 10 + i;
        mvprintw(y, 10, "%d) %s", i + 1, h->toString().c_str());
    }

    int optionCount = heroes.size();
    if (heroes.size() < 5) {
        mvprintw(10 + optionCount, 10, "%d) Create character [+]", optionCount + 1);
        ++optionCount;
    }

    mvprintw(10 + optionCount + 1, 10, "Enter your choice: ");
    int choice = getch() - '1';

    if (choice >= 0 && choice < heroes.size()) {
        return {Scene::Battle, heroes[choice]};
    } else if (choice == heroes.size() && heroes.size() < 5) {
        return {Scene::CharacterCreator, nullptr};
    } else {
        printCentered(36, "Invalid choice, please try again.");
        return {Scene::CharacterSelector, nullptr};
    }
}

std::pair<Scene, Character*> UI::showCharacterCreator() {
    clearScreen();
    drawFrame();

    printCentered(1, "Character Creation");
    printCentered(4, "Enter your character's name: ");

    char name[50];
    echo();
    getnstr(name, sizeof(name) - 1);
    noecho();

    if (strlen(name) == 0) {
        printCentered(6, "Name cannot be empty!");
        getch();
        return {Scene::CharacterCreator, nullptr};
    }

    printCentered(6, "Choose a class:");
    printCentered(8, "[1] Warrior   [2] Archer   [3] Mage");
    int classChoice = getch();

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
            return {Scene::CharacterCreator, nullptr};
    }

    printCentered(12, "Character created successfully!");
    getch();

    return {Scene::CharacterSelector, newHero};
}




#endif
