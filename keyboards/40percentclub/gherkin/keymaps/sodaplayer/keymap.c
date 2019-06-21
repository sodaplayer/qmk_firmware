#include QMK_KEYBOARD_H
#include "keymap.h"

#define COM_Q LT(COM_LAYER, KC_Q)

#define SPC_NUM LT(NUM_LAYER, KC_SPC)
#define SPC_SYM LT(SYM_LAYER, KC_SPC)

#define B_NUM LT(NUM_LAYER, KC_B)
#define B_SYM LT(SYM_LAYER, KC_B)

#define N_SYM LT(SYM_LAYER, KC_N)

#define S_ARR LT(ARR_LAYER, KC_S)
#define DOT_FUN LT(FUN_LAYER, KC_DOT)


#define WIN_W LGUI_T(LT(WIN_LAYER, KC_W))

#define SFT_A MT(MOD_LSFT,  KC_A)
#define SFT_TAB MT(MOD_LSFT, KC_TAB)

#define CTL_Z MT(MOD_LCTL,  KC_Z)
#define CTL_BS MT(MOD_RCTL,  KC_BSPC)
#define WIN_X LGUI_T(KC_X)

enum layers {
    DEFAULT_LAYER = 0,
    COM_LAYER,
    WIN_LAYER,
    NUM_LAYER,
    SYM_LAYER,
    ARR_LAYER,
    FUN_LAYER,
};

const uint16_t PROGMEM esc_combo[] = { KC_J, KC_K, COMBO_END };
combo_t key_combos[COMBO_COUNT] = { COMBO(esc_combo, KC_ESC) };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [DEFAULT_LAYER] = LAYOUT_ortho_3x10(
          COM_Q ,  KC_W ,   KC_E ,  KC_R ,  KC_T ,     KC_Y ,  KC_U ,  KC_I ,  KC_O ,    KC_P ,
          SFT_A ,   S_ARR ,   KC_D ,  KC_F ,  KC_G ,     KC_H ,  KC_J ,  KC_K ,  KC_L ,    KC_SFTENT ,
          CTL_Z ,  WIN_X ,  KC_C ,  KC_V ,   B_NUM , SPC_SYM ,   KC_N,  KC_M ,  DOT_FUN ,  CTL_BS
  ),

  [COM_LAYER] = LAYOUT_ortho_3x10(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_MPRV,  KC_MPLY,  KC_MNXT,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_VOLU,  KC_MSTP,  BL_INC,
    _______,  _______,  _______,  _______,  _______,  _______,  RESET,    KC_VOLD,  KC_MUTE,  BL_DEC
  ),

  [WIN_LAYER] = LAYOUT_ortho_3x10(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,
    _______,  _______,  _______,  _______,  _______,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______
  ),

  [NUM_LAYER] = LAYOUT_ortho_3x10(
       KC_1,  KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,      KC_9,      KC_0,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   KC_QUOTE,  KC_SCOLON,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_COMMA,  KC_DOT,    KC_SLASH
  ),

  [SYM_LAYER] = LAYOUT_ortho_3x10(
    KC_GRAVE,  _______,  _______,  _______,  _______,  _______,  KC_LBRC,  KC_RBRC,   KC_MINUS,  KC_EQUAL,
    SFT_TAB,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,   KC_COLON,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  KC_BSLASH
  ),

  [ARR_LAYER] = LAYOUT_ortho_3x10(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,
    _______,  _______,  _______,  _______,  _______,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______
  ),

  [FUN_LAYER] = LAYOUT_ortho_3x10(
    KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, 
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_F11,  KC_F12,
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
        case SYM_LAYER:
            rgblight_sethsv_noeeprom(120, 255, 255);
            break;
        case NUM_LAYER:
            rgblight_sethsv_noeeprom(0, 255, 255);
            break;
        default:
            rgblight_sethsv_noeeprom(25, 255, 255);
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
    if (keyboard_report->mods & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT))) {
        rgblight_sethsv_noeeprom(240, 255, 255);
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
