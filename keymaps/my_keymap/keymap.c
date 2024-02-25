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


// ------------- COMBO ---------------

const uint16_t PROGMEM temp_active_RGB[] = {HT_ENT, HT_SPC, COMBO_END};
combo_t key_combos[] = {
    COMBO(temp_active_RGB, OSL(_RGB)),
};

// ------------- COMBO ---------------
// TAP DANCE

void dance_layers_finished (tap_dance_state_t *state, void *user_data) {
  if (state->count == 3) {
    layer_move(_QWERTY_REG);
  } else if (state->count == 2) {
    layer_move(_COLEMAK_FR);
  } else if (state->count == 1) {
    if (IS_LAYER_ON(_QWERTY_REG)) {
      SEND_STRING(SS_TAP(X_Q));
    } else {
      SEND_STRING(SS_TAP(X_A));
    }
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
    [TD_Q] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_layers_finished, NULL)
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
    case _COLEMAK_FR :
      oled_write("COLEMAK FR   ", false);
      break;
    case _ACCENTS :
      oled_write("ACCENTS      ", false);
      break;
    case _SFT_COLEMAK_FR :
      oled_write("SHIFT        ", false);
      break;
    case _QWERTY_REG :
      oled_write("QUERTY REG   ", false);
      break;
    case _NAV :
      oled_write("NAV          ", false);
      break;
    // case 4 :
    //   oled_write("NUMPAD       ", false);
    //   break;
    case _SPE :
      oled_write("SPECIAL_CHAR ", false);
      break;
    case _RGB :
      oled_write("RGB          ", false);
      break;
    // case 4 :
    //   oled_write("", false);
    //   break;
  }
  
  return false;
}

#endif


// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &ko_make_with_layers(MOD_MASK_SHIFT, FR_COMM, FR_SCLN, 1 << _COLEMAK_FR), // check if it works
    &ko_make_with_layers(MOD_MASK_SHIFT, FR_DOT,  FR_COLN, 1 << _COLEMAK_FR),
    &ko_make_with_layers(MOD_MASK_SHIFT, FR_QUES, FR_EXLM, 1 << _COLEMAK_FR),
    &ko_make_with_layers(MOD_MASK_SHIFT, FR_QUOT, FR_DQUO, 1 << _COLEMAK_FR),
    // &ko_make_with_layers(MOD_MASK_SHIFT, FR_AT,   FR_AGRV, 1 << 2);
    
    NULL // Null terminate the array of overrides!
};

// // This globally defines all key overrides to be used
// const key_override_t **key_overrides = (const key_override_t *[]){
//     &ko_make_with_layers(MOD_MASK_SHIFT, FR_COMM, FR_SCLN,  1 << 2), 
//     &ko_make_with_layers(MOD_MASK_SHIFT, FR_DOT,  FR_COLN, 1 << 2),
//     &ko_make_with_layers(MOD_MASK_SHIFT, FR_QUES, FR_EXLM, 1 << 2),
//     &ko_make_with_layers(MOD_MASK_SHIFT, FR_QUOT, FR_DQUO, 1 << 2),
//     // &ko_make_with_layers(MOD_MASK_SHIFT, FR_AT,   FR_AGRV, 1 << 2);
    
//     NULL // Null terminate the array of overrides!
// };


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        
        case HT_E:
	        if (record->tap.count) { // tapped
	        	if (!record->event.pressed) {
	        		return false;
	        	}

	        	if (is_accent_layer()) {
	        		tap_e_grave();
	        	} else {
	        		tap_code(KC_E);
	        	}
	        } else { // held
	        	if (!record->event.pressed) {
	        		return false;
	        	}
        
	        	if (is_accent_layer()) {
	        		tap_e_circ();
	        	} else {
	        		tap_e_aigue();
	        	}
	        }
	
	        return false;
            
        case HT_C:
	        if (record->tap.count) {
	        	if (record->event.pressed) {
	        		tap_code(KC_C);
	        	}
	        } else {
	        	if (record->event.pressed) {
	        		tap_c_ced();
	        	}
	        }
	        return false;
	
        case HT_A:
            if (record->tap.count) {
                if (record->event.pressed) {
                    tap_a_grave();
                }
            } else {
                if (record->event.pressed) {
                    tap_a_circ();
                }
            }
        
            return false;
        
        case HT_U:
	        if (record->tap.count) {
	        	if (!record->event.pressed) {
	        		return false;
	        	}
        
	        	if (is_accent_layer()) {
	        		tap_u_grave();
	        	} else {
	        		tap_code(KC_U);
	        	}
	        } else {
	        	if (!record->event.pressed) {
	        		return false;
	        	}
        
	        	if (is_accent_layer()) {
	        		tap_u_circ();
	        	} else {
	        		tap_u_grave();
	        	}
	        }
        
	        return false;
        
        case HT_I:
	        if (record->tap.count) {
	        	if (!record->event.pressed) {
	        		return false;
	        	}
        
	        	if (is_accent_layer()) {
	        		tap_i_trema();
	        	} else {
	        		tap_code(KC_I);
	        	}
	        } else {
	        	if (record->event.pressed) {
	        		tap_i_circ();
	        	}
	        }
        
	        return false;

        case HT_O:
        	if (record->tap.count) {
        		if (!record->event.pressed) {
        			return false;
        		}
        
        		if (is_accent_layer()) {
        			tap_o_circ();
        		} else {
        			tap_code(KC_O);
        		}
        	} else {
        		if (record->event.pressed) {
        			tap_o_circ();
        		}
        	}
        
        	return false;

        case ESC_TAB:
            if (record->tap.count) { // tapped
                if (record->event.pressed) {
                    tap_code(KC_ESC);
                }
            } else { // held
                if (record->event.pressed) {
                    tap_code(KC_TAB);
                }
            }
        
            return false;
    
        case MY_NAV: { // I am an alias for MO(_NAV)
            static uint8_t pressed_count = 0;

            if (record->event.pressed) {
                pressed_count++;
            } else {
                pressed_count--;
                if (pressed_count) {
                    return false;
                }
            }
            return true;
        }

        // case MY_PVIRG:
        //   if (!record->event.pressed) {
        //     return false;
        //   }
        //   if (is_shift_layer()) {
        //     tap_point_virgule();
        //   } else {
        //     tap_point_virgule(); // TPDP nothing better to put atm here, maybe later
        //   }
        //   return false;

        // case HT_SPC:
            // if (record->tap.count) { // tapped
          //   	if (!record->event.pressed) {
          //   		return false;
          //   	}
          //   		tap_code(KC_SCP);
          //   } else { // held
          //   	if (!record->event.pressed) {
          //   		return false;
          //   	}
          //   		tap_code(KC_LGUI);
          //   }
           
          //   return false;

    }
    
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // _COLEMAK_FR
    [_COLEMAK_FR] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     ESC_TAB,     FR_Q,    FR_W,    KC_F,    KC_P,    KC_G,                         KC_J,    KC_L,    HT_U,    KC_Y, FR_QUOT, ESC_TAB,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      MY_LCTL,    FR_A,    KC_R,    KC_S,    KC_T,    KC_D,                         KC_H,    KC_N,    HT_E,    HT_I,    HT_O, MY_LCTL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      MY_LSFT,    FR_Z,    KC_X,    HT_C,    KC_V,    KC_B,                         KC_K,    FR_M, FR_COMM,  FR_DOT, FR_QUES, MY_LSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,  MY_NAV,  HT_SPC,     HT_ENT,  MO_SPE,  KC_RALT 
                                      //`--------------------------'  `--------------------------'

  ),
   // _ACCENTS_COLEMAK_FR
    [_ACCENTS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,    HT_A, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______,  MO_SPE,     MO_SPE, _______, _______
                                      //`--------------------------'  `--------------------------'

  ),
   // _SFT_LR_COLEMAK_FR
    [_SFT_COLEMAK_FR] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______,MY_QUOTE,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'

  ),

    // QWERTY REG, especially for keybr.com
    [_QWERTY_REG] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      ESC_TAB,     KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  ESC_TAB,
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
       KC_TAB, XXXXXXX, S(KC_7), S(KC_8), S(KC_9), XXXXXXX,                      XXXXXXX, KC_PGUP,   KC_UP, KC_PGDN, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, S(KC_0), S(KC_4), S(KC_5), S(KC_6), XXXXXXX,                      KC_BSPC, KC_LEFT, KC_DOWN,KC_RIGHT,  KC_DEL, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, S(KC_1), S(KC_2), S(KC_3), XXXXXXX,                      XXXXXXX, KC_HOME, XXXXXXX,  KC_END, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, MY_NAV, _______
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
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX,MO_QWEREG,  DT_UP,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, MO_COLFR,DT_DOWN,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, DT_PRNT,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX,  KC_SPC,    XXXXXXX, _______, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  )
};