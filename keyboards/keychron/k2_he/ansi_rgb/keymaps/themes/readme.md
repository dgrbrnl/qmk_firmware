# themes — runtime-switchable RGB themes for the K2 HE (ANSI RGB)

Merges the five standalone theme keymaps (`midnight`, `pentest`, `dracula`,
`hacker`, `tokyo_night`) into one firmware. The active theme is selected at
runtime from the Fn layer and persisted to EEPROM, so it survives a reboot.

## Build & flash

```
qmk compile -kb keychron/k2_he/ansi_rgb -km themes
qmk flash   -kb keychron/k2_he/ansi_rgb -km themes
```

Hold **Esc** while plugging the board in to enter the STM32 DFU bootloader.

## Key combinations

| Combo | Action |
|---|---|
| `Fn` + `` ` `` | Next theme (wraps) |
| `Fn` + `5` | Previous theme (wraps) |
| `Fn` + `6` | Midnight (Vim-semantic blues) |
| `Fn` + `7` | Pentest (kill-chain phases on Kali black) |
| `Fn` + `8` | Dracula |
| `Fn` + `9` | Hacker (terminal green) |
| `Fn` + `0` | Tokyo Night |

Works on both the Mac and Windows Fn layers. `Fn` + `1` … `4` are left alone —
they remain the Keychron Bluetooth host / 2.4GHz keys.

The whole board repaints instantly, so the color change is its own confirmation.

## Notes

- Themes paint every LED from `rgb_matrix_indicators_advanced_user()`, which
  returns `false`. The RGB hue/saturation/brightness/mode keys therefore have no
  visible effect; `Fn` + `Tab` (`RGB_TOG`) still turns lighting off entirely.
- `RGB_MATRIX_BRIGHTNESS_TURN_OFF_VAL` is 32 in the keyboard's `config.h`, so
  driving brightness low enough shuts the LED driver down.
- EEPROM is only written when the theme actually changes — it is flash-emulated
  with wear leveling, so needless writes cost erase cycles.
- The `dracula` and `tokyo_night` LED indices were off by one row in the
  standalone keymaps (they predate commit 4660c63, which fixed `midnight` and
  `hacker`). They are corrected here against `g_led_config` in `ansi_rgb.c`;
  `midnight`, `pentest`, and `hacker` are carried over unchanged.
