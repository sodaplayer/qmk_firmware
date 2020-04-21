#include QMK_KEYBOARD_H
#include "soda.h"

#define COM_Q LT(COM_LAYER, KC_Q)

#define SPC_NUM LT(NUM_LAYER, KC_SPC)
#define SPC_SYM LT(MISC_LAYER, KC_SPC)

#define B_NUM LT(NUM_LAYER, KC_B)
#define B_SYM LT(MISC_LAYER, KC_B)

#define N_SYM LT(MISC_LAYER, KC_N)

#define S_ARR LT(ARR_LAYER, KC_S)

#define DOT_FUN LT(FUN_LAYER, KC_DOT)


#define SFT_A MT(MOD_LSFT,  KC_A)
#define SFT_TAB MT(MOD_LSFT, KC_TAB)

#define SFT_SPC MT(MOD_LSFT, KC_SPC)

#define SFT_N MT(MOD_LSFT, KC_N)
#define SFT_B MT(MOD_LSFT, KC_B)

#define RALT_M MT(MOD_RALT, KC_M)

#define RALT_SPC MT(MOD_RALT, KC_SPC)


#define CTL_Z MT(MOD_LCTL,  KC_Z)
#define CTL_BS MT(MOD_RCTL,  KC_BSPC)

#define WIN_X LGUI_T(KC_X)

#define KC_CAD LALT(LCTL(KC_DEL))

#define CTL_DOWN (keyboard_report->mods & (MOD_BIT(KC_LCTL) | MOD_BIT(KC_RCTL)))
#define SFT_DOWN (keyboard_report->mods & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT)))
#define ALT_DOWN (keyboard_report->mods & (MOD_BIT(KC_LALT) | MOD_BIT(KC_RALT)))
#define WIN_DOWN (keyboard_report->mods & (MOD_BIT(KC_LGUI) | MOD_BIT(KC_RGUI)))

#define RGB_DEFAULT_MODE RGBLIGHT_MODE_BREATHING + 3
#define RGB_SHIFT_MODE RGBLIGHT_MODE_SNAKE + 1
#define RGB_CTRL_MODE RGBLIGHT_MODE_SNAKE
#define RGB_ALT_MODE RGBLIGHT_MODE_ALTERNATING
#define RGB_SHIFT_CTRL_MODE RGBLIGHT_MODE_KNIGHT + 2

#define HSV_DEFAULT 25, 255, 255

extern rgblight_config_t rgblight_config;

enum layers {
    DEFAULT_LAYER = 0,
    COM_LAYER,
    NUM_LAYER,
    MISC_LAYER,
    ARR_LAYER,
    FUN_LAYER,
};

enum combos {
    JK_ESC,
    BN_SPC,
};

const uint16_t PROGMEM esc_combo[] = { KC_J, KC_K, COMBO_END };
const uint16_t PROGMEM spc_combo[] = { KC_B, KC_N, COMBO_END };

combo_t key_combos[COMBO_COUNT] = {
    [JK_ESC] = COMBO(esc_combo, KC_ESC),
    [BN_SPC] = COMBO(spc_combo, KC_SPC),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [DEFAULT_LAYER] = LAYOUT_ortho_3x10(
          COM_Q ,  KC_W ,   KC_E ,  KC_R ,  KC_T ,     KC_Y ,  KC_U ,  KC_I ,  KC_O ,    KC_P ,
          SFT_A ,   S_ARR ,   KC_D ,  KC_F ,  KC_G ,     KC_H ,  KC_J ,  KC_K ,  KC_L ,    KC_SFTENT ,
          CTL_Z ,  WIN_X ,  KC_C ,  KC_V ,   B_NUM ,  N_SYM,  KC_M , RALT_SPC ,  DOT_FUN ,  CTL_BS
  ),

  [COM_LAYER] = LAYOUT_ortho_3x10(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_MPRV,  KC_MPLY,  KC_MNXT,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_VOLU,  KC_MSTP,  BL_INC,
    KC_CAD,  _______,  _______,  _______,  _______,  _______,  RESET,    KC_VOLD,  KC_MUTE,  BL_DEC
  ),

  [NUM_LAYER] = LAYOUT_ortho_3x10(
       KC_1,  KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,      KC_9,      KC_0,
    KC_TAB,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   KC_QUOTE,  KC_SCOLON,
    _______,  _______,  _______,  _______,  _______,  SFT_SPC,  _______,  KC_COMMA,  KC_DOT,    _______
  ),

  // [SYM_LAYER] = LAYOUT_ortho_3x10(
  //      KC_EXLM,  KC_AT,     KC_HASH,     KC_DOLLAR,     KC_PERC,     KC_CIRC,     KC_AMPR,     KC_ASTR,      KC_LPRN,      KC_RPRN,
  //   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,
  //   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,   _______
  // ),

  [MISC_LAYER] = LAYOUT_ortho_3x10(
    KC_GRAVE,  _______,  _______,  _______,  _______,  _______,  KC_LBRC,  KC_RBRC,   KC_MINUS,  KC_EQUAL,
    SFT_TAB,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,   KC_BSLASH,
    _______,  _______,  _______,  _______,  SFT_SPC,  _______,  _______,  _______,   _______,  KC_SLASH
  ),

  [ARR_LAYER] = LAYOUT_ortho_3x10(
    _______,  _______,  _______,  _______,  _______,  KC_MS_L,  KC_MS_D,  KC_MS_U,  KC_MS_R,   KC_BTN1,
    _______,  _______,  _______,  _______,  _______,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT,  KC_BTN2,
    _______,  _______,  _______,  _______,  _______,  KC_WH_L,  KC_WH_D,  KC_WH_U,  KC_WH_R,   _______
  ),

  [FUN_LAYER] = LAYOUT_ortho_3x10(
    KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,  KC_INS,  KC_HOME,  KC_PGUP,     _______,
     KC_F7, KC_F8, KC_F9, KC_F10,  KC_F11,  KC_F12, KC_DEL,  KC_END,  KC_PGDN, _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
  ),
};

uint8_t soda_current_layer = DEFAULT_LAYER;

uint32_t layer_state_set_user(uint32_t state) {

    soda_current_layer = biton32(state);
    do_layer_color();

    return state;
}

void do_layer_color(void) {
    switch (soda_current_layer) {
        case NUM_LAYER:
            rgblight_sethsv_noeeprom(HSV_RED);
            break;
        case MISC_LAYER:
            rgblight_sethsv_noeeprom(HSV_AZURE);
            break;
        case COM_LAYER:
            rgblight_sethsv_noeeprom(HSV_MAGENTA);
            break;
        case FUN_LAYER:
            rgblight_sethsv_noeeprom(HSV_PURPLE);
            break;
        default:
            rgblight_sethsv_noeeprom(HSV_DEFAULT);
            break;
    }
}

const uint8_t RGBLED_BREATHING_INTERVALS[] PROGMEM = {200, 100, 50, 25};
// const uint8_t RGBLED_SNAKE_INTERVALS[] PROGMEM = {255, 200, 100};

void matrix_init_user(void) {
}

void keyboard_post_init_user(void) {
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom(25, 255, 255);
    rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 3);
}

void matrix_scan_user(void) {
    if (CTL_DOWN && SFT_DOWN) {
        if (rgblight_config.mode != RGB_SHIFT_CTRL_MODE) {
            rgblight_mode_noeeprom(RGB_SHIFT_CTRL_MODE);
        }
    } else {
        if (CTL_DOWN) {
            if (rgblight_config.mode != RGB_CTRL_MODE) {
                rgblight_mode_noeeprom(RGB_CTRL_MODE);
            }
        }
        else if (SFT_DOWN) {
            if (rgblight_config.mode != RGB_SHIFT_MODE) {
                rgblight_mode_noeeprom(RGB_SHIFT_MODE);
            }
        }
        else if (ALT_DOWN) {
            if (rgblight_config.mode != RGB_ALT_MODE) {
                rgblight_mode_noeeprom(RGB_ALT_MODE);
            }
        }
        else {
            if (rgblight_config.mode != RGB_DEFAULT_MODE) {
                rgblight_mode_noeeprom(RGB_DEFAULT_MODE);
            }
        }
    }

    if (WIN_DOWN) {
        rgblight_sethsv_noeeprom(HSV_GOLD);
    } else {
        do_layer_color();
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}

void led_set_user(uint8_t usb_led) {

  if (usb_led & (1 << USB_LED_NUM_LOCK)) {
    DDRD |= (1 << 5); PORTD &= ~(1 << 5);
  } else {
    DDRD &= ~(1 << 5); PORTD &= ~(1 << 5);
  }

  if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
    DDRB |= (1 << 0); PORTB &= ~(1 << 0);
  } else {
    DDRB &= ~(1 << 0); PORTB &= ~(1 << 0);
  }

  if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {

  } else {

  }

  if (usb_led & (1 << USB_LED_COMPOSE)) {

  } else {

  }

  if (usb_led & (1 << USB_LED_KANA)) {

  } else {

  }

}
