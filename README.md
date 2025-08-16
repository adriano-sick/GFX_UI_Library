GFX UI Library for Arduino
https://img.shields.io/badge/Platform-Arduino-blue
https://img.shields.io/badge/Driver-mcufriend__kbv-green
https://img.shields.io/badge/Version-0.2.0-orange

A reusable UI library for TFT displays using the mcufriend_kbv driver. This library provides graphical components like buttons, screens with navigation, animations, transitions, and data visualization elements for Arduino projects.

Features
🖥️ Screen management system with transitions

🛠️ Reusable UI elements (buttons, sliders, graphs, gauges)

🎨 Customizable appearance with themes support

🔄 Touch event handling

📊 Data visualization components

✨ Animation support

🧩 Modular architecture for easy extension

🆕 New in v0.2.0: Specialized components for marine applications

Installation
Using PlatformIO
ini
lib_deps =
    https://github.com/yourusername/GFX_UI_Library.git
    mcufriend_kbv
Manual Installation
(Instructions remain the same)

Dependencies
(Remains the same)

Quick Start
(Remains the same)

Documentation
Core Components
GFX_UI: Main library controller

Screen: Container for UI elements

UIElement: Base class for all UI components

Button: Interactive button element

Graph: Data visualization component

Transition: Screen transition effects

New Specialized Components (v0.2.0)
InfoPanel
Display multiple information items with labels and values in a structured layout. Perfect for weather, navigation data, and system status.

cpp
InfoPanel* panel = new InfoPanel(10, 10, 300, 180, 0x001F);
panel->setTitle("Weather Info");
panel->addInfoItem("Temperature", "26°C");
panel->addInfoItem("Wind Speed", "12 knots");
CircularGauge
Circular progress indicator with customizable colors and labels. Ideal for tank levels and battery status.

cpp
CircularGauge* gauge = new CircularGauge(100, 40, 120, 0x0010, 0x07E0);
gauge->setLabel("Water Tank");
gauge->setValue(75); // 75%
IconButton
Button with icon and text support. Includes pre-defined marine-themed icons.

cpp
IconButton* btn = new IconButton(50, 50, 120, 40, "⛵", "Anchor");
btn->setColors(0x001F, 0x07FF, 0xFFFF);
ToggleButton
Maintains on/off state with visual feedback. Perfect for system controls.

cpp
ToggleButton* toggle = new ToggleButton(50, 100, 120, 40, "Lights");
toggle->setActiveColors(0x07E0, 0x0000); // Green when active
Carousel
Horizontal selector for multiple items. Great for switching between different status views.

cpp
Carousel* carousel = new Carousel(20, 180, 280, 30);
carousel->addItem("Water", "🚿");
carousel->addItem("Fuel", "⛽");
NavigationArrows
Simple left/right navigation controls with callbacks.

cpp
NavigationArrows* arrows = new NavigationArrows(10, 80, 30);
arrows->setLeftCallback(prevItem);
arrows->setRightCallback(nextItem);
Utility Methods
drawIcon() - Draws predefined icons (supports marine-themed symbols)

drawProgressBar() - Horizontal/vertical progress bars

drawBatteryIcon() - Battery level indicator

drawMarineSymbol() - Specialized nautical symbols

Example Applications
Check the examples folder for:

MarineDashboard: Complete boat control panel

SystemMonitor: Tank levels and battery status

NavigationDisplay: GPS and compass information

LightingControl: Toggle switches for marine lighting

Creating a Marine Dashboard
cpp
#include <GFX_UI.h>
#include <mcufriend_kbv.h>

Mcufriend_kbv tft;
GFX_UI ui(tft);

´´´cpp
void setup() {
    tft.begin();
    ui.begin();
    
    // Main Screen
    Screen* mainScreen = new Screen(1);
    mainScreen->setBackground(0x001F); // Navy blue
    
    // Info Panel
    InfoPanel* weather = new InfoPanel(10, 10, 140, 100, 0x0000);
    weather->addInfoItem("Temp", "26°C");
    weather->addInfoItem("Wind", "12kt");
    mainScreen->addElement(weather);
    
    // Circular Gauge
    CircularGauge* tank = new CircularGauge(180, 20, 100, 0x0000, 0x07E0);
    tank->setLabel("Water");
    tank->setValue(80);
    mainScreen->addElement(tank);
    
    // Navigation Buttons
    IconButton* navBtn = new IconButton(20, 150, 80, 40, "🧭", "Nav");
    mainScreen->addElement(navBtn);
    
    ui.addScreen(mainScreen);
    ui.setActiveScreen(1);
}

void loop() {
    ui.update();
}
´´´

## Contributing

Contributions are welcome! Please open an issue or pull request for any bugs or feature requests.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Support

If you find this library useful, consider starring the repository on GitHub! For support, please open an issue in the GitHub repository.