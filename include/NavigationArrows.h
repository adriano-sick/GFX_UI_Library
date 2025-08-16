// NavigationArrows.h
#ifndef NAVIGATION_ARROWS_H
#define NAVIGATION_ARROWS_H

#include "UIElement.h"

class NavigationArrows : public UIElement {
public:
    NavigationArrows(int x, int y, int size);
    
    void draw(Mcufriend_kbv &tft) override;
    bool contains(int x, int y) override;
    
    typedef std::function<void()> ArrowCallback;
    void setLeftCallback(ArrowCallback cb);
    void setRightCallback(ArrowCallback cb);
    
private:
    int _size;
    ArrowCallback _leftCallback = nullptr;
    ArrowCallback _rightCallback = nullptr;
};

#endif