#include "../include/NavigationArrows.h"

NavigationArrows::NavigationArrows(int x, int y, int size) 
    : UIElement(x, y, size*2, size), _size(size) {}

void NavigationArrows::draw(MCUFRIEND_kbv &tft) {
    // Desenha seta esquerda
    tft.fillTriangle(_x, _y + _size/2, 
                    _x + _size, _y,
                    _x + _size, _y + _size, 0xFFFF);
    
    // Desenha seta direita
    tft.fillTriangle(_x + _size, _y + _size/2,
                    _x + 2*_size, _y,
                    _x + 2*_size, _y + _size, 0xFFFF);
}