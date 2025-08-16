#include "../include/UIElement.h"

UIElement::UIElement(int x, int y, int w, int h) 
    : _x(x), _y(y), _width(w), _height(h) {}

bool UIElement::contains(int x, int y) {
    return (x >= _x && x <= _x + _width && 
            y >= _y && y <= _y + _height);
}

void UIElement::setPosition(int x, int y) {
    _x = x;
    _y = y;
}

void UIElement::setSize(int w, int h) {
    _width = w;
    _height = h;
}