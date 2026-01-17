#ifndef GAMESYSTEM_H
#define GAMESYSTEM_H

#include "Player.h"
#include "Car.h"
#include "Road.h"
#include "Scoreboard.h"

// ===============================
// CLASS: GameSystem
// CONCEPTS:
// - Composition: owns Player (created & destroyed here)
// - Aggregation: uses Road, Scoreboard, Cars
// - Array of Objects: array of Car pointers
// - Abstraction: central game control logic
// ===============================
class GameSystem {
private:
    // COMPOSITION (strong ownership)
    Player* player;

    // AGGREGATION (used but independent)
    static const int MAX_CARS = 5;
    Car* cars[MAX_CARS];

    Road* road;
    Scoreboard* scoreBoard;

    int carCount;
    bool isGameOver;

public:
    // Constructor & Destructor
    GameSystem();
    ~GameSystem();

    // Main game loop
    void runGameLoop();
};

#endif
