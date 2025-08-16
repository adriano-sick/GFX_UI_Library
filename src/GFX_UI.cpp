#include "../include/GFX_UI.h"
#include "../include/Screen.h"

GFX_UI::GFX_UI(MCUFRIEND_kbv &tft) : _tft(tft), _activeScreen(nullptr) {}

void GFX_UI::begin() {
    _tft.begin();
    _tft.setRotation(3);
    _initIconFont();
}

void GFX_UI::update() {
    if(_activeScreen) {
        _activeScreen->draw(_tft);
    }
}

void GFX_UI::addScreen(Screen* screen) {
    _screens.push_back(screen);
}

void GFX_UI::setActiveScreen(uint8_t screenId) {
    for(auto screen : _screens) {
        if(screen->getId() == screenId) {
            _activeScreen = screen;
            _tft.fillScreen(screen->getBackground());
            break;
        }
    }
}

void GFX_UI::drawRoundedRect(int x, int y, int w, int h, int r, uint16_t color) {
    _tft.drawRoundRect(x, y, w, h, r, color);
    _tft.fillRoundRect(x+1, y+1, w-2, h-2, r, color);
}

void GFX_UI::_initIconFont() {
    // Implementação para inicializar fonte de ícones
}