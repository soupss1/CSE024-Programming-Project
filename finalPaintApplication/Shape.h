#ifndef SHAPE_H
#define SHAPE_H
#include <GL/freeglut.h>
#include <GL/gl.h>

class Shape{

    public:
    virtual float getX() const = 0;
    virtual float getY() const = 0;
    virtual void setPosition(float x, float y) = 0;
    virtual void draw() = 0;
    virtual bool hitTest(float x, float y) = 0;
    virtual void resize(float factor) = 0;
    virtual ~Shape(){}
};

#endif