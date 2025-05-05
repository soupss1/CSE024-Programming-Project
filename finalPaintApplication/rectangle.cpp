#include "rectangle.h"
#include <GL/freeglut.h>


Rectangle::Rectangle() {
    x = 0.0;
    y = 0.0;
    width = 0.4;
    height = 0.4;
    r = 0.0;
    g = 0.0;
    b = 0.0;
}

Rectangle::Rectangle(float x, float y, float r, float g, float b){
    this->x = x;
    this->y = y;
    width = 0.4;
    height = 0.4;
    this->r = r;
    this->g = g;
    this->b = b;
}

bool Rectangle::hitTest(float px, float py) {
    return (px >= x && px <= x + width &&
            py >= y && py <= y + height);
}

float Rectangle::getX() const { 
    return x; 
}
float Rectangle::getY() const { 
    return y; 
}
void Rectangle::setPosition(float newX, float newY) {
    x = newX;
    y = newY;
}

void Rectangle::resize(float factor){
    width *= factor;
    height *= factor;
}


void Rectangle::draw(){
    glColor3f(r, g, b);


    glBegin(GL_POLYGON);
    glVertex2f(x - width/2, y + height/2);
        glVertex2f(x + width/2, y + height/2);
        glVertex2f(x + width/2, y - height/2);
        glVertex2f(x - width/2, y - height/2);
    glEnd();
}