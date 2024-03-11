// --------------------------TAP DANCE FEATURES------------------------------
typedef struct {
  bool is_press_action;
  int state;
} tap;

//Define a type for as many tap dance states as you need
enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3,
  DOUBLE_HOLD = 4,
  DOUBLE_SINGLE_TAP = 5, //send two single taps
  TRIPLE_TAP = 6,
  TRIPLE_HOLD = 7
};

enum {
  TD_CAPS_LCK = 0,     //Our custom tap dance key; add any other tap dance keys to this enum
  TD_NAV_FX_KEYS,
  TD_ENT
};

//Declare the functions to be used with your tap dance key(s)

//Function associated with all tap dances
int cur_dance (tap_dance_state_t *state);

//Functions associated with individual tap dances
//for the x tap dance. Put it here so it can be used in any keymap
void sft_finished (tap_dance_state_t *state, void *user_data);
void sft_reset (tap_dance_state_t *state, void *user_data);
void nav_fx_finished (tap_dance_state_t *state, void *user_data);
void nav_fx_reset (tap_dance_state_t *state, void *user_data);
void ent_finished (tap_dance_state_t *state, void *user_data);
void ent_fx_reset (tap_dance_state_t *state, void *user_data);
// -------------------------------------------------------------------------
// ======= Determine the current tap dance state ========

// UN TYPE DE DANCE : =======================

// int cur_dance (tap_dance_state_t *state) {
//   if (state->count == 1) {
//     if (!state->pressed) {
//       return SINGLE_TAP;
//     } else {
//       return SINGLE_HOLD;
//     }
//   } else if (state->count == 2) {
//     return DOUBLE_TAP;
//   }
//   else return 8;
// }
// FIN DE CE TYPE DE DANCE ==================

// ################################################

// MA DANCE : =======================

int ma_cur_dance (tap_dance_state_t *state) {
  if (state->count == 1) {
    if (!state->pressed) {
      return SINGLE_TAP;
    } else {
      return SINGLE_HOLD;
    }
  } else if (state->count == 2) {
    if (!state->pressed) {
      return DOUBLE_TAP;
    } else {
      return DOUBLE_HOLD;
    }
  }
  else return 8;
}
// FIN DE MA DE DANCE ==================


// ################################################
// UNE AUTRE DANCE : ==================

// /* Return an integer that corresponds to what kind of tap dance should be executed.
//  *
//  * How to figure out tap dance state: interrupted and pressed.
//  *
//  * Interrupted: If the state of a dance dance is "interrupted", that means that another key has been hit
//  *  under the tapping term. This is typically indicitive that you are trying to "tap" the key.
//  *
//  * Pressed: Whether or not the key is still being pressed. If this value is true, that means the tapping term
//  *  has ended, but the key is still being pressed down. This generally means the key is being "held".
//  *
//  * One thing that is currenlty not possible with qmk software in regards to tap dance is to mimic the "permissive hold"
//  *  feature. In general, advanced tap dances do not work well if they are used with commonly typed letters.
//  *  For example "A". Tap dances are best used on non-letter keys that are not hit while typing letters.
//  *
//  * Good places to put an advanced tap dance:
//  *  z,q,x,j,k,v,b, any function key, home/end, comma, semi-colon
//  *
//  * Criteria for "good placement" of a tap dance key:
//  *  Not a key that is hit frequently in a sentence
//  *  Not a key that is used frequently to double tap, for example 'tab' is often double tapped in a terminal, or
//  *    in a web form. So 'tab' would be a poor choice for a tap dance.
//  *  Letters used in common words as a double. For example 'p' in 'pepper'. If a tap dance function existed on the
//  *    letter 'p', the word 'pepper' would be quite frustating to type.
//  *
//  * For the third point, there does exist the 'DOUBLE_SINGLE_TAP', however this is not fully tested
//  *
//  */
// int cur_dance (tap_dance_state_t *state) {
//   if (state->count == 1) {
//     if (state->interrupted || !state->pressed)  return SINGLE_TAP;
//     //key has not been interrupted, but they key is still held. Means you want to send a 'HOLD'.
//     else return SINGLE_HOLD;
//   }
//   else if (state->count == 2) {
//     /*
//      * DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
//      * action when hitting 'pp'. Suggested use case for this return value is when you want to send two
//      * keystrokes of the key, and not the 'double tap' action/macro.
//     */
//     if (state->interrupted) return DOUBLE_SINGLE_TAP;
//     else if (state->pressed) return DOUBLE_HOLD;
//     else return DOUBLE_TAP;
//   }
//   //Assumes no one is trying to type the same letter three times (at least not quickly).
//   //If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
//   //an exception here to return a 'TRIPLE_SINGLE_TAP', and define that enum just like 'DOUBLE_SINGLE_TAP'
//   if (state->count == 3) {
//     if (state->interrupted || !state->pressed)  return TRIPLE_TAP;
//     else return TRIPLE_HOLD;
//   }
//   else return 8; //magic number. At some point this method will expand to work for more presses
// }

// FIN D'UNE AUTRE DANCE : ==================

// -------------------------------------------------------------------------
//Initialize tap structure associated with example tap dance key
static tap sft_tap_state = {
  .is_press_action = true,
  .state = 0
};
static tap nav_tap_state = {
  .is_press_action = true,
  .state = 0
};
static tap ent_tap_state = {
  .is_press_action = true,
  .state = 0
};
// ================= SHIFT TAPDANCE ================
//Functions that control what our tap dance key does
void sft_finished (tap_dance_state_t *state, void *user_data) {
  sft_tap_state.state = ma_cur_dance(state);
  switch (sft_tap_state.state) {
    // case SINGLE_TAP: 
    //   tap_code(KC_QUOT);
    //   break;
    case SINGLE_HOLD: 
      layer_on(_SFT_COLEMAK_FR);
      // TODO moi
      register_mods(MOD_BIT_LSHIFT);
      // add_mods(MOD_BIT_LSHIFT);
      // tap_code(KC_PSCR);
      // TODO moi
      break;
    case DOUBLE_TAP: 
      //check to see if the layer is already set
      if (layer_state_is(_CAPS_LOCK)) {
        //if already set, then switch it off
        layer_off(_CAPS_LOCK);
      } else { 
        //if not already set, then switch the layer on
        layer_on(_CAPS_LOCK);
      }
      break;
    // case DOUBLE_HOLD:
    //   tap_code(KC_M);
  }
}

void sft_reset (tap_dance_state_t *state, void *user_data) {
  //if the key was held down and now is released then switch off the layer
  if (sft_tap_state.state==SINGLE_HOLD) {
    layer_off(_SFT_COLEMAK_FR);
    unregister_mods(MOD_BIT_LSHIFT);
  }
  sft_tap_state.state = 0;
}
// %%%%%%%%%%%%%%%%% END SHIFT TAPDANCE %%%%%%%%%%%%%%%%%

// ================= NAV_F_KEYS TAPDANCE ================
//Functions that control what our tap dance key does
void nav_fx_finished (tap_dance_state_t *state, void *user_data) {
  nav_tap_state.state = ma_cur_dance(state);
  switch (nav_tap_state.state) {
    // case SINGLE_TAP: 
    //   tap_code(KC_QUOT);
    //   // layer_on(_NAV);
    //   break;
    case SINGLE_HOLD: 
      layer_on(_NAV);
      // TODO moi
      // register_mods(MOD_BIT_LSHIFT);
      // add_mods(MOD_BIT_LSHIFT);
      // tap_code(KC_PSCR);
      // TODO moi
      break;
    case DOUBLE_HOLD :
      layer_on(_F_KEYS);
      // TODO moi
      // register_mods(MOD_BIT_LSHIFT);
      // add_mods(MOD_BIT_LSHIFT);
      // tap_code(KC_PSCR);
      // TODO moi
      break;
    case DOUBLE_TAP: 
      //check to see if the layer is already set
      if (layer_state_is(_LATEX)) {
        //if already set, then switch it off
        layer_off(_LATEX);
      } else { 
        //if not already set, then switch the layer on
        // layer_clear();
        layer_move(_COLEMAK_FR);
        layer_on(_LATEX);
      }
      break;
  }
}

void nav_fx_reset (tap_dance_state_t *state, void *user_data) {
  //if the key was held down and now is released then switch off the layer
  if (nav_tap_state.state==SINGLE_HOLD) {
    layer_off(_NAV);
    // unregister_mods(MOD_BIT_LSHIFT);
  }
  if (nav_tap_state.state==DOUBLE_HOLD) {
    layer_off(_F_KEYS);
    // unregister_mods(MOD_BIT_LSHIFT);
  }
  nav_tap_state.state = 0;
}

// %%%%%%%%%%%%%%%%% END NAV_F_KEYS TAPDANCE %%%%%%%%%%%%%%%%%

// ================= ENT TAPDANCE ================
//Functions that control what our tap dance key does
void ent_finished (tap_dance_state_t *state, void *user_data) {
  ent_tap_state.state = ma_cur_dance(state);
  switch (ent_tap_state.state) {
    case SINGLE_TAP:
      // // if (IS_LAYER_ON(_ACCENTS)) {
      // //   SS_DOWN(X_LSFT);
      // //   tap_code(KC_ENT);
      // //   SS_UP(X_LSFT);
      // // } else {
      //   tap_code(KC_ENT);
      // // }

      if (IS_LAYER_ON(_ACCENTS)) {
        SEND_STRING(SS_LSFT(SS_TAP(X_ENT)));
      } else {
        tap_code(KC_ENT);
      }
      break;
    case SINGLE_HOLD:
      if (IS_LAYER_ON(_ACCENTS)) {
        layer_on(_RGB);
      } else {
        layer_on(_REG_SPE);
      }
      // TODO moi
      // register_mods(MOD_BIT_LSHIFT);
      // add_mods(MOD_BIT_LSHIFT);
      // tap_code(KC_PSCR);
      // TODO moi
      break;
    // case DOUBLE_TAP: 
    //   //check to see if the layer is already set
    //   if (layer_state_is(_CAPS_LOCK)) {
    //     //if already set, then switch it off
    //     layer_off(_CAPS_LOCK);
    //   } else { 
    //     //if not already set, then switch the layer on
    //     layer_on(_CAPS_LOCK);
    //   }
    //   break;
    // // case DOUBLE_HOLD:
    // //   tap_code(KC_M);
  }
}

void ent_reset (tap_dance_state_t *state, void *user_data) {
  //if the key was held down and now is released then switch off the layer
  if (ent_tap_state.state==SINGLE_HOLD) {
    layer_off(_REG_SPE);
    layer_off(_RGB);
  }
  ent_tap_state.state = 0;
}
// %%%%%%%%%%%%%%%%% END ENT TAPDANCE %%%%%%%%%%%%%%%%%

//Associate our tap dance key with its functionality
tap_dance_action_t tap_dance_actions[] = {
  [TD_CAPS_LCK] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, sft_finished, sft_reset)
  ,[TD_NAV_FX_KEYS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, nav_fx_finished, nav_fx_reset)
  ,[TD_ENT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ent_finished, ent_reset)
};
// --------------------------END OF TAP DANCE FEATURES------------------------------

#define MY_LSFT TD(TD_CAPS_LCK)
#define MY_NAV TD(TD_NAV_FX_KEYS)
#define MY_ENT TD(TD_ENT)