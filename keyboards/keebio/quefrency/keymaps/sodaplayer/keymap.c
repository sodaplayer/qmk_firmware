#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define TO_DEF TO(_DEF)
#define TO_FN1 TO(_FN1)
#define TO_FN2 TO(_FN2)

#define PS_COM LT(_COM, KC_PAUS)

#define TAPPING_TERM 200



const uint8_t RGBLED_BREATHING_INTERVALS[] PROGMEM = {200, 100, 50, 25};

static uint16_t numtog_timer;
static bool numtog_on = false;

void keyboard_post_init_user(void) {
    rgblight_enable_noeeprom();
    rgblight_set_effect_range(0, 16);
    rgblight_sethsv_noeeprom(125, 255, 255);
    rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 3);
    // rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_SWIRL + 4);
    // rgblight_mode_noeeprom(RGBLIGHT_MODE_CHRISTMAS);
}

// enum custom_keycodes {
//   QWERTY = SAFE_RANGE,
// };

enum custom_keycodes {
    NUMTOG = SAFE_RANGE
};


enum layers {
    _DEF,
    _FN1,
    _FN2,
    _ARR,
    _NUM,
    _PS,
    _COM

};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DEF] = LAYOUT_65_with_macro(
// ┌────────┬────────┐ ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐        ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
    KC_NO,   TO_FN1,    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,             KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,  KC_DEL, KC_HOME, \
// ┌────────┬────────┐ ├────────┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┘    ┌───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────────┼────────┤
    KC_F1,   KC_F2,     KC_TAB,       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,         KC_END,  \
// ┌────────┬────────┐ ├─────────────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┐      └─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴────────────┼────────┤
    KC_F3,   KC_F4,     KC_ESC,         KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT, KC_PGUP, \
// ┌────────┬────────┐ ├───────────────┴─────┬──┴─────┬──┴─────┬──┴─────┬──┴─────┬──┴─────┐  └─────┬──┴─────┬──┴─────┬──┴─────┬──┴─────┬──┴─────┬──┴───────────────────┼────────┤
    KC_F5,   KC_F6,     KC_LSFT,              KC_Z,       KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_INS, KC_PGDN, \
// ┌────────┬────────┐ ├──────────┬──────────┴┬───────┴──┬─────┴─────┬──┴────────┴────────┤        ├────────┴────────┴────┬───┴────┬───┴────┬───┴────┬────────┬────────┼────────┤
    KC_F7,   KC_F8,     KC_LCTL, KC_LGUI, KC_LALT, MO(_ARR),KC_SPC,          KC_SPC,  NUMTOG,    KC_RALT, KC_RGUI, KC_MENU, KC_RCTL, KC_PSCR, PS_COM
// └────────┴────────┘ └──────────┴───────────┴──────────┴───────────┴────────────────────┘        └──────────────────────┴────────┴────────┴────────┴────────┴────────┴────────┘
  ),

  [_FN1] = LAYOUT_65_with_macro(
    TO_DEF, TO_FN2, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
     KC_F9, KC_F10, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    KC_F11, KC_F12, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    KC_F13, KC_F14, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    KC_F15, KC_F16, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_FN2] = LAYOUT_65_with_macro(
    TO_FN1, KC_NO, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    KC_F17, KC_F18, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    KC_F19, KC_F20, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    KC_F21, KC_F22, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    KC_F23, KC_F24, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_PS] = LAYOUT_65_with_macro(
    C(KC_MINS), C(KC_EQL), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    KC_LBRC, KC_RBRC, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    KC_E, KC_B, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    KC_SPC, KC_L, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    KC_DEL, KC_BSPC, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_ARR] = LAYOUT_65_with_macro(
     TO_DEF, TO(_PS), _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_BSPC, _______, \
    _______, _______, _______, KC_BTN2, KC_MS_U, KC_BTN1, _______, KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_BTN2, _______, _______, _______, _______, \
    _______, _______, KC_CAPS, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,          KC_BSPC, _______, _______, _______, _______, _______, _______, _______
  ),

  [_NUM] = LAYOUT_65_with_macro(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______,   KC_P7,   KC_P8,   KC_P9, KC_PPLS, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______,   KC_P4,   KC_P5,   KC_P6, KC_PCMM, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______,   KC_P1,   KC_P2,   KC_P3, KC_PEQL, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,          _______, _______,   KC_P0, KC_PDOT, KC_PENT, _______, _______, _______
  ),

  [_COM] = LAYOUT_65_with_macro(
     TO_DEF, TO(_PS), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______
  ),
};

uint8_t soda_current_layer = _DEF;

void do_layer_color(void) {
    switch (soda_current_layer) {
        case(_FN1):

            rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_SWIRL + 4);
            rgblight_set_effect_range(0, 12);

            rgblight_sethsv_range(10, 255, 255, 12, 16);
            break;
        case(_FN2):
            rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_SWIRL + 4);
            rgblight_set_effect_range(0, 12);

            rgblight_sethsv_range(20, 255, 255, 12, 16);
            break;
        case(_NUM):
            rgblight_set_effect_range(0, 11);
            if (IS_HOST_LED_ON(USB_LED_NUM_LOCK)) {
                rgblight_sethsv_range(0, 255, 255, 11, 12);
            } else {
                rgblight_sethsv_range(0, 125, 255, 11, 12);
            }
            break;
        case(_PS):
            rgblight_set_effect_range(0, 12);
            // rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_SWIRL + 4);

            rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 3);
            rgblight_sethsv_noeeprom(HSV_RED);

            rgblight_sethsv_range(125, 255, 255, 12, 16);
            break;
        case(_COM):
            rgblight_set_effect_range(0, 16);
            rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 3);
            rgblight_sethsv_noeeprom(HSV_PURPLE);
            break;
        default:
            rgblight_set_effect_range(0, 16);
            rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_SWIRL + 4);

            rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 3);
            rgblight_sethsv_noeeprom(HSV_RED);

            break;
    }
}

uint32_t layer_state_set_user(uint32_t state) {

    soda_current_layer = biton32(state);
    do_layer_color();

    return state;
}

void matrix_scan_user(void) {
    // do_layer_color();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case NUMTOG:
            if (record->event.pressed) {
                numtog_timer = timer_read();               
                layer_on(_NUM);
            } else {
                layer_off(_NUM);

                if (numtog_on) { 
                    numtog_on = false; 
                    do_layer_color();
                    break; 
                }

                if (timer_elapsed(numtog_timer) < TAPPING_TERM) {
                    layer_invert(_NUM);
                    numtog_on = true;
                }
            }
            do_layer_color();
            break;
    }
    return true;
}

void led_set_user(uint8_t usb_led) {
    do_layer_color();
}
