#include <iostream>
#include <vector>
#include <string>

class GameEngine {
public:
    void initializeGraphics() {
        std::cout << "Graphics Initialized" << std::endl;
    }

    void managePlayer(std::string playerName) {
        std::cout << "Player " << playerName << " managed!" << std::endl;
    }

    void initializeVault() {
        std::cout << "Vault System Initialized" << std::endl;
    }

    void manageWeapon(std::string weaponName) {
        std::cout << "Weapon " << weaponName << " managed!" << std::endl;
    }

    void initializePhysics() {
        std::cout << "Physics Engine Initialized" << std::endl;
    }

    void mainGameLoop() {
        std::cout << "Main Game Loop Active" << std::endl;
    }
};

int main() {
    GameEngine game;
    game.initializeGraphics();
    game.managePlayer("Player1");
    game.initializeVault();
    game.manageWeapon("Sword");
    game.initializePhysics();

    while (true) {
        game.mainGameLoop();
    }

    return 0;
}