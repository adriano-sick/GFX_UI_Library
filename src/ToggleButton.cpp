#include "../include/ToggleButton.h"

ToggleButton::ToggleButton(int x, int y, int w, int h, const String &label)
    : Button(x, y, w, h, label) {}

void ToggleButton::draw(MCUFRIEND_kbv &tft) {
    uint16_t bgColor = _active ? _activeBgColor : _normalColor;
    uint16_t textColor = _active ? _activeTextColor : _textColor;
    
    tft.fillRoundRect(_x, _y, _width, _height, 5, bgColor);
    tft.setTextColor(textColor);
    tft.setCursor(_x + 10, _y + 10);
    tft.print(_label);
}