#include "Polygon.h"
#include <GL/freeglut.h>
#include <cmath>

Polygon::Polygon() {
    x = 0.0;
    y = 0.0;
    sides = 5;
    length = 0.1;
    r = 0.0;
    g = 0.0;
    b = 0.0;
}

Polygon::Polygon(float x, float y, int sides, float length, float r, float g, float b) {
    this->x = x;
    this->y = y;
    this->sides = sides;
    this->length = length;
    this->r = r;
    this->g = g;
    this->b = b;
}

void Polygon::draw() {
    glColor3f(r, g, b);
    
    glBegin(GL_POLYGON);
        float inc = 2 * M_PI / sides;
        for (float theta = 0; theta <= 2 * M_PI; theta += inc) {
            glVertex2f(x + length * cos(theta), y + length * sin(theta));
        }
    glEnd();
}
bool Polygon::hitTest(float px, float py) {
    return (px >= x - length && px <= x + length &&
            py >= y - length && py <= y + length);
}
void Polygon::setColor(float r, float g, float b) {
    this->r = r;
    this->g = g;
    this->b = b;
}
bool Polygon::contains(float mx, float my) {
    // only works for hexagons as the draw fnc only draws hexagons
    if (sides != 6) {
        return false; 
    }

    bool inside = false;
    float angleStep = 2.0f * M_PI / 6.0f;
    float vertices[6][2];

    // Generate hexagon vertices
    for (int i = 0; i < 6; ++i) {
        float angle = i * angleStep;
        vertices[i][0] = x + length * cos(angle);
        vertices[i][1] = y + length * sin(angle);
    }


    for (int i = 0, j = 5; i < 6; j = i++) {
        float xi = vertices[i][0];
        float yi = vertices[i][1];
        float xj = vertices[j][0];
        float yj = vertices[j][1];

        if (((yi > my) != (yj > my))) {
            float intersectX = (xj - xi) * (my - yi) / (yj - yi + 0.00001f) + xi;
            if (mx < intersectX) {
                if (!inside) {
                    inside = true;
                } else {
                    inside = false;
                }
            }
        }
    }

    if (inside) {
        return true;
    }
    return false;
}