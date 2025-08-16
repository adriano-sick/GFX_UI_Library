# GFX UI Library for Arduino

![Platform](https://img.shields.io/badge/Platform-Arduino-blue)
![Driver](https://img.shields.io/badge/Driver-mcufriend__kbv-green)
![Version](https://img.shields.io/badge/Version-0.2.0-orange)

A reusable UI library for TFT displays using the **mcufriend_kbv** driver.  
This library provides graphical components like buttons, screens with navigation, animations, transitions, and data visualization elements for Arduino projects.

---

## 📑 Table of Contents

- [Features](#features)
- [Installation](#installation)
  - [Using PlatformIO](#using-platformio)
  - [Manual Installation](#manual-installation)
- [Dependencies](#dependencies)
- [Documentation](#documentation)
  - [Core Components](#core-components)
  - [New Specialized Components (v0.2.0)](#new-specialized-components-v020)
  - [Utility Methods](#utility-methods)
- [Example Applications](#example-applications)
  - [Example: Creating a Marine Dashboard](#example-creating-a-marine-dashboard)
- [Contributing](#contributing)
- [License](#license)

---

## Features

- 🖥️ Screen management system with transitions
- 🛠️ Reusable UI elements (buttons, sliders, graphs, gauges)
- 🎨 Customizable appearance with theme support
- 🔄 Touch event handling
- 📊 Data visualization components
- ✨ Animation support
- 🧩 Modular architecture for easy extension
- 🆕 **New in v0.2.0**: Specialized components for marine applications

---

## Installation

### Using PlatformIO

Add the library to your `platformio.ini`:

```ini
lib_deps =
    https://github.com/yourusername/GFX_UI_Library.git
    mcufriend_kbv
```

Then run:

```bash
pio lib install
```

### Manual Installation

1. Clone or download this repository into your Arduino `libraries` folder  
2. Install the [mcufriend_kbv](https://github.com/prenticedavid/MCUFRIEND_kbv) library  
3. Restart the Arduino IDE  

---

## Dependencies

- [mcufriend_kbv](https://github.com/prenticedavid/MCUFRIEND_kbv) — TFT display driver  

---

## Documentation

### Core Components

- **GFX_UI** — Main library controller
- **Screen** — Container for UI elements
- **UIElement** — Base class for UI components
- **Button** — Interactive button element
- **Graph** — Data visualization component
- **Transition** — Screen transition effects

---

### New Specialized Components (v0.2.0)

#### `InfoPanel`
Displays multiple labeled values in a structured layout (weather, navigation, status).

```cpp
InfoPanel* panel = new InfoPanel(10, 10, 300, 180, 0x001F);
panel->setTitle("Weather Info");
panel->addInfoItem("Temperature", "26°C");
panel->addInfoItem("Wind Speed", "12 knots");
```

#### `CircularGauge`
Circular progress indicator with customizable colors and labels (tank levels, battery status).

```cpp
CircularGauge* gauge = new CircularGauge(100, 40, 120, 0x0010, 0x07E0);
gauge->setLabel("Water Tank");
gauge->setValue(75); // 75%
```

#### `IconButton`
Button with icon + text, includes marine-themed icons.

```cpp
IconButton* btn = new IconButton(50, 50, 120, 40, "⛵", "Anchor");
btn->setColors(0x001F, 0x07FF, 0xFFFF);
```

#### `ToggleButton`
Maintains on/off state with visual feedback.

```cpp
ToggleButton* toggle = new ToggleButton(50, 100, 120, 40, "Lights");
toggle->setActiveColors(0x07E0, 0x0000); // Green when active
```

#### `Carousel`
Horizontal selector for switching between views.

```cpp
Carousel* carousel = new Carousel(20, 180, 280, 30);
carousel->addItem("Water", "🚿");
carousel->addItem("Fuel", "⛽");
```

#### `NavigationArrows`
Left/right navigation controls with callbacks.

```cpp
NavigationArrows* arrows = new NavigationArrows(10, 80, 30);
arrows->setLeftCallback(prevItem);
arrows->setRightCallback(nextItem);
```

---

### Utility Methods

- `drawIcon()` — Predefined icons (marine symbols supported)
- `drawProgressBar()` — Horizontal/vertical bars
- `drawBatteryIcon()` — Battery level indicator
- `drawMarineSymbol()` — Specialized nautical symbols

---

## Example Applications

- **MarineDashboard** — Boat control panel
- **SystemMonitor** — Tank levels and battery
- **NavigationDisplay** — GPS & compass
- **LightingControl** — Toggle marine lighting

---

### Example: Creating a Marine Dashboard

```cpp
#include <GFX_UI.h>
#include <mcufriend_kbv.h>

Mcufriend_kbv tft;
GFX_UI ui(tft);

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
    
    // Navigation Button
    IconButton* navBtn = new IconButton(20, 150, 80, 40, "🧭", "Nav");
    mainScreen->addElement(navBtn);
    
    ui.addScreen(mainScreen);
    ui.setActiveScreen(1);
}

void loop() {
    ui.update();
}
```

---

## Contributing

Contributions are welcome! Please open an **issue** or **pull request** for improvements, bug fixes, or new components.

---

## License

This project is licensed under the **MIT License** — see [LICENSE](LICENSE) for details.

---

⭐ If this library helped you, consider giving it a star on GitHub!
