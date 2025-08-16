#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <mcufriend_kbv.h>

class Graph : public UIElement {
public:
    Graph(int x, int y, int width, int height);
    
    void draw(Mcufriend_kbv &tft) override;
    void addDataPoint(float value);
    void clearData();
    void setColor(uint16_t color);
    
private:
    std::vector<float> _dataPoints;
    uint16_t _color = 0x07E0; // Verde padrão
    float _maxValue = 100.0;
    float _minValue = 0.0;
};

#endif