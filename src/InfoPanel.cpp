#include "../include/InfoPanel.h"

InfoPanel::InfoPanel(int x, int y, int w, int h, uint16_t bg) 
    : UIElement(x, y, w, h), _bgColor(bg) {}

void InfoPanel::draw(MCUFRIEND_kbv &tft) {
    tft.fillRect(_x, _y, _width, _height, _bgColor);
    
    // Desenha título
    tft.setTextColor(0xFFFF);
    tft.setTextSize(2);
    tft.setCursor(_x + 5, _y + 5);
    tft.print(_title);
    
    // Desenha itens
    tft.setTextSize(1);
    for(size_t i = 0; i < _labels.size(); i++) {
        int yPos = _y + 30 + (i * 20);
        tft.setCursor(_x + 10, yPos);
        tft.print(_labels[i] + ": " + _values[i]);
    }
}