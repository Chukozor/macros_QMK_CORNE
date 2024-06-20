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

#include "print.h"
#include QMK_KEYBOARD_H
#include "keymap.h"
#include "keymap_french.h"
#include "custom_files/helpers.h"
#include "custom_files/french_symbols/french_symbols.h"
#include "custom_files/tap_dances/tap_dance.h"


// ------------- COMBO ---------------
enum combos {
  COMBO_MULTIMEDIAB,
  COMBO_MULTIMEDIA,
  COMBO_OSL_SHIFT,
  COMBO_BOOT
  // COMBO_E_AIGU
};

// const uint16_t PROGMEM temp_active_RGB[] = {MY_ENT, HT_SPC, COMBO_END};
const uint16_t PROGMEM temp_active_MULTIMEDIA[] = {KC_LGUI, MY_NAV, HT_SPC, COMBO_END};
const uint16_t PROGMEM temp_active_MULTIMEDIAB[] = {KC_LGUI, MY_BNAV, HT_SPC, COMBO_END};
const uint16_t PROGMEM temp_active_SHIFT[] = {CSTM_ENT, HT_SPC, COMBO_END};
const uint16_t PROGMEM temp_active_boot[] = {MY_NAV,HT_SPC,KC_LGUI,KC_LALT,CSTM_ENT,MO(_RIEN), COMBO_END};
// const uint16_t PROGMEM temp_active_e_aigu[] = {HT_SPC, HT_E, COMBO_END};
// const uint16_t PROGMEM bis_temp_active_RGB[] = {HT_ENT, HT_SPC, COMBO_END};
// const uint16_t PROGMEM bis_x_temp_active_RGB[] = {CSTM_ENT, HT_SPC, COMBO_END};
// const uint16_t PROGMEM temp_active_RGB[] = {HT_ENT, HT_SPC, COMBO_END};
combo_t key_combos[] = {
    // [COMBO_OSL_RGB]=COMBO(temp_active_RGB, OSL(_RGB)),
    [COMBO_MULTIMEDIAB]=COMBO(temp_active_MULTIMEDIA, MO(_MULTIMEDIA)),
    [COMBO_MULTIMEDIA]=COMBO(temp_active_MULTIMEDIAB, MO(_MULTIMEDIA)),
    // COMBO(temp_active_SHIFT, COMBO_SHIFT), 
    // COMBO(temp_active_SHIFT, CUSTOM_OSL_WITH_MOD),
    [COMBO_OSL_SHIFT]=COMBO(temp_active_SHIFT, OSL(_OSL_SHIFT)),
    [COMBO_BOOT]=COMBO(temp_active_boot, QK_BOOT),
    // [COMBO_E_AIGU]=COMBO(temp_active_e_aigu, E_AIGU),
//     COMBO(bis_temp_active_RGB, OSL(_RGB)),
//     COMBO(bis_x_temp_active_RGB, OSL(_RGB)),
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
#include "process_record_user.h"
// -----------------------------------

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // _COLEMAK_FR
    [_COLEMAK_FR] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       MY_ESC,    FR_Q,    FR_W,    KC_F,    KC_P,    KC_G,                         KC_J,    KC_L,    KC_U,    KC_Y, XXXXXXX,  KC_TAB,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      MY_LCTL,    FR_A,    KC_R,    KC_S,    KC_T,    KC_D,                         KC_H,    KC_N,    HT_E,    KC_I,    KC_O, MY_LCTL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      MY_LSFT,    FR_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_K,    FR_M, FR_COMM,  FR_DOT, FR_QUES, MY_LSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          MY_NAV,  HT_SPC, KC_LGUI,     KC_LALT,CSTM_ENT, MO(_RIEN)
                                      //`--------------------------'  `--------------------------'
  ),
  //   // _GAMING for gaming
  //   [_GAMING] = LAYOUT_split_3x6_3(
  // //,-----------------------------------------------------.                    ,-----------------------------------------------------.
  //      MY_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,   KC_TAB,
  // //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //     MY_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, MY_LCTL,
  // //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //     MY_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, MY_LSFT,
  // //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
  //                                          MY_NAV,  HT_SPC, KC_LGUI,    KC_LALT,CSTM_ENT, XXXXXXX 
  //                                     //`--------------------------'  `--------------------------'
  // ),
  //   [_LATEX] = LAYOUT_split_3x6_3(
  // //,-----------------------------------------------------.                    ,-----------------------------------------------------.
  //      MY_ESC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
  //                                         MY_NAV,  XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
  //                                     //`--------------------------'  `--------------------------'
  // ),
   // _SFT_LR_COLEMAK_FR
    [_SFT_COLEMAK_FR] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       MY_ESC,    FR_Q,    FR_W,    KC_F,    KC_P,    KC_G,                         KC_J,    KC_L,    KC_U,    KC_Y, XXXXXXX,  KC_TAB,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      MY_LCTL,    FR_A,    KC_R,    KC_S,    KC_T,    KC_D,                         KC_H,    KC_N,    KC_E,    KC_I,    KC_O, MY_LCTL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      MY_LSFT,    FR_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_K,    FR_M, FR_COMM,  FR_DOT, FR_QUES, MY_LSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           MY_NAV,  HT_SPC, KC_LGUI,    KC_LALT,CSTM_ENT, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),
   // _CAPS_LOCK
    [_CAPS_LOCK] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       MY_ESC, S(FR_Q), S(FR_W), S(KC_F), S(KC_P), S(KC_G),                      S(KC_J), S(KC_L), S(KC_U), S(KC_Y), XXXXXXX,  KC_TAB,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      MY_LCTL, S(FR_A), S(KC_R), S(KC_S), S(KC_T), S(KC_D),                      S(KC_H), S(KC_N), S(KC_E), S(KC_I), S(KC_O), MY_LCTL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      MY_LSFT, S(FR_Z), S(KC_X), S(KC_C), S(KC_V), S(KC_B),                      S(KC_K), S(FR_M), FR_COMM,  FR_DOT, FR_QUES, MY_LSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           MY_NAV,  HT_SPC, KC_LGUI,    KC_LALT,CSTM_ENT, XXXXXXX 
                                      //`--------------------------'  `--------------------------'
  ),
   // _CAPS_LOCK
    [_OSL_SHIFT] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       MY_ESC, S(FR_Q), S(FR_W), S(KC_F), S(KC_P), S(KC_G),                      S(KC_J), S(KC_L), S(KC_U), S(KC_Y), FR_QUOT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, S(FR_A), S(KC_R), S(KC_S), S(KC_T), S(KC_D),                      S(KC_H), S(KC_N), S(KC_E), S(KC_I), S(KC_O), XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, S(FR_Z), S(KC_X), S(KC_C), S(KC_V), S(KC_B),                      S(KC_K), S(FR_M), FR_COLN, FR_SCLN, FR_EXLM, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX 
                                      //`--------------------------'  `--------------------------'
  ),
  //   [_F_KEYS] = LAYOUT_split_3x6_3(
  // //,-----------------------------------------------------.                    ,-----------------------------------------------------.
  //      MY_ESC, XXXXXXX,   KC_F7,   KC_F8,   KC_F9,  KC_F12,                      XXXXXXX, KC_PGUP,   KC_UP, KC_PGDN, XXXXXXX, XXXXXXX,
  // //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //     MY_LCTL, XXXXXXX,   KC_F4,   KC_F5,   KC_F6,  KC_F11,                      KC_BSPC, KC_LEFT, KC_DOWN,KC_RIGHT,  KC_DEL, MY_LCTL,
  // //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //     MY_LSFT, XXXXXXX,   KC_F1,   KC_F2,   KC_F3,  KC_F10,                      XXXXXXX, KC_HOME, XXXXXXX,  KC_END, XXXXXXX, XXXXXXX,
  // //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
  //                                          MY_NAV, XXXXXXX, XXXXXXX,    KC_LALT, KC_LCTL, XXXXXXX
  //                                     //`--------------------------'  `--------------------------'
  // ),
  //   [_WEB_BROWSER] = LAYOUT_split_3x6_3(
  // //,-------------------------------------------------------------.                    ,-----------------------------------------------------.
  //      MY_ESC,    XXXXXXX, RCS(KC_T), WEB_TAB,   C(KC_T),RCS(KC_P),                        TEST1,   TEST2,   TEST3,   TEST4,   TEST5, XXXXXXX,
  // //|--------+-----------+----------+--------+----------+ --------|                    |--------+--------+--------+--------+--------+--------|
  //     MY_LCTL,    XXXXXXX,     WEB_G, KC_LALT,     WEB_D,  C(KC_N),                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MY_LCTL,
  // //|--------+-----------+----------+--------+----------+---------|                    |--------+--------+--------+--------+--------+--------|
  //     KC_LSFT,  RCS(KC_N),  A(KC_F4), C(KC_D), RCS(KC_O),  XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // //|--------+-----------+----------+--------+----------+---------+--------|  |--------+--------+--------+--------+--------+--------+--------|
  //                                                 MY_NAV,   HT_SPC, KC_LGUI,    KC_LALT,CSTM_ENT, XXXXXXX 
  //                                         //`----------- ------------------'  `--------------------------'
  // ),
  //   [_NOTHING_FOR_THE_MOMENT] = LAYOUT_split_3x6_3(
  // //,-----------------------------------------------------.                    ,-----------------------------------------------------.
  //     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
  //                                         XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
  //                                     //`--------------------------'  `--------------------------'
  // ),
    [_NAV] = LAYOUT_split_3x6_3(
  //,--------------------------------------------------------.                    ,-----------------------------------------------------.
       MY_ESC,    XXXXXXX,   KC_P7,   KC_P8,   KC_P9, KC_BSPC,                      XXXXXXX, KC_PGUP,   KC_UP, KC_PGDN, XXXXXXX, XXXXXXX,
  //|--------+-----------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      MY_LCTL,      KC_P0,   KC_P4,   KC_P5,   KC_P6, KC_PDOT,                      KC_BSPC, KC_LEFT, KC_DOWN,KC_RIGHT,  KC_DEL, MY_LCTL,
  //|--------+-  --------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    XXXXXXX,   KC_P1,   KC_P2,   KC_P3,  KC_ENT,                      XXXXXXX, KC_HOME, XXXXXXX,  KC_END, XXXXXXX, XXXXXXX,
  //|--------+-----------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                             _______, _______, _______,    KC_LALT, KC_LCTL,  MY_NAV
                                      //`-----------------------------'  `--------------------------'
  ),
    [_OP_NAV] = LAYOUT_split_3x6_3(
  //,------------------------------------------------------------.                    ,-----------------------------------------------------.
       MY_ESC,    XXXXXXX, KC_NUBS,S(KC_NUBS),   XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+-----------+--------+----------+----------+--------|                    |--------+--------+--------+--------+--------+--------|
      MY_LCTL,    XXXXXXX, KC_PMNS,    KC_EQL,   KC_PPLS, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+-  --------+--------+----------+----------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    XXXXXXX, KC_PSLS,   XXXXXXX,   KC_PAST, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+-----------+--------+----------+----------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                             XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,  XXXXXXX, XXXXXXX
                                      //`-----------------------------'  `--------------------------'
  ),
    [_ACCENTS] = LAYOUT_split_3x6_3(
  //,------------------------------------------------------.                    ,-----------------------------------------------------.
       MY_ESC, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX,    HT_U, XXXXXXX, XXXXXXX,  KC_TAB,
  //|--------+---------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      MY_LCTL,     HT_A, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX,                      KC_BSPC, XXXXXXX,     HT_E,    HT_I,MY_OCIRC, MY_LCTL,
  //|--------+---------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      MY_LSFT,  XXXXXXX, XXXXXXX, C_CEDIL, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, FR_COLN, FR_SCLN, FR_EXLM, MY_LSFT,
  //|--------+---------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           MY_NAV,   HT_SPC, KC_LGUI,    KC_LALT,CSTM_ENT, XXXXXXX 
                                       //`--------------------------'  `--------------------------'
  ),
    [_REG_SPE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,---------------------------------------------------------.
       MY_ESC, MY_TILD, FR_LBRC, XXXXXXX, FR_RBRC,MY_DIESE,                      FR_PERC, FR_LCBR,   FR_UNDS, FR_RCBR,ALGR(KC_9),  KC_TAB,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+----------+--------+----------+--------|
      MY_LCTL,   FR_AT, KC_PMNS,  KC_EQL, KC_PPLS, MY_DOLL,                      FR_ASTR, XXXXXXX,   FR_QUOT, FR_DQUO,   XXXXXXX, MY_LCTL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+----------+--------+----------+--------|
      _______, XXXXXXX, KC_PSLS, MY_PIPE, KC_PAST, MY_EURO,                      FR_AMPR, FR_LPRN,ALGR(KC_8), FR_RPRN,   XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+----------+--------+----------+--------|
                                          _______, _______, _______,   _______, CSTM_ENT, _______
                                      //`--------------------------'  `--------------------------'
  ),
    [_MULTIMEDIA] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MSTP, KC_MPRV, KC_VOLD, KC_MNXT, KC_MUTE, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, KC_MPLY, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),
    [_RGB] = LAYOUT_split_3x6_3(
  //,------------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,   DT_UP,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+---------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI,  XXXXXXX, DT_DOWN,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+---------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD,  XXXXXXX, DT_PRNT,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+---------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX,  XXXXXXX,    XXXXXXX, XXXXXXX, _______
                                      //`---------------------------'  `--------------------------'
  ),
    [_RIEN] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  )
};


  //   [_SPE] = LAYOUT_split_3x6_3(
  // //,-----------------------------------------------------.                    ,-----------------------------------------------------.
  //      MY_ESC, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  // //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //     KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
  // //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //     KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
  // //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
  //                                         XXXXXXX, XXXXXXX,  MO_RGB,    XXXXXXX, _______, XXXXXXX
  //                                     //`--------------------------'  `--------------------------'

  // ),

void render_layer_status(void) {
  switch (get_highest_layer(layer_state)){
    case _COLEMAK_FR :
      // -------|"-----00000-----00000-----00000-----00000-----"
      //         "                                             "
      oled_write("COLE-  MAK       FR                           ", false);
      break;
    // case _GAMING :
    //   // -------|"-----00000-----00000-----00000-----00000-----"
    //   //         "                                             "
    //   oled_write(" GAME                                        ", false);
    //   break;
    // case _LATEX :
    //   // -------|"-----00000-----00000-----00000-----00000-----"
    //   //         "                                             "
    //   oled_write("LATEX                                        ", false);
    //   break;
    case _SFT_COLEMAK_FR :
      // -------|"-----00000-----00000-----00000-----00000-----"
      //         "                                             "
      oled_write(" MAJ                                         ", false);
      break;
    case _CAPS_LOCK :
      // -------|"-----00000-----00000-----00000-----00000-----"
      //         "                                             "
      oled_write(" VERR MAJ                                    ", false);
      break;
    case _OSL_SHIFT :
      // -------|"-----00000-----00000-----00000-----00000-----"
      //         "                                             "
      oled_write(" Uni- que  MAJ                               ", false);
      break;
    // case _F_KEYS :
    //   // -------|"-----00000-----00000-----00000-----00000-----"
    //   //         "                                             "
    //   oled_write("  F_  KEYS                                   ", false);
    //   break;
    // case _WEB_BROWSER :
    //   // -------|"-----00000-----00000-----00000-----00000-----"
    //   //         "                                             "
    //   oled_write(" WEB_                                        ", false);
    //   break;
    // case _NOTHING_FOR_THE_MOMENT :
    //   // -------|"-----00000-----00000-----00000-----00000-----"
    //   //         "                                             "
    //   oled_write("RIEN  ATM                                    ", false);
    //   break;
    case _NAV :
      // -------|"-----00000-----00000-----00000-----00000-----"
      //         "                                             "
      oled_write("  NAV                                        ", false);
      break;
    case _OP_NAV :
      // -------|"-----00000-----00000-----00000-----00000-----"
      //         "                                             "
      oled_write("OPERA TEUR                                   ", false);
      break;
    case _ACCENTS :
      // -------|"-----00000-----00000-----00000-----00000-----"
      //         "                                             "
      oled_write("ACCE-  NTS                                   ", false);
      break;
    case _REG_SPE :
      // -------|"-----00000-----00000-----00000-----00000-----"
      //         "                                             "
      oled_write("CARACTERES     SPEC- IAUX                    ", false);
      break;
    case _MULTIMEDIA :
      // -------|"-----00000-----00000-----00000-----00000-----"
      //         "                                             "
      oled_write("MULTIMEDIA                                   ", false);
      break;
    case _RGB :
      // -------|"-----00000-----00000-----00000-----00000-----"
      //         "                                             "
      oled_write(" RGB                                         ", false);
      break;
    case _RIEN :
      // -------|"-----00000-----00000-----00000-----00000-----"
      //         "                                             "
      oled_write(" RIEN                                        ", false);
      break;
  }
}

void render_logo(void) {
  static const char PROGMEM logo[] = {
    // 'cornia', 32x32px
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 
    0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xe0, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xf8, 0xff, 0xff, 0xff, 0x3f, 0xff, 0xff, 0xff, 0xfd, 0xe1, 
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 
    0x00, 0x00, 0xc0, 0xf8, 0xff, 0xff, 0xff, 0x3f, 0x07, 0x00, 0x00, 0x00, 0x07, 0x3f, 0xff, 0xff, 
    0xff, 0xf8, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x1e, 0x1f, 0x1f, 0x1f, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 
    0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x0e, 0x00
  };
  oled_write_raw_P(logo, sizeof(logo));
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_270; }

// Draw to OLED
bool oled_task_user() {
  oled_set_cursor(0, 0);
  render_logo();
  oled_set_cursor(0, 7);
  render_layer_status();
  return false;
}

void oled_render_boot(bool bootloader) {
  oled_clear();
  oled_set_cursor(0, 2);
  if (bootloader) {
    oled_write_P(PSTR("FLASH"), false);
  } else {
    oled_write_P(PSTR("RESET"), false);
  }
  oled_render_dirty(true);
}

bool shutdown_user(bool jump_to_bootloader) {
  oled_render_boot(jump_to_bootloader);
  return false;
}