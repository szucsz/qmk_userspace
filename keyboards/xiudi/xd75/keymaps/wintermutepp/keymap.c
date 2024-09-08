/* Copyright 2017 Wunder
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

#ifdef CONSOLE_ENABLE
#include "print.h"
#endif

enum layer_names {
    _QW,
    _CO,
    _UP,
    _NV
};

#define NV(k)    LT(_NV,k)

#define HS(k)    MT(MOD_LSFT,k)
#define HC(k)    MT(MOD_LCTL,k)
#define HG(k)    MT(MOD_LGUI,k)
#define HA(k)    MT(MOD_LALT,k)

#define LEFT_D   G(C(KC_LEFT))
#define RGHT_D   G(C(KC_RGHT))
#define ADD_D    G(C(KC_D))
#define DEL_D    G(C(KC_F4))
#define LT_X     LT(0,KC_X)
#define LT_C     LT(0,KC_C)
#define LT_V     LT(0,KC_V)
#define LT_END   LT(0,KC_END)

enum custom_keycodes {
    PREV_W = SAFE_RANGE,
    NEXT_W,
    CC_QWER,
    CC_COLM,
    M_01,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//                                                   ||||||||                                                    ||||||||
    [_QW] = LAYOUT_ortho_5x15( /* QWERTY */
        KC_ESC,        KC_1,     KC_2,       KC_3,       KC_4,       KC_5,       C(KC_PGUP), C(KC_PGDN), KC_6,       KC_7,     KC_8,     KC_9,     KC_0,        KC_DEL,    KC_BSPC,
        KC_GRV,        KC_Q,     KC_W,       KC_E,       KC_R,       KC_T,         KC_LBRC,    KC_RBRC,  KC_Y,       KC_U,     KC_I,     KC_O,     KC_P,        KC_ENT,    KC_PGUP,
        CW_TOGG,       KC_A,     KC_S,       HC(KC_D),   HS(KC_F),   KC_G,         KC_EQL,     C(KC_F5), KC_H,       HS(KC_J), HC(KC_K), KC_L,     KC_SCLN,     KC_QUOT,   KC_PGDN,
        OSM(MOD_LSFT), KC_Z,     LT_X,       LT_C,       LT_V,       KC_B,         KC_MINS,    KC_BSLS,  KC_N,       KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,     KC_UP,     LT_END,
        OSM(MOD_LCTL), KC_LGUI,  KC_LALT,    TT(_UP),    TT(_NV),    KC_BSPC,      KC_TAB,     KC_ENT,   KC_SPC,     KC_DEL,   MO(_UP),  KC_HOME,  KC_LEFT,     KC_DOWN,   KC_RGHT
    ),
    [_CO] = LAYOUT_ortho_5x15( /* Colemak DH */
        KC_ESC,        KC_1,     KC_2,       KC_3,       KC_4,       KC_5,       C(KC_PGUP), C(KC_PGDN), KC_6,       KC_7,     KC_8,     KC_9,     KC_0,        KC_DEL,    KC_BSPC,
        KC_GRV,        KC_Q,     KC_W,       KC_F,       KC_P,       KC_B,         KC_LBRC,    KC_RBRC,  KC_J,       KC_L,     KC_U,     KC_Y,     KC_SCLN,     KC_ENT,    KC_PGUP,
        CW_TOGG,       KC_A,     KC_R,       HC(KC_S),   HS(KC_T),   KC_G,         KC_EQL,     C(KC_F5), KC_M,       HS(KC_N), HC(KC_E), KC_I,     KC_O,        KC_QUOT,   KC_PGDN,
        OSM(MOD_LSFT), KC_Z,     KC_X,       KC_C,       KC_D,       KC_V,         KC_MINS,    KC_BSLS,  KC_K,       KC_H,     KC_COMM,  KC_DOT,   KC_SLSH,     KC_UP,     LT_END,
        OSM(MOD_LCTL), KC_LGUI,  KC_LALT,    MO(_UP),    KC_SPC,     NV(KC_BSPC),  KC_TAB,     KC_ENT,   KC_SPC,     KC_DEL,   MO(_UP),  KC_HOME,  KC_LEFT,     KC_DOWN,   KC_RGHT
    ),
    [_UP] = LAYOUT_ortho_5x15( /* FUNCTION */
        KC_ESC,        KC_F1,    KC_F2,      KC_F3,      KC_F4,      KC_F5,        KC_F13,     KC_F14,   KC_F6,      KC_F7,    KC_F8,    KC_F9,    KC_F10,      KC_F11,    KC_F12,
        PREV_W,        NEXT_W,   KC_MPRV,    KC_MPLY,    KC_MNXT,    _______,      RGB_HUD,    RGB_HUI,  DT_PRNT,    _______,  _______,  _______,  KC_PSCR,     KC_SCRL,   KC_PAUS,
        KC_VOLD,       KC_VOLU,  _______,    _______,    _______,    _______,      RGB_SAD,    RGB_SAI,  DT_UP,      _______,  QK_BOOT,  _______,  CC_QWER,     CC_COLM,   _______,
        _______,       KC_MUTE,  _______,    _______,    _______,    RGB_TOG,      RGB_VAD,    RGB_VAI,  DT_DOWN,    _______,  _______,  _______,  _______,     KC_PGUP,   _______,
        _______,       _______,  _______,    MO(_UP),    _______,    _______,      RGB_RMOD,   RGB_MOD,  _______,    _______,  MO(_UP),  _______,  KC_HOME,     KC_PGDN,   KC_END
    ),
    [_NV] = LAYOUT_ortho_5x15( /* NAVIGATION */
        _______,       KC_F1,    KC_F2,      KC_F3,      KC_F4,      KC_F5,        _______,    _______,  KC_F6,      KC_F7,    KC_F8,    KC_F9,    KC_F10,      KC_F11,    KC_F12,
        C(KC_GRV),     M_01,     KC_PGUP,    KC_UP,      KC_PGDN,    KC_INS,       _______,    _______,  KC_F1,      KC_F2,    KC_F3,    KC_F4,    KC_F5,       KC_F6,     _______,
        _______,       KC_HOME,  KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_END,       _______,    _______,  KC_F7,      KC_F8,    KC_F9,    KC_F10,   KC_F11,      KC_F12,    _______,
        _______,       C(KC_Z),  C(KC_X),    C(KC_INS),  S(KC_INS),  KC_APP,       _______,    _______,  _______,    _______,  _______,  _______,  _______,     _______,   _______,
        _______,       _______,  _______,    _______,    _______,    _______,      _______,    _______,  KC_BTN1,    KC_BTN2,  _______,  _______,  _______,     _______,   _______
    )
};

/*
    [_LAYER] = LAYOUT_ortho_5x15(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
    )

*/

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    #ifdef CONSOLE_ENABLE
        const bool is_combo = record->event.type == COMBO_EVENT;
        uprintf("0x%04X,%u,%u,%u,%b,0x%02X,0x%02X,%u\n",
             0,
             is_combo ? 254 : record->event.key.row,
             is_combo ? 254 : record->event.key.col,
             get_highest_layer(layer_state),
             record->event.pressed,
             get_mods(),
             get_oneshot_mods(),
             record->tap.count
             );
    #endif
    switch (keycode) { // This will do most of the grunt work with the keycodes.
        case PREV_W:
            if (record->event.pressed) {
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    register_code(KC_LALT);
                }
                alt_tab_timer = timer_read();
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            break;
        case NEXT_W:
            if (record->event.pressed) {
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    register_code(KC_LALT);
                }
                alt_tab_timer = timer_read();
                register_code(KC_LSFT);
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
                unregister_code(KC_LSFT);
            }
            break;
        case LT(0,KC_END):
            if (!record->tap.count && record->event.pressed) {
                tap_code16(KC_HOME); // Intercept hold function to send Home
                return false;
            }
            return true;             // Return true for normal processing of tap keycode
        case LT(0,KC_X):
            if (!record->tap.count && record->event.pressed) {
                tap_code16(C(KC_X)); // Intercept hold function to send Ctrl-X
                return false;
            }
            return true;             // Return true for normal processing of tap keycode
        case LT(0,KC_C):
            if (!record->tap.count && record->event.pressed) {
                tap_code16(C(KC_C)); // Intercept hold function to send Ctrl-C
                return false;
            }
            return true;             // Return true for normal processing of tap keycode
        case LT(0,KC_V):
            if (!record->tap.count && record->event.pressed) {
                tap_code16(C(KC_V)); // Intercept hold function to send Ctrl-V
                return false;
            }
            return true;             // Return true for normal processing of tap keycode
        case CC_QWER:
            set_single_persistent_default_layer(_QW);
            return false;
        case CC_COLM:
            set_single_persistent_default_layer(_CO);
            return false;
        case M_01:
            if (record->event.pressed) {
//                SEND_STRING( SS_TAP(X_F2) SS_LCTL("a") SS_LCTL("x") SS_LSFT("\n") SS_TAP(X_F2) SS_LALT("\n") SS_LCTL("v") SS_TAP(X_ENT) );
            }
            break;
    }
    return true;
}

void matrix_scan_user(void) {
    if (is_alt_tab_active && IS_LAYER_OFF(_UP)) {
        unregister_code(KC_LALT);
        is_alt_tab_active = false;
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    int hue_fst = rgblight_get_hue();
    int sat_fst = rgblight_get_sat();
    int val_fst = rgblight_get_val();
    switch (get_highest_layer(state)) {
    case _NV:
        rgblight_sethsv_range(HSV_PURPLE, 0, 2);
        rgblight_set_effect_range( 2, 10);
        break;
    case _UP:
        rgblight_sethsv_range(HSV_CYAN, 0, 2);
        rgblight_set_effect_range( 2, 10);
        break;
    default:
        rgblight_sethsv_range(hue_fst, sat_fst, val_fst, 0, 2);
        rgblight_set_effect_range( 0, 12);
        break;
    }
    return state;
}

/*
 qmk info -m -kb xiudi/xd75 -km wintermutepp
⚠ xiudi/xd75: MOUSEKEY_ENABLE in rules.mk is overwriting mouse_key.enabled in info.json
⚠ xiudi/xd75: Feature mousekey is specified in both info.json and rules.mk, the rules.mk value wins.
⚠ xiudi/xd75: Feature console is specified in both info.json and rules.mk, the rules.mk value wins.
Keyboard Name: XD75
Manufacturer: xiudi
Website:
Maintainer: QMK Community
Layouts: LAYOUT_ortho_5x15
Processor: atmega32u4
Bootloader: atmel-dfu
Layout aliases: LAYOUT=LAYOUT_ortho_5x15
Matrix for "LAYOUT_ortho_5x15":
┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐
│0A││0B││0C││0D││0E││0F││0G││0H││0I││0J││0K││0L││0M││0N││0O│
└──┘└──┘└──┘└──┘└──┘└──┘└──┘└──┘└──┘└──┘└──┘└──┘└──┘└──┘└──┘
┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐
│1A││1B││1C││1D││1E││1F││1G││1H││1I││1J││1K││1L││1M││1N││1O│
└──┘└──┘└──┘└──┘└──┘└──┘└──┘└──┘└──┘└──┘└──┘└──┘└──┘└──┘└──┘
┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐
│2A││2B││2C││2D││2E││2F││2G││2H││2I││2J││2K││2L││2M││2N││2O│
└──┘└──┘└──┘└──┘└──┘└──┘└──┘└──┘└──┘└──┘└──┘└──┘└──┘└──┘└──┘
┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐
│3A││3B││3C││3D││3E││3F││3G││3H││3I││3J││3K││3L││3M││3N││3O│
└──┘└──┘└──┘└──┘└──┘└──┘└──┘└──┘└──┘└──┘└──┘└──┘└──┘└──┘└──┘
┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐
│4A││4B││4C││4D││4E││4F││4G││4H││4I││4J││4K││4L││4M││4N││4O│
└──┘└──┘└──┘└──┘└──┘└──┘└──┘└──┘└──┘└──┘└──┘└──┘└──┘└──┘└──┘
*/
