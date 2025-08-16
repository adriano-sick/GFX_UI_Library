#ifndef GFX_UI_H
#define GFX_UI_H

#include <mcufriend_kbv.h>
#include "UIElement.h"
#include "Screen.h"
#include "Button.h"
#include "Graph.h"

class GFX_UI {
public:
    GFX_UI(Mcufriend_kbv &tft);
    
    void begin();
    void update();
    void draw();
    
    // Gerenciamento de telas
    void addScreen(Screen* screen);
    void setActiveScreen(uint8_t screenId);
    Screen* getActiveScreen();
    
    // Utilitários gráficos
    void drawRoundedRect(int x, int y, int w, int h, int r, uint16_t color);
    void drawGradient(int x, int y, int w, int h, uint16_t color1, uint16_t color2);

    void drawIcon(int x, int y, const String &icon, uint16_t color, uint8_t size = 1);
    void drawProgressBar(int x, int y, int w, int h, float percent, uint16_t color);
    void drawBatteryIcon(int x, int y, float percent, uint16_t color);
    
private:
    Mcufriend_kbv &_tft;
    Screen* _activeScreen;
    std::vector<Screen*> _screens;

    void _initIconFont();
};

#endif