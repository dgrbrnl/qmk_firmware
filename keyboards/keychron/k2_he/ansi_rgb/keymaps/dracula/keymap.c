/* Copyright 2024 @ Keychron (https://www.keychron.com)
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
#include "keychron_common.h"

enum layers {
    MAC_BASE,
    MAC_FN,
    WIN_BASE,
    WIN_FN,
};

#define FN_MAC MO(MAC_FN)
#define FN_WIN MO(WIN_FN)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_84(
        KC_ESC,   KC_BRID,  KC_BRIU,  KC_MCTRL, KC_LNPAD, RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_SNAP,  KC_DEL,   RGB_MOD,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_HOME,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,  KC_UP,    KC_END,
        KC_LCTL,  KC_LOPTN, KC_LCMMD,                               KC_SPC,                                 KC_RCMMD, FN_MAC,   KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [MAC_FN] = LAYOUT_ansi_84(
        _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,  _______,  RGB_TOG,
        _______,  BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,            _______,            _______,
        _______,            _______,  _______,  _______,  _______,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,            _______,  _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______,  _______,  _______),

    [WIN_BASE] = LAYOUT_ansi_84(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,  KC_DEL,   RGB_MOD,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_HOME,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,  KC_UP,    KC_END,
        KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                                 KC_RALT,  FN_WIN,   KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [WIN_FN] = LAYOUT_ansi_84(
        _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,  _______,  RGB_TOG,
        _______,  BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,            _______,            _______,
        _______,            _______,  _______,  _______,  _______,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,            _______,  _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______,  _______,  _______)
};
// clang-format on

// Dracula color palette
// Purple:    #bd93f9  189, 147, 249
// Pink:      #ff79c6  255, 121, 198
// Cyan:      #8be9fd  139, 233, 253
// Green:     #50fa7b   80, 250, 123
// Yellow:    #f1fa8c  241, 250, 140
// Orange:    #ffb86c  255, 184, 108
// Red:       #ff5555  255,  85,  85
// Comment:   #6272a4   98, 114, 164  (dim blue-grey for modifiers)
// Selection: #44475a   68,  71,  90  (near-dark base)

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    for (uint8_t i = led_min; i < led_max; i++) {
        switch (i) {
            // Esc: red
            case 0:
                rgb_matrix_set_color(i, 255, 85, 85);
                break;
            // Function row: purple
            case 1: case 2: case 3: case 4: case 5: case 6:
            case 7: case 8: case 9: case 10: case 11: case 12:
            case 13: case 14: case 15:
                rgb_matrix_set_color(i, 189, 147, 249);
                break;
            // Number row: green
            case 16: case 17: case 18: case 19: case 20: case 21:
            case 22: case 23: case 24: case 25: case 26: case 27:
            case 28:
                rgb_matrix_set_color(i, 80, 250, 123);
                break;
            // Backspace: orange
            case 29:
                rgb_matrix_set_color(i, 255, 184, 108);
                break;
            // Tab: comment blue-grey
            case 30:
                rgb_matrix_set_color(i, 98, 114, 164);
                break;
            // Top alpha row Q-P: cyan
            case 31: case 32: case 33: case 34: case 35: case 36:
            case 37: case 38: case 39: case 40: case 41: case 42:
            case 43: case 44:
                rgb_matrix_set_color(i, 139, 233, 253);
                break;
            // Caps Lock: red (danger indicator)
            case 45:
                rgb_matrix_set_color(i, 255, 85, 85);
                break;
            // Home row A-L: pink
            case 46: case 47: case 48: case 49: case 50: case 51:
            case 52: case 53: case 54: case 55: case 56: case 57:
                rgb_matrix_set_color(i, 255, 121, 198);
                break;
            // Enter: orange
            case 58:
                rgb_matrix_set_color(i, 255, 184, 108);
                break;
            // Left Shift: purple
            case 59:
                rgb_matrix_set_color(i, 189, 147, 249);
                break;
            // Bottom alpha row Z-M: yellow
            case 60: case 61: case 62: case 63: case 64: case 65:
            case 66: case 67: case 68: case 69: case 70:
                rgb_matrix_set_color(i, 241, 250, 140);
                break;
            // Right Shift: purple
            case 71:
                rgb_matrix_set_color(i, 189, 147, 249);
                break;
            // Arrow up: cyan
            case 72:
                rgb_matrix_set_color(i, 139, 233, 253);
                break;
            // Left Ctrl, Option/Alt, Cmd/Win: comment blue-grey
            case 73: case 74: case 75:
                rgb_matrix_set_color(i, 98, 114, 164);
                break;
            // Space: dim purple
            case 76:
                rgb_matrix_set_color(i, 80, 60, 120);
                break;
            // Right Cmd/Win, Fn, Right Ctrl: comment blue-grey
            case 77: case 78: case 79:
                rgb_matrix_set_color(i, 98, 114, 164);
                break;
            // Arrow left, down, right: cyan
            case 80: case 81: case 82: case 83:
                rgb_matrix_set_color(i, 139, 233, 253);
                break;
            // Everything else: dark selection base
            default:
                rgb_matrix_set_color(i, 68, 71, 90);
                break;
        }
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_keychron_common(keycode, record)) {
        return false;
    }
    return true;
}
