#ifndef POINT_H
#define POINT_H

#include "Shape.h"

class Point: public Shape{
float x;
float y;
float r;
float g;
float b;
int size;

public:
Point();
void resize(float factor);

Point(float x, float y);
Point(float x, float y, float r, float g, float b);
Point(float x, float y, float r, float g, float b, int size);
bool hitTest(float px, float py);


void draw();

float getX() const;
float getY() const;
void setPosition(float x, float y);
float getR() const;
float getG() const;
float getB() const;
int getSize() const;
};


#endif