// // const uint16_t PROGMEM go_in_bootloader_mod[] = {KC_RCTL, FR_AT, KC_DEL, COMBO_END};
// // const uint16_t PROGMEM comment_vscode[] = {KC_LCTL, LM(LAYER_SHIFT, MOD_LSFT), FR_SLSH, COMBO_END};
// // const uint16_t PROGMEM go_to_accents_autres[] = {LM(LAYER_ACCENTS_GRAVE, MOD_LALT), LM(LAYER_ACCENTS_AIGUE, MOD_RALT), COMBO_END};
// // const uint16_t PROGMEM test_combo2[] = {KC_C, KC_D, COMBO_END};
// const uint16_t PROGMEM switch_to_qwerty_fr[] = {KC_LSFT, KC_LCTL, KC_TAB, KC_BSPC};
// const uint16_t PROGMEM switch_to_qwerty_reg[] = {KC_LSFT, KC_LCTL, KC_TAB, KC_QUOT};
// const uint16_t PROGMEM switch_to_colemak_fr[] = {KC_LSFT, KC_LCTL, KC_TAB, KC_ESC};
// const uint16_t PROGMEM switch_to_colemak_reg[] = {KC_LSFT, KC_LCTL, KC_TAB, KC_ESC};
// combo_t key_combos[] = {
//     // COMBO(go_in_bootloader_mod, QK_BOOT),
//     // COMBO(comment_vscode, MY_COMMENT),
//     // COMBO(go_to_accents_autres, OSL(LAYER_ACCENTS_AUTRES)),
//     // COMBO(test_combo2, LCTL(KC_Z)), // keycodes with modifiers are possible too!
//     // COMBO(test_combo2, LCTL(KC_Z)), // keycodes with modifiers are possible too!
//     COMBO(switch_default_layer, TO(1)),
// };



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

  }
  return true;
}
