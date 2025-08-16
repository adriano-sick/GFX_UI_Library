#include "../include/Screen.h"
#include "../include/UIElement.h"

Screen::Screen(uint8_t id) : _id(id) {}

void Screen::addElement(UIElement* element) {
    _elements.push_back(element);
}

void Screen::draw(MCUFRIEND_kbv &tft) {
    tft.fillScreen(_bgColor);
    for(auto element : _elements) {
        if(element->isVisible()) {
            element->draw(tft);
        }
    }
}

void Screen::handleTouch(int x, int y) {
    for(auto element : _elements) {
        if(element->contains(x, y)) {
            element->onPress();
            element->onRelease();
            break;
        }
    }
}