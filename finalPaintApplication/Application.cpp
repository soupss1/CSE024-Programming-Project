#include "Application.h"
#include "Enums.h"
#include <FL/Enumerations.H>
#include <bobcat_ui/bobcat_ui.h>

using namespace bobcat;
using namespace std;

void Application::onCanvasMouseDown(bobcat::Widget* sender, float mx, float my){
    SELECTOR tool = Selector->getTool();
    Color color = colorSelector->getColor();
    std::cout<< "colorFbghkjn" << std::endl;

    if(tool == PENCIL){
        canvas->startScribble();
        canvas->updateScribble(mx, my, color.getR(), color.getG(), color.getB(), 7);
        canvas->redraw();
    }
    else if(tool == ERASER){
        canvas->eraseAt(mx, my);
        canvas->redraw();

    }
    else if(tool == RECTANGLE){
        canvas->addRectangle(mx, my, color.getR(), color.getG(), color.getB());
        canvas->redraw();
    }
    else if(tool == CIRCLE){
        canvas->addCircle(mx, my, color.getR(), color.getG(), color.getB());
        canvas->redraw();
    }
    else if(tool == TRIANGLE){
    canvas->addTriangle(mx, my, 0.2, 0.2, color.getR(), color.getG(), color.getB());
    canvas->redraw();

    }

    else if (tool == POLYGON) {
        canvas->addPolygon(mx, my, 6, 0.1, color.getR(), color.getG(), color.getB());
        canvas->redraw();
    }
    else if(tool == MOUSE){
    canvas->selectShapeAt(mx, my);
    canvas->startDragging(mx, my);
    

    }
    

   
    
}

void Application::onCanvasMouseUp(bobcat::Widget* sender, float mx, float my){
    canvas->stopDragging();
    canvas->endScribble();
}

void Application::onCanvasDrag(bobcat::Widget* sender, float mx, float my){
    SELECTOR tool = Selector->getTool();
    Color color = colorSelector->getColor();
    if (tool == PENCIL) {
        canvas->updateScribble(mx, my, color.getR(), color.getG(), color.getB(), 7);
        canvas->redraw();
    }
    else if (tool == ERASER) {
        canvas->eraseAt(mx, my);
        //canvas->updateScribble(mx, my, 1.0, 1.0, 1.0, 14);
        canvas->redraw();
    }
    else if(tool == MOUSE){
        canvas->dragSelectedShape(mx, my);
        canvas->redraw();
    }
    
}

void Application::onToolbarChange(bobcat::Widget* sender) {
    ACTION action = Selector->getAction();

    if (action == CLEAR) {
        canvas->clear();
        canvas->redraw();
    }
    else if(action == INCREASE){
        canvas->resizeSelected(1.5);
        canvas->redraw();
    }
    else if(action == DECREASE){
        canvas->resizeSelected(0.8);
        canvas->redraw();
    }
    else if(action == SENDBACK){
    canvas->sendToBack();
    canvas->redraw();
    }
    else if(action == BRINGFRONT){
    canvas->bringToFront();
    canvas->redraw();
    

    }
    
    
}


Application::Application() {
    window = new Window(100, 100, 530, 600, "Paint Application");
    Selector = new Toolbar(0, 0, 50, 600);
    canvas = new Canvas(50, 0, 480, 490);
    colorSelector = new ColorSelector(50, 490, 480, 110);
    colorSelector->box(FL_FLAT_BOX);
    canvas->box(FL_FLAT_BOX);

    Selector->box(FL_FLAT_BOX);

    window->add(Selector);
    window->add(canvas);
    window->add(colorSelector);
    window->resizable(nullptr);
    window->box(FL_NO_BOX);

    ON_MOUSE_DOWN(canvas, Application::onCanvasMouseDown);
    ON_DRAG(canvas, Application::onCanvasDrag);
    ON_CHANGE(Selector, Application::onToolbarChange);
    ON_MOUSE_UP(canvas, Application::onCanvasMouseUp);

    window->show();
}