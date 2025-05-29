#ifndef UI_H
#define UI_H

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <windows.h>

using namespace std;

class UI {
private:
    int width, height;
public:
    static int borderScaling; // Scaling factor for borders and margins
    static void clearTerminal();
    static int terminalHeight();
    static int terminalWidth();
    static void printMenu();
    static void printUI();
    static void printCentered(const string& text);
    static void printLeftAligned(const string& text);
    static void printTopBorder();
    static void printBottomBorder();
    static void printMarginHeight();
    static void printMarginWidth();
    static void printGameName();
};

// Visual Parameters
int UI::borderScaling = 4;

void UI::clearTerminal() {
// Clear the terminal screen
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int UI::terminalHeight() {
    // Get the size of the terminal
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.dwSize.Y;
}

int UI::terminalWidth() {
    // Get the size of the terminal
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.dwSize.X;
}

void UI::printTopBorder() {
    int width = terminalWidth();
    printMarginHeight();
    printMarginWidth();
    for (int i = 0; i < (width - 2*(width/borderScaling)); i++) {
        cout << "-";
    }
    cout << "\n";
}

void UI::printBottomBorder() {
    int width = terminalWidth();
    printMarginWidth();
    for (int i = 0; i < (width - 2*(width/borderScaling)); i++) {
        cout << "-";
    }
    printMarginWidth();
    cout << "\n";
    printMarginHeight();
}

void UI::printMarginHeight() {
    int height = terminalHeight();
    for (int i = 0; i < height/7; i++) {
        cout << "\n";
    }
}

void UI::printMarginWidth() {
    int width = terminalWidth();
    for (int i = 0; i < width/borderScaling; i++) {
        cout << " ";
    }
}

void UI::printUI() {
    int width = terminalWidth();
    int height = terminalHeight();
    clearTerminal();
    printTopBorder();
    printCentered("Welcome to the Game!");
    printGameName();
    for (int i = 0; i < height/8; i++) {
        cout << "\n";
    }
    printMenu();
    for (int i = 0; i < height/12; i++) {
        cout << "\n";
    }
    printCentered("Press selected key to continue...");
    for (int i = 0; i < height/12; i++) {
        cout << "\n";
    }
    printBottomBorder();

}

void UI::printCentered(const string& text) {
    int width = terminalWidth();
    int padding = (width - text.length())/2;
    for (int i = 0; i < padding; i++) {
        cout << " ";
    }
    cout << text;
    for (int i = 0; i < padding; i++) {
        cout << " ";
    }
    cout << "\n";
}

void UI::printLeftAligned(const string& text) {
    int width = terminalWidth();
    int padding = width - (width/borderScaling) - text.length();
    printMarginWidth();
    cout << text;
    for (int i = 0; i < padding; i++) {
        cout << " ";
    }
    cout << "\n";
}

void UI::printMenu() {
    printLeftAligned("1. Start Game");
    cout << "\n";
    printLeftAligned("2. Load Game");
    cout << "\n";
    printLeftAligned("3. Settings");
    cout << "\n";
    printLeftAligned("4. Exit");
    cout << "\n";
}

void UI::printGameName() {
    // prints a function of the game name in ASCII art "No Name" centered in the terminal using center text
    printCentered(" _   _       _   _                      ");
    printCentered("| \\ | |     | \\ | |                     ");
    printCentered("|  \\| | ___ |  \\| | ___  _ __ ___   ___ ");
    printCentered("| . ` |/ _ \\| . ` |/ _ \\| '_ ` _ \\ / _ \\");
    printCentered("| |\\  | (_) | |\\  | (_) | | | | | |  __/");
    printCentered("\\_| \\_/\\___/\\_| \\_/\\___/|_| |_| |_|\\___|");
}

#endif