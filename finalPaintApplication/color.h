#ifndef COLOR_H
#define COLOR_H

class Color {


public:
float r;
float g;
float b;
Color();
Color(float r, float g, float b);

float getR() const;
float getG() const;
float getB() const;

};

#endif