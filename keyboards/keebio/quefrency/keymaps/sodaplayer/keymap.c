#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _BASE 0
#define _FN1 1
#define _FN2 2


const uint8_t RGBLED_BREATHING_INTERVALS[] PROGMEM = {200, 100, 50, 25};

void keyboard_post_init_user(void) {
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom(125, 255, 255);
    // rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 3);
    rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_SWIRL + 4);
}

// enum custom_keycodes {
//   QWERTY = SAFE_RANGE,
// };

// enum layers {
// }

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_65_with_macro(
    KC_F1,   KC_F2,   KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,  KC_DEL, KC_HOME, \
    KC_F3,   KC_F4,   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_END, \
    KC_F5,   KC_F6,   KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,                    KC_PGUP, \
    KC_F7,   KC_F8,   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_INS,                    KC_PGDN, \
    KC_F9,   KC_F10,  KC_LCTL, MO(_FN1),KC_LGUI, KC_LALT, KC_SPC,           KC_SPC,  MO(_FN2),KC_RALT, KC_RGUI, KC_MENU, KC_RCTL,                   KC_PSCR, KC_PAUS
  ),

  [_FN1] = LAYOUT_65_with_macro(
    KC_KP_1, KC_KP_2, KC_GESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_BSPC, _______, \
    KC_KP_3, KC_KP_4, RGB_TOG, RGB_MOD, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    KC_KP_5, KC_KP_6, KC_CAPS, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, _______, _______, \
    KC_KP_7, KC_KP_8, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    KC_KP_9, KC_KP_0, KC_TILD, _______, _______, _______, KC_BSPC,          _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_FN2] = LAYOUT_65_with_macro(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______,   KC_P7,   KC_P8,   KC_P9, KC_PPLS, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______,   KC_P4,   KC_P5,   KC_P6, KC_PCMM, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______,   KC_P1,   KC_P2,   KC_P3, KC_PEQL, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,          _______, _______,   KC_P0, KC_PDOT, KC_PENT, _______, _______, _______
  )
};
