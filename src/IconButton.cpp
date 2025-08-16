#include "../include/IconButton.h"

IconButton::IconButton(int x, int y, int w, int h, const String &icon, const String &label)
    : Button(x, y, w, h, label), _icon(icon) {}

void IconButton::draw(MCUFRIEND_kbv &tft) {
    Button::draw(tft);
    
    // Desenha ícone
    tft.setCursor(_x + 10, _y + 10);
    tft.print(_icon);
}