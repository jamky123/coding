#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>

// ===============================
// CLASS: GameObject
// CONCEPTS:
// - Encapsulation: position, size, color are protected
// - Inheritance: base class for Car and other objects
// - Polymorphism: show() can be overridden by child classes
// ===============================
class GameObject {
protected:
    int x;          // position X
    int y;          // position Y
    int width;      // object width
    int height;     // object height
    std::string color;

public:
    // Constructor & Destructor
    GameObject(int startX = 0, int startY = 0,
               int w = 10, int h = 5,
               std::string clr = "none");

    virtual ~GameObject(); // virtual destructor for polymorphism

    // Getters (Encapsulation)
    int getX() const;
    int getY() const;
    int getWidth() const;
    int getHeight() const;
    std::string getColor() const;

    // Setters (Encapsulation)
    void setX(int x);
    void setY(int y);
    void setWidth(int width);
    void setHeight(int height);
    void setColor(std::string color);

    // Virtual function (Polymorphism)
    virtual void show() const;
};

#endif
