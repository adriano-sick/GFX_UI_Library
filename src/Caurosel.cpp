#include "../include/Carousel.h"

Carousel::Carousel(int x, int y, int w, int h) : UIElement(x, y, w, h) {}

void Carousel::draw(MCUFRIEND_kbv &tft) {
    tft.fillRect(_x, _y, _width, _height, _bgColor);
    
    if(_items.empty()) return;
    
    // Desenha item selecionado
    tft.setTextColor(_selectedColor);
    tft.setTextSize(2);
    tft.setCursor(_x + 10, _y + 10);
    tft.print(_items[_selectedIndex]);
}