#ifndef SCRIBBLE_H
#define SCRIBBLE_H

#include "Shape.h"
#include "Point.h"
#include <vector>

class Scribble: public Shape {
std::vector<Point*> points;

public:
void addPoint(float x, float y, float r, float g, float b, int size);
void erasePoints(float px, float py, float radius);
bool hitTest(float px, float py);
void resize(float factor);
bool isEmpty()const;

float getX()const;
float getY()const;
void setPosition(float x, float y);

void draw();

~Scribble();
};

#endif