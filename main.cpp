#include <graphics.h>
#include <conio.h>
#include <windows.h>

#include "GameSystem.h"
#include "Road.h"
#include "Car.h"

// ===============================
// MAIN MENU FUNCTION
// CONCEPTS:
// - Abstraction: menu logic separated from game logic
// - Array of Objects: animated cars in menu
// ===============================
void MainMenu() {

    initwindow(1100, 600, "Main Menu");

    int screenWidth  = getmaxx();
    int screenHeight = getmaxy();

    Road rd; // Aggregation: Road used independently

    // ARRAY OF OBJECTS (menu animation cars)
    const int numCars = 8;
    Car* cars[numCars] = {
        new Car(screenWidth / 4 + 20,     0,    80, 40, "red",    15, "DOWN", 1),
        new Car(screenWidth / 2 - 40,   100,    80, 40, "blue",   10, "DOWN", 2),
        new Car(3 * screenWidth / 4 - 100,200,  80, 40, "green",  12, "DOWN", 3),
        new Car(screenWidth / 2 - 40,  -300,    80, 40, "purple",  8, "DOWN", 4),
        new Car(screenWidth / 4 + 20,  -500,    80, 40, "red",    15, "DOWN", 1),
        new Car(3 * screenWidth / 4 - 100,-700, 80, 40, "blue",   12, "DOWN", 2),
        new Car(screenWidth / 2 - 40,  -900,    80, 40, "green",  10, "DOWN", 3),
        new Car(screenWidth / 4 + 20, -1100,    80, 40, "purple",  8, "DOWN", 4)
    };

    int page = 0;

    while (true) {

        setactivepage(page);
        setvisualpage(1 - page);
        cleardevice();

        // Background
        rd.show();

        // Menu text
        setcolor(WHITE);
        settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
        outtextxy(400, 100, (char*)"CAR RACING GAME");

        settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
        outtextxy(500, 250, (char*)"1. Start Game");
        outtextxy(500, 300, (char*)"2. Exit");

        outtextxy(250, 400,(char*)"Use W / A / S / D keys to move the player.");

        // Animate menu cars
        for (int i = 0; i < numCars; i++) {
            cars[i]->show();
            cars[i]->updatePosition(screenHeight);
        }

        // Input handling
        if (GetAsyncKeyState('1') & 0x8000) {
            closegraph();
            break;
        }

        if (GetAsyncKeyState('2') & 0x8000) {
            closegraph();
            exit(0);
        }

        delay(30);
        page = 1 - page;
    }

    // Cleanup menu cars
    for (int i = 0; i < numCars; i++) {
        delete cars[i];
    }
}

// ===============================
// MAIN FUNCTION
// CONCEPTS:
// - Abstraction: main only controls flow
// - Delegation: gameplay handled by GameSystem
// ===============================
int main() {

    MainMenu();   // show menu

    GameSystem game;   // Composition & Aggregation inside GameSystem
    game.runGameLoop();

    return 0;
}