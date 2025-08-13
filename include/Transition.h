#ifndef TRANSITION_H
#define TRANSITION_H

#include <mcufriend_kbv.h>

class Transition {
public:
    virtual ~Transition() = default;
    virtual void apply(Mcufriend_kbv &tft, Screen* current, Screen* next) = 0;
    virtual void setDuration(uint16_t duration);
    
protected:
    uint16_t _duration = 300; // ms
};

class SlideTransition : public Transition {
public:
    enum Direction { LEFT, RIGHT, TOP, BOTTOM };
    
    SlideTransition(Direction dir);
    void apply(Mcufriend_kbv &tft, Screen* current, Screen* next) override;
    
private:
    Direction _direction;
};

#endif