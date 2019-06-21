#pragma once

#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

#undef COMBO_COUNT
#define COMBO_COUNT 1

#define TAPPING_TERM 200

#define IGNORE_MOD_TAP_INTERRUPT

#undef COMBO_TERM
#define COMBO_TERM 30

#define RGB_DI_PIN F6

#define RGBLED_NUM 10

// #define RGBLIGHT_LED_MAP { 8, 9, 0, 1, 2, 3, 4, 5, 6, 7 }

#define RGBLIGHT_EFFECT_BREATHING 3
#define RGBLIGHT_EFFECT_BREATHE_CENTER 1

// #define RGBLIGHT_EFFECT_SNAKE_LENGTH 10

#define RGBLIGHT_EFFECT_KNIGHT
#define RGBLIGHT_EFFECT_SNAKE
#define RGBLIGHT_EFFECT_ALTERNATING

#define BACKLIGHT_BREATHING

#undef MATRIX_COL_PINS
#undef MATRIX_ROW_PINS
#define MATRIX_ROW_PINS { B6, B2, B3, B1, F7 }
#define MATRIX_COL_PINS { D0, D4, C6, D7, E6, B4 }
