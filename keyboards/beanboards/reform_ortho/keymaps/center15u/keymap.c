/*
* Copyright 2024 BeanBoards & OLKB (github.com/C44Supra & github.com/olkb)
* SPDX-License-Identifier: GPL-2.0-or-later
*/

#include QMK_KEYBOARD_H

enum reformortho_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST
};

enum reformortho_keycodes {
    RO_MENU = QK_USER,
    DIAMOND,
    CIRCLE,
    STAR,
    MOON,
    HEART,
    GEAR
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_center15u(
        /*
         * ,--------------------------------------------------------------------------------------------------------.
         * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   |   DIAMOND  |   |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
         * |------+------+------+------+------+------+---+------------+---+------+------+------+------+------+------|
         * |   `  |   1  |   2  |   3  |   4  |   5  |   |   CIRCLE   |   |   6  |   7  |   8  |   9  |   0  |  DEL |
         * |------+------+------+------+------+------+---+------------+---+------+------+------+------+------+------|
         * |  TAB |   Q  |   W  |   E  |   R  |   T  |   |   STAR     |   |   Y  |   U  |   I  |   O  |   P  | BSPC |
         * |------+------+------+------+------+------+---+------------+---+------+------+------+------+------+------|
         * |  ESC |   A  |   S  |   D  |   F  |   G  |   |   MOON     |   |   H  |   J  |   K  |   L  |   ;  |   '  |
         * |------+------+------+------+------+------+---+------------+---+------+------+------+------+------+------|
         * |LSHIFT|   Z  |   X  |   C  |   V  |   B  |   |   HEART    |   |   N  |   M  |   ,  |   .  |   /  | ENTER|
         * |------+------+------+------+------+------+---+------------+---+------+------+------+------+------+------|
         * | MENU | LALT | LGUI | LCTL | LOWER| RSFT |   |   GEAR     |   | SPACE| RAISE| LEFT | DOWN |  UP  | RIGHT|
         * `--------------------------------------------------------------------------------------------------------'
        */
        KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      DIAMOND,    KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,
        KC_GRV,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       CIRCLE,     KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_DEL,
        KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       STAR,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_BSLS,
        KC_ESC,     KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       MOON,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,
        KC_CAPS,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       HEART,      KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_ENT,
        RO_MENU,    KC_LALT,    KC_LGUI,    KC_LCTL,    TL_LOWR,    KC_RSFT,    GEAR,       KC_SPC,     TL_UPPR,    KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT
    ),
    [_LOWER] = LAYOUT_center15u(
        /*
         * ,--------------------------------------------------------------------------------------------------------.
         * |      |      |      |      |      |      |   |            |   |      |      |      |      |      |      |
         * |------+------+------+------+------+------+---+------------+---+------+------+------+------+------+------|
         * |  ~   |   !  |   @  |   #  |   $  |   %  |   |            |   |   ^  |   &  |   *  |   (  |   )  | Bspc |
         * |------+------+------+------+------+------+---+------------+---+------+------+------+------+------+------|
         * |      |      |      |      |      |      |   |            |   |      |      |      |      |      |  Del |
         * |------+------+------+------+------+------+---+------------+---+------+------+------+------+------+------|
         * |      |      |      |      |      |      |   |            |   |      |      |      | Home | End  |      |
         * |------+------+------+------+------+------+---+------------+---+------+------+------+------+------+------|
         * |      |      |      |      |      |      |   |            |   |      |      |      | Prev | Next |      |
         * |------+------+------+------+------+------+---+------------+---+------+------+------+------+------+------|
         * |      |      |      |      |      |      |   |            |   |      |      |      | Vol- | Vol+ | Play |
         * `--------------------------------------------------------------------------------------------------------'
        */
        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
        KC_QUOT,    KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,     KC_PERC,    KC_TRNS,    KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_LPRN,    KC_RPRN,    KC_BSPC,
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_TRNS,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_DEL,
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_TRNS,    KC_NO,      KC_NO,      KC_NO,      KC_HOME,    KC_END,     KC_NO,
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_TRNS,    KC_NO,      KC_NO,      KC_NO,      KC_MPRV,    KC_MNXT,    KC_NO,
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_TRNS,    KC_NO,      KC_TRNS,    KC_NO,      KC_VOLD,    KC_VOLU,    KC_MPLY
    ),
    [_RAISE] = LAYOUT_center15u(
        /*
         * ,--------------------------------------------------------------------------------------------------------.
         * |      |      |      |      |      |      |   |            |   |      |      |      |      |      |      |
         * |------+------+------+------+------+------+---+------------+---+------+------+------+------+------+------|
         * |      |      |      |      |      |      |   |            |   |      |      |      |      |      |      |
         * |------+------+------+------+------+------+---+------------+---+------+------+------+------+------+------|
         * |      |      |      |      |      |      |   |            |   |      |      |      |      |      |      |
         * |------+------+------+------+------+------+---+------------+---+------+------+------+------+------+------|
         * |      |      |      |      |      |      |   |            |   |      |      |      |      |      |      |
         * |------+------+------+------+------+------+---+------------+---+------+------+------+------+------+------|
         * |      |      |      |      |      |      |   |            |   |      |      |      |      |      |      |
         * |------+------+------+------+------+------+---+------------+---+------+------+------+------+------+------|
         * |      |      |      |      |      |      |   |            |   |      |      |      |      |      |      |
         * `--------------------------------------------------------------------------------------------------------'
        */
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_TRNS,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_TRNS,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_TRNS,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_TRNS,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_TRNS,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_TRNS,    KC_NO,      KC_TRNS,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO
    ),
    [_ADJUST] = LAYOUT_center15u(
        /*
         * ,--------------------------------------------------------------------------------------------------------.
         * | RESET|      |      |      |      |      |   |            |   |      |      |      |      |      |      |
         * |------+------+------+------+------+------+---+------------+---+------+------+------+------+------+------|
         * |      |      |      |      |      |      |   |            |   |      |      |      |      |      |      |
         * |------+------+------+------+------+------+---+------------+---+------+------+------+------+------+------|
         * |      |      |      |      |      |      |   |            |   |      |      |      |      |      |      |
         * |------+------+------+------+------+------+---+------------+---+------+------+------+------+------+------|
         * |      |      |      |      |RM_B+ |      |   |            |   |      |      |      |      |      |      |
         * |------+------+------+------+------+------+---+------------+---+------+------+------+------+------+------|
         * |      |RM_TGG|RM_PRV|RM_NXT|RM_B- |      |   |            |   |      |      |      |      |      |      |
         * |------+------+------+------+------+------+---+------------+---+------+------+------+------+------+------|
         * |      |      |      |      |      |      |   |            |   |      |      |      |      |      |      |
         * `--------------------------------------------------------------------------------------------------------'
        */
        QK_BOOT,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_TRNS,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_TRNS,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_TRNS,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      RM_VALU,    KC_NO,      KC_TRNS,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
        KC_NO,      RM_TOGG,    RM_PREV,    RM_NEXT,    RM_VALD,    KC_NO,      KC_TRNS,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_TRNS,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO
    )
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}