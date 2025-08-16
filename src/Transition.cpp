#include "../include/Transition.h"

void SlideTransition::apply(MCUFRIEND_kbv &tft, Screen* current, Screen* next) {
    int startX = 0, startY = 0;
    switch(_direction) {
        case LEFT: startX = tft.width(); break;
        case RIGHT: startX = -tft.width(); break;
        case TOP: startY = tft.height(); break;
        case BOTTOM: startY = -tft.height(); break;
    }
    
    // Animação de slide
    for(int i = 0; i < tft.width(); i += 5) {
        int x = _direction == LEFT ? -i : (_direction == RIGHT ? i : 0);
        int y = _direction == TOP ? -i : (_direction == BOTTOM ? i : 0);
        
        tft.drawRect(x, y, tft.width(), tft.height(), BLACK);
        next->draw(tft, x, y);
        delay(10);
    }
}