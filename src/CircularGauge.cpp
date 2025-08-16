#include "../include/CircularGauge.h"

CircularGauge::CircularGauge(int x, int y, int d, uint16_t bg, uint16_t fill) 
    : UIElement(x, y, d, d), _bgColor(bg), _fillColor(fill) {}

void CircularGauge::draw(MCUFRIEND_kbv &tft) {
    // Desenha fundo
    tft.fillCircle(_x + _width/2, _y + _height/2, _width/2, _bgColor);
    
    // Desenha preenchimento
    float angle = _percent * 3.6;
    tft.fillArc(_x + _width/2, _y + _height/2, _width/2, angle, 0, _fillColor);
    
    // Desenha texto
    tft.setTextColor(_textColor);
    tft.setTextSize(2);
    String percentStr = String((int)_percent) + "%";
    int textX = _x + (_width - percentStr.length()*12)/2;
    int textY = _y + (_height - 16)/2;
    tft.setCursor(textX, textY);
    tft.print(percentStr);
}