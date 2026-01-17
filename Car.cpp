#include "Car.h"

// ===============================
// Car implementation
// ===============================

Car::Car(int startX, int startY, int w, int h,
         std::string clr, int spd, std::string dir, int id)
    : GameObject(startX, startY, w, h, clr),
      speed(spd),
      direction(dir),
      id_car(id) {}

Car::~Car() {}

// Update car position based on direction
void Car::updatePosition(int screenHeight) {
    if (direction == "DOWN") {
        y += speed;
        if (y > screenHeight) {
            resetToStart(screenHeight);
        }
    }
    else if (direction == "UP") {
        y -= speed;
        if (y + height < 0) {
            resetToStart(screenHeight);
        }
    }
}

// Reset car position back to starting point
void Car::resetToStart(int screenHeight) {
    int roadLeft  = 195;
    int roadRight = getmaxx() - 230;
    int laneCount = 3; // same as road->getLaneCount()
    float laneWidth = float(roadRight - roadLeft) / laneCount;

    // Determine current lane
    int currentLane = int((x - roadLeft) / laneWidth);
    if (currentLane < 0) currentLane = 0;
    if (currentLane >= laneCount) currentLane = laneCount - 1;

    // Center car in its lane
    x = roadLeft + int(currentLane * laneWidth + laneWidth / 2) - width / 2;

    // Reset Y based on movement direction
    if (direction == "DOWN") {
        y = -height;         // start above screen
    }
    else if (direction == "UP") {
        y = screenHeight;   // start below screen
    }
}

// Polymorphic drawing function
void Car::show() const {
    if (id_car == 1 || id_car == 2) {
        readimagefile(
            "C:\\Users\\zaky\\utm\\PT2\\coding pt2\\Project\\Updated Version Project\\Game Images\\car1.bmp",
            x, y, x + width, y + height
        );
    }
    else if (id_car == 3 || id_car == 4) {
        readimagefile(
            "C:\\Users\\zaky\\utm\\PT2\\coding pt2\\Project\\Updated Version Project\\Game Images\\car2.bmp",
            x, y, x + width, y + height
        );
    }

    // Draw text on the car
    setcolor(WHITE);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    outtextxy(x + width / 4, y + height / 4, (char*)"UTM");
}