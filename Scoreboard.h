#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <graphics.h>

// ===============================
// CLASS: Scoreboard
// CONCEPTS:
// - Encapsulation: score value is private
// - Abstraction: all score display logic is handled here
// - Aggregation: used by GameSystem, but exists independently
// ===============================
class Scoreboard {
private:
    int currentScore; // encapsulated score value

public:
    // Constructor
    Scoreboard();

    // Score display functions
    void display(int point);
    void victorymessage(int point);
    void displaygameover(int point);
};

#endif
