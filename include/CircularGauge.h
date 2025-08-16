// CircularGauge.h
#ifndef CIRCULAR_GAUGE_H
#define CIRCULAR_GAUGE_H

#include "UIElement.h"

class CircularGauge : public UIElement {
public:
    CircularGauge(int x, int y, int diameter, uint16_t bgColor, uint16_t fillColor);
    
    void draw(Mcufriend_kbv &tft) override;
    void setValue(float percent); // 0-100
    void setLabel(const String &label);
    void setColors(uint16_t bg, uint16_t fill, uint16_t text);
    
private:
    float _percent = 0;
    String _label;
    uint16_t _bgColor;
    uint16_t _fillColor;
    uint16_t _textColor = 0xFFFF;
};

#endif