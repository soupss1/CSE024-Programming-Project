#ifndef SCRIBBLE_H
#define SCRIBBLE_H


#include "Shape.h"
#include "Point.h"
#include <vector>


class Scribble: public Shape {

    std::vector<Point> points;
    float r,g,b;

    public:

    Scribble();

    Scribble(const std::vector<Point>& points, float r, float g, float b);

    void draw();
    bool hitTest(float px, float py);
    bool contains(float mx, float my);
    void setColor(float r, float g, float b);

};

#endif