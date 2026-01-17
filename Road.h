#ifndef ROAD_H
#define ROAD_H


// ===============================
// Road implementation
// ===============================

class Road {
private:
    int laneCount; // number of lanes
    double length; // length of the road
public:
    Road(int laneCount = 1, double length = 0.0);
    int getLaneCount() const;
    void setLaneCount(int lanes);
    double getLength() const;
    void setLength(double len);
    void show() const;           // display road info
    void drawFinishLine() const; // draw the finish line
};
#endif // ROAD_H