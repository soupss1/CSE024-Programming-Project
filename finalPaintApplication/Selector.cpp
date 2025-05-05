#include "Selector.h"
using namespace bobcat;

void Toolbar::deselectAllTools(){

 BringToFrontButton->color(FL_BACKGROUND_COLOR);
 CircleButton->color(FL_BACKGROUND_COLOR);

 EraserButton->color(FL_BACKGROUND_COLOR);
 MinusButton->color(FL_BACKGROUND_COLOR);
 MouseButton->color(FL_BACKGROUND_COLOR);
PencilButton->color(FL_BACKGROUND_COLOR);
 PlusButton->color(FL_BACKGROUND_COLOR);
 PolygonButton->color(FL_BACKGROUND_COLOR);
 RectangleButton->color(FL_BACKGROUND_COLOR);
 SendBacktoFrontButton->color(FL_BACKGROUND_COLOR);
 TriangleButton->color(FL_BACKGROUND_COLOR);
 ClearButton->color(FL_BACKGROUND_COLOR);

    
   

 
}

void Toolbar::visualizeSelectedTool() {
    if (action == BRINGFRONT) {
        BringToFrontButton->color(FL_WHITE);
    }
    else if (tool == CIRCLE) {
        CircleButton->color(FL_WHITE);
    }
    else if (tool == ERASER) {
        EraserButton->color(FL_WHITE);
    }
    else if (action == DECREASE) {
        MinusButton->color(FL_WHITE);
    }
    else if (tool == MOUSE) {
        MouseButton->color(FL_WHITE);
    }
    else if (tool == PENCIL) {
        PencilButton->color(FL_WHITE);
    }
    else if (action == INCREASE) {
        PlusButton->color(FL_WHITE);
    }
    else if (tool == POLYGON) {
        PolygonButton->color(FL_WHITE);
    }
    else if (tool == RECTANGLE) {
        RectangleButton->color(FL_WHITE);
    }
    else if (action == SENDBACK) {
        SendBacktoFrontButton->color(FL_WHITE);
    }
    else if (tool == TRIANGLE) {
        TriangleButton->color(FL_WHITE);
    }
    else if (action == CLEAR) {
        ClearButton->color(FL_WHITE);
    }
}

void Toolbar::onClick(bobcat::Widget* sender) {
    deselectAllTools();
    action = NONE;

    if (sender == BringToFrontButton) {
        action = BRINGFRONT;
    }
    else if (sender == CircleButton) {
        tool = CIRCLE;
    }
    else if (sender == EraserButton) {
        tool = ERASER;
    }
    else if (sender == MinusButton) {
        action = DECREASE;
    }
    else if (sender == MouseButton) {
        tool = MOUSE;
    }
    else if (sender == PencilButton) {
        tool = PENCIL;
    }
    else if (sender == PlusButton) {
        action = INCREASE;
    }
    else if (sender == PolygonButton) {
        tool = POLYGON;
    }
    else if (sender == RectangleButton) {
        tool = RECTANGLE;
    }
    else if (sender == SendBacktoFrontButton) {
        action = SENDBACK;
    }
    else if (sender == TriangleButton) {
        tool = TRIANGLE;
    }
    else if (sender == ClearButton) {
        action = CLEAR;
    }

    if (onChangeCb) {
        onChangeCb(this);
    }

    visualizeSelectedTool();
    redraw();
}

SELECTOR Toolbar::getTool() const {
    return tool;
}

ACTION Toolbar::getAction() const {
    return action;
}

Toolbar::Toolbar(int x, int y, int w, int h) : Group(x, y, w, h){
 BringToFrontButton = new Image(x, y, 50, 50, "./assets/bring-to-front.png");
CircleButton = new Image(x, y + 50, 50, 50, "./assets/circle.png");
EraserButton = new Image(x, y + 100, 50, 50, "./assets/eraser.png");
 MinusButton = new Image(x, y + 150, 50, 50, "./assets/minus.png");
MouseButton = new Image(x, y + 200, 50, 50, "./assets/mouse.png");
PencilButton = new Image(x, y + 250, 50, 50, "./assets/pencil.png");
PlusButton = new Image(x, y + 300, 50, 50, "./assets/plus.png");
PolygonButton = new Image(x, y + 350, 50, 50, "./assets/polygon.png");
RectangleButton = new Image(x, y + 400, 50, 50, "./assets/rectangle.png");
SendBacktoFrontButton = new Image(x, y + 450, 50, 50, "./assets/send-to-back.png");
TriangleButton = new Image(x, y + 500, 50, 50, "./assets/triangle.png");
ClearButton = new Image(x, y + 550, 50, 50, "./assets/clear.png");


tool = PENCIL;
action = NONE;

BringToFrontButton->box(FL_BORDER_BOX);
CircleButton->box(FL_BORDER_BOX);
EraserButton->box(FL_BORDER_BOX);
MinusButton->box(FL_BORDER_BOX);
MouseButton->box(FL_BORDER_BOX);
PencilButton->box(FL_BORDER_BOX);
PlusButton->box(FL_BORDER_BOX);
PolygonButton->box(FL_BORDER_BOX);
RectangleButton->box(FL_BORDER_BOX);
SendBacktoFrontButton->box(FL_BORDER_BOX);
ClearButton->box(FL_BORDER_BOX);

    visualizeSelectedTool();

    ON_CLICK(BringToFrontButton, Toolbar::onClick);
    ON_CLICK(CircleButton, Toolbar::onClick);
    ON_CLICK(EraserButton, Toolbar::onClick);
    ON_CLICK(MinusButton, Toolbar::onClick);
    ON_CLICK(MouseButton, Toolbar::onClick);
    ON_CLICK(PencilButton, Toolbar::onClick);
    ON_CLICK(PlusButton, Toolbar::onClick);
    ON_CLICK(PolygonButton, Toolbar::onClick);
    ON_CLICK(RectangleButton, Toolbar::onClick);
    ON_CLICK(SendBacktoFrontButton, Toolbar::onClick);
    ON_CLICK(ClearButton, Toolbar::onClick);
    ON_CLICK(TriangleButton, Toolbar::onClick);
 
}

