// ToggleButton.h
#ifndef TOGGLE_BUTTON_H
#define TOGGLE_BUTTON_H

#include "Button.h"

class ToggleButton : public Button {
public:
    ToggleButton(int x, int y, int width, int height, const String &label);
    
    void draw(Mcufriend_kbv &tft) override;
    void setState(bool active);
    bool getState() const;
    void toggle();
    
    void setActiveColors(uint16_t bg, uint16_t text);
    
private:
    bool _active = false;
    uint16_t _activeBgColor = 0x07E0; // Verde
    uint16_t _activeTextColor = 0x0000; // Preto
};

#endif