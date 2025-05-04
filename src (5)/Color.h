#ifndef COLOR_H
#define COLOR_H

class Color {
    float r;
    float g;
    float b;

public:
    Color();
    Color(float r, float g, float b);

    float getR() const;
    float getG() const;
    float getB() const;
    bool contains(float mx, float my);
    void setColor(float r, float g, float b);
};

#endif