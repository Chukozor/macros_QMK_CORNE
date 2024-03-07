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

#include QMK_KEYBOARD_H
#include "keymap.h"
#include "keymap_french.h"
#include "helpers.h"
#include "french_symbols.h"
#include "tap_dance.h"


// ------------- COMBO ---------------

const uint16_t PROGMEM temp_active_RGB[] = {HT_ENT, HT_SPC, COMBO_END};
// const uint16_t PROGMEM temp_active_RGB[] = {HT_ENT, HT_SPC, COMBO_END};
combo_t key_combos[] = {
    COMBO(temp_active_RGB, OSL(_RGB)),
};

// ------------- END COMBO ---------------

// -----------------------------------







// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &ko_make_with_layers(MOD_MASK_SHIFT, FR_COMM, FR_COLN, 1 << _COLEMAK_FR), // check if it works
    &ko_make_with_layers(MOD_MASK_SHIFT, FR_DOT,  FR_SCLN, 1 << _COLEMAK_FR),
    &ko_make_with_layers(MOD_MASK_SHIFT, FR_QUES, FR_EXLM, 1 << _COLEMAK_FR),
    &ko_make_with_layers(MOD_MASK_SHIFT, FR_QUOT, FR_DQUO, 1 << _COLEMAK_FR),
    &ko_make_with_layers(MOD_MASK_SHIFT, FR_COMM, FR_COLN, 1 << _CAPS_LOCK), // check if it works
    &ko_make_with_layers(MOD_MASK_SHIFT, FR_DOT,  FR_SCLN, 1 << _CAPS_LOCK),
    &ko_make_with_layers(MOD_MASK_SHIFT, FR_QUES, FR_EXLM, 1 << _CAPS_LOCK),
    &ko_make_with_layers(MOD_MASK_SHIFT, FR_QUOT, FR_DQUO, 1 << _CAPS_LOCK),
    &ko_make_with_layers(MOD_MASK_SHIFT, FR_COMM, FR_COLN, 1 << _SFT_COLEMAK_FR), // check if it works
    &ko_make_with_layers(MOD_MASK_SHIFT, FR_DOT,  FR_SCLN, 1 << _SFT_COLEMAK_FR),
    &ko_make_with_layers(MOD_MASK_SHIFT, FR_QUES, FR_EXLM, 1 << _SFT_COLEMAK_FR),
    &ko_make_with_layers(MOD_MASK_SHIFT, FR_QUOT, FR_DQUO, 1 << _SFT_COLEMAK_FR),
    // &ko_make_with_layers(MOD_MASK_SHIFT, FR_AT,   FR_AGRV, 1 << 2);
    
    NULL // Null terminate the array of overrides!
};



// -----------------------------------
#include "oled_display.h"
#include "process_record_user.h"
// -----------------------------------


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // _COLEMAK_FR
    [_COLEMAK_FR] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    FR_Q,    FR_W,    KC_F,     KC_P,   KC_G,                         KC_J,    KC_L,    HT_U,    KC_Y, FR_QUOT,  KC_TAB,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      MY_LCTL,    FR_A,    KC_R,    KC_S,    KC_T,    KC_D,                         KC_H,    KC_N,    HT_E,    HT_I,    KC_O, MY_LCTL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
 TD(CAPS_LCK),    FR_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_K,    FR_M, FR_COMM,  FR_DOT, FR_QUES, MY_LSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,  MY_NAV,  HT_SPC,     HT_ENT,  MO_SPE,  KC_LALT 
                                      //`--------------------------'  `--------------------------'

  ),
   // _ACCENTS_COLEMAK_FR
    [_ACCENTS] = LAYOUT_split_3x6_3(
  //,------------------------------------------------------.                    ,-----------------------------------------------------.
      _______,  XXXXXXX, MY_UNDO, MY_REDO,  MY_CUT,MY_PRT_P,                      XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, _______,
  //|--------+---------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,     HT_A, XXXXXXX, MY_SAVE, MY_COPY,MY_PRT_Z,                      KC_BSPC, XXXXXXX, _______, _______,MY_OCIRC, _______,
  //|--------+---------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_ENT,MY_COMENT, XXXXXXX, C_CEDIL,MY_PASTE,MY_PRT_S,                      XXXXXXX, XXXXXXX, FR_COLN, FR_SCLN, FR_EXLM, _______,
  //|--------+---------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______,  MO_SPE,   MO(_RGB), _______, _______
                                      //`--------------------------'  `--------------------------'

  ),
   // _SFT_LR_COLEMAK_FR
    [_SFT_COLEMAK_FR] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    FR_Q,    FR_W,    KC_F,     KC_P,   KC_G,                         KC_J,    KC_L,    KC_U,    KC_Y, FR_QUOT,  KC_TAB,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      MY_LCTL,    FR_A,    KC_R,    KC_S,    KC_T,    KC_D,                         KC_H,    KC_N,    KC_E,    KC_I,    KC_O, MY_LCTL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
 TD(CAPS_LCK),    FR_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_K,    FR_M, FR_COMM,  FR_DOT, FR_QUES, MY_LSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,  MY_NAV,  HT_SPC,     HT_ENT,  MO_SPE,  KC_LALT 
                                      //`--------------------------'  `--------------------------'
  ),
   // _CAPS_LOCK
    [_CAPS_LOCK] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.M
       KC_ESC, S(FR_Q), S(FR_W), S(KC_F), S(KC_P), S(KC_G),                      S(KC_J), S(KC_L), S(KC_U), S(KC_Y), FR_QUOT,  KC_TAB,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      MY_LCTL, S(FR_A), S(KC_R), S(KC_S), S(KC_T), S(KC_D),                      S(KC_H), S(KC_N), S(KC_E), S(KC_I), S(KC_O), MY_LCTL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
 TD(CAPS_LCK), S(FR_Z), S(KC_X), S(KC_C), S(KC_V), S(KC_B),                      S(KC_K), S(FR_M), FR_COMM,  FR_DOT, FR_QUES, MY_LSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,  MY_NAV,  HT_SPC,     HT_ENT,  MO_SPE,  KC_LALT 
                                      //`--------------------------'  `--------------------------'

  ),
   // _REG_SPE_FR
    [_REG_SPE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,---------------------------------------------------------.
      _______, MY_TILD, FR_LBRC, XXXXXXX, FR_RBRC,MY_DIESE,                      FR_PERC, FR_LCBR,   FR_UNDS, FR_RCBR,ALGR(KC_9), _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+----------+--------+----------+--------|
      _______,   FR_AT,  KC_EQL, KC_PMNS, KC_PPLS, MY_DOLL,                      FR_ASTR,MY_BQUOT,   FR_QUOT, FR_DQUO,   XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+----------+--------+----------+--------|
      _______, XXXXXXX, MY_PIPE, KC_PSLS, KC_PAST, MY_EURO,                      FR_AMPR, FR_LPRN,ALGR(KC_8), FR_RPRN,   XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+----------+--------+----------+--------|
                                          _______, _______,  MO_SPE,     MO_SPE, _______, _______
                                      //`--------------------------'  `--------------------------'

  ),

    // _GAMING for gaming
    [_GAMING] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      ESC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  ESC_TAB,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      MY_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, MY_LCTL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      MY_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, MY_LSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,  MY_NAV,  HT_SPC,     HT_ENT,  MO_SPE,  KC_RALT 
                                      //`--------------------------'  `--------------------------'

  ),

    [_NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, XXXXXXX, S(KC_7), S(KC_8), S(KC_9), KC_BSPC,                      XXXXXXX, KC_PGUP,   KC_UP, KC_PGDN, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, S(KC_0), S(KC_4), S(KC_5), S(KC_6),  FR_DOT,                      KC_BSPC, KC_LEFT, KC_DOWN,KC_RIGHT,  KC_DEL, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, S(KC_1), S(KC_2), S(KC_3),  KC_ENT,                      XXXXXXX, KC_HOME, XXXXXXX,  KC_END, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    KC_LCTL, MY_NAV, _______
                                      //`--------------------------'  `--------------------------'

  ),
    [_NOTHING_FOR_THE_MOMENT] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),
    [_SPE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX,  MO_RGB,    XXXXXXX, _______, XXXXXXX
                                      //`--------------------------'  `--------------------------'

  ),
    [_RGB] = LAYOUT_split_3x6_3(
  //,------------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX,MO_GAMING,   DT_UP,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+---------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, MO_COLFR,DT_DOWN,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+---------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD,  XXXXXXX, DT_PRNT,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+---------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX,  KC_SPC,    XXXXXXX, _______, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  )
};