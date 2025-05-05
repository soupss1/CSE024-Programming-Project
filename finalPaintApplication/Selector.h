#ifndef SELECTOR_H
#define SELECTOR_H

#include <bobcat_ui/all.h>
#include "Enums.h"

class Toolbar : public bobcat::Group{
bobcat::Image* BringToFrontButton;
bobcat::Image* CircleButton;
bobcat::Image* ClearButton;
bobcat::Image* EraserButton;
bobcat::Image* MinusButton;
bobcat::Image* MouseButton;
bobcat::Image* PencilButton;
bobcat::Image* PlusButton;
bobcat::Image* PolygonButton;
bobcat::Image* RectangleButton;
bobcat::Image* SendBacktoFrontButton;
bobcat::Image* TriangleButton;

 SELECTOR tool;
    ACTION action;
    void deselectAllTools();
    void visualizeSelectedTool();
    void onClick(bobcat::Widget* sender);

public:
    Toolbar(int x, int y, int w, int h);

    SELECTOR getTool() const;
    ACTION getAction() const;
};



#endif