#ifndef BUTTON_H
#define BUTTON_H

#include "UIElement.h"

class Button : public UIElement {
public:
    Button(int x, int y, int width, int height, const String &label);
    
    void draw(Mcufriend_kbv &tft) override;
    void onPress() override;
    void onRelease() override;
    
    void setLabel(const String &label);
    void setColors(uint16_t normal, uint16_t pressed, uint16_t text);
    
    typedef std::function<void()> Callback;
    void setCallback(Callback cb);
    
private:
    String _label;
    uint16_t _normalColor = 0x07FF;
    uint16_t _pressedColor = 0x001F;
    uint16_t _textColor = 0x0000;
    Callback _callback = nullptr;
};

#endif