#include "Scribble.h"

void Scribble::addPoint(float x, float y, float r, float g, float b, int size){
    points.push_back(new Point(x, y, r, g, b, size));
}

void Scribble::draw(){
    for(unsigned int i = 0; i < points.size(); i++){
        points[i]->draw();
    }
}

Scribble::~Scribble(){
    for(unsigned int i = 0; i < points.size(); i++){
        delete points[i];
    }
    points.clear();
}
bool Scribble::hitTest(float px, float py) {
    for (Point* p : points) {
        if (p->hitTest(px, py)) {
            return true;
        }
    }
    return false;
}

float Scribble::getX() const{
    if(!points.empty()) return points[0]->getX();
    return 0;

    
}

float Scribble::getY() const{
    if(!points.empty()) return points[0]->getY();
    return 0;

    
}
void Scribble::setPosition(float newX, float newY){
    if(points.empty()) return;
    float dx = newX - points[0]->getX();
    float dy = newY - points[0]->getY();

    for(Point* p : points){
        p->setPosition(p->getX() + dx, p->getY() + dy);
    }
}

void Scribble::resize(float factor){
    for(Point* p : points){
        p->resize(factor);
    }
}
void Scribble::erasePoints(float px, float py, float radius) {
    for (int i = points.size() - 1; i >= 0; --i) {
        float dx = points[i]->getX() - px;
        float dy = points[i]->getY() - py;
        if (dx * dx + dy * dy <= radius * radius) {
            delete points[i];
            points.erase(points.begin() + i);
        }
    }
}

bool Scribble::isEmpty() const{
    return points.empty();
}