#define _BASE_LEFT 1
#define _BASE   0

#include QMK_KEYBOARD_H

/* const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//     [_BASE_LEFT] = layout_left_split_cluster(
//         KC_ESC,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,
//         KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,
//         KC_LSFT,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,
//         KC_LCTL,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,
//                                 KC_LALT,    KC_SPC,     KC_LGUI,    KC_MUTE
//     )
// };

// #define LAYOUT( \
//     L00,    L01,    L02,    L03,    L04,    L05,    R00,    R01,    R02,    R03,    R04,    R05, \
//     L10,    L11,    L12,    L13,    L14,    L15,    R10,    R11,    R12,    R13,    R14,    R15, \
//     L20,    L21,    L22,    L23,    L24,    L25,    R20,    R21,    R22,    R23,    R24,    R25, \
//     L30,    L31,    L32,    L33,    L34,    L35,    R30,    R31,    R32,    R33,    R34,    R35, \
//                     L40,    L41,    L42,    L04,    R40,    R41,    R42,    R43 \
// ) \
*/


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_ESC,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_BSPC,
        KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_DEL,
        KC_LSFT,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_ENT,
        KC_LCTL,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_RSFT,
                                KC_LALT,    KC_SPC,     KC_LGUI,    KC_MUTE,    KC_PAUSE,   KC_NO,      KC_SPC,     KC_NO
    )
};

/*const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {*/
/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Adjust| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 *
[_BASE] = LAYOUT(
   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
   KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT , \
   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT , \
   ADJUST,  KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
),
*/

static void render_logo(void) {
  static const char PROGMEM qmk_logo[] = {
    0x80,0x81,0x82,0x83,0x84,
    0xa0,0xa1,0xa2,0xa3,0xa4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0};

  oled_write_P(qmk_logo, false);
}

void encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        // tap_code(KC_VOLU);
        tap_code(KC__VOLUP);
    } else {
        // tap_code(KC_VOLD);
        tap_code(KC__VOLDOWN);
    }
}


#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  return OLED_ROTATION_90;  // flips the display 180 degrees if offhand
}

void oled_task_user(void) {
  // Host Keyboard Layer Status
  oled_write_P(PSTR("Layer: "), false);
  switch (biton32(layer_state)) {
    case _BASE_LEFT:
      oled_write_P(PSTR("Base\n"), false);
      break;
    default:
      // Or use the write_ln shortcut over adding '\n' to the end of your string
      oled_write_ln_P(PSTR("Undefined"), false);
  }

  render_logo();

  // Host Keyboard LED Status
  uint8_t led_usb_state = host_keyboard_leds();
  oled_write_P(led_usb_state & (1<<USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false);
  oled_write_P(led_usb_state & (1<<USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);
  oled_write_P(led_usb_state & (1<<USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
}
#endif
