/*
Copyright 2022 aki27

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

// to compile: qmk compile -kb aki27/cocot46plus -km wintermute

#include QMK_KEYBOARD_H
// #include <stdio.h>
// #include "quantum.h"
// #include <print.h>
#include "version.h"
// #include "cocot46plus.h"

// Defines names for use in layer keycodes and the keymap
enum layer_number {
    L_BASE = 0,
    L_FUN,
    L_SYM,
    L_META,
    L_CURSOR,
    L_LAYER
};

enum custom_keycodes {
    PREV_W = SAFE_RANGE,
    NEXT_W,
};

#define FUN(k)    LT(L_FUN,k)
#define WNAV(k)   LT(L_WNAV,k)
#define SYM(k)    LT(L_SYM,k)
#define META(k)   LT(L_META,k)

#define HS(k)     MT(MOD_LSFT,k)
#define HC(k)     MT(MOD_LCTL,k)
#define HA(k)     MT(MOD_LALT,k)
#define HG(k)     MT(MOD_LGUI,k)

#define CA(k)     C(A(k))
#define SA(k)     S(A(k))
#define GA(k)     G(A(k))
#define GC(k)     G(C(k))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  //`------' O O O     O O O `------'
  [L_BASE] = LAYOUT(
  //|------------------------------------------------------------------|            |------------------------------------------------------------------------|
       KC_ESC,      KC_Q,      KC_W,       KC_E,       KC_R,    KC_T,                 KC_Y,        KC_U,       KC_I,       KC_O,          KC_P, KC_GRV,
       KC_LGUI,  HC(KC_A),  HA(KC_S),   HG(KC_D),   HS(KC_F),   KC_G,                 KC_H,     HS(KC_J),   HG(KC_K),   HA(KC_L),   HC(KC_SCLN), KC_QUOT,
       KC_LSFT,     KC_Z,      KC_X,       KC_C,       KC_V,    KC_B,                 KC_N,        KC_M,    KC_COMM,     KC_DOT,       KC_SLSH, KC_BSLS,
  //|------------------------------------------------------------------|            |------------------------------------------------------------------------|
                  XXXXXXX, KC_LALT, KC_TAB, FUN(KC_BSPC), KC_MS_BTN1,                 KC_MS_BTN2,  SYM(KC_SPC), KC_DEL,   KC_LCTL, TO(L_CURSOR),
                                                                 XXXXXXX, TO(L_LAYER), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
                               //`------------------------------------' O O O  O O O `------------------------------------'
    ),

// left hand activated
    //`------' O O X     O O O `------'
    [L_FUN] = LAYOUT(
    //|------------------------------------------------------------------|            |------------------------------------------------------------------------|
      _______,   C(KC_GRV),G(KC_LEFT),   KC_UP,  G(KC_RIGHT),     KC_DEL,                      KC_F1,      KC_F2,    KC_F3,     KC_F4,         KC_F5,    KC_F6,
       NEXT_W,     PREV_W,   KC_LEFT,   KC_DOWN,    KC_RGHT,    KC_PGUP,                     KC_F7,   HS(KC_F8), HG(KC_F9), HA(KC_F10), HC(KC_F11),   KC_F12,
      CW_TOGG,     G(KC_Z),  G(KC_X),   G(KC_C),    G(KC_V),    KC_PGDN,                     KC_INS,   G(KC_W), C(KC_PGUP), C(KC_PGDN),   C(KC_F5), C(KC_F12),
   //|------------------------------------------------------------------|            |------------------------------------------------------------------------|
                              _______, KC_VOLD, KC_VOLU, KC_BSPC, KC_MS_BTN1,         KC_MS_BTN2,  KC_SPC, _______,  _______, _______,
                                                                     XXXXXXX, TO(L_BASE) , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

// right hand activated layers
    //`------' O O O     X O O `------'
    [L_SYM] = LAYOUT(
    //|------------------------------------------------------------------|            |------------------------------------------------------------------------|
        _______, KC_EXLM,     KC_AT,    KC_HASH,  KC_DLR,  KC_PERC,                     KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_COMM,
        _______, HC(KC_1), HA(KC_2),   HG(KC_3),HS(KC_4),   KC_5,                        KC_6,    HS(KC_7), HG(KC_8), HA(KC_9), HC(KC_0),  KC_DOT,
        _______, XXXXXXX,     KC_LBRC,  KC_RBRC, KC_LCBR, KC_RCBR,                     KC_UNDS,  KC_MINS,   KC_EQL,  KC_PLUS,  KC_SLSH,  XXXXXXX,
    //|------------------------------------------------------------------|            |------------------------------------------------------------------------|
                              _______, _______, _______, KC_BSPC, KC_MS_BTN1,         KC_MS_BTN2,  KC_SPC, _______,  _______, _______,
                                                           XXXXXXX, TO(L_BASE),         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),
    //`------' O X O     O X O `------'
    [L_META] = LAYOUT(
    //|------------------------------------------------------------------|            |------------------------------------------------------------------------|
        QK_BOOT, DB_TOGG,  EE_CLR, DM_REC1, DM_REC2,     XXXXXXX,                             SCRL_TO,  CPI_SW, SCRL_SW, ROT_L15,  ROT_R15, RGB_TOG,
        XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,     DM_RSTP,                             SCRL_MO, RGB_VAI, RGB_SAI, RGB_HUI,  RGB_MOD, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, DM_PLY1, DM_PLY2,     XXXXXXX,                             SCRL_IN, RGB_VAD, RGB_SAD, RGB_HUD, RGB_RMOD, XXXXXXX,
    //|------------------------------------------------------------------|            |------------------------------------------------------------------------|
                             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MS_BTN1,         KC_MS_BTN2,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                           XXXXXXX, TO(L_BASE),         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    //`------' O O O     O O O `------'
    [L_CURSOR] = LAYOUT(
    //|------------------------------------------------------------------|            |------------------------------------------------------------------------|
         KC_ESC,  C(KC_Q),   C(KC_W), C(KC_PGUP), C(KC_PGDN), C(S(KC_T)),                 XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME,  KC_DEL, KC_BSPC,
        _______,  C(KC_A),   KC_LALT,    KC_LCTL,    KC_LSFT,    KC_F3,                   XXXXXXX, XXXXXXX, XXXXXXX,  KC_END,   KC_UP,  KC_ENT,
        _______,  C(KC_Z), S(KC_DEL),  C(KC_INS),  S(KC_INS),  XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT,
    //|------------------------------------------------------------------|            |------------------------------------------------------------------------|
                        _______,   _______,  KC_TAB, KC_BSPC, KC_MS_BTN1,         KC_MS_BTN2, KC_SPC, KC_DEL, KC_LGUI, TO(L_BASE),
                                                       XXXXXXX, TO(L_BASE),         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [L_LAYER] = LAYOUT(
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                      XXXXXXX, XXXXXXX, XXXXXXX, TO(L_FUN), XXXXXXX,        XXXXXXX, TO(L_SYM), TO(L_META), XXXXXXX, XXXXXXX,
                                                             XXXXXXX, TO(L_BASE), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [L_BASE]   = { ENCODER_CCW_CW(KC_WH_D, KC_WH_U) },
    [L_FUN]    = { ENCODER_CCW_CW(KC_WH_D, KC_WH_U) },
    [L_SYM]    = { ENCODER_CCW_CW(KC_WH_D, KC_WH_U) },
    [L_META]   = { ENCODER_CCW_CW(KC_WH_D, KC_WH_U) },
    [L_CURSOR] = { ENCODER_CCW_CW(C(KC_COMM), C(KC_DOT)) },
    [L_LAYER]  = { ENCODER_CCW_CW(KC_WH_D, KC_WH_U) },
};
#endif

const uint16_t PROGMEM combo_enter_comma_dot[] =     {KC_COMM,     KC_DOT,       COMBO_END};
const uint16_t PROGMEM combo_enter_vb[] =            {KC_V,        KC_B,         COMBO_END};
const uint16_t PROGMEM combo_space_rt[] =            {KC_R,        KC_T,         COMBO_END};
const uint16_t PROGMEM combo_fun_lock_tab_f_bspc[] = {KC_TAB,      FUN(KC_BSPC), COMBO_END};
const uint16_t PROGMEM combo_sym_lock_s_spc_del[] =  {SYM(KC_SPC), KC_DEL,       COMBO_END};
const uint16_t PROGMEM combo_fun_lock_tab_bspc[] =   {KC_VOLU,     KC_BSPC,      COMBO_END};
const uint16_t PROGMEM combo_sym_lock_spc_del[] =    {KC_SPC,      KC_DEL,       COMBO_END};
const uint16_t PROGMEM combo_meta[] =                {KC_TAB,      KC_DEL,       COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_enter_comma_dot, KC_ENT),
    COMBO(combo_enter_vb, KC_ENT),
    COMBO(combo_space_rt, KC_SPACE),
    COMBO(combo_fun_lock_tab_bspc, TG(L_FUN)),
    COMBO(combo_fun_lock_tab_f_bspc, TG(L_FUN)),
    COMBO(combo_sym_lock_spc_del, TG(L_SYM)),
    COMBO(combo_sym_lock_s_spc_del, TG(L_SYM)),
    COMBO(combo_meta, MO(L_META)),
};

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) { // This will do most of the grunt work with the keycodes.
        case PREV_W:
            if (record->event.pressed) {
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    register_code(KC_LGUI);
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
                    register_code(KC_LGUI);
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
    if (is_alt_tab_active && IS_LAYER_OFF(L_FUN)) {
        unregister_code(KC_LGUI);
        is_alt_tab_active = false;
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    int hue_fst = rgblight_get_hue();
    int sat_fst = rgblight_get_sat();
    int val_fst = rgblight_get_val();

    switch (get_highest_layer(state)) {
    case L_SYM:
        rgblight_sethsv_range(HSV_RED, 0, 2);
        rgblight_set_effect_range( 2, 10);
        cocot_set_scroll_mode(true);
        break;
    case L_FUN:
    case L_CURSOR:
        rgblight_sethsv_range(HSV_PURPLE, 0, 2);
        rgblight_set_effect_range( 2, 10);
        cocot_set_scroll_mode(true);
        break;
    case L_META:
        rgblight_sethsv_range(HSV_CYAN, 0, 2);
        rgblight_set_effect_range( 2, 10);
        cocot_set_scroll_mode(true);
        break;
    default:
        rgblight_sethsv_range(hue_fst, sat_fst, val_fst, 0, 2);
        rgblight_set_effect_range( 0, 12);
        cocot_set_scroll_mode(false);
        break;
    }
    return state;
};


#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    oled_set_brightness(80);
    return OLED_ROTATION_0;
}

void oled_write_layer_state_user(void) {

    oled_write_P(PSTR(" "), false);
    // int cpi = pointing_device_get_cpi();
    int cpi = cpi_array[cocot_config.cpi_idx];
    int scroll_div = scrl_div_array[cocot_config.scrl_div];
    int angle = angle_array[cocot_config.rotation_angle];

    char buf1[5];
    char buf2[3];
    char buf3[4];
    snprintf(buf1, 5, "%4d", cpi);
    snprintf(buf2, 3, "%2d", scroll_div);
    snprintf(buf3, 4, "%3d", angle);

    switch (get_highest_layer(layer_state | default_layer_state)) {
        case L_BASE:
            oled_write_P(PSTR("BASE "), false);
            break;
        case L_SYM:
            oled_write_P(PSTR(" SYM "), false);
            break;
        case L_FUN:
            oled_write_P(PSTR(" FUN "), false);
            break;
        case L_META:
            oled_write_P(PSTR("META "), false);
            break;
        case L_CURSOR:
            oled_write_P(PSTR("CRSR "), false);
            break;
        case L_LAYER:
            oled_write_P(PSTR("LAYER"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
            break;
    }
    oled_write_P(PSTR("/"), false);
    if (cocot_get_scroll_mode()){
        oled_write_P(PSTR("S"), false);
    } else{
        oled_write_P(PSTR("C"), false);
    }
    oled_write_P(PSTR("/"), false);
    oled_write(buf1, false);
    oled_write_P(PSTR("/"), false);
    oled_write(buf2, false);
    oled_write_P(PSTR("/"), false);
    oled_write_ln(buf3, false);
    oled_write_P(PSTR(QMK_VERSION "\n" QMK_BUILDDATE), false);
}

bool oled_task_user(void) {
    oled_write_layer_state_user();
    return false;
}
#endif

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  //debug_enable=true;
  //debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}
