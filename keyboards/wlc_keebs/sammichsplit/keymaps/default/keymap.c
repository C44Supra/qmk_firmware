#include QMK_KEYBOARD_H

#define _QWERTY     0
#define _COLEMAK    1
#define _DVORAK     2
#define _RAISE      3
#define _LOWER      4
#define _ADJUST     5

#define RAISE   MO(_RAISE)
#define LOWER   MO(_LOWER)
#define ADJUST  MO(_ADJUST)
#define YT_FAST LSFT(KC_DOT)
#define YT_SLOW LSFT(KC_COMMA)
#define TD_CAPS TD(TD_CAPSLOCK)

#define CAPTAC  LGUI(LSFT(LCTL(KC_4)))  // Area Copy
#define CAPTAS  LGUI(LSFT(KC_4))        // Area Save
#define CAPTSC  LGUI(LSFT(LCTL(KC_3)))  // Screen Copy
#define CAPTSS  LGUI(LSFT(KC_3))        // Screen Save


enum{
    TD_CAPSLOCK = 0
};

enum custom_keycodes {
    MSWGLR = SAFE_RANGE,
};

uint16_t    _activeKeyCode;
uint8_t     _changeDefaultLayout = false;
uint8_t     _mouseWiggler = false;
uint32_t    _lastMouseWiggle = 0;
uint8_t     _mouseDir = 0; // 0 right, 1 down, 2 left, 3 up
uint8_t     _mouseWiggleEnd = 0;


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Qwerty
    * ,-----------------------------------------------------------------------------------.
    * | ESC  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
    * |------+------+------+------+------+-------------+------+------+------+------+------|
    * | TAB  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
    * |------+------+------+------+------+------|------+------+------+------+------+------|
    * | Shift|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |   `  |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      | Raise| CTRL | GUI  | Mute | Pause|  Alt | Spc  |Lower |      |      |
    * `-----------------------------------------------------------------------------------'
    *
    */
    [_QWERTY] = LAYOUT(
        KC_ESC,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_BSPC,
        KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_DEL,
        TD_CAPS,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,
        KC_GRV,     KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_ENT,
                                RAISE,      KC_LCTL,    KC_LGUI,    KC_MUTE,    KC_MPLY,    KC_LALT,    KC_SPC,     LOWER
    ),
    /* Colemak
    * ,-----------------------------------------------------------------------------------.
    * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
    * |------+------+------+------+------+-------------+------+------+------+------+------|
    * | TAB  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Del  |
    * |------+------+------+------+------+------|------+------+------+------+------+------|
    * | Shift|   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |   `  |   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      | Raise| Spc  | GUI  | Mute | Pause|  Alt | Spc  |Lower |      |      |
    * `-----------------------------------------------------------------------------------'
    *
    */
    [_COLEMAK] = LAYOUT(
        KC_ESC,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_BSPC,
        KC_TAB,     KC_Q,       KC_W,       KC_F,       KC_P,       KC_G,       KC_J,       KC_L,       KC_U,       KC_Y,       KC_SCLN,    KC_DEL,
        TD_CAPS,    KC_A,       KC_R,       KC_S,       KC_T,       KC_D,       KC_H,       KC_N,       KC_E,       KC_I,       KC_O,       KC_QUOT,
        KC_GRV,     KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_K,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_ENTER,
                                RAISE,      KC_LCTL,    KC_LGUI,    KC_MUTE,    KC_MPLY,    KC_LALT,    KC_SPC,     LOWER
    ),
    /* Raise
    * ,-----------------------------------------------------------------------------------.
    * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
    * |------+------+------+------+------+-------------+------+------+------+------+------|
    * |CAPTAC|CAPTSC|CAPTAS|CAPTSS|      |      |      |      |      |   {  |  }   |   |  |
    * |------+------+------+------+------+------|------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |      |      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |      |      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |      |      |      |      |
    * `-----------------------------------------------------------------------------------'
    *
    */
    [_RAISE] = LAYOUT(
        KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,
        CAPTAC,     CAPTSC,     CAPTAS,    CAPTSS,    _______,    _______,    _______,    _______,    _______,    KC_LBRC,    KC_RBRC,    KC_PIPE,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
                                _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
    ),
    /* Lower
    * ,-----------------------------------------------------------------------------------.
    * |      |      |      |      |      |      |      |      |      |      |  -   |  =   |
    * |------+------+------+------+------+-------------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |  Up  |   [  |  ]   |  \   |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |      |      | Left | Down |Right |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |      |      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |      |      |      |      |
    * `-----------------------------------------------------------------------------------'
    *
    */
    [_LOWER] = LAYOUT(
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_MINS,    KC_EQL,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_UP,      _______,    _______,    KC_BSLS,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_LEFT,    KC_DOWN,    KC_RGHT,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
                                _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
    ),
    /* ADJUST
    * ,-----------------------------------------------------------------------------------.
    * | RGB  |R_RMOD|R_MOD |      |      |      |      |      |      |      |      |      |
    * |------+------+------+------+------+-------------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |      |      |      | RESET|
    * |------+------+------+------+------+------|------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |      |      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |MSWGLR|      |      |      |      |      |      |      |      |      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |      |      |      |      |
    * `-----------------------------------------------------------------------------------'
    *
    */
    [_ADJUST] = LAYOUT(
        RGB_TOG,    RGB_RMOD,   RGB_MOD,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    RESET,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        MSWGLR,     _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
                                _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
    )

};
// static void render_logo(void) {
//   static const char PROGMEM qmk_logo[] = {
//     0x80,0x81,0x82,0x83,0x84,
//     0xa0,0xa1,0xa2,0xa3,0xa4,
//     0xc0,0xc1,0xc2,0xc3,0xc4,0};

//   oled_write_P(qmk_logo, false);
// }

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_CAPSLOCK] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS)
};

void encoder_update_user(uint8_t index, bool clockwise) {
    switch(index){
        case 0:
            if (clockwise) {
                // tap_code(KC_VOLU);
                tap_code(KC__VOLUP);
            } else {
                // tap_code(KC_VOLD);
                tap_code(KC__VOLDOWN);
            }
            break;
        case 1:
            if (_activeKeyCode == RAISE){
                if (clockwise || !clockwise){
                    _changeDefaultLayout = true;
                }

            } else {
                if (clockwise){
                tap_code16(YT_FAST);
                } else {
                    tap_code16(YT_SLOW);
                }
            }
            break;
    }

}

void matrix_scan_user(void){
    if (_mouseWiggler){
        if (_lastMouseWiggle == 0){
            _lastMouseWiggle = timer_read();
            return;
        } else if (_mouseWiggleEnd == 0) {
            if (timer_read() > _lastMouseWiggle + 500){
                switch (_mouseDir){
                    case 0:
                    default:
                        // right
                        register_code(KC_MS_RIGHT);
                        _mouseWiggleEnd = timer_read() + 100;
                        break;
                    case 1:
                        // down
                        register_code(KC_MS_DOWN);
                        _mouseWiggleEnd = timer_read() + 100;
                        break;
                    case 2:
                        // left
                        register_code(KC_MS_LEFT);
                        _mouseWiggleEnd = timer_read() + 100;
                        break;
                    case 3:
                        // up;
                        register_code(KC_MS_UP);
                        _mouseWiggleEnd = timer_read() + 100;
                        break;
                }
            }
        } else if (_mouseWiggleEnd != 0){
            if (timer_read() >= _mouseWiggleEnd){
                switch (_mouseDir){
                    case 0:
                    default:
                        // right
                        unregister_code(KC_MS_RIGHT);
                        _mouseWiggleEnd = 0;
                        _mouseDir++;
                        break;
                    case 1:
                        // down
                        unregister_code(KC_MS_DOWN);
                        _mouseWiggleEnd = 0;
                        _mouseDir++;
                        break;
                    case 2:
                        // left
                        unregister_code(KC_MS_LEFT);
                        _mouseWiggleEnd = 0;
                        _mouseDir++;
                        break;
                    case 3:
                        // up
                        unregister_code(KC_MS_UP);
                        _mouseWiggleEnd = 0;
                        _mouseDir = 0;
                        break;
                }
            }
        }

    }

    return;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    _activeKeyCode = keycode;

    if (_changeDefaultLayout){
        if (biton32(default_layer_state) == _QWERTY){
            set_single_persistent_default_layer(_COLEMAK);
        } else {
            set_single_persistent_default_layer(_QWERTY);
        }
        _changeDefaultLayout = false;
    }

    switch(keycode){
        case LOWER:
            if (record->event.pressed){
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;
        case RAISE:
            if (record->event.pressed){
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;
        case MSWGLR:
            if (record->event.pressed){
                _mouseWiggler = !_mouseWiggler;
            }
    }

    return true;
}


#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  return OLED_ROTATION_90;  // flips the display 180 degrees if offhand
}

void oled_task_user(void) {
    // Host Keyboard Layer Status

    if (biton32(layer_state) > 2){
        oled_write_P(PSTR("Layer: \n"), false);
        switch(biton32(layer_state)){
            case _RAISE:
                oled_write_P(PSTR("Raise\n"), false);
                break;
            case _LOWER:
                oled_write_P(PSTR("Lower\n"), false);
                break;
            case _ADJUST:
                oled_write_P(PSTR("Adjust\n"), false);
                break;
            default:
                oled_write_P(PSTR("Eh...\n"), false);
                break;
        }
    } else {
        oled_write_P(PSTR("Layout: \n"), false);
        switch(biton32(default_layer_state)){
            case _QWERTY:
                oled_write_P(PSTR("Qwerty\n"), false);
                break;
            case _COLEMAK:
                oled_write_P(PSTR("Colemak\n"), false);
                break;
            case _DVORAK:
                oled_write_P(PSTR("Dvorak\n"), false);
                break;
            default:
                oled_write_P(PSTR("Whoopsie\n"), false);
                break;
        }
    }

//   render_logo();

  // Host Keyboard LED Status
  uint8_t led_usb_state = host_keyboard_leds();
  oled_write_P(led_usb_state & (1<<USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false);
  oled_write_P(led_usb_state & (1<<USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);
  oled_write_P(led_usb_state & (1<<USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
}
#endif

void keyboard_post_init_user(void) {
    // Customise these values to desired behaviour
    // debug_enable=true;
    // debug_matrix=true;
    // debug_keyboard=true;
    // debug_mouse=true;
}
