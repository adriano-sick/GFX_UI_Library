// IconButton.h
#ifndef ICON_BUTTON_H
#define ICON_BUTTON_H

#include "Button.h"

class IconButton : public Button {
public:
    IconButton(int x, int y, int width, int height, const String &icon, const String &label);
    
    void draw(Mcufriend_kbv &tft) override;
    void setIcon(const String &icon);
    
private:
    String _icon;
};

#endif