/* Copyright 2022 Jose Pablo Ramirez <jp.ramangulo@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

enum reformortho_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST
};

enum reformortho_keycodes {
    RO_MENU,
    ALLWHITE
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_ortho(
        /*
         * ,--------------------------------------------------------------------------------------------------------.
         * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |      |   +  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
         * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
         * |   `  |   1  |   2  |   3  |   4  |   5  |   (  |      |   )  |   6  |   7  |   8  |   9  |   0  |  DEL |
         * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
         * |  TAB |   Q  |   W  |   E  |   R  |   T  |   {  |      |   }  |   Y  |   U  |   I  |   O  |   P  | BSPC |
         * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
         * |  ESC |   A  |   S  |   D  |   F  |   G  |   [  |      |   ]  |   H  |   J  |   K  |   L  |   ;  |   '  |
         * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
         * |LSHIFT|   Z  |   X  |   C  |   V  |   B  |   <  |      |   >  |   N  |   M  |   ,  |   .  |   /  | ENTER|
         * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
         * | MENU | LALT | LGUI | LCTL | LOWER| RSFT | PIPE |      |   \  | SPACE| RAISE| LEFT | DOWN |  UP  | RIGHT|
         * `-------------------------------------------------------+------------------------------------------------'
        */
        KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_PMNS,    KC_P1,      KC_PPLS,    KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,
        KC_GRV,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_LPRN,    KC_P2,      KC_RPRN,    KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_DEL,
        KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_LCBR,    KC_P3,      KC_RCBR,    KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_BSLS,
        KC_ESC,     KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_LBRC,    KC_P4,      KC_RBRC,    KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,
        KC_CAPS,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_LT,      KC_P5,      KC_GT,      KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_ENT,
        KC_P9,    KC_LALT,    KC_LGUI,    KC_LCTL,    KC_P7,      KC_RSFT,    KC_PIPE,    KC_P6,      KC_SLSH,    KC_SPC,     KC_P8,      KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT
    ),
    [_LOWER] = LAYOUT_ortho(
        /*
         * ,--------------------------------------------------------------------------------------------------------.
         * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
         * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
         * |  ~   |   !  |   @  |   #  |   $  |   %  |      |      |      |   ^  |   &  |   *  |   (  |   )  | Bspc |
         * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
         * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |  Del |
         * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
         * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
         * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
         * |      |      |      |      |      |      |      |      |      |      |      |      | Home |  End |      |
         * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
         * |      |      |      |      |      |      |      |      |      |      | Prev | Next | Vol- | Vol+ | Play |
         * `-------------------------------------------------------+------------------------------------------------'
        */
        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_NO,      KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
        KC_QUOT,    KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,     KC_PERC,    KC_TRNS,    KC_NO,      KC_TRNS,    KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_LPRN,    KC_RPRN,    KC_BSPC,
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_TRNS,    KC_NO,      KC_TRNS,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_DEL,
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_TRNS,    KC_NO,      KC_TRNS,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_TRNS,    KC_NO,      KC_TRNS,    KC_NO,      KC_NO,      KC_NO,      KC_HOME,    KC_END,     KC_NO,
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_TRNS,    KC_NO,      KC_TRNS,    KC_NO,      KC_MPRV,    KC_MNXT,    KC_VOLD,    KC_VOLU,    KC_MPLY
    ),
    [_RAISE] = LAYOUT_ortho(
        /*
         * ,--------------------------------------------------------------------------------------------------------.
         * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
         * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
         * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
         * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
         * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
         * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
         * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
         * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
         * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
         * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
         * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
         * `-------------------------------------------------------+------------------------------------------------'
        */
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO
    ),
    [_ADJUST] = LAYOUT_ortho(
        /*
         * ,--------------------------------------------------------------------------------------------------------.
         * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
         * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
         * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
         * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
         * |      | RESET| DEBUG|EE_RST|      |      |      |      |      |      |      |      |      |      |      |
         * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
         * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
         * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
         * |      |RGBTOG|RGBMOD|RGBRMD|      |      |      |      |      |      |      |      |      |      |      |
         * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
         * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
         * `-------------------------------------------------------+------------------------------------------------'
        */
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
        KC_NO,      QK_BOOT,    DB_TOGG,    EE_CLR,     KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
        KC_NO,      RGB_TOG,    RGB_MOD,    RGB_RMOD,   KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO
    )
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ALLWHITE:
            rgb_matrix_set_color_all(254, 254, 254);
            return false;
    }
    return true;
}

// MNT Menu structure
//
// Exit Menu        ESC
// Key Backlight-    F1
// Key Backlight+    F2
// System Status      s
// USB Flashing Mode  x
//
//
// System status shows
//
// MNT Reform Keyboard
// RM 20220221
//
// The last line could potentially be a firmware build date?
//
// Enter menu with circle key, then use hotkeys as indicated.
//
// Todo:
// - Add splash
// - Add basic menu (see above)
// - Add RGB controls?
// - while in menu, prevent (hot)keys from registering on host



static void render_logo(void) {
    static const char PROGMEM mnt_splash[] = {
        // 'mntreform-splash', 128x32px
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xe0, 0xc0, 0x80,
0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xe0,
0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
0x7f, 0xfe, 0xfc, 0xf8, 0xf0, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xfe, 0xfc, 0xf8, 0xf0, 0xff, 0xff,
0xff, 0xff, 0x7f, 0xfe, 0xfc, 0xf8, 0xf0, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,
0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 0x03,
0x00, 0x00, 0x01, 0x03, 0x07, 0x0f, 0x1f, 0x3f, 0x7f, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0f, 0x1f,
0x3f, 0x7f, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0f, 0x1f, 0x3f, 0x7f, 0x00, 0x00, 0x00, 0xff, 0xff,
0x03, 0xdb, 0xdb, 0x27, 0xff, 0x03, 0xdb, 0xdb, 0xdb, 0xff, 0x07, 0xdb, 0xdb, 0xfb, 0xff, 0x07,
0xfb, 0xfb, 0xfb, 0x07, 0xff, 0x03, 0xdb, 0xdb, 0x27, 0xff, 0x03, 0xf7, 0xef, 0xdf, 0xef, 0xf7,
0x03, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07,
0x06, 0x07, 0x07, 0x06, 0x07, 0x06, 0x06, 0x06, 0x06, 0x07, 0x06, 0x07, 0x07, 0x07, 0x07, 0x07,
0x06, 0x06, 0x06, 0x07, 0x07, 0x06, 0x07, 0x07, 0x06, 0x07, 0x06, 0x07, 0x07, 0x07, 0x07, 0x07,
0x06, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    oled_write_raw_P(mnt_splash, sizeof(mnt_splash));
}

bool oled_task_user(void) {
    render_logo();
    return false;
}
