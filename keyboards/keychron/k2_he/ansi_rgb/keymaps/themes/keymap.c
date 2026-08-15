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

// Runtime-selectable RGB themes. Order defines the THEME_NEXT / THEME_PREV cycle
// and maps to the direct-select keys Fn+6 .. Fn+0.
enum theme_id {
    THEME_MIDNIGHT,
    THEME_PENTEST,
    THEME_DRACULA,
    THEME_HACKER,
    THEME_TOKYO_NIGHT,
    THEME_COUNT,
};

enum custom_keycodes {
    THEME_NEXT = NEW_SAFE_RANGE,
    THEME_PREV,
    THEME_1,
    THEME_2,
    THEME_3,
    THEME_4,
    THEME_5,
};

typedef union {
    uint32_t raw;
    struct {
        uint8_t theme;
    };
} user_config_t;

static user_config_t user_config;

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
        THEME_NEXT, BT_HST1, BT_HST2, BT_HST3,  P2P4G,    THEME_PREV, THEME_1, THEME_2, THEME_3,  THEME_4,  THEME_5,  _______,  _______,  _______,            _______,
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
        THEME_NEXT, BT_HST1, BT_HST2, BT_HST3,  P2P4G,    THEME_PREV, THEME_1, THEME_2, THEME_3,  THEME_4,  THEME_5,  _______,  _______,  _______,            _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,            _______,            _______,
        _______,            _______,  _______,  _______,  _______,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,            _______,  _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______,  _______,  _______)
};
// clang-format on

// ---------------------------------------------------------------------------
// LED index map (from g_led_config in ansi_rgb.c) — all themes use these:
//
//   row 0   0=Esc  1-13=Fn row  14=Del  15=RGB_MOD
//   row 1  16=`   17-26=1..0   27=-   28==   29=Bspc  30=PgUp
//   row 2  31=Tab 32=Q 33=W 34=E 35=R 36=T 37=Y 38=U 39=I 40=O 41=P
//          42=[ 43=] 44=\  45=PgDn
//   row 3  46=Caps 47=A 48=S 49=D 50=F 51=G 52=H 53=J 54=K 55=L
//          56=; 57='  58=Enter 59=Home
//   row 4  60=LShift 61=Z 62=X 63=C 64=V 65=B 66=N 67=M 68=, 69=. 70=/
//          71=RShift 72=Up 73=End
//   row 5  74=LCtrl 75=LOpt 76=LCmd 77=Space 78=RCmd 79=Fn 80=RCtrl
//          81=Left 82=Down 83=Right
// ---------------------------------------------------------------------------

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
static void theme_midnight(uint8_t led_min, uint8_t led_max) {
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
            case 65: // B — word back
            case 51: // G — goto (gg / G / 5G)
            case 66: // N — next search match
            case 50: // F — find char (fa, fb…)
            case 36: // T — till char (ta, tb…)
                rgb_matrix_set_color(i, 0, 220, 255);
                break;

            // Operators: amber — delete / change / yank / delete-char / replace / repeat
            case 49: // D — delete
            case 63: // C — change
            case 37: // Y — yank
            case 62: // X — delete char under cursor
            case 35: // R — replace char
            case 69: // . — repeat last change (most powerful Vim key)
                rgb_matrix_set_color(i, 255, 155, 0);
                break;

            // Insert-mode entry: green — I / A / O
            case 39: // I — insert before cursor
            case 47: // A — append after cursor
            case 40: // O — open new line below
                rgb_matrix_set_color(i, 0, 200, 80);
                break;

            // Visual mode: violet — V
            case 64:
                rgb_matrix_set_color(i, 160, 0, 255);
                break;

            // Undo: red-orange — U
            case 38:
                rgb_matrix_set_color(i, 255, 70, 30);
                break;

            // Search: yellow — /
            case 70:
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
            case 60: case 71:
                rgb_matrix_set_color(i, 80, 144, 255);
                break;

            // Bottom-row modifiers (Ctrl, Opt/Alt, Cmd/Win, Fn): ice blue
            case 74: case 75: case 76: case 78: case 79: case 80:
                rgb_matrix_set_color(i, 80, 144, 255);
                break;

            // Space: midnight blue
            case 77:
                rgb_matrix_set_color(i, 0, 50, 154);
                break;

            // Side cluster + arrows (PgUp/PgDn/Home/End/arrows): cyan
            case 30: case 45: case 59: case 73:
            case 72: case 81: case 82: case 83:
                rgb_matrix_set_color(i, 0, 200, 255);
                break;

            // Remaining alphas + punctuation: electric blue
            // TAB(31) Q(32) S(48) Z(61) M(67) ,(68) [(42) ](43) \(44) '(57)
            case 31: case 32: case 48: case 61:
            case 67: case 68: case 42: case 43: case 44: case 57:
                rgb_matrix_set_color(i, 0, 75, 210);
                break;

            // Everything else: navy void
            default:
                rgb_matrix_set_color(i, 3, 8, 28);
                break;
        }
    }
}

// Pentest palette — kill-chain phases on a Kali-black backdrop.
//
// Each alpha key is colored by the phase of the engagement its mnemonic tool
// belongs to, so the board reads like a methodology cheat sheet:
//
//   recon cyan    rgb(  0, 215, 255)  Recon / enum   — N A D W G F E O
//   web blue      rgb(  0, 110, 255)  Web app        — B Z S X
//   exploit red   rgb(255,  40,  40)  Exploitation   — M P C V
//   cred amber    rgb(255, 150,   0)  Creds / crack  — H J T R K U
//   post violet   rgb(180,   0, 255)  Post-exploit   — I L Y Q
//   port green    rgb(  0, 255,  65)  Ports / scope  — number row
//   exec white    rgb(255, 255, 255)  Execute        — Enter
//   cleanup rust  rgb(200,  45,   0)  Anti-forensics — Bspc / Del
//   kill red      rgb(255,   0,   0)  Abort session  — Esc
//   root red      rgb(255,   0,  40)  CapsLock ON    — "root engaged"
//   steel         rgb( 60,  85, 110)  Modifiers
//   toolkit green rgb(  0, 120,  40)  Fn row / Space / nav
//   void          rgb(  0,  18,   8)  Background
static void theme_pentest(uint8_t led_min, uint8_t led_max) {
    bool caps_on = host_keyboard_led_state().caps_lock;

    for (uint8_t i = led_min; i < led_max; i++) {
        switch (i) {
            // Esc: kill switch — drop the session
            case 0:
                rgb_matrix_set_color(i, 255, 0, 0);
                break;

            // Fn row (media / RGB controls): dim toolkit green
            case 1: case 2: case 3: case 4: case 5: case 6: case 7:
            case 8: case 9: case 10: case 11: case 12: case 13:
            case 15:
                rgb_matrix_set_color(i, 0, 120, 40);
                break;

            // Del: anti-forensics — wipe logs
            case 14:
                rgb_matrix_set_color(i, 200, 45, 0);
                break;

            // Number row (` 1-0 - =): port / scope green (22, 80, 443, 445...)
            case 16: case 17: case 18: case 19: case 20: case 21:
            case 22: case 23: case 24: case 25: case 26: case 27:
            case 28:
                rgb_matrix_set_color(i, 0, 255, 65);
                break;

            // Backspace: anti-forensics — clear history
            case 29:
                rgb_matrix_set_color(i, 200, 45, 0);
                break;

            // Recon / enumeration: cyan
            case 66: // N — nmap
            case 47: // A — amass
            case 49: // D — dnsrecon
            case 33: // W — whois / wfuzz
            case 51: // G — gobuster
            case 50: // F — ffuf
            case 34: // E — enum4linux
            case 40: // O — OSINT (theHarvester)
                rgb_matrix_set_color(i, 0, 215, 255);
                break;

            // Web application testing: electric blue
            case 65: // B — Burp Suite
            case 61: // Z — OWASP ZAP
            case 48: // S — sqlmap
            case 62: // X — XSStrike
                rgb_matrix_set_color(i, 0, 110, 255);
                break;

            // Exploitation: red
            case 67: // M — Metasploit
            case 41: // P — payload (msfvenom)
            case 63: // C — C2 / beacon
            case 64: // V — vuln lookup (searchsploit)
                rgb_matrix_set_color(i, 255, 40, 40);
                break;

            // Credential attacks / cracking: amber
            case 52: // H — hashcat
            case 53: // J — john
            case 36: // T — THC-Hydra
            case 35: // R — Responder
            case 54: // K — kerbrute
            case 38: // U — unshadow
                rgb_matrix_set_color(i, 255, 150, 0);
                break;

            // Post-exploitation / privesc: violet
            case 39: // I — impacket
            case 55: // L — LinPEAS / lateral movement
            case 37: // Y — YARA / artifact analysis
            case 32: // Q — quiet ops / opsec check
                rgb_matrix_set_color(i, 180, 0, 255);
                break;

            // CapsLock: root indicator — blazing red while engaged
            case 46:
                if (caps_on) {
                    rgb_matrix_set_color(i, 255, 0, 40);
                } else {
                    rgb_matrix_set_color(i, 60, 20, 0);
                }
                break;

            // Enter: execute
            case 58:
                rgb_matrix_set_color(i, 255, 255, 255);
                break;

            // Tab: pivot / completion — toolkit green
            case 31:
                rgb_matrix_set_color(i, 0, 120, 40);
                break;

            // Space: payload delivery — mid green
            case 77:
                rgb_matrix_set_color(i, 0, 160, 50);
                break;

            // Modifiers (Shift, Ctrl, Opt/Alt, Cmd/Win, Fn): steel
            case 60: case 71:                     // LShift / RShift
            case 74: case 75: case 76:            // LCtrl / LOpt / LCmd
            case 78: case 79: case 80:            // RCmd / Fn / RCtrl
                rgb_matrix_set_color(i, 60, 85, 110);
                break;

            // Nav cluster + arrows (PgUp/PgDn/Home/End/arrows): toolkit green
            case 30: case 45: case 59: case 73:
            case 72: case 81: case 82: case 83:
                rgb_matrix_set_color(i, 0, 120, 40);
                break;

            // Everything else (punctuation, brackets, slashes): void
            default:
                rgb_matrix_set_color(i, 0, 18, 8);
                break;
        }
    }
}

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
static void theme_dracula(uint8_t led_min, uint8_t led_max) {
    for (uint8_t i = led_min; i < led_max; i++) {
        switch (i) {
            // Esc: red
            case 0:
                rgb_matrix_set_color(i, 255, 85, 85);
                break;
            // Function row (F1-F12, Del, RGB_MOD): purple
            case 1: case 2: case 3: case 4: case 5: case 6:
            case 7: case 8: case 9: case 10: case 11: case 12:
            case 13: case 14: case 15:
                rgb_matrix_set_color(i, 189, 147, 249);
                break;
            // Number row (` 1-0 - =): green
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
            case 31:
                rgb_matrix_set_color(i, 98, 114, 164);
                break;
            // Top alpha row Q-P: cyan
            case 32: case 33: case 34: case 35: case 36: case 37:
            case 38: case 39: case 40: case 41:
                rgb_matrix_set_color(i, 139, 233, 253);
                break;
            // Caps Lock: red (danger indicator)
            case 46:
                rgb_matrix_set_color(i, 255, 85, 85);
                break;
            // Home row A-L: pink
            case 47: case 48: case 49: case 50: case 51: case 52:
            case 53: case 54: case 55:
                rgb_matrix_set_color(i, 255, 121, 198);
                break;
            // Enter: orange
            case 58:
                rgb_matrix_set_color(i, 255, 184, 108);
                break;
            // Shift keys: purple
            case 60: case 71:
                rgb_matrix_set_color(i, 189, 147, 249);
                break;
            // Bottom alpha row Z-/ : yellow
            case 61: case 62: case 63: case 64: case 65:
            case 66: case 67: case 68: case 69: case 70:
                rgb_matrix_set_color(i, 241, 250, 140);
                break;
            // Bottom-row modifiers (Ctrl, Opt/Alt, Cmd/Win, Fn): comment blue-grey
            case 74: case 75: case 76: case 78: case 79: case 80:
                rgb_matrix_set_color(i, 98, 114, 164);
                break;
            // Space: dim purple
            case 77:
                rgb_matrix_set_color(i, 80, 60, 120);
                break;
            // Nav cluster + arrows (PgUp/PgDn/Home/End/arrows): cyan
            case 30: case 45: case 59: case 73:
            case 72: case 81: case 82: case 83:
                rgb_matrix_set_color(i, 139, 233, 253);
                break;
            // Everything else ([ ] \ ; '): dark selection base
            default:
                rgb_matrix_set_color(i, 68, 71, 90);
                break;
        }
    }
}

// Hacker palette — classic terminal green on black
// Bright green:  #00ff41  (Matrix/CRT phosphor)
// Mid green:     #00cc33  (secondary alphas)
// Dim green:     #003b00  (base/off keys — near black)
// Amber accent:  #ffb000  (critical modifiers — danger/warning)
// Red alert:     #ff0000  (Esc key)
static void theme_hacker(uint8_t led_min, uint8_t led_max) {
    for (uint8_t i = led_min; i < led_max; i++) {
        switch (i) {
            // Esc: red alert
            case 0:
                rgb_matrix_set_color(i, 255, 0, 0);
                break;
            // Alpha keys (Q-P, A-L, Z-M rows): bright green
            case 32: case 33: case 34: case 35: case 36: case 37:
            case 38: case 39: case 40: case 41:
            case 47: case 48: case 49: case 50: case 51: case 52:
            case 53: case 54: case 55:
            case 61: case 62: case 63: case 64: case 65: case 66:
            case 67:
                rgb_matrix_set_color(i, 0, 255, 65);
                break;
            // Number row (` 1-0 - =): mid green
            case 16: case 17: case 18: case 19: case 20: case 21:
            case 22: case 23: case 24: case 25: case 26: case 27:
            case 28:
                rgb_matrix_set_color(i, 0, 204, 51);
                break;
            // Backspace, Enter: amber
            case 29: case 58:
                rgb_matrix_set_color(i, 255, 176, 0);
                break;
            // Shift keys: amber
            case 60: case 71:
                rgb_matrix_set_color(i, 255, 176, 0);
                break;
            // Arrow keys: bright green
            case 72: case 81: case 82: case 83:
                rgb_matrix_set_color(i, 0, 255, 65);
                break;
            // Space: dim green
            case 77:
                rgb_matrix_set_color(i, 0, 100, 20);
                break;
            // Everything else: near-black dim green
            default:
                rgb_matrix_set_color(i, 0, 30, 0);
                break;
        }
    }
}

// Tokyo Night color palette
// Blue:        #7aa2f7  122, 162, 247
// Purple:      #bb9af7  187, 154, 247
// Cyan:        #7dcfff  125, 207, 255
// Orange:      #ff9e64  255, 158, 100
// Base:        dim blue-purple  26, 27, 80
static void theme_tokyo_night(uint8_t led_min, uint8_t led_max) {
    for (uint8_t i = led_min; i < led_max; i++) {
        switch (i) {
            // Esc + function row: purple
            case 0: case 1: case 2: case 3: case 4: case 5:
            case 6: case 7: case 8: case 9: case 10: case 11:
            case 12: case 13: case 14: case 15:
                rgb_matrix_set_color(i, 187, 154, 247);
                break;
            // Number row (` 1-0 - =): blue
            case 16: case 17: case 18: case 19: case 20:
            case 21: case 22: case 23: case 24: case 25:
            case 26: case 27: case 28:
                rgb_matrix_set_color(i, 122, 162, 247);
                break;
            // Backspace, Enter, Shifts, Ctrls: orange
            case 29: case 58: case 60: case 71: case 74: case 80:
                rgb_matrix_set_color(i, 255, 158, 100);
                break;
            // Nav cluster + arrows (PgUp/PgDn/Home/End/arrows): cyan
            case 30: case 45: case 59: case 73:
            case 72: case 81: case 82: case 83:
                rgb_matrix_set_color(i, 125, 207, 255);
                break;
            // Everything else: dim blue-purple base
            default:
                rgb_matrix_set_color(i, 26, 27, 80);
                break;
        }
    }
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    switch (user_config.theme) {
        case THEME_PENTEST:
            theme_pentest(led_min, led_max);
            break;
        case THEME_DRACULA:
            theme_dracula(led_min, led_max);
            break;
        case THEME_HACKER:
            theme_hacker(led_min, led_max);
            break;
        case THEME_TOKYO_NIGHT:
            theme_tokyo_night(led_min, led_max);
            break;
        case THEME_MIDNIGHT:
        default:
            theme_midnight(led_min, led_max);
            break;
    }
    return false;
}

// Persist only on an actual change — the EEPROM is flash-emulated with
// wear leveling, so needless writes cost erase cycles.
static void theme_set(uint8_t theme) {
    if (theme >= THEME_COUNT || theme == user_config.theme) {
        return;
    }
    user_config.theme = theme;
    eeconfig_update_user(user_config.raw);
}

void eeconfig_init_user(void) {
    user_config.raw   = 0;
    user_config.theme = THEME_MIDNIGHT;
    eeconfig_update_user(user_config.raw);
}

void keyboard_post_init_user(void) {
    user_config.raw = eeconfig_read_user();
    // Guards a never-initialised or stale EEPROM block (reads as 0xFFFFFFFF).
    // Repaired in place so the bad value is not re-read on every boot.
    if (user_config.theme >= THEME_COUNT) {
        user_config.raw   = 0;
        user_config.theme = THEME_MIDNIGHT;
        eeconfig_update_user(user_config.raw);
    }

    rgb_matrix_enable_noeeprom();
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_keychron_common(keycode, record)) {
        return false;
    }

    if (record->event.pressed) {
        switch (keycode) {
            case THEME_NEXT:
                theme_set((user_config.theme + 1) % THEME_COUNT);
                return false;
            case THEME_PREV:
                theme_set((user_config.theme + THEME_COUNT - 1) % THEME_COUNT);
                return false;
            case THEME_1 ... THEME_5:
                theme_set(keycode - THEME_1);
                return false;
        }
    }

    return true;
}
