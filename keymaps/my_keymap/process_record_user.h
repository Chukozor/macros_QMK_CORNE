bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        
        case HT_E:
	        if (record->tap.count) { // tapped
	        	if (!record->event.pressed) {
              // your logic when released
	        		return false;
	        	}

	        	if (is_accent_layer()) {
	        		tap_e_aigue();
	        	} else {
	        		tap_code(KC_E);
	        	}
	        } else { // held
	        	if (!record->event.pressed) {
              // your logic when released
	        		return false;
	        	}
            
            if (record->tap.interrupted) {
              if (is_accent_layer()) {
                tap_e_aigue();
              } else {
                tap_code(KC_E);
              }
            } else {
              if (is_accent_layer()) {
	        	  	tap_e_circ();
	        	  } else {
	        	  	tap_e_grave();
	        	  }
            }
	        }
	
	        return false;
            
        case HT_C:
	        // if (record->tap.count) { // tapped
	        	if (!record->event.pressed) {
	        		return false;
	        	}

	        	if (is_accent_layer()) {
	        		tap_c_ced();
	        	} else {
	        		tap_code(KC_C);
	        	}
	        // } else { // held
	        	  // if (!record->event.pressed) {
	        	  // 	return false;
	        	  // }
              // if (is_accent_layer()) {
	        		//   tap_code(KC_C);
	        	  // } else {
	        		//   tap_code(KC_C);
	        	  // }
	        // }
	        return false;

        case C_CEDIL:
	        // if (record->tap.count) { // tapped
	        	if (!record->event.pressed) {
	        		return false;
	        	}
	        		tap_c_ced();
	        // } else { // held
	        	  // if (!record->event.pressed) {
	        	  // 	return false;
	        	  // }
              // if (is_accent_layer()) {
	        		//   tap_code(KC_C);
	        	  // } else {
	        		//   tap_code(KC_C);
	        	  // }
	        // }
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
          if (record->tap.count) { // tapped
	        	if (!record->event.pressed) {
	        		return false;
	        	}

	        	if (is_accent_layer()) {
	        		tap_u_grave();
	        	} else {
	        		tap_code(KC_U);
	        	}
	        } else { // held

            if (record->event.pressed) {
              // logic when pressed
              if (record->tap.interrupted) {
                // logic when interrupted
                tap_u_grave();
              } else {
                // logic when not interrupted
                if (is_accent_layer()) {
	        		    tap_u_circ();
	        	}
              }
            } else {
              // logic when released
              return false;
            }
	        }
	        return false;
        
        case HT_I:
	        if (record->tap.count) { // Tap
	        	if (!record->event.pressed) {
              // your logic when pressed
	        		return false;
	        	}
        
	        	if (is_accent_layer()) {
	        		tap_i_circ();
	        	} else {
	        		tap_code(KC_I);
	        	}
	        } else { // held

            if (record->event.pressed) {
              // logic when pressed
              if (record->tap.interrupted) {
                // logic when interrupted
                tap_i_circ();
              } else {
                // logic when not interrupted
                if (is_accent_layer()) {
	        		    tap_i_trema();
	        	}
              }
            } else {
              // logic when released
              return false;
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
              if (is_accent_layer()) {
        			  tap_o_circ();
              }
        		}
        	}
        
        	return false;

        case MY_OCIRC:
        	// if (record->tap.count) {
        		if (!record->event.pressed) {
        			return false;
        		}
        
        		// if (is_accent_layer()) {
        			tap_o_circ();
        		// } else {
        			// tap_code(KC_O);
        		// }
        	// } else {
        	// 	if (record->event.pressed) {
          //     if (is_accent_layer()) {
        	// 		  tap_o_circ();
          //     }
        	// 	}
        	// }
        
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

        // case MY_SLASHES:
        // // if (record->event.pressed && get_mods() & MOD_BIT(KC_LCTL)) {
        //   if (record->event.pressed) {
        //     if (IS_LAYER_ON(LAYER_SHIFT)){
        //         unregister_mods(MOD_BIT_LSHIFT);
        //         unregister_mods(MOD_BIT_RSHIFT);
        //         SEND_STRING(SS_LALT(SS_TAP(X_KP_4) SS_TAP(X_KP_7))); // 47 Slash
        //       } else {
        //       if (get_mods() & MOD_BIT(KC_LCTL)) {
        //         // unregister_mods(MOD_BIT_LCTRL);
        //         SEND_STRING(SS_LCTL(SS_TAP(X_DOT)));
        //         // SEND_STRING(SS_LALT(SS_TAP(X_KP_5) SS_TAP(X_KP_8))); // 58 deux points
        //         // register_mods(MOD_BIT_LCTRL);
        //       } else {
        //         SEND_STRING(SS_LALT(SS_TAP(X_KP_9) SS_TAP(X_KP_2))); // 92 backslash 
        //       }
        //     }
        // } else {
        //   unregister_mods(MOD_BIT_LSHIFT);
        //   unregister_mods(MOD_BIT_RSHIFT);
        // }
        // return false;
        // break;

        case MY_SLH:
          if (record->event.pressed) {
            add_mods(MOD_BIT_LALT);
            tap_code(KC_KP_4);
            tap_code(KC_KP_7);
            unregister_mods(MOD_BIT_LALT);
            // here we override its «press» behavior (hence, return false)
            return false;
          } else {
            // here we don't alter its «release» default behavior (hence, return true)
            return true;
          }
        case MY_BSLH:
          if (record->event.pressed) {
            add_mods(MOD_BIT_LALT);
            tap_code(KC_KP_8);
            unregister_mods(MOD_BIT_LALT);
            // here we override its «press» behavior (hence, return false)
            return false;
          } else {
            // here we don't alter its «release» default behavior (hence, return true)
            return true;
          }
        case MY_DOLL:
          if (record->event.pressed) {
            add_mods(MOD_BIT_LALT);
            tap_code(KC_KP_3);
            tap_code(KC_KP_6);
            unregister_mods(MOD_BIT_LALT);
            // here we override its «press» behavior (hence, return false)
            return false;
          } else {
            // here we don't alter its «release» default behavior (hence, return true)
            return true;
          }
        case MY_DIESE:
          if (record->event.pressed) {
            add_mods(MOD_BIT_LALT);
            tap_code(KC_KP_3);
            tap_code(KC_KP_5);
            unregister_mods(MOD_BIT_LALT);
            // here we override its «press» behavior (hence, return false)
            return false;
          } else {
            // here we don't alter its «release» default behavior (hence, return true)
            return true;
          }
        case MY_EURO:
          if (record->event.pressed) {
            add_mods(MOD_BIT_LALT);
            tap_code(KC_KP_0);
            tap_code(KC_KP_1);
            tap_code(KC_KP_2);
            tap_code(KC_KP_8);
            unregister_mods(MOD_BIT_LALT);
            // here we override its «press» behavior (hence, return false)
            return false;
          } else {
            // here we don't alter its «release» default behavior (hence, return true)
            return true;
          }
        case MY_TILD:
          if (record->event.pressed) {
            add_mods(MOD_BIT_LALT);
            tap_code(KC_KP_1);
            tap_code(KC_KP_2);
            tap_code(KC_KP_6);
            unregister_mods(MOD_BIT_LALT);
            // here we override its «press» behavior (hence, return false)
            return false;
          } else {
            // here we don't alter its «release» default behavior (hence, return true)
            return true;
          }
        case MY_BQUOT:
          if (record->event.pressed) {
            add_mods(MOD_BIT_LALT);
            tap_code(KC_KP_9);
            tap_code(KC_KP_6);
            unregister_mods(MOD_BIT_LALT);
            // here we override its «press» behavior (hence, return false)
            return false;
          } else {
            // here we don't alter its «release» default behavior (hence, return true)
            return true;
          }
        case MY_PRT_S:
          if (record->event.pressed) {
            tap_code(KC_PSCR);
            // here we override its «press» behavior (hence, return false)
            return false;
          } else {
            // here we don't alter its «release» default behavior (hence, return true)
            return true;
          }
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
        case MY_COPY:
          if (record->event.pressed) {
            add_mods(MOD_BIT_LCTRL);
            tap_code(KC_C);
            unregister_mods(MOD_BIT_LCTRL);
            // here we override its «press» behavior (hence, return false)
            return false;
          } else {
            // here we don't alter its «release» default behavior (hence, return true)
            return true;
          }
        case MY_CUT:
          if (record->event.pressed) {
            add_mods(MOD_BIT_LCTRL);
            tap_code(KC_X);
            unregister_mods(MOD_BIT_LCTRL);
            // here we override its «press» behavior (hence, return false)
            return false;
          } else {
            // here we don't alter its «release» default behavior (hence, return true)
            return true;
          }
        case MY_PASTE:
          if (record->event.pressed) {
            add_mods(MOD_BIT_LCTRL);
            tap_code(KC_V);
            unregister_mods(MOD_BIT_LCTRL);
            // here we override its «press» behavior (hence, return false)
            return false;
          } else {
            // here we don't alter its «release» default behavior (hence, return true)
            return true;
          }
        case MY_UNDO:
          if (record->event.pressed) {
            add_mods(MOD_BIT_LCTRL);
            tap_code(FR_Z);
            unregister_mods(MOD_BIT_LCTRL);
            // here we override its «press» behavior (hence, return false)
            return false;
          } else {
            // here we don't alter its «release» default behavior (hence, return true)
            return true;
          }
        case MY_REDO:
          if (record->event.pressed) {
            add_mods(MOD_BIT_LCTRL);
            tap_code(KC_Y);
            unregister_mods(MOD_BIT_LCTRL);
            // here we override its «press» behavior (hence, return false)
            return false;
          } else {
            // here we don't alter its «release» default behavior (hence, return true)
            return true;
          }
        case MY_SAVE:
          if (record->event.pressed) {
            add_mods(MOD_BIT_LCTRL);
            tap_code(KC_S);
            unregister_mods(MOD_BIT_LCTRL);
            // here we override its «press» behavior (hence, return false)
            return false;
          } else {
            // here we don't alter its «release» default behavior (hence, return true)
            return true;
          }
        case MY_PIPE:
          if (record->event.pressed) {
            // add_mods(MOD_BIT_LCTRL);
            add_mods(MOD_BIT_RALT);
            tap_code(KC_6);
            // tap_code(KC_KP_9);
            // tap_code(KC_KP_6);
            unregister_mods(MOD_BIT_RALT);
            // unregister_mods(MOD_BIT_LCTRL);
            // here we override its «press» behavior (hence, return false)
            return false;
          } else {
            // here we don't alter its «release» default behavior (hence, return true)
            return true;
          }
        
        case CSTM_ENT:
          if (record->tap.count) { // Tap
            if (record->event.pressed) {
              // your logic when pressed
              if (IS_LAYER_ON(_ACCENTS)) {
                SEND_STRING(SS_LSFT(SS_TAP(X_ENT)));
              } else {
                tap_code(KC_ENT);
              }
            }
          } else { // Hold
            if (record->event.pressed) {
              // your logic when pressed
              if (IS_LAYER_ON(_ACCENTS)) {
                layer_on(_RGB);
              } else {
                layer_on(_REG_SPE);
              }
            } else {
              // your logic when released
              layer_off(_REG_SPE);
              layer_off(_RGB);
            }
          }
          return false;

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


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // case SFT_T(KC_SPC):
        //    return g_tapping_term + 1250;
        case MY_LSFT:
            return 160;
        case HT_SPC:
            return 190;
        case MY_NAV:
            return 200;
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