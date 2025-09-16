# RPG Battle Game (POO University Project on Unix operating system)

This is a turn-based RPG battle game developed in C++ as part of the Object-Oriented Programming (POO) course at Tecnológico de Monterrey. The game includes character creation, level selection, permadeath mechanics, and a UI powered by `ncurses`.

--- 

## Building the project
---
### Dependencies
- C++17 or higher
- ncurses library
- Unix system

To install ncurses on Debian/Ubuntu:

```
sudo apt-get install libncurses5-dev libncursesw5-dev
```

### Compilation

To compile the game, run:

```
g++ main.cpp -o rpg -lncurses
```

To execute the game just run 
```
./rpg
```

---

## Project Overview

This RPG allows the player to:
- Create up to 3 unique characters (Warrior, Archer, Mage).
- Battle against different enemies in sequential levels.
- View real-time stats using a custom UI.
- Save and load progress using binary serialization.
- Experience permadeath: characters that die remain dead until reset.
- Reset levels and characters from the options menu.

---

## Features and Innovations

### Core Features:
- Abstract base class `Character` and polymorphic classes `Warrior`, `Archer`, `Mage`, and `Enemy`.
- Turn-based battle logic with strength, mana, shield, and health.
- Dynamic level system using `Level` class.

### Innovations:
- **Scene System with Enum Class:** Allows smooth scene transitions using `Scene` enum (`MainMenu`, `CharacterSelector`, `CharacterCreator`, etc).
- **ncurses-based UI:** Enables real-time rendering, text-based health bars, and navigation.
- **Save System:** Game progress is saved in a binary file using `SaveManager.h`.
- **Character Permadeath:** Dead characters remain dead across sessions.
- **Multiple Character Slots:** Players can create and reuse up to 5 characters.
- **Reset System:** Resets either all levels or all characters from the options menu.

---

## File Structure

```plaintext
.
├── Character.h       # Character classes: Character, Warrior, Mage, Archer, Enemy
├── Level.h           # Level management class
├── ui.h              # UI and scene control (menu, combat, etc)
├── saveManager.h     # Save/load functionality via binary files
├── main.cpp          # Entry point and game loop
