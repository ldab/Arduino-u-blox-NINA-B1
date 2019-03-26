# Arduino-u-blox-NINA-B1

u-blox NINA-B1 Arduino example + SHT31 temperature and humidity + Bluetooth BLE

[![GitHub version](https://img.shields.io/github/release/ldab/Arduino-u-blox-NINA-B1.svg)](https://github.com/ldab/Arduino-u-blox-NINA-B1/releases/latest)
[![Build Status](https://travis-ci.org/ldab/Arduino-u-blox-NINA-B1.svg?branch=master)](https://travis-ci.org/ldab/Arduino-u-blox-NINA-B1)
[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](https://github.com/ldab/Arduino-u-blox-NINA-B1/blob/master/LICENSE)

[![GitHub last commit](https://img.shields.io/github/last-commit/ldab/Arduino-u-blox-NINA-B1.svg?style=social)](https://github.com/ldab/Arduino-u-blox-NINA-B1)

![EVK-NINA-B1](https://www.u-blox.com/sites/default/files/styles/product_full/public/products/EVK-NINA-B1_2D-medium_RGB-CI.png)


## How to build PlatformIO based project

1. [Install PlatformIO Core](http://docs.platformio.org/page/core.html)
2. Download [development platform with examples](https://github.com/platformio/platform-nordicnrf52/archive/develop.zip)
3. Extract ZIP archive
4. Run these commands:

```
# Change directory to example
> cd platform-nordicnrf52/examples/Arduino-u-blox-NINA-B1

# Build project
> platformio run

# Upload firmware
> platformio run --target upload

# Build specific environment
> platformio run -e nina_b1

# Upload firmware for the specific environment
> platformio run -e nina_b1 --target upload

# Clean build files
> platformio run --target clean
```

## Credits

Github Shields and Badges created with [Shields.io](https://github.com/badges/shields/)

u-blox official mBed [library](https://os.mbed.com/platforms/u-blox-EVK-NINA-B1/)