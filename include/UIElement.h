#ifndef UI_ELEMENT_H
#define UI_ELEMENT_H

#include <Arduino.h>
#include <MCUFRIEND_kbv.h>

class UIElement {
public:
    UIElement(int x, int y, int width, int height);
    virtual ~UIElement() = default;
    
    virtual void draw(MCUFRIEND_kbv &tft) = 0;
    virtual bool contains(int x, int y);
    virtual void onPress();
    virtual void onRelease();
    virtual void setVisible(bool visible);
    
    void setPosition(int x, int y);
    void setSize(int width, int height);
    
protected:
    int _x, _y;
    int _width, _height;
    bool _visible = true;
    bool _pressed = false;
};

#endif