// TAP DANCE

// void dance_layers_finished (tap_dance_state_t *state, void *user_data) {
// if (state->count == 2) {
//     layer_move(_COLEMAK_FR);
//   } else if (state->count == 1) {
//       // if (IS_LAYER_ON(_QWERTY_REG)) {
//       // SEND_STRING(SS_TAP(X_Q));
//       // } else {
//       SEND_STRING(SS_TAP(X_A));
//     // }
//   }
// }

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

// tap_dance_action_t tap_dance_actions[] = {
//     [TD_Q] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_layers_finished, NULL)
// };

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

// -------------------------------------------------------------------------

