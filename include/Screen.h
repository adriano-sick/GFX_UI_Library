#ifndef SCREEN_H
#define SCREEN_H

#include <vector>
#include "UIElement.h"

class Screen {
public:
    Screen(uint8_t id);
    
    void addElement(UIElement* element);
    void removeElement(UIElement* element);
    void draw(Mcufriend_kbv &tft);
    void handleTouch(int x, int y);
    
    uint8_t getId() const;
    void setBackground(uint16_t color);
    
private:
    uint8_t _id;
    uint16_t _bgColor = 0x0000;
    std::vector<UIElement*> _elements;
};

#endif