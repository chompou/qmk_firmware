/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

/*
    Thank you @Zower for showing me colemak
    Thank you @HellSingCoder for showing me how to adopt Luna and for more inspiration!
*/

#include QMK_KEYBOARD_H

// Norwegian keys
#include "keymap_norwegian.h"

enum crkbd_layers {
    _QWERTY,
    _COLEMAK,
    _NUMS,
    _SYMBOLS,
    _FUNCS
};

enum my_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_COLEMAK,
    KC_NUMS,
    KC_SYMBOLS,
    KC_FUNCS
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_ESC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LCTL,   KC_NUMS,  KC_SPC,     KC_LGUI,   KC_SYMBOLS, KC_LALT
                                      //`--------------------------'  `--------------------------'

  ),

    [_COLEMAK] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TAB,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y,   KC_SCLN,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_ESC,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                         KC_M,    KC_N,    KC_E,    KC_I, KC_O, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_X,    KC_C,    KC_D,    KC_V,    KC_Z,                       KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LCTL, KC_NUMS,  KC_SPC,     KC_LGUI,   KC_SYMBOLS, KC_LALT
                                      //`--------------------------'  `--------------------------'

  ),

    [_NUMS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TAB, XXXXXXX,  KC_UP,  XXXXXXX,  XXXXXXX, XXXXXXX,                     XXXXXXX,  KC_7,    KC_8,    KC_9,  KC_DEL,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_ESC, KC_LEFT, XXXXXXX, KC_RIGHT, XXXXXXX, KC_CAPS,                      XXXXXXX,  KC_4,    KC_5,    KC_6,  XXXXXXX, KC_LBRC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, KC_DOWN, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_0,  KC_1,    KC_2,    KC_3,  XXXXXXX, KC_ENT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LCTL, _______, KC_SPC,     KC_LCTL,  KC_FUNCS, KC_LALT
                                      //`--------------------------'  `--------------------------'
  ),

    [_SYMBOLS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.'
       KC_TAB, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      NO_GRV, NO_QUOT, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      NO_AMPR, NO_AT, NO_PND, NO_SLSH, NO_LCBR, NO_LBRC,                        NO_RBRC,  NO_RCBR, KC_EQL, KC_SLSH,  NO_PLUS, NO_PIPE,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      NO_CIRC, NO_DLR, NO_ASTR, NO_TILD, XXXXXXX, XXXXXXX,                      NO_QUES, NO_LABK, NO_RABK, NO_UNDS, NO_EQL, KC_ENT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         KC_LCTL, KC_FUNCS, KC_SPC,     KC_LGUI, _______, KC_LALT
                                      //`--------------------------'  `--------------------------'
  ),

    [_FUNCS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TAB, QK_BOOT, XXXXXXX, XXXXXXX, DF(_COLEMAK), DF(_QWERTY),                   KC_F13,   KC_F14,  KC_F15, KC_F16,  KC_F17,  KC_F18,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_ESC, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      KC_F7,    KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      KC_F1,    KC_F2,   KC_F3,  KC_F4,   KC_F5,   KC_F6,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LCTL, _______,  KC_SPC,     KC_LGUI, _______, KC_LALT
                                      //`--------------------------'  `--------------------------'
  )

};
