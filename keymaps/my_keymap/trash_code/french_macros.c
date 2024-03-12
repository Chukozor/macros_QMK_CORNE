#include "french_symbols.h"


#define HT_E TT(16)
#define HT_C TT(17)
#define HT_A TT(18)
#define HT_U TT(19)
#define HT_I TT(20)
#define HT_O TT(21)

case HT_E:
	if (record->tap.count) { // tapped
		if (!record->event.pressed) {
			return false;
		}
		
		if (is_grave_layer()) {
			tap_e_grave();
		} else {
			tap_code(KC_E);
		}
	} else { // held
		if (!record->event.pressed) {
			return false;
		}
		
		if (is_grave_layer()) {
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
		
		if (is_grave_layer()) {
			tap_u_grave();
		} else {
			tap_code(KC_U);
		}
	} else {
		if (!record->event.pressed) {
			return false;
		}
		
		if (is_grave_layer()) {
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
		
		if (is_grave_layer()) {
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
		
		if (is_grave_layer()) {
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