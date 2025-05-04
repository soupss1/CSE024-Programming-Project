#ifndef CANVAS_H
#define CANVAS_H

#include <bobcat_ui/all.h>
#include <vector>
#include "Point.h"
#include "Polygon.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Shape.h"
#include "Triangle.h"

class Canvas : public bobcat::Canvas_ {
    std::vector<Point*> points;
    std::vector<Shape*> shapes;
    


public:
    Canvas(int x, int y, int w, int h);

    void addPoint(float x, float y, float r, float g, float b, int size);

    void addRectangle(float x, float y, float r, float g, float b);

    void addCircle(float x, float y, float r, float g, float b);

    void addTriangle(float x, float y, float base, float height, float r, float g, float b);

    void addPolygon(float x, float y, int sides, float length, float r, float g, float b);

    void eraseAt(float x, float y);

    void clear();

    void render();
    Shape* getSelectedShape(float mx, float my);
};

#endif