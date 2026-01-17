#ifndef PLAYER_H
#define PLAYER_H

#include <graphics.h>

// ===============================
// CLASS: Player
// CONCEPTS:
// - Encapsulation: position, speed, score are private
// - Abstraction: all player-related logic is inside this class
// ===============================
class Player {
private:
    int x;      // encapsulated position X
    int y;      // encapsulated position Y
    int speed;  // encapsulated movement speed
    int score;  // encapsulated score

public:
    // Constructor & Destructor
    Player(int startX = 0, int startY = 0, int spd = 1);
    ~Player();

    // Getters (Encapsulation)
    int getX() const;
    int getY() const;
    int getSpeed() const;
    int getScore() const;

    // Setters (Encapsulation)
    void setX(int x);
    void setY(int y);
    void setSpeed(int speed);
    void setScore(int score);

    // Player actions
    void move(char direction);
    void resetPosition();
    void show() const;
};

#endif
