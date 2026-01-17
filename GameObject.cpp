#include "GameObject.h"
#include <iostream>
#include <graphics.h>

// ===============================
// GameObject implementation
// ===============================

GameObject::GameObject(int startX, int startY,
                       int w, int h, std::string clr)
    : x(startX), y(startY), width(w), height(h), color(clr) {}

GameObject::~GameObject() {}

int GameObject::getX() const {
    return x;
}

int GameObject::getY() const {
    return y;
}

int GameObject::getWidth() const {
    return width;
}

int GameObject::getHeight() const {
    return height;
}

std::string GameObject::getColor() const {
    return color;
}

void GameObject::setX(int newX) {
    x = newX;
}

void GameObject::setY(int newY) {
    y = newY;
}

void GameObject::setWidth(int w) {
    width = w;
}

void GameObject::setHeight(int h) {
    height = h;
}

void GameObject::setColor(std::string clr) {
    color = clr;
}

// Base implementation (can be overridden)
void GameObject::show() const {
    // intentionally empty
}