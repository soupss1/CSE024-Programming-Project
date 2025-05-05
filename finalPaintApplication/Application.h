#ifndef APPLICATION_H
#define APPLICATION_H

#include "Enums.h"
#include "Canvas.h"
#include "Selector.h"
#include "ColorSelector.h"
#include <bobcat_ui/all.h>

class Application : public bobcat::Application_ {
    bobcat::Window* window;
    Toolbar* Selector;
    Canvas* canvas;
    ColorSelector* colorSelector;

    void onCanvasMouseDown(bobcat::Widget* sender, float mx, float my);
    void onCanvasDrag(bobcat::Widget* sender, float mx, float my);
    void onToolbarChange(bobcat::Widget* sender);
    void onCanvasMouseUp(bobcat::Widget* sender, float mx, float my);
   

public:
    Application();

    friend struct::AppTest;
};


#endif