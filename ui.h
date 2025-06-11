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

enum class Scene {
    MainMenu,
    CharacterSelector,
    CharacterCreator,
    LevelSelect,
    Battle,
    GameOver,
    Victory,
    Exit
};

class UI {
private:
    static void drawFrame();
    static void printCentered(int row, const string& text);
    static void printBlock(int startRow, int startCol, const vector<string>& block);
    static void printCenteredBlock(int startRow, const vector<string>& block);
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
    // static Scene showVictory();

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

void UI::printCentered(int row, const string& text) {
    int col = (COLS - text.length()) / 2;
    mvprintw(row, col, "%s", text.c_str());
}

void UI::printBlock(int startRow, int startCol, const vector<string>& block) {
    for (size_t i = 0; i < block.size(); ++i) {
        mvprintw(startRow + i, startCol, "%s", block[i].c_str());
    }
}

void UI::printCenteredBlock(int startRow, const vector<string>& block) {
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
    init_pair(2, COLOR_RED, COLOR_BLACK); // Red color pair
    init_pair(3, COLOR_GREEN, COLOR_BLACK); // Green color pair
    init_pair(4, COLOR_BLUE, COLOR_BLACK); // Blue color pair
    init_pair(5, COLOR_BLACK, COLOR_RED); // Red Black inverted
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

Character* UI::showCharacterSelector(const vector<Character*>& heroes) {
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
    int choice;
    while (choice < '1' || choice > '0'  + optionCount ) {
        choice = getch();
        if (choice < '1' || choice > '0' + optionCount) {
            printCentered(36, "Invalid choice, please try again.");
        }
    }
    choice -= '1';
    if (choice >= 0 && choice < heroes.size()) {
        return heroes[choice];
    } else if (choice == heroes.size() && heroes.size() < 5) {
        return nullptr;
    } else {
        printCentered(36, "Invalid choice, please try again.");
        return nullptr;
    }
}

Character* UI::showCharacterCreator() {
    clearScreen();
    drawFrame();

    printCentered(1, "Character Creation");
    printCentered(6, "Enter your character's name: ");
    printCentered(7, "");

    char name[50] = {0};
    echo();
    while (strlen(name) == 0 || strlen(name) > 50) {
        getnstr(name, sizeof(name) - 1);
    }
    noecho();

    printCentered(8, "Choose a class:");
    printCentered(10, "[1] Warrior   [2] Archer   [3] Mage");
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
            return nullptr;
    }

    printCentered(16, "Character created successfully!");
    getch();

    return newHero;
}

Level* UI::showLevelSelector(const vector<Level*>& levels) {
    clearScreen();
    drawFrame();

    printCentered(1, "Level Selection");
    printCentered(5, "Choose a level:");
    for (size_t i = 0; i < levels.size(); ++i) {
        std::string status = levels[i]->hasWon() ? "Completed" : "Not Completed";
        std::string line = std::to_string(i + 1) + ") " + levels[i]->getName() + "\t\tStatus: " + status;
        mvprintw(10 + i, 10, "%s", line.c_str());
    }
    mvprintw(10 + levels.size(), 10, "Enter your choice: ");
    char input[8] = {0};
    int key = getch();
    int index = key - '1';

    if (index >= 0 && index < (int)levels.size()) {
        return levels[index];
    } else {
        printCentered(36, "Invalid choice, please try again.");
        return nullptr;
    }
}

bool UI::showBattleScreen(const Level* level) {
    clearScreen();
    drawFrame();

    printCentered(1, "Battle Screen");
    printCentered(3, level->getName());
    printCentered(5, level->getPrologue());
    

    mvprintw(36, 10, "[1] Attack");
    mvprintw(37, 10, "[2] recover");
    mvprintw(38, 10, "[3] Exit");
    
    while (true) {
        if (!(level->getHero() == nullptr || level->getEnemy() == nullptr)) {
            mvprintw(7, 10, "%s", level->getHero()->toString().c_str());
            mvprintw(9, 10, "%s", level->getEnemy()->toString().c_str());    
        } else { return false; }

        int choice = getch();

        switch (choice) {
            case '1':
                level->getHero()->attack(level->getEnemy());
                break;
            case '2':
                level->getHero()->recover();
                printCentered(30, "You have recovered some health and mana.");
                break;
            case '3':
                printCentered(10, "Exiting battle...");
                return false;
                break;
            default:
                printCentered(10, "Invalid choice, try again.");
                getch();
                continue;
        }

        if (level->getEnemy()->isAlive()) {
            level->getEnemy()->attack(level->getHero());
            printCentered(30, "The enemy has attacked you!");
            if (!level->getHero()->isAlive()) {
                printCentered(10, "You have been defeated!");
                printCentered(30, level->getEnemy()->getName() + " has won the battle.");
                getch();
                return false;
                break;
            }
        } else {
            printCentered(10, "You have defeated the enemy!");
            printCentered(30, level->getEpilogue());
            level->hasWon();
            getch();
            return true;
        }
    }
}

Scene UI::showGameOver() {
    clearScreen();
    attron(COLOR_PAIR(2));
    drawFrame();
    printCentered(1, "You have been defeated.");
    printCenteredBlock(8, gameOverArt);
    printCentered(35, "Press any key to return to the main menu...");
    getch();
    attron(COLOR_PAIR(1));
    return Scene::MainMenu;
}


#endif
