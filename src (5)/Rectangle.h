#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape {
    float x;
    float y;
    float width;
    float height;
    float r;
    float g;
    float b;

public:
    Rectangle();
    Rectangle(float x, float y, float r, float g, float b);
    void draw();
    bool hitTest(float px, float py);
    bool contains(float mx, float my);
    void setColor(float r, float g, float b);
    float getX()const;
    float getY()const;
    void setPosition(float x, float y);
};

#endif