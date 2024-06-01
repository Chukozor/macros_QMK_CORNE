// #include "timer.h"
// static uint8_t nav_interrupted = 0;
// static bool spc_is_held = false;


#include "custom_files/functions_record_user.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
      // #include "obsolete/my_old_accents_char.h"
      // #include "obsolete/my_old_specials_char.h"
      #include "custom_files/french_symbols/my_accents_char_precuser.h"
      #include "custom_files/my_specials_char_precuser.h"
      // #include "custom_files\french_symbols\accents_for_combo.h"

      case MY_PRT_S:
        if (record->event.pressed) {
          tap_code(KC_PSCR);
          // here we override its «press» behavior (hence, return false)
          return false;
        } else {
          // here we don't alter its «release» default behavior (hence, return true)
          return true;
        }
        break;

      case MY_PRT_Z:
        if (record->event.pressed) {
          add_mods(MOD_BIT_RCTRL);
          tap_code(KC_PSCR);
          unregister_mods(MOD_BIT_RCTRL);
          // here we override its «press» behavior (hence, return false)
          return false;
        } else {
          // here we don't alter its «release» default behavior (hence, return true)
          return true;
        }
        break;

      case MY_PRT_P:
        if (record->event.pressed) {
          add_mods(MOD_BIT_LSHIFT);
          tap_code(KC_PSCR);
          unregister_mods(MOD_BIT_LSHIFT);
          // here we override its «press» behavior (hence, return false)
          return false;
        } else {
          // here we don't alter its «release» default behavior (hence, return true)
          return true;
        }
        break;

      case MY_COMENT:
        if (record->event.pressed) {
          add_mods(MOD_BIT_RCTRL);
          tap_code(KC_DOT);
          unregister_mods(MOD_BIT_RCTRL);
          // here we override its «press» behavior (hence, return false)
          return false;
        } else {
          // here we don't alter its «release» default behavior (hence, return true)
          return true;
        }
        break;

      case MY_COPY:
        if (record->event.pressed) {
          my_copy();
        }
        return false;
        break;
        
      case MY_CUT:
        if (record->event.pressed) {
          my_cut();
        }
        return false;
        break;

      case MY_PASTE:
        if (record->event.pressed) {
          my_paste();
        }
        return false;
        break;

      case MY_UNDO:
        if (record->event.pressed) {
          my_undo_down();
        } else {
          my_undo_up();
        }
        return false;
        break;

      case MY_REDO:
        if (record->event.pressed) {
          my_redo_down();
        } else {
          my_redo_up();
        }
        return false;
        break;

      case MY_SAVE:
        if (record->event.pressed) {
          my_save();
        }
        return false;
        break;

      case CSTM_ENT:
        if (record->tap.count) { // Tap
          if (record->event.pressed) {
            // your logic when pressed
            if (is_accent_layer()) {
              SEND_STRING(SS_LSFT(SS_TAP(X_ENT)));
            } else {
              tap_code(KC_ENT);
            }
          }
        } else { // Hold
          if (record->event.pressed) { // pressed
            // if (!record->tap.interrupted) {
              if (is_accent_layer()) {
                layer_on(_RGB);
              } else {
                layer_on(_REG_SPE);
              }
            // } 
          //   else { // interrupted
          //     if (is_accent_layer()) {
          //       layer_on(_RGB);
          //     } else {
          //       layer_on(_CAPS_LOCK);
          //     }
          //   }
          }
          else { // released
            layer_off(_REG_SPE);
            layer_off(_RGB);
          }
          return false;
        }
        return false;
        break;

      // case HT_SPC:
      //   if (record->tap.count) { // tapped
      //     if (!record->event.pressed) {
      //       // your logic when released
      //       return false;
      //     }
      //     if (is_colemak_layer()) {
      //       tap_code(KC_SPC);
      //     } else {
      //       // tap_code(KC_NO);
      //       tap_code(KC_SPC);
      //     }
      //     // if (is_accent_layer()) {
      //     // 	tap_e_aigue();
      //     // } else {
      //     // 	tap_code(KC_SPC);
      //     // }
      //     // spc_is_held = false;
      //   } else { // held
      //     if (record->event.pressed) {
      //       if (record->tap.interrupted) {
      //       // if (is_colemak_layer()) {
      //         layer_on(_ACCENTS);
      //       // } else {
      //       //   tap_code(KC_NO);
      //       // }
      //       } else {
      //         layer_on(_ACCENTS);
      //       }
      //       // spc_is_held = true;
      //     } else if (!record->event.pressed) {
      //       // SEND_STRING(SS_DELAY(300));
      //       layer_off(_ACCENTS);
      //       return false;
      //       // spc_is_held = false;
      //     }
      //   }
      //   return false;
      //   break;

      case MY_ESC:
        if (record->event.pressed) {
          tap_code(KC_ESC);
          // soft_reset_keyboard();
          // eeconfig_init();
          clear_mods();
          layer_clear();
          nav_already_activated = false;
          capslock_was_activated = false;
          // spc_is_held = false;
          layer_move(_COLEMAK_FR);
        } else {
          // nothing needed here
        }
        return false;
        break;

      case WEB_D:
        // if (spc_is_held) {
        //   if (record->event.pressed) {
        //     my_copy();
        //   }
        //   return false;
        // } else {
        if (get_mods() != MOD_BIT(KC_LALT)) {
          if (record->event.pressed) {
            register_code(KC_LCTL);
          } else {
            unregister_code(KC_LCTL);
          }
        }
        if (record->event.pressed) {
          tap_code(KC_TAB);
        }
        return false;
        break;

      case WEB_G:
        // if (spc_is_held) {
        //   if (record->event.pressed) {
        //     my_selec_all();
        //   }
        //   return false;
        // } else {
        if (get_mods() != MOD_BIT(KC_LALT)) {
          if (record->event.pressed) {
            register_code(KC_LCTL);
          } else {
            unregister_code(KC_LCTL);
          }
        }
        if (record->event.pressed) {
            SEND_STRING(SS_LSFT(SS_TAP(X_TAB)));
        }
        return false;
        break;

      case WEB_TAB:
        if (record->tap.count) { // tapped
          if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LCTL));
            SEND_STRING(SS_DELAY(1));
            SEND_STRING(SS_TAP(X_Z));// CTRL + W, ici Z pcq langue francaise KC_Z = FR_W
            SEND_STRING(SS_UP(X_LCTL));
          }
        } else { // held
          if (record->event.pressed) {
            // if (record->tap.interrupted) {
            // } else {
            //   layer_on(_ACCENTS);
            // }
            SEND_STRING(SS_DOWN(X_LCTL));
            SEND_STRING(SS_DOWN(X_LSFT));
            SEND_STRING(SS_DELAY(1));
            SEND_STRING(SS_TAP(X_T));
            SEND_STRING(SS_UP(X_LSFT));
            SEND_STRING(SS_UP(X_LCTL));
          }
        }
        return false;
        break;
      case SEL_ALL:
        if (record->event.pressed) {
          my_selec_all();
        }
        return false;
        break;

      case TEST1:
        if (record->event.pressed) {
          // À (a majuscule accent) = Ctrl + Alt + 7 puis Maj + A (le 7 est celui situé en haut du clavier et non celui du pavé numérique)
          SEND_STRING(SS_DOWN(X_LCTL));
          SEND_STRING(SS_DOWN(X_LALT));
          SEND_STRING(SS_DELAY(1));
          SEND_STRING(SS_TAP(X_7));
          SEND_STRING(SS_UP(X_LALT));
          SEND_STRING(SS_UP(X_LCTL));
          SEND_STRING(SS_LSFT(SS_TAP(X_Q)));// KC_Q = FR_A 
        }
        return false;
        break;

      case TEST2:
        if (record->event.pressed) {
          // É (e majuscule accent aigu) = Ctrl + 4 puis Maj + E
          SEND_STRING(SS_DOWN(X_LCTL));
          // SEND_STRING(SS_DOWN(X_LALT));
          SEND_STRING(SS_DELAY(1));
          SEND_STRING(SS_TAP(X_4));
          // SEND_STRING(SS_UP(X_LALT));
          SEND_STRING(SS_LSFT(SS_TAP(X_E)));// KC_Q = FR_A 
          SEND_STRING(SS_UP(X_LCTL));
        }
        return false;
        break;

      case TEST3:
        if (record->event.pressed) {
          // È (e majuscule accent grave) = Ctrl + Alt + 7 puis Maj + E
          SEND_STRING(SS_DOWN(X_LCTL));
          SEND_STRING(SS_DOWN(X_LALT));
          SEND_STRING(SS_DELAY(1));
          SEND_STRING(SS_TAP(X_7));
          SEND_STRING(SS_UP(X_LALT));
          SEND_STRING(SS_UP(X_LCTL));
          SEND_STRING(SS_LSFT(SS_TAP(X_E)));
        }
        return false;
        break;

      case TEST4:
        if (record->event.pressed) {
          // Ç (c cédille majuscule) = Ctrl+, puis Maj + C
          SEND_STRING(SS_DOWN(X_LCTL));
          // SEND_STRING(SS_DOWN(X_LALT));
          SEND_STRING(SS_DELAY(1));
          SEND_STRING(SS_TAP(X_M));// KC_M = "FR_VIRGULE"
          // SEND_STRING(SS_UP(X_LALT));
          SEND_STRING(SS_UP(X_LCTL));
          SEND_STRING(SS_LSFT(SS_TAP(X_C)));
        }
        return false;
        break;

      case TEST5:
        if (record->event.pressed) {
          // Ê = Ctrl + Alt + 9 puis Maj + E (le 9 est celui situé en haut du clavier et non celui du pavé numérique)
          SEND_STRING(SS_DOWN(X_LSFT));
          SEND_STRING(SS_DOWN(X_RSFT));
          SEND_STRING(SS_DELAY(1));
          SEND_STRING(SS_TAP(X_LBRC));
          SEND_STRING(SS_UP(X_RSFT));
          SEND_STRING(SS_UP(X_LSFT));
          SEND_STRING(SS_TAP(X_E));
          // SEND_STRING(SS_LSFT(SS_TAP(X_E)));
        }
        return false;
        break;

  }
  return true;
}


// #define WEB_BROWSER_LAYER_TIMEOUT 10000  //configure your timeout in milliseconds

// void matrix_scan_user(void) {
//   if (IS_LAYER_ON(_WEB_BROWSER)) {
//     if (last_input_activity_elapsed() > WEB_BROWSER_LAYER_TIMEOUT) {
//       layer_off(_WEB_BROWSER);
//     }
//   }
// }

// void matrix_scan_user(void) {
//   if (get_highest_layer(layer_state) == _WEB_BROWSER) {
//     if (last_input_activity_elapsed() > WEB_BROWSER_LAYER_TIMEOUT) {
//       layer_off(_WEB_BROWSER);
//     }
//   }
// }

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // case SFT_T(KC_SPC):
        //    return g_tapping_term + 1250;
        case MY_LSFT:
            return 160;
        case HT_SPC:
            return 210;
        case MY_NAV:
            return 200;
        case HT_A:
            return 200;
        case HT_E:
            return 160;
        case MY_BNAV:
            return 230;
        case WEB_TAB:
            return 230;
        default:
            return g_tapping_term;
    }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HT_E:
            // Do not force the mod-tap key press to be handled as a modifier
            // if any other key was pressed while the mod-tap key is held down.
            return false;
        case HT_I:
            // Do not force the mod-tap key press to be handled as a modifier
            // if any other key was pressed while the mod-tap key is held down.
            return false;
        case HT_U:
            // Do not force the mod-tap key press to be handled as a modifier
            // if any other key was pressed while the mod-tap key is held down.
            return false;
        case HT_O:
            // Do not force the mod-tap key press to be handled as a modifier
            // if any other key was pressed while the mod-tap key is held down.
            return false;
        case HT_A:
            // Do not force the mod-tap key press to be handled as a modifier
            // if any other key was pressed while the mod-tap key is held down.
            return false;
        default:
            // Force the dual-role key press to be handled as a modifier if any
            // other key was pressed while the mod-tap key is held down.
            return true;
    }
}

uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    // // decide by combo->keycode
    // switch (combo->keycode) {
    //     case KC_X:
    //         return 50;
    // }

    // or with combo index, i.e. its name from enum.
    switch (index) {
        case COMBO_OSL_SHIFT:
            return 50;
    }

    // // And if you're feeling adventurous, you can even decide by the keys in the chord,
    // // i.e. the exact array of keys you defined for the combo.
    // // This can be useful if your combos have a common key and you want to apply the
    // // same combo term for all of them.
    // if (combo->keys[0] == KC_ENT) { // if first key in the array is Enter
    //     return 150;
    // }

    return COMBO_TERM;
}



// case MY_NAV: { // I am an alias for MO(_NAV)
//     static uint8_t pressed_count = 0;

//     if (record->event.pressed) {
//         pressed_count++;
//     } else {
//         pressed_count--;
//         if (pressed_count) {
//             return false;
//         }
//     }
//     return true;
// }