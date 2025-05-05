#ifndef POLYGON_H
#define POLYGON_H

#include "Shape.h"

class Polygon: public Shape {
    float x;
    float y;
    int sides;
    float length;
    float r;
    float g;
    float b;

public:
    Polygon();
    Polygon(float x, float y, int sides, float length, float r, float g, float b);
    float getX() const;
float getY() const;
void setPosition(float x, float y);
    void resize(float factor);
    void draw();
    bool hitTest(float px, float py);

    friend struct AppTest;
};

#endif