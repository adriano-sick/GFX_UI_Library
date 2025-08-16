#include "../include/Button.h"

Button::Button(int x, int y, int w, int h, const String &label) 
    : UIElement(x, y, w, h), _label(label) {}

void Button::draw(MCUFRIEND_kbv &tft) {
    uint16_t bgColor = _pressed ? _pressedColor : _normalColor;
    
    tft.fillRoundRect(_x, _y, _width, _height, 5, bgColor);
    tft.drawRoundRect(_x, _y, _width, _height, 5, 0xFFFF);
    
    tft.setTextColor(_textColor);
    tft.setTextSize(2);
    int textX = _x + (_width - _label.length()*12)/2;
    int textY = _y + (_height - 16)/2;
    tft.setCursor(textX, textY);
    tft.print(_label);
}

void Button::onPress() {
    _pressed = true;
    if(_callback) _callback();
}

void Button::onRelease() {
    _pressed = false;
}