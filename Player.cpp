#include <iostream>
#include <vector>
#include <string>

class Player {
private:
    int health;
    int armor;
    std::vector<std::string> inventory;

public:
    Player(int h, int a) : health(h), armor(a) {}

    void takeDamage(int damage) {
        damage -= armor;
        if (damage < 0) damage = 0;
        health -= damage;
        if (health < 0) health = 0;
    }
    
    void heal(int amount) {
        health += amount;
    }

    void addItem(const std::string& item) {
        inventory.push_back(item);
    }

    void removeItem(const std::string& item) {
        auto it = std::find(inventory.begin(), inventory.end(), item);
        if (it != inventory.end()) {
            inventory.erase(it);
        }
    }

    void showInventory() const {
        std::cout << "Inventory:\n";
        for (const auto &item : inventory) {
            std::cout << "- " << item << '\n';
        }
    }

    int getHealth() const { return health; }
    int getArmor() const { return armor; }
};

int main() {
    Player player(100, 5);
    player.addItem("Sword");
    player.addItem("Shield");
    player.takeDamage(10);
    player.showInventory();
    return 0;
}