// Copyright (C) 2026  Keyboard.io, Inc
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layer_number {
    L_IB = 0,
    L_WB,
    L_WF,
    L_WS,
    L_IF,
    L_IS,
    L_META
};

enum custom_keycodes {
    I_PREV_W = SAFE_RANGE,
    I_NEXT_W,
    W_PREV_W,
    W_NEXT_W,
};

#define WF(k)     LT(L_WF,k)
#define WS(k)     LT(L_WS,k)
#define META(k)   LT(L_META,k)
#define IF(k)     LT(L_IF,k)
#define IS(k)     LT(L_IS,k)

#define HS(k)     MT(MOD_LSFT,k)
#define HC(k)     MT(MOD_LCTL,k)
#define HA(k)     MT(MOD_LALT,k)
#define HG(k)     MT(MOD_RGUI,k)

#define CA(k)     C(A(k))
#define SA(k)     S(A(k))
#define SG(k)     S(G(k))
#define GA(k)     G(A(k))
#define GC(k)     G(C(k))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [L_IB] = LAYOUT(
        KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,                                   KC_Y,     KC_U,      KC_I,      KC_O,     KC_P,
        HC(KC_A),  HA(KC_S),  HG(KC_D),  HS(KC_F),  KC_G,                                   KC_H,     HS(KC_J),  HG(KC_K),  HA(KC_L), HC(KC_SCLN),
        KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,       KC_GRV,          KC_QUOT,   KC_N,     KC_M,      KC_COMM,   KC_DOT,   KC_SLSH,
        KC_LCTL,   KC_LALT,   KC_RGUI,   KC_ESC,    KC_TAB,  IF(KC_BSPC),     IS(KC_SPC),   KC_DEL,   XXXXXXX,   XXXXXXX,   XXXXXXX,  KC_BSLS
    ),

    [L_WB] = LAYOUT(
        KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,                                   KC_Y,     KC_U,      KC_I,      KC_O,     KC_P,
        HG(KC_A),  HA(KC_S),  HC(KC_D),  HS(KC_F),  KC_G,                                   KC_H,     HS(KC_J),  HC(KC_K),  HA(KC_L), HG(KC_SCLN),
        KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,       KC_GRV,          KC_QUOT,   KC_N,     KC_M,      KC_COMM,   KC_DOT,   KC_SLSH,
        KC_LGUI,   KC_LALT,   KC_LCTL,   KC_ESC,    KC_TAB,  WF(KC_BSPC),     WS(KC_SPC),   KC_DEL,   XXXXXXX,   XXXXXXX,   XXXXXXX,  KC_BSLS
    ),

    [L_IF] = LAYOUT(
        C(KC_GRV), G(KC_LEFT), KC_UP,  G(KC_RIGHT), KC_DEL,                                 KC_INS,    KC_F1,      KC_F2,       KC_F3,     KC_F4,
        I_PREV_W,  KC_LEFT,    KC_DOWN,  KC_RGHT,   KC_PGUP,                                KC_ESC,    HS(KC_F5),  HG(KC_F6),   HA(KC_F7), HC(KC_F8),
        G(KC_Z),   G(KC_X),    G(KC_C),  G(KC_V),   KC_PGDN,   KC_ESC,           KC_INS,    CW_TOGG,   KC_F9,      KC_F10,      KC_F11,    KC_F12,
        KC_LCTL,   KC_LALT,    KC_RGUI,  KC_ESC,    KC_TAB,    KC_BSPC,          KC_SPC,    KC_DEL,    SG(KC_LBRC),SG(KC_RBRC), C(KC_F11), C(KC_F12)
    ),

    [L_WF] = LAYOUT(
        C(KC_GRV), KC_HOME,    KC_UP,    KC_END,    KC_DEL,                                 KC_INS,    KC_F1,     KC_F2,     KC_F3,     KC_F4,
        W_PREV_W,  KC_LEFT,    KC_DOWN,  KC_RGHT,   KC_PGUP,                                KC_ESC,    HS(KC_F5), HC(KC_F6), HA(KC_F7), HG(KC_F8),
        G(KC_Z),   G(KC_X),    G(KC_C),  G(KC_V),   KC_PGDN,   KC_ESC,           KC_INS,    CW_TOGG,   KC_F9,     KC_F10,    KC_F11,    KC_F12,
        KC_RGUI,   KC_LALT,    KC_LCTL,  KC_ESC,    KC_TAB,    KC_BSPC,          KC_SPC,    KC_DEL,    C(KC_PGUP),C(KC_PGDN),C(KC_F11), C(KC_F12)
    ),

    [L_IS] = LAYOUT(
        KC_EXLM,   KC_AT,     KC_HASH,   KC_DLR,    KC_PERC,                                KC_CIRC,   KC_AMPR,   KC_ASTR,   KC_LPRN,   KC_RPRN,
        HC(KC_1),  HA(KC_2),  HG(KC_3),  HS(KC_4),  KC_5,                                   KC_6,      HS(KC_7),  HG(KC_8),  HA(KC_9),  HC(KC_0),
        XXXXXXX,   KC_LBRC,   KC_RBRC,   KC_LCBR,   KC_RCBR,   KC_ESC,           KC_DOT,    KC_UNDS,   KC_MINS,   KC_EQL,    KC_PLUS,   KC_SLSH,
        KC_LCTL,   KC_LALT,   KC_RGUI,   KC_ESC,    KC_TAB,    KC_BSPC,          KC_SPC,    KC_DEL,    XXXXXXX,   XXXXXXX,   XXXXXXX,   KC_BSLS
    ),

    [L_WS] = LAYOUT(
        KC_EXLM,   KC_AT,     KC_HASH,   KC_DLR,    KC_PERC,                                KC_CIRC,   KC_AMPR,   KC_ASTR,   KC_LPRN,   KC_RPRN,
        HG(KC_1),  HA(KC_2),  HC(KC_3),  HS(KC_4),  KC_5,                                   KC_6,      HS(KC_7),  HC(KC_8),  HA(KC_9),  HG(KC_0),
        XXXXXXX,   KC_LBRC,   KC_RBRC,   KC_LCBR,   KC_RCBR,   KC_ESC,           KC_DOT,    KC_UNDS,   KC_MINS,   KC_EQL,    KC_PLUS,   KC_SLSH,
        KC_RGUI,   KC_LALT,   KC_LCTL,   KC_ESC,    KC_TAB,    KC_BSPC,          KC_SPC,    KC_DEL,    XXXXXXX,   XXXXXXX,   XXXXXXX,   KC_BSLS
    ),
};

const uint16_t PROGMEM combo_enter_comma_dot[] =     {KC_COMM,     KC_DOT,       COMBO_END};
const uint16_t PROGMEM combo_enter_vb[] =            {KC_V,        KC_B,         COMBO_END};
const uint16_t PROGMEM combo_space_rt[] =            {KC_R,        KC_T,         COMBO_END};
const uint16_t PROGMEM combo_win[] =                 {KC_TAB,      KC_DEL,       COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_enter_comma_dot, KC_ENT),
    COMBO(combo_enter_vb, KC_ENT),
    COMBO(combo_space_rt, KC_SPACE),
    COMBO(combo_win, DF(L_WB)),
};

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HS(KC_J):
        case HS(KC_F):
            // Immediately select the hold action when another key is pressed.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;
bool is_gui_tab_active = false;
uint16_t gui_tab_timer = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case I_PREV_W:
            if (record->event.pressed) {
                if (!is_gui_tab_active) {
                    is_gui_tab_active = true;
                    register_code(KC_LGUI);
                }
                gui_tab_timer = timer_read();
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            break;
        case I_NEXT_W:
            if (record->event.pressed) {
                if (!is_gui_tab_active) {
                    is_gui_tab_active = true;
                    register_code(KC_LGUI);
                }
                gui_tab_timer = timer_read();
                register_code(KC_LSFT);
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
                unregister_code(KC_LSFT);
            }
            break;
        case W_PREV_W:
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
        case W_NEXT_W:
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
    }
    return true;
}

void matrix_scan_user(void) {
    if (is_gui_tab_active && IS_LAYER_OFF(L_IF)) {
        unregister_code(KC_LGUI);
        is_gui_tab_active = false;
    }
    if (is_alt_tab_active && IS_LAYER_OFF(L_WF)) {
        unregister_code(KC_LALT);
        is_alt_tab_active = false;
    }
}
