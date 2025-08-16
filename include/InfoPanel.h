// InfoPanel.h
#ifndef INFO_PANEL_H
#define INFO_PANEL_H

#include "UIElement.h"
#include <vector>

class InfoPanel : public UIElement {
public:
    InfoPanel(int x, int y, int width, int height, uint16_t bgColor);
    
    void draw(Mcufriend_kbv &tft) override;
    void addInfoItem(const String &label, const String &value);
    void updateValue(uint8_t index, const String &newValue);
    void setTitle(const String &title);
    
private:
    String _title;
    uint16_t _bgColor;
    std::vector<String> _labels;
    std::vector<String> _values;
    uint8_t _textSize = 1;
};

#endif