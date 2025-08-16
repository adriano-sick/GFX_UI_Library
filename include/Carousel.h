// Carousel.h
#ifndef CAROUSEL_H
#define CAROUSEL_H

#include "UIElement.h"
#include <vector>

class Carousel : public UIElement {
public:
    Carousel(int x, int y, int width, int height);
    
    void draw(Mcufriend_kbv &tft) override;
    void addItem(const String &label, const String &icon = "");
    uint8_t getSelectedIndex() const;
    String getSelectedLabel() const;
    void next();
    void prev();
    void select(uint8_t index);
    
    void setColors(uint16_t bg, uint16_t text, uint16_t selected);
    
private:
    std::vector<String> _items;
    std::vector<String> _icons;
    uint8_t _selectedIndex = 0;
    uint16_t _bgColor = 0x0000;
    uint16_t _textColor = 0xFFFF;
    uint16_t _selectedColor = 0x07E0;
};

#endif