
#include "GameSystem.h"
#include "Road.h"        
#include "Player.h"
#include "Car.h"
#include "Scoreboard.h"
#include <graphics.h>
#include <windows.h>
#include <cstdlib>

// ===============================
// GameSystem implementation
// ===============================

GameSystem::GameSystem() {

    // Initialize graphics window
    initwindow(1100, 600, "My Game");

    // COMPOSITION: Player is created and owned by GameSystem
    player = new Player(getmaxx() / 2, getmaxy() - 80, 10);

    // AGGREGATION: Environment objects
    road = new Road();
    scoreBoard = new Scoreboard();

    isGameOver = false;

    const int ROAD_LEFT  = 195;
    const int ROAD_RIGHT = getmaxx() - 230;
    const int CAR_WIDTH  = 80;
    const int CAR_HEIGHT = 40;

    int roadWidth = ROAD_RIGHT - ROAD_LEFT;

    // ARRAY OF OBJECTS: multiple cars
    carCount = MAX_CARS;

    int spacing = 0;
    if (carCount > 1) {
        spacing = (roadWidth - carCount * CAR_WIDTH) / (carCount - 1);
    }

    int startY = 50;
    for (int i = 0; i < carCount; i++) {
        int x = ROAD_LEFT + i * (CAR_WIDTH + spacing);
        int id_car = i % 4 + 1;

        cars[i] = new Car(
            x,
            startY,
            CAR_WIDTH,
            CAR_HEIGHT,
            "red",
            6,
            "DOWN",
            id_car
        );
    }
}

GameSystem::~GameSystem() {

    // COMPOSITION cleanup
    delete player;

    // AGGREGATION cleanup
    delete road;
    delete scoreBoard;

    // ARRAY cleanup
    for (int i = 0; i < carCount; i++) {
        delete cars[i];
    }
}

// ===============================
// Main game loop
// ===============================
void GameSystem::runGameLoop() {

    int CAR_SPEED = 7;

    int page = 0;                 // double buffering
    DWORD startTime = GetTickCount();
    bool showFinishLine = false;

    int gapIndex = rand() % carCount;
    bool gapPassed = false;

    static int sharedY = 50;

    while (!isGameOver) {

        setactivepage(page);
        setvisualpage(1 - page);
        cleardevice();

        // Draw road
        road->show();

        // Finish line logic
        if (!showFinishLine && GetTickCount() - startTime >= 15000) {
            showFinishLine = true;
        }
        if (showFinishLine) {
            road->drawFinishLine();
        }

        // Move cars
        sharedY += CAR_SPEED;

        if (sharedY > getmaxy()) {
            sharedY = -40;
            gapIndex = rand() % carCount;
            gapPassed = false;
        }

        // Draw cars (array of objects)
        for (int i = 0; i < carCount; i++) {
            cars[i]->setY(sharedY);

            if (i != gapIndex) {
                cars[i]->show();
            } else {
                setfillstyle(SOLID_FILL, BLACK);
                bar(
                    cars[i]->getX(),
                    sharedY,
                    cars[i]->getX() + cars[i]->getWidth(),
                    sharedY + cars[i]->getHeight()
                );
            }
        }

        // Scoring logic
        Car* gapCar = cars[gapIndex];

        if (!gapPassed &&
            player->getX() + 40 > gapCar->getX() &&
            player->getX() < gapCar->getX() + gapCar->getWidth() &&
            player->getY() <= sharedY + gapCar->getHeight()) {

            player->setScore(player->getScore() + 50);
            gapPassed = true;
        }

        // Draw player
        player->show();

        // Display score
        scoreBoard->display(player->getScore());

        // Player input
        if (GetAsyncKeyState('W') & 0x8000) player->move('U');
        if (GetAsyncKeyState('S') & 0x8000) player->move('D');
        if (GetAsyncKeyState('A') & 0x8000) player->move('L');
        if (GetAsyncKeyState('D') & 0x8000) player->move('R');

        // Collision detection
        for (int i = 0; i < carCount; i++) {
            if (i == gapIndex) continue;

            if (player->getX() < cars[i]->getX() + cars[i]->getWidth() &&
                player->getX() + 40 > cars[i]->getX() &&
                player->getY() < cars[i]->getY() + cars[i]->getHeight() &&
                player->getY() + 40 > cars[i]->getY()) {

                isGameOver = true;
                break;
            }
        }

        // Finish line reached
        if (player->getY() <= 50) {
            isGameOver = true;
        }

        page = 1 - page;
        delay(20);
    }

    // End screen
    setactivepage(0);
    setvisualpage(0);
    cleardevice();

    if (player->getY() <= 50) {
        scoreBoard->victorymessage(player->getScore());
        delay(3000);
    } else {
        scoreBoard->displaygameover(player->getScore());
        delay(3000);
    }

    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    outtextxy(350, 500, (char*)"Press any key to exit...");
    while (kbhit()) getch();   // clear old input

    while (true) {// wait until key press
    if (kbhit()) break;
    if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) break;
    delay(50);
}

    closegraph();
}