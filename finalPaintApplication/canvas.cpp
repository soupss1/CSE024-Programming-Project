#include "Canvas.h"
#include "Polygon.h"
#include "circle.h"
#include "Scribble.h"
#include "Triangle.h"
#include "rectangle.h"
#include <GL/freeglut.h>
#include <algorithm>
#include <cstdlib>

Canvas::Canvas(int x, int y, int w, int h) : Canvas_(x, y, w, h){
    curr = nullptr;
}

void Canvas::addPoint(float x, float y, float r, float g, float b, int size){
    shapes.push_back(new Point(x, y, r, g, b, size));
}

void Canvas::addRectangle(float x, float y, float r, float g, float b) {
    shapes.push_back(new Rectangle(x, y, r, g, b));
}

void Canvas::addCircle(float x, float y, float r, float g, float b) {
    shapes.push_back(new Circle(x, y, r, g, b));
}
void Canvas::addTriangle(float x, float y, float base, float height, float r, float g, float b) {
    shapes.push_back(new Triangle(x, y, base, height, r, g, b));
}
void Canvas::addPolygon(float x, float y, int sides, float length, float r, float g, float b) {
    shapes.push_back(new Polygon(x, y, sides, length, r, g, b));
}

void Canvas::startDragging(float mx, float my){
    if(selectedShape){
        offsetX = mx - selectedShape->getX();
        offsetY = my - selectedShape->getY();
        dragging = true;
    }
}
void Canvas::stopDragging(){
    dragging = false;
}
void Canvas::dragSelectedShape(float mx, float my){
    if(selectedShape && dragging){
        selectedShape->setPosition(mx - offsetX, my - offsetY);

    }
}

void Canvas::clear(){
    for(unsigned int i = 0; i < shapes.size(); i++){
        delete shapes[i];

    }
    shapes.clear();
}

void Canvas::undo(){
    if(shapes.size() > 0){
        delete shapes[shapes.size() - 1];
        shapes.pop_back();
    }

    if(curr){
        curr-> draw();
    }
}

void Canvas::resizeSelected(float factor){
    if(selectedShape){
        selectedShape->resize(factor);
    }
}

void Canvas::eraseAt(float mx, float my) {
    
    for (int i = shapes.size() - 1; i >= 0; --i) {
       if (Scribble* s = dynamic_cast<Scribble*>(shapes[i])) {
    s->erasePoints(mx, my, 0.02);  
    if (s->isEmpty()) {               
        delete s;
        shapes.erase(shapes.begin() + i);
    }
    break;
} else if (shapes[i]->hitTest(mx, my)) {
    delete shapes[i];
    shapes.erase(shapes.begin() + i);
    break;
}
    }
}

 
Shape* Canvas::selectShapeAt(float mx, float my) {
    for (int i = shapes.size() - 1; i >= 0; --i) {
        if (shapes[i]->hitTest(mx, my)) {
            selectedShape = shapes[i];
            return selectedShape;
        }
    }
    selectedShape = nullptr;
    return nullptr;
}







void Canvas::render(){
    for(unsigned int i = 0; i < shapes.size(); i++){
        shapes[i]->draw();
    }
}

void Canvas::startScribble(){
    curr = new Scribble();
    shapes.push_back(curr);
}

void Canvas::updateScribble(float x, float y, float r, float g, float b, int size){
    if (curr){
        curr->addPoint(x, y, r, g, b, size);
        if (std::find(shapes.begin(), shapes.end(), curr) == shapes.end()) {
            shapes.push_back(curr);
        }
        redraw();
    }
    
}

void Canvas::endScribble(){
    if (curr && std::find(shapes.begin(), shapes.end(), curr) == shapes.end()){
        shapes.push_back(curr);
       
    }
     curr = nullptr;
}




void Canvas::sendToBack(){
    if(selectedShape){
        sendToBack(selectedShape);
    }
}

void Canvas::bringToFront(){
     if(selectedShape){
        bringToFront(selectedShape);
    }
}
void Canvas::bringToFront(Shape* shape){
    auto it = std::find(shapes.begin(), shapes.end(), shape);
    if(it != shapes.end()){
        shapes.erase(it);
        shapes.push_back(shape);
    }
}
void Canvas::sendToBack(Shape* shape) {
    auto it = std::find(shapes.begin(), shapes.end(), shape);
    if (it != shapes.end()) {
        shapes.erase(it);
        shapes.insert(shapes.begin(), shape);
    }
}