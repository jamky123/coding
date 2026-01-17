#ifndef CAR_H
#define CAR_H

#include "GameObject.h"
#include <graphics.h>
#include <string>

// ===============================
// CLASS: Car
// CONCEPTS:
// - Inheritance: Car inherits from GameObject
// - Polymorphism: overrides show() from GameObject
// - Encapsulation: speed, direction, id_car are private
// ===============================
class Car : public GameObject {
private:
    int speed;               // encapsulated speed
    std::string direction;   // movement direction (UP / DOWN)
    int id_car;              // used to select car image

public:
    // Constructor & Destructor
    Car(int startX = 0, int startY = 0,
        int w = 10, int h = 5,
        std::string clr = "red",
        int spd = 1,
        std::string dir = "RIGHT",
        int id = 0);

    ~Car();

    // Car movement behavior
    void updatePosition(int screenHeight);
    void resetToStart(int screenHeight);

    // Polymorphic function
    void show() const;
};

#endif
