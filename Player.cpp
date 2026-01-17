#include "Player.h"
#include <cctype>
#include <graphics.h>

// ===============================
// Player implementation
// ===============================

Player::Player(int startX, int startY, int spd)
    : x(startX), y(startY), speed(spd), score(0) {}

Player::~Player() {}

int Player::getX() const {
    return x;
}

int Player::getY() const {
    return y;
}

int Player::getSpeed() const {
    return speed;
}

int Player::getScore() const {
    return score;
}

void Player::setX(int newX) {
    x = newX;
}

void Player::setY(int newY) {
    y = newY;
}

void Player::setSpeed(int newSpeed) {
    speed = newSpeed;
}

void Player::setScore(int newScore) {
    score = newScore;
}

// Handle player movement with road boundary limits
void Player::move(char direction) {
    int screenHeight = getmaxy();

    // ROAD LIMITS (same as original logic)
    const int ROAD_LEFT  = 195;
    const int ROAD_RIGHT = getmaxx() - 230;

    switch (toupper(direction)) {
        case 'U':
            if (y - speed > 0)
                y -= speed;
            break;

        case 'D':
            if (y + speed < screenHeight)
                y += speed;
            break;

        case 'L':
            if (x - speed > ROAD_LEFT)
                x -= speed;
            break;

        case 'R':
            if (x + speed < ROAD_RIGHT)
                x += speed;
            break;

        default:
            break;
    }
}

// Reset player position
void Player::resetPosition() {
    x = 0;
    y = 0;
}

// Draw player sprite
void Player::show() const {
    readimagefile(
        "C:\\Users\\zaky\\utm\\PT2\\coding pt2\\Project\\Updated Version Project\\Game Images\\playerpic.bmp",
        x - 25, y - 25, x + 25, y + 25
    );
}