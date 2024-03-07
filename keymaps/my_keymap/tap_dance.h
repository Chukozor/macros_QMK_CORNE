// --------------------------TAP DANCE FEATURES------------------------------
typedef struct {
  bool is_press_action;
  int state;
} tap;

//Define a type for as many tap dance states as you need
enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3
};

enum {
  CAPS_LCK = 0     //Our custom tap dance key; add any other tap dance keys to this enum 
};

//Declare the functions to be used with your tap dance key(s)

//Function associated with all tap dances
int cur_dance (tap_dance_state_t *state);

//Functions associated with individual tap dances
void sft_finished (tap_dance_state_t *state, void *user_data);
void sft_reset (tap_dance_state_t *state, void *user_data);
// -------------------------------------------------------------------------
//Determine the current tap dance state
int cur_dance (tap_dance_state_t *state) {
  if (state->count == 1) {
    if (!state->pressed) {
      return SINGLE_TAP;
    } else {
      return SINGLE_HOLD;
    }
  } else if (state->count == 2) {
    return DOUBLE_TAP;
  }
  else return 8;
}

//Initialize tap structure associated with example tap dance key
static tap ql_tap_state = {
  .is_press_action = true,
  .state = 0
};

//Functions that control what our tap dance key does
void sft_finished (tap_dance_state_t *state, void *user_data) {
  ql_tap_state.state = cur_dance(state);
  switch (ql_tap_state.state) {
    case SINGLE_TAP: 
      tap_code(KC_QUOT); 
      break;
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
  }
}

void sft_reset (tap_dance_state_t *state, void *user_data) {
  //if the key was held down and now is released then switch off the layer
  if (ql_tap_state.state==SINGLE_HOLD) {
    layer_off(_SFT_COLEMAK_FR);
    unregister_mods(MOD_BIT_LSHIFT);
  }
  ql_tap_state.state = 0;
}

//Associate our tap dance key with its functionality
tap_dance_action_t tap_dance_actions[] = {
  [CAPS_LCK] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, sft_finished, sft_reset)
};
// --------------------------END OF TAP DANCE FEATURES------------------------------