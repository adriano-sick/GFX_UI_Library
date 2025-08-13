# GFX UI Library for Arduino

![Arduino TFT UI](https://img.shields.io/badge/Platform-Arduino-blue)
![TFT Support](https://img.shields.io/badge/Driver-mcufriend__kbv-green)
![Version](https://img.shields.io/badge/Version-0.1.0-orange)

A reusable UI library for TFT displays using the mcufriend_kbv driver. This library provides graphical components like buttons, screens with navigation, animations, transitions, and data visualization elements for Arduino projects.

## Features

- 🖥️ Screen management system with transitions
- 🛠️ Reusable UI elements (buttons, sliders, graphs)
- 🎨 Customizable appearance
- 🔄 Touch event handling
- 📊 Data visualization components
- ✨ Animation support
- 🧩 Modular architecture for easy extension

## Installation

### Using PlatformIO

1. Add the library as a dependency in your `platformio.ini` file:

```ini
lib_deps =
    https://github.com/yourusername/GFX_UI_Library.git
    mcufriend_kbv
```

2. Run `pio lib install` to download the dependencies

### Manual Installation

1. Clone this repository into your Arduino libraries folder
2. Install the required [mcufriend_kbv](https://github.com/prenticedavid/MCUFRIEND_kbv) library
3. Restart your Arduino IDE

## Dependencies

This library **requires** the following dependency to work:

- [mcufriend_kbv](https://github.com/prenticedavid/MCUFRIEND_kbv) - Driver for TFT displays

Make sure to install it before using this library.

## Quick Start

```cpp
#include <GFX_UI.h>
#include <mcufriend_kbv.h>

Mcufriend_kbv tft;
GFX_UI ui(tft);

void setup() {
    tft.begin();
    ui.begin();
    
    // Create a screen
    Screen* mainScreen = new Screen(1);
    mainScreen->setBackground(0x0000); // Black background
    
    // Create a button
    Button* btn = new Button(50, 50, 100, 40, "Click Me");
    btn->setColors(0x07FF, 0x001F, 0x0000); // Blue, dark blue, black text
    btn->setCallback([]() {
        Serial.println("Button pressed!");
    });
    
    mainScreen->addElement(btn);
    ui.addScreen(mainScreen);
    ui.setActiveScreen(1);
}

void loop() {
    // Handle touch input and redraw
    ui.update();
}
```

## Documentation

### Core Components

- **GFX_UI**: Main library controller
- **Screen**: Container for UI elements
- **UIElement**: Base class for all UI components
- **Button**: Interactive button element
- **Graph**: Data visualization component
- **Transition**: Screen transition effects

### Available Transitions

- Slide (left, right, top, bottom)
- Fade
- None (instant switch)

## Examples

Check the [examples](examples/) folder for complete usage examples:

1. **BasicExample**: Simple screen with buttons
2. **AdvancedExample**: Multiple screens with transitions
3. **GraphExample**: Data visualization demo

## Contributing

Contributions are welcome! Please open an issue or pull request for any bugs or feature requests.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Support

If you find this library useful, consider starring the repository on GitHub! For support, please open an issue in the GitHub repository.