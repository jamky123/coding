#include "Scoreboard.h"
#include <string>
#include <graphics.h>

// ===============================
// Scoreboard implementation
// ===============================

Scoreboard::Scoreboard() : currentScore(0) {}

// Display current score during gameplay
void Scoreboard::display(int point) {
    currentScore = point;

    setcolor(WHITE);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);

    std::string scoreText = "Score: " + std::to_string(point);
    outtextxy(10, 10, (char*)scoreText.c_str());
}

// Display victory message at end of game
void Scoreboard::victorymessage(int point) {
    cleardevice();

    setcolor(GREEN);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);

    std::string victoryText =
        "Congratulations! You Win! Final Score: " + std::to_string(point);

    outtextxy(200, 250, (char*)victoryText.c_str());
}

// Display game over message
void Scoreboard::displaygameover(int point) {
    cleardevice();

    setcolor(RED);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);

    std::string gameOverText =
        "Game Over! Final Score: " + std::to_string(point);

    outtextxy(200, 250, (char*)gameOverText.c_str());
}