#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"



class Circle : public Shape{
float x;
float y;
float radius;
float r;
float g;
float b;

public:
Circle();
Circle(float x, float y, float r, float g, float b);
bool hitTest(float px, float py);
float getX() const;
float getY() const;
void setPosition(float x, float y);
void resize(float factor);
void draw();

};



#endif