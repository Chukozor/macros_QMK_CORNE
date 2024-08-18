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
#include "custom_files/french_symbols/shift_behaviours.c"
// -----------------------------------
bool game_mode = 0;
bool test_game_mode(void){
 return game_mode;
}

void toggle_game_mode(bool value){
 game_mode = value;
}
// -----------------------------------
#include "custom_files/tap_dances/tap_dance.h"


// ------------- COMBO ---------------
enum combos {
  COMBO_MULTIMEDIA,
  COMBO_OSM_SHIFT,
  COMBO_BOOT,
  // TOGGLE_GAMING,
  TOGGLE_GAME,
  TOGGLE_GAME2,
  FAST_SWITCH_GAME_COLEMAK_COMBO,
  FAST_SWITCH_GAME_COLEMAK_COMBO2,
  TOGGLE_WEB,
  TOGGLE_RGB,
  COMBO_CLEAR_EEPROM,
  COMBO_ESPACE,
  COMBO_ESPACE2
  // COMBO_E_AIGU
};

// const uint16_t PROGMEM temp_active_RGB[] = {MY_ENT, HT_SPC, COMBO_END};
const uint16_t PROGMEM temp_active_MULTIMEDIA[] = {KC_LGUI, MY_NAV, HT_SPC, COMBO_END};
const uint16_t PROGMEM temp_active_SHIFT[] = {CSTM_ENT, HT_SPC, COMBO_END};
const uint16_t PROGMEM temp_active_boot[] = {MY_NAV,HT_SPC,KC_LGUI,KC_LALT,CSTM_ENT,TG(_NAV_LEFT), COMBO_END};
// const uint16_t PROGMEM toggle_gaming[] = {FR_Q,FR_W,KC_F,KC_P,KC_G, COMBO_END};
const uint16_t PROGMEM toggle_game[] = {FR_A,KC_R,KC_S,KC_T,KC_D, COMBO_END};
const uint16_t PROGMEM toggle_game2[] = {KC_LSFT,FR_A,FR_W,KC_D,KC_T, COMBO_END};
const uint16_t PROGMEM fast_switch_game_colemak_combo[] = {MY_LCTL,MY_LSFT, COMBO_END};
const uint16_t PROGMEM fast_switch_game_colemak_combo2[] = {KC_TAB, KC_LCTL, COMBO_END};
// const uint16_t PROGMEM combo_toggle_web[] = {KC_LGUI,MY_NAV, COMBO_END};
const uint16_t PROGMEM toggle_RGB[] = {KC_LALT,CSTM_ENT,TG(_NAV_LEFT), COMBO_END};
const uint16_t PROGMEM combo_clear_eeprom[] = {RGB_TOG, ____MOD, _I_COUL, __I_LUM, __I_SAT, COMBO_END};
const uint16_t PROGMEM combo_espace[] = {KC_N, HT_E, COMBO_END};
const uint16_t PROGMEM combo_espace2[] = {S(KC_N), S(KC_E), COMBO_END};
// const uint16_t PROGMEM toggle_gaming_2[] = {FR_Q, KC_R, KC_C, KC_F, KC_T, COMBO_END};
// const uint16_t PROGMEM temp_active_e_aigu[] = {HT_SPC, HT_E, COMBO_END};
// const uint16_t PROGMEM bis_temp_active_RGB[] = {HT_ENT, HT_SPC, COMBO_END};
// const uint16_t PROGMEM bis_x_temp_active_RGB[] = {CSTM_ENT, HT_SPC, COMBO_END};
// const uint16_t PROGMEM temp_active_RGB[] = {HT_ENT, HT_SPC, COMBO_END};
combo_t key_combos[] = {
    [COMBO_MULTIMEDIA]=COMBO(temp_active_MULTIMEDIA, MO(_MULTIMEDIA)),
    // [TOGGLE_GAMING]=COMBO(toggle_gaming, TG(_AUX_GAME)),
    [TOGGLE_GAME]=COMBO(toggle_game, TG_GAME),
    [TOGGLE_GAME2]=COMBO(toggle_game2, TG_GAME),
    [COMBO_OSM_SHIFT]=COMBO(temp_active_SHIFT, OSM(MOD_LSFT)),
    [COMBO_BOOT]=COMBO(temp_active_boot, QK_BOOT),
    [COMBO_BOOT]=COMBO(temp_active_boot, QK_BOOT),
    [FAST_SWITCH_GAME_COLEMAK_COMBO]=COMBO(fast_switch_game_colemak_combo, FAST_SWITCH_GAME_COLEMAK),
    [FAST_SWITCH_GAME_COLEMAK_COMBO2]=COMBO(fast_switch_game_colemak_combo2, FAST_SWITCH_GAME_COLEMAK),
    // [TOGGLE_WEB]=COMBO(combo_toggle_web, TG(_WEB_BROWSER)),
    [TOGGLE_RGB]=COMBO(toggle_RGB, TG(_RGB)),
    [COMBO_CLEAR_EEPROM]=COMBO(combo_clear_eeprom, QK_CLEAR_EEPROM),
    [COMBO_ESPACE]=COMBO(combo_espace, KC_SPC),
    [COMBO_ESPACE2]=COMBO(combo_espace2, KC_SPC),
    // [COMBO_OSL_RGB]=COMBO(temp_active_RGB, OSL(_RGB)),
    // [TOGGLE_GAMING_2]=COMBO(toggle_gaming_2, TG(_GAMING)),
    // COMBO(temp_active_SHIFT, COMBO_SHIFT), 
    // COMBO(temp_active_SHIFT, CUSTOM_OSL_WITH_MOD),
    // [COMBO_E_AIGU]=COMBO(temp_active_e_aigu, E_AIGU),
//     COMBO(bis_temp_active_RGB, OSL(_RGB)),
//     COMBO(bis_x_temp_active_RGB, OSL(_RGB)),
};

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    /* Disable combo `SOME_COMBO` on layer `_LAYER_A` */
    switch (combo_index) {
        // case SOME_COMBO:
        //   if (layer_state_is(_LAYER_A)) {
        //     return false;
        //   }
        case COMBO_ESPACE2 - FAST_SWITCH_GAME_COLEMAK_COMBO:
          if (layer_state_is(_GAME)) {
            return false;
          }
        case TOGGLE_GAME:
          if (layer_state_is(_GAME)) {
            return true;
          }
        default:
          if (layer_state_is(_GAME)) {
            return false;
          }
    }

    return true;
}

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
    // &ko_make_with_layers(MOD_MASK_SHIFT, FR_COMM, FR_COLN, 1 << _SFT_COLEMAK_FR), // check if it works
    // &ko_make_with_layers(MOD_MASK_SHIFT, FR_DOT,  FR_SCLN, 1 << _SFT_COLEMAK_FR),
    // &ko_make_with_layers(MOD_MASK_SHIFT, FR_QUES, FR_EXLM, 1 << _SFT_COLEMAK_FR),
    // &ko_make_with_layers(MOD_MASK_SHIFT, FR_QUOT, FR_DQUO, 1 << _SFT_COLEMAK_FR),
    // &ko_make_with_layers(MOD_MASK_SHIFT, FR_AT,   FR_AGRV, 1 << 2);
    
    NULL // Null terminate the array of overrides!
};

// -----------------------------------
// -----------------------------------
#include "process_record_user.h"
// -----------------------------------

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // _COLEMAK_FR
    [_COLEMAK_FR] = CHOCO_MAX(
  //,-----------------------------------------------------.                      ,-----------------------------------------------------.
       MY_ESC,    FR_Q,    FR_W,    KC_F,    KC_P,    KC_G,                           KC_J,    KC_L,    KC_U,    KC_Y, FR_QUOT,  KC_TAB,
  //|--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
      MY_LCTL,    FR_A,    KC_R,    KC_S,    KC_T,    KC_D,                           KC_H,    KC_N,    HT_E,    KC_I,    KC_O, MY_LCTL,
  //|--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
      MY_LSFT,    FR_Z,    KC_X,    KC_C,    KC_V,    KC_B,                           KC_K,    FR_M, FR_COMM,  FR_DOT, FR_QUES, MY_LSFT,
  //|--------------------------------------------------------------|     |-------------------------------------------------------------|
                        HT_E, KC_LALT, KC_LGUI,  MY_NAV,  HT_SPC,      KC_LALT,CSTM_ENT, TG(_NAV_LEFT), HT_E, KC_LALT
                     //`-------------------------------------------'     `-------------------------------------------'
  ),
    // OTHER_GAMING for gaming
    [_GAME] = CHOCO_MAX(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       MY_ESC,    FR_Q,    FR_W,    KC_F,    KC_P,    KC_G,                         KC_J,    KC_L,    KC_U,    KC_Y, FR_QUOT,  KC_TAB,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    FR_A,    KC_R,    KC_S,    KC_T,    KC_D,                         KC_H,    KC_N,    KC_E,    KC_I,    KC_O, KC_LCTL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TAB,     FR_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_K,    FR_M, FR_COMM,  FR_DOT, FR_QUES, KC_LSFT,
  //|--------------------------------------------------------------|   |-------------------------------------------------------------|
                        XXXXXXX, XXXXXXX, MO_OX_G,    KC_I,  KC_SPC,    KC_LALT,  KC_ENT, XXXXXXX, XXXXXXX, XXXXXXX
                     //`-------------------------------------------'   `-------------------------------------------'
  ),
    // _AUX_GAME for gaming
    [_AUX_GAME] = CHOCO_MAX(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       MY_ESC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, KC_ACL0, KC_ACL1, KC_ACL2, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX,   KC_F1,   KC_F2,   KC_F3, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------------------------------------------------------------|   |-------------------------------------------------------------|
                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
                     //`-------------------------------------------'   `-------------------------------------------'
  ),
  //   // QWERTY
  //   [_QWERTY] = CHOCO_MAX(
  // //,-----------------------------------------------------.                    ,-----------------------------------------------------.
  //      MY_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,   KC_TAB,
  // //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //     KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_LCTL,
  // //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //     KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_LSFT,
  // //|--------------------------------------------------------------|  |--------------------------------------------------------------|
  //                       XXXXXXX, XXXXXXX, KC_LGUI,MO(_NAV),  KC_SPC,    KC_LALT,  KC_ENT, XXXXXXX, XXXXXXX, XXXXXXX
                        //`-------------------------------------------'   `-------------------------------------------'
  // ),
    [_LATEX] = CHOCO_MAX(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       MY_ESC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------------------------------------------------------------|   |-------------------------------------------------------------|
                        XXXXXXX, XXXXXXX, XXXXXXX,  MY_NAV, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
                     //`-------------------------------------------'   `-------------------------------------------'
  ),
   // _CAPS_LOCK
    [_CAPS_LOCK] = CHOCO_MAX(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       MY_ESC, S(FR_Q), S(FR_W), S(KC_F), S(KC_P), S(KC_G),                      S(KC_J), S(KC_L), S(KC_U), S(KC_Y), FR_QUOT,  KC_TAB,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      MY_LCTL, S(FR_A), S(KC_R), S(KC_S), S(KC_T), S(KC_D),                      S(KC_H), S(KC_N), S(KC_E), S(KC_I), S(KC_O), MY_LCTL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      MY_LSFT, S(FR_Z), S(KC_X), S(KC_C), S(KC_V), S(KC_B),                      S(KC_K), S(FR_M), FR_COMM,  FR_DOT, FR_QUES, MY_LSFT,
  //|--------------------------------------------------------------|   |-------------------------------------------------------------|
                        XXXXXXX, XXXXXXX, KC_LGUI,  MY_NAV,  HT_SPC,    KC_LALT,CSTM_ENT, TG(_NAV_LEFT), XXXXXXX, XXXXXXX
                     //`-------------------------------------------'   `-------------------------------------------'
  ),
    [_F_KEYS] = CHOCO_MAX(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       MY_ESC, XXXXXXX,   KC_F7,   KC_F8,   KC_F9,  KC_F12,                      XXXXXXX, KC_PGUP,   KC_UP, KC_PGDN, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      MY_LCTL, XXXXXXX,   KC_F4,   KC_F5,   KC_F6,  KC_F11,                      KC_BSPC, KC_LEFT, KC_DOWN,KC_RIGHT,  KC_DEL, MY_LCTL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      MY_LSFT, XXXXXXX,   KC_F1,   KC_F2,   KC_F3,  KC_F10,                      XXXXXXX, KC_HOME, XXXXXXX,  KC_END, XXXXXXX, XXXXXXX,
  //|--------------------------------------------------------------|  |--------------------------------------------------------------|
                        XXXXXXX, XXXXXXX, XXXXXXX,  MY_NAV, XXXXXXX,    KC_LALT, KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX
                     //`-------------------------------------------'   `-------------------------------------------'
  ),
    [_NAV_LEFT] = CHOCO_MAX(
  //,--------------------------------------------------------.                    ,-----------------------------------------------------.
       MY_ESC,  XXXXXXX,  XXXXXXX,  WEB_TAB, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+---------+---------+---------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,  XXXXXXX,  KY_LEFT,KY_WEBNAV,KY_RIGHT, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+---------+---------+---------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,  XXXXXXX,  XXXXXXX,  C(KC_D), XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|-----------------------------------------------------------------|  |--------------------------------------------------------------|
                          XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,  KY_SPC,    XXXXXXX, XXXXXXX, TG(_NAV_LEFT), XXXXXXX, XXXXXXX
                      //`---------------------------------------------'  `--------------------------------------------'
  ),
    [_WEB_BROWSER] = CHOCO_MAX(
  //,----------------------------------------------------------.                    ,--------------------------------------------------------.
       MY_ESC,  XXXXXXX, XXXXXXX, WEB_TAB,  C(KC_T), RCS(KC_P),                    RCS(KC_P), C(KC_T), WEB_TAB, XXXXXXX,   XXXXXXX, XXXXXXX,
  //|--------+---------+--------+--------+---------+----------|                    |--------+--------+--------+--------+----------+--------|
      MY_LCTL,RCS(KC_O),   WEB_G, KC_LALT,    WEB_D,  C(KC_N),                       C(KC_N),   WEB_G, KC_LALT,   WEB_D, RCS(KC_O), MY_LCTL,
  //|--------+---------+--------+--------+---------+----------|                    |--------+--------+--------+--------+----------+--------|
      KC_LSFT,  XXXXXXX, XXXXXXX, C(KC_D),  XXXXXXX, RCS(KC_N),                    RCS(KC_N), XXXXXXX, C(KC_D), XXXXXXX,   XXXXXXX, XXXXXXX,
  //|------------------------------------------------------------------|   |---------------------------------------------------------------|
                         XXXXXXX,  XXXXXXX, KC_LGUI,    MY_NAV,  HT_SPC,    KC_LALT,CSTM_ENT, TG(_NAV_LEFT), XXXXXXX, XXXXXXX
                      //`----------------------------------------------'   `-------------------------------------------'
  ),
    [_NAV] = CHOCO_MAX(
  //,--------------------------------------------------------.                    ,-----------------------------------------------------.
       MY_ESC, IMGLASS_CP,   KC_P7,   KC_P8,   KC_P9, KC_BSPC,                      XXXXXXX, KC_PGUP,   KC_UP, KC_PGDN, XXXXXXX, XXXXXXX,
  //|--------+-----------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      MY_LCTL,      KC_P0,   KC_P4,   KY_P5,   KC_P6, KC_PDOT,                      KC_BSPC, KC_LEFT, KC_DOWN,KC_RIGHT,  KC_DEL, MY_LCTL,
  //|--------+-  --------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,   MY_ALT_T,   KY_P1,   KY_P2,   KY_P3,  KC_ENT,                      XXXXXXX, KC_HOME, XXXXXXX,  KC_END, XXXXXXX, XXXXXXX,
  //|-----------------------------------------------------------------|   |-------------------------------------------------------------|
                           XXXXXXX, XXXXXXX, _______, _______, _______,    KC_LALT, KC_LCTL,  MY_NAV, XXXXXXX, XXXXXXX
                        //`-------------------------------------------'   `-------------------------------------------'
  ),
    [_OP_NAV] = CHOCO_MAX(
  //,------------------------------------------------------------.                    ,-----------------------------------------------------.
       MY_ESC,     KC_NUM, KC_NUBS,S(KC_NUBS),   XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+-----------+--------+----------+----------+--------|                    |--------+--------+--------+--------+--------+--------|
      MY_LCTL,    XXXXXXX, KC_PMNS,    KC_EQL,   KC_PPLS, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+-  --------+--------+----------+----------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    XXXXXXX, KC_PSLS,   MY_PIPE,   KC_PAST, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|---------------------------------------------------------------|               |-------------------------------------------------------|
                    XXXXXXX, XXXXXXX, XXXXXXX, MY_NAV_FROM_OP,HT_SPC,                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
                  //`-----------------------------------------------'               `-------------------------------------------'
  ),
    [_MOUSE_LAYER] = CHOCO_MAX(
  //,-----------------------------------------------------.                       ,-----------------------------------------------------.
       MY_ESC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                       |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, KC_BTN1, KC_BTN3, KC_BTN2, XXXXXXX,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                       |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         XXXXXXX, XXXXXXX, KC_BTN2, XXXXXXX, XXXXXXX, XXXXXXX,
  //|-----------------------------------------------------|    |----------------------------------------------------------|
                        XXXXXXX, XXXXXXX, XXXXXXX, KC_LCTL, MO(_ACCENTS),     KC_BTN1, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
                     //`------------------------------------------------'    `-------------------------------------------'
  ),
   // _ACCENTS_COLEMAK_FR
    [_ACCENTS] = CHOCO_MAX(
  //,------------------------------------------------------.                    ,-----------------------------------------------------.
       MY_ESC, XXXXXXX,  MY_UNDO, MY_REDO, MY_CUT, MY_PRT_P,                      XXXXXXX, XXXXXXX,    HT_U, XXXXXXX, XXXXXXX,  KC_TAB,
  //|--------+---------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      MY_LCTL,     HT_A, SEL_ALL, MY_SAVE, MY_COPY,MY_PRT_Z,                      KC_BSPC, XXXXXXX, _______,    HT_I,MY_OCIRC, MY_LCTL,
  //|--------+---------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      MY_LSFT,MY_COMENT, XXXXXXX, C_CEDIL,MY_PASTE,MY_PRT_S,                      XXXXXXX, XXXXXXX, FR_COLN, FR_SCLN, FR_EXLM, MY_LSFT,
  //|---------------------------------------------------------------|   |-------------------------------------------------------------|
                         XXXXXXX, XXXXXXX, KC_LGUI,  MY_NAV,  HT_SPC,    KC_LALT,CSTM_ENT, XXXXXXX, XXXXXXX, XXXXXXX
                      //`-------------------------------------------'   `-------------------------------------------'
  ),
   // _REG_SPE_FR
    [_REG_SPE] = CHOCO_MAX(
  //,-----------------------------------------------------.                    ,---------------------------------------------------------.
       MY_ESC, MY_TILD, FR_LBRC, XXXXXXX, FR_RBRC,MY_DIESE,                      FR_PERC, FR_LCBR,   FR_UNDS, FR_RCBR,   FR_AMPR,  KC_TAB,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+----------+--------+----------+--------|
      MY_LCTL,   FR_AT, KC_PMNS,  KC_EQL, KC_PPLS, MY_DOLL,                      FR_ASTR,MY_BQUOT,   FR_QUOT, FR_DQUO,S(KC_MINS), MY_LCTL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+----------+--------+----------+--------|
      _______, XXXXXXX, KC_PSLS, MY_PIPE, KC_PAST, MY_EURO,                   ALGR(KC_9), FR_LPRN,ALGR(KC_8), FR_RPRN,   XXXXXXX, _______,
  //|--------------------------------------------------------------|  |------------------------------------------------------------------|
                        XXXXXXX, XXXXXXX, _______, _______, _______,   _______, CSTM_ENT, _______, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),
    [_MULTIMEDIA] = CHOCO_MAX(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MSTP, KC_MPRV, KC_VOLD, KC_MNXT, KC_MUTE, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------------------------------------------------------------|  |--------------------------------------------------------------|
                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, KC_MPLY, XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),
    [_RGB] = CHOCO_MAX(
  //,------------------------------------------------------.                    ,-----------------------------------------------------.
       MY_ESC, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+---------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,                      RGB_TOG, ____MOD, _I_COUL, __I_LUM, __I_SAT, __I_VIT,
  //|--------+--------+--------+--------+---------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|---------------------------------------------------------------|  |--------------------------------------------------------------|
                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,    XXXXXXX, KC_LSFT, TG(_RGB), XXXXXXX, XXXXXXX
                                      //`---------------------------'  `--------------------------'
  )
};

// |--------+--------+--------+--------+--------+--------|
//   RGB_TOG, ____MOD, _I_COUL, __I_LUM, __I_SAT, __I_VIT,
// |--------+--------+--------+--------+--------+--------|

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
      if (game_mode) {
        // -------|"-----00000-----00000-----00000-----00000-----"
        oled_write("COLE-  MAK       FR      (GAME  BG)          ", false);
      } else {
        oled_write("COLE-  MAK       FR                        ", false);
      }
      break;
    case _GAME :
      // -------|"-----00000-----00000-----00000-----00000-----"
      //         "                                             "
      oled_write(" GAME                                        ", false);
      break;
    case _AUX_GAME :
      // -------|"-----00000-----00000-----00000-----00000-----"
      //         "                                             "
      oled_write(" AUX  GAME                                   ", false);
      break;
    case _LATEX :
      // -------|"-----00000-----00000-----00000-----00000-----"
      //         "                                             "
      oled_write("LATEX                                        ", false);
      break;
    // case _SFT_COLEMAK_FR :
    //   // -------|"-----00000-----00000-----00000-----00000-----"
    //   //         "                                             "
    //   oled_write(" SFT                                         ", false);
    //   break;
    case _CAPS_LOCK :
      // -------|"-----00000-----00000-----00000-----00000-----"
      //         "                                             "
      oled_write(" CAPS_LOCK                                   ", false);
      break;
    // case _OSL_SHIFT :
    //   // -------|"-----00000-----00000-----00000-----00000-----"
    //   //         "                                             "
    //   oled_write(" OSL_SHIFT                                   ", false);
    //   break;
    case _F_KEYS :
      // -------|"-----00000-----00000-----00000-----00000-----"
      //         "                                             "
      oled_write("  F_  KEYS                                   ", false);
      break;
    case _WEB_BROWSER :
      // -------|"-----00000-----00000-----00000-----00000-----"
      //         "                                             "
      oled_write(" WEB_                                        ", false);
      break;
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
      oled_write("  REG _SPE                                   ", false);
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
    case _NAV_LEFT :
      // -------|"-----00000-----00000-----00000-----00000-----"
      //         "                                             "
      oled_write("  NAV_LEFT                                   ", false);
      break;
    case _MOUSE_LAYER :
      // -------|"-----00000-----00000-----00000-----00000-----"
      //         "                                             "
      oled_write("MOUSELAYER                                   ", false);
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

// ==============================================
// MOUSE AUTO-LAYER
void pointing_device_init_user(void) {
    set_auto_mouse_layer(_MOUSE_LAYER); // only required if AUTO_MOUSE_DEFAULT_LAYER is not set to index of <mouse_layer>
    set_auto_mouse_enable(true);         // always required before the auto mouse feature will work
}

// #include "custom_files/trackpad/scrolling.h"