
#include "Scribble.h"
#include <GL/freeglut.h>

Scribble::Scribble() {
    r = g = b = 0.0f;
}

Scribble::Scribble(const std::vector<Point>& pts, float r, float g, float b) {
    points = pts;
    this->r = r;
    this->g = g;
    this->b = b;
}

void Scribble::draw() {
    glPointSize(7.0f);
    glBegin(GL_POINTS);
    for (const auto& p : points) {
        glColor3f(p.getR(), p.getG(), p.getB());
        glVertex2f(p.getX(), p.getY());
    }
    glEnd();
}

bool Scribble::hitTest(float px, float py) {
    return contains(px, py);
}

bool Scribble::contains(float mx, float my) {
    float threshold = 0.02f; // world units; adjust if needed
    for (const auto& p : points) {
        float dx = p.getX() - mx;
        float dy = p.getY() - my;
        if (dx * dx + dy * dy <= threshold * threshold) {
            return true;
        }
    }
    return false;
}

void Scribble::setColor(float r, float g, float b) {
    for (auto& p : points) {
        p.setColor(r, g, b);
    }
}

float Scribble::getX() const {
    return points.empty() ? 0.0f : points[0].getX();
}

float Scribble::getY() const {
    return points.empty() ? 0.0f : points[0].getY();
}

void Scribble::setPosition(float x, float y) {
    if (points.empty()) return;

    float dx = x - points[0].getX();
    float dy = y - points[0].getY();

    for (auto& p : points) {
        p.setPosition(p.getX() + dx, p.getY() + dy);
    }
}