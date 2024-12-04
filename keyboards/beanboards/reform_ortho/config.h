/*
* Copyright 2024 BeanBoards & OLKB (github.com/C44Supra & github.com/olkb)
* SPDX-License-Identifier: GPL-2.0-or-later
*/

#pragma once

/* Double tap the side button to enter bootloader */
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U

// RGB
#define WS2812_PIO_USE_PIO1

#ifdef RGB_MATRIX_ENABLE
    #define WS2812_PIO_USE_PIO1
#endif

#ifdef OLED_ENABLE
    #define OLED_DISPLAY_128X32
    #define I2C1_SCL_PIN        GP16
    #define I2C1_SDA_PIN        GP17
    #define I2C_DRIVER I2CD0
    #define OLED_BRIGHTNESS     128
#endif
