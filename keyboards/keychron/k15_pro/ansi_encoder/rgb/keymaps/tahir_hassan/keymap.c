/* Copyright 2023 @ Keychron (https://www.keychron.com)
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

#include "k15_pro.h"
#include "action_layer.h"
#include "color.h"
#include "encoder.h"
#include "rgb_matrix.h"
#include "keycodes.h"
#include "process_auto_shift.h"
#include "process_tap_dance.h"

#include QMK_KEYBOARD_H

enum layers{
    WIN_BASE,
    WIN_FN,
    TAHIR_BASE,
    TAHIR_FN,
    TAHIR_UDLR
};

// Tap Dance declarations
enum {
    TD_LSFT_ESC,
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_LSFT_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_ESC),
};


#ifndef LAYOUT_90_ansi
#define LAYOUT_90_ansi(...) { __VA_ARGS__ }
#endif


#define __ 255

const uint8_t led_matrix[MATRIX_ROWS][MATRIX_COLS] =
    {
        // Key Matrix to LED Index
        { __,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14 },
        { 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30 },
        { 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46 },
        { 47, 48, 49, 50, 51, 52, 53, __, 54, 55, 56, 57, 58, 59, 60, 61 },
        { 62, 63, __, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, },
        { 77, 78, 79, __, 80, __, 81, 82, __, 83, 84, 85, __, 86, 87, 88 },
    };


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [WIN_BASE] = LAYOUT_90_ansi(
        KC_MUTE,    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_INS,             KC_DEL,
        MC_1,       KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
        MC_2,       KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
        MC_3,       KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_HOME,
        MC_4,       KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,
        MC_5,       KC_LCTL,  KC_LWIN,            KC_LALT,  KC_SPC,  MO(WIN_FN),           KC_SPC,             KC_RALT,            KC_RCTL,            KC_LEFT,  KC_DOWN,  KC_RGHT),

    [WIN_FN] = LAYOUT_90_ansi(
        RGB_TOG,    _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  RGB_VAD,   RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,   KC_VOLU,  _______,            RESET,
        _______,    _______,  BT_HST1,  BT_HST2,  BT_HST3,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,            _______,
        _______,    RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,   _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,            _______,
        _______,    KC_CAPS,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,   _______,  _______,  _______,  _______,  _______,  _______,             _______,            _______,
        _______,    _______,            _______,  _______,  _______,  _______,   BAT_LVL,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,   _______,  _______,  _______,
        _______,    _______,  _______,            _______,  _______,  _______,             _______,            _______,            _______,             _______,  _______,  _______),

    [TAHIR_BASE] = LAYOUT_90_ansi(
        KC_MUTE,   /*_*/     KC_ESC,          KC_F1,    KC_F2,    KC_F3,        KC_F4,       KC_F5,   /**/    KC_F6,      /*|*/      KC_F7,    KC_F8,     KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_INS,    MO(TAHIR_FN),
        MC_1,      /*_*/     KC_GRV,          KC_1,     KC_2,     KC_3,         KC_4,        KC_5,    /**/    KC_6,       /*|*/      KC_7,     KC_8,      KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,   KC_PGUP,
        MC_2,      /*_*/     KC_TAB,          KC_Q,     KC_W,     KC_E,         KC_R,        KC_T,    /*|*/   /**/        KC_Y,      KC_U,     KC_I,      KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,   KC_HOME,
        MC_3,      /*_*/     MO(TAHIR_UDLR),  KC_A,     KC_S,     KC_D,         KC_F,        KC_G,    /*|*/   /**/        KC_H,      KC_J,     KC_K,      KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,   /*_*/      KC_END,
        MC_4,      /*_*/     TD(TD_LSFT_ESC), KC_Z,     KC_X,     KC_C,         KC_V,        KC_B,    /*|*/   KC_B,       KC_N,      KC_M,     KC_COMMA,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,    /*_*/
        MC_5,      KC_LCTL,  KC_LWIN,         /*_*/     KC_LALT,  KC_BSPC,      /*>*/        KC_DEL,  /*|*/   KC_SPACE,   /*>*/      KC_RALT,  KC_RCTL,   /*_*/     /*_*/     KC_LEFT,  KC_DOWN,   KC_RGHT ),

// if you hold down shift while pressing FN+RGB_MODE it goes in reverse order.
    [TAHIR_FN] = LAYOUT_90_ansi(
        RGB_TOG,  /*_*/      KC_TRNS,         KC_NO,    KC_NO,    KC_NO,        KC_NO,       KC_NO,   /**/    KC_NO,      /*|*/      KC_MPRV,  KC_MPLY,   KC_MNXT,  KC_NO,    KC_NO,    KC_NO,    KC_TRNS,   KC_NO,
        KC_TRNS,  /*_*/      KC_TRNS,         BT_HST1,  BT_HST2,  BT_HST3,      KC_TRNS,     KC_TRNS, /**/    KC_TRNS,    /*|*/      KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,
        KC_TRNS,  /*_*/      KC_NO,           RGB_MOD,  RGB_HUI,  RGB_SAI,      RGB_SPI,     KC_NO,   /*|*/   /**/        KC_TRNS,   KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_PSCR,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,
        KC_TRNS,  /*_*/      KC_CAPS,         KC_NO,    KC_NO,    KC_NO,        KC_NO,       KC_NO,   /*|*/   /**/        KC_TRNS,   KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  /*_*/      KC_TRNS,
        KC_TRNS,  /*_*/      KC_TRNS,         KC_TRNS,  KC_TRNS,  KC_TRNS,      KC_TRNS,     KC_NO,   /*|*/   BAT_LVL,    NK_TOGG,   KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  /*_*/
        KC_TRNS,  KC_TRNS,   KC_TRNS,         /*_*/     KC_TRNS,  KC_TRNS,      /*>*/        KC_TRNS, /*|*/   KC_TRNS,    /*>*/      KC_TRNS,  KC_TRNS,   /*_*/     /*_*/     KC_TRNS,  KC_TRNS,  KC_TRNS),

    [TAHIR_UDLR] = LAYOUT_90_ansi(
        KC_NO,    /*_*/      KC_NO,           KC_NO,    KC_NO,    KC_NO,         KC_NO,      KC_NO,   /**/    KC_NO,      /*|*/      KC_NO,    KC_NO,     KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,     KC_NO,
        MC_1,     /*_*/      KC_NO,           KC_NO,    KC_NO,    KC_NO,         KC_NO,      KC_NO,   /**/    KC_NO,      /*|*/      KC_NO,    KC_NO,     KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,     KC_NO,
        MC_2,     /*_*/      KC_NO,           KC_NO,    KC_NO,    KC_NO,         KC_NO,      KC_NO,   /*|*/   /**/        KC_NO,     KC_NO,    KC_NO,     KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,     KC_NO,
        MC_3,     /*_*/      KC_NO,           KC_NO,    KC_NO,    KC_NO,         KC_NO,      KC_NO,   /*|*/   /**/        KC_LEFT,   KC_DOWN,  KC_UP,     KC_RIGHT, KC_NO,    KC_NO,    KC_NO,    /*_*/      KC_NO,
        MC_4,     /*_*/      KC_LSFT,         KC_NO,    KC_NO,    KC_NO,         KC_NO,      KC_NO,   /*|*/   KC_NO,      KC_NO,     KC_NO,    KC_HOME,   KC_END,   KC_NO,    KC_RSFT,  KC_UP,    /*_*/
        MC_5,     KC_LCTL,   KC_LWIN,         /*_*/     KC_LALT,  KC_BACKSPACE,  /*>*/       KC_NO,   /*|*/   KC_SPC,     /*>*/      KC_RALT,  KC_RCTL,   /*_*/     /*_*/     KC_LEFT,  KC_DOWN,  KC_RGHT),
};

#if defined(ENCODER_MAP_ENABLE)

// NOLINTNEXTLINE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [WIN_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [WIN_FN]   = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [TAHIR_BASE]   = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [TAHIR_FN]   = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [TAHIR_UDLR]   = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
};
#endif // ENCODER_MAP_ENABLE

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (layer_state_is(TAHIR_UDLR)) {
        int start = led_matrix[3][8];
        int end = led_matrix[3][11];
        for (int i = start; i <= end; ++i) {
            rgb_matrix_set_color(i, RGB_WHITE);
        }
        rgb_matrix_set_color(72, RGB_WHITE); // KC_COMMA
        rgb_matrix_set_color(73, RGB_WHITE); // KC_DOT
    }

    return false;
}

uint16_t get_autoshift_timeout(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case KC_COMM:
        case KC_DOT:
            return get_generic_autoshift_timeout() + 75;
        default:
            return get_generic_autoshift_timeout();

    }
}
