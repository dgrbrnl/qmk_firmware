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

// Midnight + Vim palette
//
// Color groups by Vim role — base midnight blue aesthetic preserved:
//
//  near-white  rgb(220, 235, 255)  ESC        — exit any mode (most critical)
//  deep purple rgb( 90,  15, 170)  Fn row     — media / RGB controls
//  vivid cyan  rgb(  0, 220, 255)  Motions    — HJKL, WEB, GNF/T (where to go)
//  amber       rgb(255, 155,   0)  Operators  — DCYRX + . (what to do)
//  green       rgb(  0, 200,  80)  Insert     — IAO (enter insert mode)
//  violet      rgb(160,   0, 255)  Visual     — V
//  red-orange  rgb(255,  70,  30)  Undo       — U
//  yellow      rgb(255, 215,   0)  Search     — /
//  lime        rgb( 80, 220,  80)  Paste      — P
//  ice-white   rgb(180, 220, 255)  Command    — ; (Shift+; = :)
//  cyan        rgb(  0, 200, 255)  Counts     — number row + Enter + arrows
//  dim amber   rgb(100,  40,   0)  CapsLock   — "remap me to Esc or Ctrl"
//  ice blue    rgb( 80, 144, 255)  Modifiers  — Shift / Ctrl / Cmd / Fn
//  midnight    rgb(  0,  50, 154)  Space
//  electric bl rgb(  0,  75, 210)  Other alpha — unlisted keys
//  navy void   rgb(  3,   8,  28)  Background — non-alpha

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    for (uint8_t i = led_min; i < led_max; i++) {
        switch (i) {
            // ESC: near-white — exit any Vim mode
            case 0:
                rgb_matrix_set_color(i, 220, 235, 255);
                break;

            // Function row (F1–F12, Del, RGB_MOD): deep purple
            case 1: case 2: case 3: case 4: case 5: case 6: case 7:
            case 8: case 9: case 10: case 11: case 12: case 13: case 14: case 15:
                rgb_matrix_set_color(i, 90, 15, 170);
                break;

            // Number row (` 1–0 - = Bspc): cyan — count multipliers (5j, 10dd…)
            case 16: case 17: case 18: case 19: case 20:
            case 21: case 22: case 23: case 24: case 25:
            case 26: case 27: case 28: case 29:
                rgb_matrix_set_color(i, 0, 200, 255);
                break;

            // Motion keys: vivid cyan — HJKL + word motions + goto/find/next
            case 52: // H — left
            case 53: // J — down
            case 54: // K — up
            case 55: // L — right
            case 33: // W — word forward
            case 34: // E — word end
            case 64: // B — word back
            case 51: // G — goto (gg / G / 5G)
            case 65: // N — next search match
            case 50: // F — find char (fa, fb…)
            case 36: // T — till char (ta, tb…)
                rgb_matrix_set_color(i, 0, 220, 255);
                break;

            // Operators: amber — delete / change / yank / delete-char / replace / repeat
            case 49: // D — delete
            case 62: // C — change
            case 37: // Y — yank
            case 61: // X — delete char under cursor
            case 35: // R — replace char
            case 68: // . — repeat last change (most powerful Vim key)
                rgb_matrix_set_color(i, 255, 155, 0);
                break;

            // Insert-mode entry: green — I / A / O
            case 39: // I — insert before cursor
            case 47: // A — append after cursor
            case 40: // O — open new line below
                rgb_matrix_set_color(i, 0, 200, 80);
                break;

            // Visual mode: violet — V
            case 63:
                rgb_matrix_set_color(i, 160, 0, 255);
                break;

            // Undo: red-orange — U
            case 38:
                rgb_matrix_set_color(i, 255, 70, 30);
                break;

            // Search: yellow — /
            case 69:
                rgb_matrix_set_color(i, 255, 215, 0);
                break;

            // Paste: lime — P
            case 41:
                rgb_matrix_set_color(i, 80, 220, 80);
                break;

            // Command mode: bright ice — ; (Shift+; = :)
            case 56:
                rgb_matrix_set_color(i, 180, 220, 255);
                break;

            // CapsLock: dim amber — "remap me to Esc or Ctrl"
            case 46:
                rgb_matrix_set_color(i, 100, 40, 0);
                break;

            // Enter: cyan — confirm Ex commands / jump
            case 58:
                rgb_matrix_set_color(i, 0, 210, 255);
                break;

            // Shift keys: ice blue
            case 59: case 73:
                rgb_matrix_set_color(i, 80, 144, 255);
                break;

            // Bottom-row modifiers (Ctrl, Opt/Alt, Cmd/Win, Fn): ice blue
            case 74: case 75: case 76: case 77: case 78:
                rgb_matrix_set_color(i, 80, 144, 255);
                break;

            // Space: midnight blue
            case 72:
                rgb_matrix_set_color(i, 0, 50, 154);
                break;

            // Side cluster + arrows (PgUp/PgDn/Home/End/arrows): cyan
            case 30: case 44: case 45: case 70: case 71:
            case 79: case 80: case 81: case 82: case 83:
                rgb_matrix_set_color(i, 0, 200, 255);
                break;

            // Remaining alphas: electric blue
            // TAB(31) Q(32) S(48) Z(60) M(66) ,(67) [(42) ](43) \(44) '(57)
            case 31: case 32: case 48: case 60:
            case 66: case 67: case 42: case 43: case 57:
                rgb_matrix_set_color(i, 0, 75, 210);
                break;

            // Everything else: navy void
            default:
                rgb_matrix_set_color(i, 3, 8, 28);
                break;
        }
    }
    return false;
}

void keyboard_post_init_user(void) {
    rgb_matrix_enable_noeeprom();
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_keychron_common(keycode, record)) {
        return false;
    }
    return true;
}
