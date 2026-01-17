#include "Road.h"
#include <graphics.h>

// ===============================
// Road implementation
// ===============================

Road::Road(int laneCount, double length)
    : laneCount(laneCount), length(length) {}

int Road::getLaneCount() const {
    return laneCount;
}

void Road::setLaneCount(int lanes) {
    laneCount = lanes;
}

double Road::getLength() const {
    return length;
}

void Road::setLength(double len) {
    length = len;
}

// Draw road background image
void Road::show() const {
    readimagefile(
        "C:\\Users\\zaky\\utm\\PT2\\coding pt2\\Project\\Updated Version Project\\Game Images\\road.bmp",
        0, 0, 1100, 600
    );
}

// Draw finish line on the road
void Road::drawFinishLine() const {
    int roadLeft  = 195;
    int roadRight = getmaxx() - 230;

    setcolor(RED);
    setlinestyle(SOLID_LINE, 0, 3);
    line(roadLeft, 30, roadRight, 30);
}