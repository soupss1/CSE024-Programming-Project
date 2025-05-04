#include "Circle.h"
#include "Polygon.h"
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <cmath>

Circle::Circle() {
    x = 0.0;
    y = 0.0;
    radius = 0.2;
    r = 0.0;
    g = 0.0;
    b = 0.0;
}

Circle::Circle(float x, float y, float r, float g, float b) {
    this->x = x; 
    this->y = y; 
    radius = 0.2;
    this->r = r; 
    this->g = g; 
    this->b = b; 
}

void Circle::draw() {
    glColor3f(r, g, b);

    float inc = M_PI / 32;
    glBegin(GL_POLYGON);
        for (float theta = 0; theta <= 2 * M_PI; theta += inc){
            glVertex2d(x + cos(theta) * radius, y + sin(theta) * radius);
        }
    glEnd();
}

bool Circle::hitTest(float px, float py) {
    float dx = px - x;
    float dy = py - y;
    return dx * dx + dy * dy <= radius * radius;
}
void Circle::setColor(float r, float g, float b) {
    this->r = r;
    this->g = g;
    this->b = b;
}
bool Circle::contains(float mx, float my) {
     float dx = mx - x;
    float dy = my - y;
    float distanceSquared = dx * dx + dy * dy;
    if (distanceSquared <= radius * radius) {
        return true;
    }
    return false;
}
    