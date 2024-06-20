#pragma once

// #define LEAST TT(0)

#define HT_E     TT(16)
#define HT_C     TT(17)
#define HT_A     TT(18)
#define HT_U     TT(19)
#define HT_I     TT(20)
#define HT_O     TT(21)
#define CSTM_ENT TT(22)
// #define HT_SPC   TT(23)
// #define HT_T     TT(22)
// #define HT_SLSH  TT(22)
// #define HT_BSLSH TT(23)
#define MY_ESC  TT(24)
#define MY_BNAV TT(25)
#define WEB_TAB TT(26)

// #define COMBO_SHIFT  TT(25)
// #define CUSTOM_OSL_WITH_MOD  TT(26)

// #define MOST TT(31)

#define MO_ACC MO(_ACCENTS)
#define MO_NUM MO(_NUMPAD)
#define MO_RGB MO(_RGB)
#define MO_NAV MO(_NAV)
// #define MY_NAV MO(_NAV)
// #define MO_SPE MO(_SPE)
#define HT_ENT LT(_REG_SPE, KC_ENT)
#define HT_SPC LT(_ACCENTS, KC_SPC)
// #define MY_LCTL KC_LCTL
// #define MY_LSFT LM(_SFT_COLEMAK_FR, MOD_LSFT)
#define MO_COLFR TO(_COLEMAK_FR)
// #define MO_GAMING TO(_GAMING)

#define IMGLASS_CP LCTL(LSFT(KC_C))


// #define MO_QWEREG TO(_QWERTY_REG)

// #define MY_LCTL ACTION_TAP_DANCE_DOUBLE(KC_LCTL, KC_ESC)

// enum {
//  TD_Q=0,

// //  CT_CLN,
// //  CT_EGG,
// //  CT_FLSH,
// //  X_TAP_DANCE
// };

enum layers{
    _COLEMAK_FR,
    // _GAMING,
    // _LATEX,
    _SFT_COLEMAK_FR,
    _CAPS_LOCK,
    _OSL_SHIFT,
    // _F_KEYS,
    // _WEB_BROWSER,
    // _NOTHING_FOR_THE_MOMENT,
    // _SPE,
    _NAV,
    _OP_NAV,
    _ACCENTS,
    _REG_SPE,
    _MULTIMEDIA,
    _RGB,
    _RIEN
};

enum custom_keycodes {
    MY_QUOTE = SAFE_RANGE,
    MY_SLH,
    MY_BSLH,
    MY_DOLL,
    MY_DIESE,
    MY_EURO,
    MY_TILD,
    MY_BQUOT,
    C_CEDIL,
    MY_OCIRC,
    MY_PRT_S,
    MY_PRT_Z,
    MY_PRT_P,
    MY_COMENT,
    MY_COPY,
    MY_PASTE,
    MY_CUT,
    MY_UNDO,
    MY_REDO,
    MY_SAVE,
    // MY_SRCH,
    MY_PIPE,
    // MY_PVRGL,
    // MY_TWO_P,
    // MY_EXCLM,
    // ESC_TAB,
    // MY_PVIRG,
    MY_PMNS,
    MY_PPLS,
    MY_PSLS,
    MY_PAST,
    MY_SOLU,
    WEB_G,
    WEB_D,
    SEL_ALL,
    TEST1,
    TEST2,
    TEST3,
    TEST4,
    TEST5,
    E_AIGU,
};