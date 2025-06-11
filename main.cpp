#include "Level.h"
#include "Character.h"
#include "ui.h"
#include <iostream>
#include <vector>
#include <string>
#include <utility> // for std::pair
using namespace std;

vector<Level*> levels(3);
vector<Character*> heroes;
Character* player = nullptr;

void createLevels() {
    levels[0] = new Level(
        "The Duel in the Goblin's Lair",
        "The hero entered a foggy forest. Twisted trees whispered secrets. In a moonlit clearing, a mighty goblin appeared, ready to battle.",
        "The hero bravely defeated the goblin. Exhausted but victorious, he looked at the sunrise, ready for future challenges.",
        new Enemy("Goblin", 25, 15, 5, 2)
    );

    levels[1] = new Level(
        "The Battle of the Shadow Cave",
        "The cave was dark and damp, with stalactites, bats, and an oppressive atmosphere. An orc awaited the hero by a fire.",
        "The hero, bleeding but victorious, defeated the orc. Exhausted, he picked up his sword and set out for new adventures.",
        new Enemy("Orc", 75, 45, 15, 5)
    );

    levels[2] = new Level(
        "The Confrontation at the Frosty Peak",
        "On the snowy mountaintop, the hero faced the red dragon. Icy wind whipped as the dragon roared, its scales glistening. Battle imminent.",
        "The hero stood over the fallen dragon. Wind scattered ashes. Sword smoking, he looked out over the snowy landscape, triumphant.",
        new Enemy("Dragon", 100, 60, 30, 10)
    );
}

int main() {
    UI::init();
    Scene currentScene = Scene::MainMenu;
    while (currentScene != Scene::Exit) {
        switch (currentScene) {
            case Scene::MainMenu:
                currentScene = UI::showMainMenu();
                break;
            case Scene::CharacterSelector: {
                auto [nextScene, selectedHero] = UI::showCharacterSelector(heroes);
                if (selectedHero) player = selectedHero;
                currentScene = nextScene;
                break;
            }
            case Scene::CharacterCreator: {
                auto [nextScene, newHero] = UI::showCharacterCreator();
                if (newHero) heroes.push_back(newHero);
                currentScene = nextScene;
                break;
            }
            case Scene::Battle: {
                if (player) {
                    Level* currentLevel = levels[0];
                    currentLevel->addHero(player);
                    if (!player->isAlive()) {
                        currentScene = Scene::GameOver;
                    } else {
                        currentScene = Scene::Victory;
                    }
                } else {
                    cout << "No character selected!" << endl;
                    currentScene = Scene::CharacterSelector;
                }
                break;
            }
            
        }
    }    
    UI::shutdown();
    return 0;
}

