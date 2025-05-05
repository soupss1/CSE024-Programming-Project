#ifndef CANVAS_H
#define CANVAS_H


#include <bobcat_ui/all.h>
#include <vector>
#include "Point.h"
#include "rectangle.h"
#include "circle.h"
#include "Shape.h"
#include "Triangle.h"
#include "Scribble.h"
#include "Polygon.h"

class Canvas : public bobcat::Canvas_{
std::vector<Shape*> shapes;
Scribble* curr;

Shape* selectedShape = nullptr;
float offsetX = 0;
float offsetY = 0;
bool dragging = false;


public:
Canvas(int x, int y, int w, int h);

void addPoint(float x, float y, float r, float g, float b, int size);
void resizeSelected(float factor);

void addRectangle(float x, float y, float r, float g, float b);
void addCircle(float x, float y, float r, float g, float b);
void addTriangle(float x, float y, float base, float height, float r, float g, float b);
void addPolygon(float x, float y, int sides, float length, float r, float g, float b);
void clear();
void undo();
void eraseAt(float x, float y);
void startScribble();


void updateScribble(float x, float y, float r, float g, float b, int size);

void endScribble();

void render();

void sendToBack();              
void bringToFront();          
void sendToBack(Shape* shape);
void bringToFront(Shape* shape);


Shape* selectShapeAt(float mx, float my);
void startDragging(float mx, float my);
void dragSelectedShape(float mx, float my);
void stopDragging();

void pushBack(Shape* shape);
bool isDragging();
Shape* getSelectedShape(float mx, float my);

};

#endif