#ifndef GAME_H
#define GAME_H

#include <glm/glm.hpp>
#include <vector>
#include <map>
#include <memory>

class Player;
class Vault;
class Gun;
class GunMod;
class Physics;
class Graphics3D;
class REPO;

class Game {
public:
    Game(int width, int height);
    ~Game();
    
    // Game lifecycle
    void Initialize();
    void Update(float deltaTime);
    void Render();
    void Run();
    void Shutdown();
    
    // Game state management
    void PauseGame();
    void ResumeGame();
    bool IsRunning() const;
    
    // Player management
    Player* GetPlayer();
    void SetPlayer(Player* player);
    
    // Vault management
    Vault* GetCurrentVault();
    void LoadVault(const std::string& vaultName);
    
    // Weapon management
    void AddWeapon(Gun* gun);
    Gun* GetWeapon(int index);
    void RemoveWeapon(int index);
    
    // Physics
    Physics* GetPhysicsEngine();
    
    // Graphics
    Graphics3D* GetGraphicsEngine();
    
private:
    int screenWidth;
    int screenHeight;
    bool isRunning;
    bool isPaused;
    
    std::unique_ptr<Player> player;
    std::unique_ptr<Vault> currentVault;
    std::unique_ptr<Physics> physicsEngine;
    std::unique_ptr<Graphics3D> graphicsEngine;
    
    std::vector<std::unique_ptr<Gun>> weapons;
    std::map<std::string, std::unique_ptr<GunMod>> gunMods;
    
    float gameTime;
    float deltaTime;
};

#endif // GAME_H
