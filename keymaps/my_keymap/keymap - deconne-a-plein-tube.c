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
#include "keymap_french.h"

// -------------------------------------------------------------------------
enum {
 TD_LAYERS = 0,
//  CT_CLN,
//  CT_EGG,
//  CT_FLSH,
//  X_TAP_DANCE
};

// -------------------------------------------------------------------------
// TAP DANCE

// layer_move(layer)

void dance_layers_finished (tap_dance_state_t *state, void *user_data) {
  if (state->count == 5) {
    layer_move(4);
  } else if (state->count == 4) {
    layer_move(2);
  } else if (state->count == 3) {
    layer_move(1);
  } else if (state->count == 2) {
    layer_move(0);
  } else if (state->count == 1) {
    SEND_STRING(SS_TAP(X_TAB));
  }
}

// void dance_cln_reset (qk_tap_dance_state_t *state, void *user_data) {
//   if (state->count == 1) {
//     unregister_code (KC_LCTL);
//     unregister_code (KC_SCLN);
//   } else {
//     unregister_code (KC_SCLN);
//   }
// }

// qk_tap_dance_action_t tap_dance_actions[] = {
//  [CT_CLN] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_cln_finished, dance_cln_reset)
// };

tap_dance_action_t tap_dance_actions[] = {
 [TD_LAYERS] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_layers_finished, NULL)
};


// -------------------------------------------------------------------------

// bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
//     for (uint8_t i = led_min; i < led_max; i++) {
//         switch(get_highest_layer(layer_state|default_layer_state)) {
//             case 0:
//                 rgb_matrix_set_color(i, RGB_RED);
//                 break;
//             // case 1:
//             //     rgb_matrix_set_color(i, RGB_YELLOW);
//             //     break;
//             case 1:
//                 rgb_matrix_set_color(i, RGB_BLUE);
//                 break;
//             case 2:
//                 rgb_matrix_set_color(i, RGB_YELLOW);
//                 break;
//             case 3:
//                 rgb_matrix_set_color(i, RGB_GREEN);
//                 break;
//             default:
//                 break;
//         }
//     }
//     return false;
// }




// ================================ OLED DISPLAY ==============================================
#ifdef OLED_ENABLE

// // rotate oled
// oled_rotation_t oled_init_user(oled_rotation_t rotation) {
//   return OLED_ROTATION_90;
// }

// Draw to OLED
bool oled_task_user() {
  // Set cursor position
  oled_set_cursor(0,1);

  // // Write text to OLED
  // oled_write("Hello World!", false);

  switch (get_highest_layer(layer_state)){
    case 0 :
      oled_write("QWERTY FR ", false);
      break;
    case 1 :
      oled_write("QWERTY REG", false);
      break;
    case 2 :
      oled_write("COLEMAK FR ", false);
      break;
    case 3 :
      oled_write("COLEMAK REG", false);
    //   break;
    // case 4 :
    //   oled_write("", false);
    //   break;
  }
  
  return false;
}

#endif

// enum custom_keycodes {
//     MY_DIEZE = SAFE_RANGE,
// };


#define MY_LCTL ACTION_TAP_DANCE_DOUBLE(KC_LCTL, KC_ESC)
#define MY_LSFT LM(3, MOD_LSFT)


const key_override_t point_virgule_key_override  = ko_make_with_layers(MOD_MASK_SHIFT, FR_COMM, FR_DLR, 1 << 2);
const key_override_t deux_points_key_override  = ko_make_with_layers(MOD_MASK_SHIFT, FR_DOT, FR_COLN, 1 << 2);
const key_override_t exclm_key_override  = ko_make_with_layers(MOD_MASK_SHIFT, FR_QUES, FR_EXLM, 1 << 2);
const key_override_t guillemets_key_override  = ko_make_with_layers(MOD_MASK_SHIFT, FR_QUOT, FR_SCLN, 1 << 2);
// const key_override_t ligne2_2_key_override  = ko_make_with_layers(MOD_MASK_SHIFT, FR_AT, FR_AGRV, 1 << 2);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &point_virgule_key_override,
    &deux_points_key_override,
    &exclm_key_override,
    &guillemets_key_override,
    NULL // Null terminate the array of overrides!
};


enum custom_keycodes {
    MYNEWKEY = SAFE_RANGE,
    MY_COMMENT,
    MY_E_CIRCONFLEXE,
    MY_SLASHES,
    MY_BACKQUOTE,
    MY_QUOTE,
    MY_POINT_VIRGULE,
    MY_DIEZE,
    MY_TILD,
    MY_DOLLAR,
    MY_U_GRAVE,
    MY_U_CIRC,
    MY_A_GRAVE,
    MY_A_CIRC,
    MY_E_AIGU,
    MY_E_GRAVE,
    MY_E_CIRC,
    MY_I_CIRC,
    MY_O_CIRC,
    MY_C_CEDILLE,
    MY_EURO,
};
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
      case MYCAPSKEY:
        if (record->tap.count) { // tapped
          if (!record->event.pressed) {
            return false;
          }

          if (layer_state_is(LAYER_SHIFT)) {
            unregister_mods(MOD_BIT_LSHIFT);
            layer_off(LAYER_SHIFT);
          } else {
            register_mods(MOD_BIT_LSHIFT); // Here is the line that causes behavior issue with mouse 1
            layer_on(LAYER_SHIFT);
          }
        } else { // held
          if (record->event.pressed) {
            register_mods(MOD_BIT_LSHIFT);
            layer_on(LAYER_SHIFT);
          } else {
            layer_off(LAYER_SHIFT);
            unregister_mods(MOD_BIT_LSHIFT);
          }
        }
        return true;
        break;
      
      case MY_SLASHES:
        // if (record->event.pressed && get_mods() & MOD_BIT(KC_LCTL)) {
          if (record->event.pressed) {
            if (IS_LAYER_ON(LAYER_SHIFT)){
                unregister_mods(MOD_BIT_LSHIFT);
                unregister_mods(MOD_BIT_RSHIFT);
                SEND_STRING(SS_LALT(SS_TAP(X_KP_4) SS_TAP(X_KP_7))); // 47 Slash
              } else {
              if (get_mods() & MOD_BIT(KC_LCTL)) {
                // unregister_mods(MOD_BIT_LCTRL);
                SEND_STRING(SS_LCTL(SS_TAP(X_DOT)));
                // SEND_STRING(SS_LALT(SS_TAP(X_KP_5) SS_TAP(X_KP_8))); // 58 deux points
                // register_mods(MOD_BIT_LCTRL);
              } else {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_9) SS_TAP(X_KP_2))); // 92 backslash 
              }
            }
        } else {
          unregister_mods(MOD_BIT_LSHIFT);
          unregister_mods(MOD_BIT_RSHIFT);
        }
        return false;
        break;

      case MY_E_CIRCONFLEXE:
        if (record->event.pressed) {
          SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_3) SS_TAP(X_KP_6)));
          // unregister_mods(MOD_BIT_LALT);
        }
        return false;
        break;

      case MY_BACKQUOTE:
        if (record->event.pressed) {
          if (IS_LAYER_ON(LAYER_SHIFT)) {
            unregister_mods(MOD_BIT_LSHIFT);
            unregister_mods(MOD_BIT_RSHIFT);
            SEND_STRING(SS_LALT(SS_TAP(X_KP_9) SS_TAP(X_KP_6)));
            // unregister_mods(MOD_BIT_LALT);
            // register_mods(MOD_BIT_LSHIFT);
          }
        }
        return false;
        break;
        
        case MY_QUOTE:
        if (record->event.pressed) {
          if (IS_LAYER_ON(LAYER_SHIFT)) {
            unregister_mods(MOD_BIT_LSHIFT);
            unregister_mods(MOD_BIT_RSHIFT);
            SEND_STRING(SS_LALT(SS_TAP(X_KP_3) SS_TAP(X_KP_4)));
            // unregister_mods(MOD_BIT_LALT);
            // register_mods(MOD_BIT_LSHIFT);
          }
        }
        return false;
        break;
        
        case MY_POINT_VIRGULE:
        if (record->event.pressed) {
          if (IS_LAYER_ON(LAYER_SHIFT)) {
            unregister_mods(MOD_BIT_LSHIFT);
            unregister_mods(MOD_BIT_RSHIFT);
            SEND_STRING(SS_LALT(SS_TAP(X_KP_5) SS_TAP(X_KP_9)));
            // unregister_mods(MOD_BIT_LALT);
            // register_mods(MOD_BIT_LSHIFT);
          }
        }
        return false;
        break;

        case MY_DIEZE:
        if (record->event.pressed) {
          if (IS_LAYER_ON(LAYER_SHIFT)) {
            unregister_mods(MOD_BIT_LSHIFT);
            unregister_mods(MOD_BIT_RSHIFT);
            SEND_STRING(SS_LALT(SS_TAP(X_KP_3) SS_TAP(X_KP_5)));
            // unregister_mods(MOD_BIT_LALT);
            // register_mods(MOD_BIT_LSHIFT);
          }
        }
        return false;
        break;

        case MY_TILD:
        if (record->event.pressed) {
          if (IS_LAYER_ON(LAYER_SHIFT)) {
            unregister_mods(MOD_BIT_LSHIFT);
            unregister_mods(MOD_BIT_RSHIFT);
            SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_2) SS_TAP(X_KP_6)));
            // unregister_mods(MOD_BIT_LALT);
            // register_mods(MOD_BIT_LSHIFT);
          }
        }
        return false;
        break;

      case MY_DOLLAR:
        if (record->event.pressed) {
          SEND_STRING(SS_LALT(SS_TAP(X_KP_3) SS_TAP(X_KP_6)));
          // unregister_mods(MOD_BIT_LALT);
        }
        return false;
        break;

        case MY_U_GRAVE:
        if (record->event.pressed) {
          unregister_mods(MOD_BIT_LALT);
          unregister_mods(MOD_BIT_RALT);
          SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_5) SS_TAP(X_KP_1)));
          // unregister_mods(MOD_BIT_LALT);
        }
        return false;
        break;

        case MY_U_CIRC:
        if (record->event.pressed) {
          SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_5) SS_TAP(X_KP_0)));
          // unregister_mods(MOD_BIT_LALT);
        }
        return false;
        break;

        case MY_A_GRAVE:
        if (record->event.pressed) {
          unregister_mods(MOD_BIT_LALT);
          unregister_mods(MOD_BIT_RALT);
          SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_3) SS_TAP(X_KP_3)));
        }
        return false;
        break;

        case MY_A_CIRC:
        if (record->event.pressed) {
          SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_3) SS_TAP(X_KP_1)));
          // unregister_mods(MOD_BIT_LALT);
        }
        return false;
        break;

        case MY_E_AIGU:
        if (record->event.pressed) {
          unregister_mods(MOD_BIT_LALT);
          unregister_mods(MOD_BIT_RALT);
          SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_3) SS_TAP(X_KP_0)));
          // unregister_mods(MOD_BIT_LALT);
        }
        return false;
        break;

        case MY_E_GRAVE:
        if (record->event.pressed) {
          unregister_mods(MOD_BIT_LALT);
          unregister_mods(MOD_BIT_RALT);
          SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_3) SS_TAP(X_KP_8)));
          // unregister_mods(MOD_BIT_LALT);
        }
        return false;
        break;

        case MY_E_CIRC:
        if (record->event.pressed) {
          SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_3) SS_TAP(X_KP_6)));
          // unregister_mods(MOD_BIT_LALT);
        }
        return false;
        break;

        case MY_I_CIRC:
        if (record->event.pressed) {
          unregister_mods(MOD_BIT_LALT);
          unregister_mods(MOD_BIT_RALT);
          SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_4) SS_TAP(X_KP_0)));
          // unregister_mods(MOD_BIT_LALT);
        }
        return false;
        break;

        case MY_O_CIRC:
        if (record->event.pressed) {
          unregister_mods(MOD_BIT_LALT);
          unregister_mods(MOD_BIT_RALT);
          SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_4) SS_TAP(X_KP_7)));
          // unregister_mods(MOD_BIT_LALT);
        }
        return false;
        break;

        case MY_C_CEDILLE:
        if (record->event.pressed) {
          unregister_mods(MOD_BIT_LALT);
          unregister_mods(MOD_BIT_RALT);
          SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_3) SS_TAP(X_KP_5)));
          // unregister_mods(MOD_BIT_LALT);
        }
        return false;
        break;

        case MY_EURO:
        if (record->event.pressed) {
          // unregister_mods(MOD_BIT_LALT);
          // unregister_mods(MOD_BIT_RALT);
          SEND_STRING(SS_RALT(SS_TAP(X_E)));
          // unregister_mods(MOD_BIT_LALT);
        }
        return false;
        break;
  }
  return true;
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // QWERTY FR
    [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
TD(TD_LAYERS),    FR_Q,    FR_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      MY_LCTL,    FR_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    FR_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    FR_M, FR_COMM,  FR_DOT, FR_QUES,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(5),  KC_SPC,     KC_ENT,   MO(6), KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),
  // QWERTY REG
    [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(5),  KC_SPC,     KC_ENT,   MO(6), KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),
  // COLEMAK FR
    [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
TD(TD_LAYERS),    FR_Q,    FR_W,    KC_F,    KC_P,    KC_G,                         KC_J,    KC_L,    KC_U,    KC_Y,   FR_AT, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      MY_LCTL,    FR_A,    KC_R,    KC_S,    KC_T,    KC_D,                         KC_H,    KC_N,    KC_E,    KC_I,    KC_O, FR_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      MY_LSFT,    FR_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_K,    FR_M, FR_COMM,  FR_DOT, FR_QUES,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(5),  KC_SPC,     KC_ENT,   MO(6), KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),
   // SHIFTED COLEMAK FR
    [LAYER_SHIFT] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,---------------------------          --------------------------.
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______,          _______, MY_DIEZE, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+          --------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______,          _______, _______, MY_QUOTE,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+          --------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      _______, _______, MY_POINT_VIRGULE, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+          --------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),
  // COLEMAK REG
    [4] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,    KC_A,    KC_R,    KC_S,    KC_T,    KC_D,                         KC_H,    KC_N,    KC_E,    KC_I,    KC_O, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_K,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(5),  KC_SPC,     KC_ENT,   MO(6), KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

    [5] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT,   MO(7), KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

    [6] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(7),  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

    [7] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  )
};
