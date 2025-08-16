#include "../include/Graph.h"

Graph::Graph(int x, int y, int w, int h) : UIElement(x, y, w, h) {}

void Graph::draw(MCUFRIEND_kbv &tft) {
    tft.drawRect(_x, _y, _width, _height, 0xFFFF);
    
    if(_dataPoints.empty()) return;
    
    float xStep = (float)_width / (_dataPoints.size() - 1);
    float yScale = (float)_height / (_maxValue - _minValue);
    
    for(size_t i = 0; i < _dataPoints.size() - 1; i++) {
        int x1 = _x + (i * xStep);
        int y1 = _y + _height - ((_dataPoints[i] - _minValue) * yScale);
        int x2 = _x + ((i + 1) * xStep);
        int y2 = _y + _height - ((_dataPoints[i + 1] - _minValue) * yScale);
        
        tft.drawLine(x1, y1, x2, y2, _color);
    }
}