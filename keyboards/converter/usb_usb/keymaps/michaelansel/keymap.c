#include QMK_KEYBOARD_H

#define _ENTRY_ KC_TRANSPARENT // Alias for the key that got us into this layer

#define BASE 0
#define NAV 2 // Navigation/Focus control
#define SYM 3 // Symbols
#define UNI 4 // Universal/media keys
#define THMB 5 // Activate basic functions of left thumb keys

#define BSPC_SYM LT(SYM, KC_BSPC)
#define DEL_NAV LT(NAV, KC_DEL)
#define SPC_THMB LT(THMB, KC_SPC)

// Mod-tap keys
#if 1
#define MT_A     LCTL_T(KC_A)
#define MT_S     LALT_T(KC_S)
#define MT_D     LGUI_T(KC_D)
#define MT_F     LSFT_T(KC_F)
#define MT_J     RSFT_T(KC_J)
#define MT_K     RGUI_T(KC_K)
#define MT_L     RALT_T(KC_L)
#define MT_SCLN  RCTL_T(KC_SCLN)
#else
#define MT_A     KC_A
#define MT_S     KC_S
#define MT_D     KC_D
#define MT_F     KC_F
#define MT_J     KC_J
#define MT_K     KC_K
#define MT_L     KC_L
#define MT_SCLN  KC_SCLN
#endif

// Hammerspoon Triggers
#define HS_WARP HYPR(KC_A) // Launch warpd
#define HS_CHRM HYPR(KC_B) // Launch Chrome
#define HS_MEET HYPR(KC_C) // Launch Meet
#define HS_TYPR HYPR(KC_D) // Launch Typora
#define HS_SLAK HYPR(KC_E) // Launch Slack
#define HS_CODE HYPR(KC_F) // Launch VS Code
#define HS_PTAB HYPR(KC_G) // Previous Tab
#define HS_NTAB HYPR(KC_H) // Next Tab
#define HS_SCRN HYPR(KC_I) // Switch Monitor Focus
#define HS_TERM HYPR(KC_J) // Launch iTerm2
#define HS_RTM  HYPR(KC_K) // Launch Remember the Milk
#define HS_SPFY HYPR(KC_L) // Launch Spotify
#define HS_SCDN HYPR(KC_M) // Scroll Down
#define HS_SCUP HYPR(KC_N) // Scroll Up
#define HS_BTN1 HYPR(KC_O) // Click Mouse Button 1
// TODO UNI-r left mouse click for selecting whatever window is already under the mouse (shortcut for single action in warpd)


typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Double tab and additional key pressed within TAPPING_TERM
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

// Tap dance enums
enum {
    TD_LTHMB
};

td_state_t cur_dance(qk_tap_dance_state_t *state);

// For the x tap dance. Put it here so it can be used in any keymap
void lthmb_finished(qk_tap_dance_state_t *state, void *user_data);
void lthmb_reset(qk_tap_dance_state_t *state, void *user_data);

// #define LTHMB TD(TD_LTHMB)
#define LTHMB BSPC_SYM

/****************************************************************************************************
*
* Keymap: Directly mirror what is received from the keyboard
*
* ,-------------------------------------------------------------------------------------------------------------------.
* | Esc    |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F8  |  F9  |  F10 |  F12 | PSCR | SCRL | PAUS |  XXX |  XXX   |
* |--------+------+------+------+------+------+---------------------------+------+------+------+------+------+--------|
* | =+     |  1!  |  2@  |  3#  |  4$  |  5%  |                           |  6^  |  7&  |  8*  |  9(  |  0)  | -_     |
* |--------+------+------+------+------+------|                           +------+------+------+------+------+--------|
* | Tab    |   Q  |   W  |   E  |   R  |   T  |                           |   Y  |   U  |   I  |   O  |   P  | \|     |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* | Caps   |   A  |   S  |   D  |   F  |   G  |                           |   H  |   J  |   K  |   L  |  ;:  | '"     |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* | Shift  |   Z  |   X  |   C  |   V  |   B  |                           |   N  |   M  |  ,.  |  .>  |  /?  | Shift  |
* `--------+------+------+------+------+-------                           `------+------+------+------+------+--------'
*          | `~   | Intl | Left | Right|                                         | Up   | Down |  [{  |  ]}  |
*          `---------------------------'                                         `---------------------------'
*                                        ,-------------.         ,-------------.
*                                        | Ctrl | Alt  |         | Gui  | Ctrl |
*                                 ,------|------|------|         |------+------+------.
*                                 |      |      | Home |         | PgUp |      |      |
*                                 | BkSp | Del  |------|         |------|Return| Space|
*                                 |      |      | End  |         | PgDn |      |      |
*                                 `--------------------'         `--------------------'
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Layer TEMPLATE
  [TEMP] = LAYOUT_kinesis(
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,         XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                                                                           XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                                                                           XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                                                                           XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                                                                           XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
               XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                                                                                                 XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
                                                           XXXXXXX,   XXXXXXX,                                                     XXXXXXX,   XXXXXXX,
                                                                      XXXXXXX,                                                     XXXXXXX,
                                                XXXXXXX,   XXXXXXX,   XXXXXXX,                                                     XXXXXXX,   XXXXXXX,   XXXXXXX
  ),
*/

  [BASE] = LAYOUT_kinesis(
    KC_ESC,    KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,     KC_F6,     KC_F7,     KC_F8,           KC_F9,     KC_F10,    KC_F11,    KC_F12,    XXXXXXX,   XXXXXXX,   QK_BOOT,
    KC_EQL,    KC_1,      KC_2,      KC_3,      KC_4,      KC_5,                                                                              KC_6,      KC_7,      KC_8,      KC_9,      KC_0,      KC_MINS,
    KC_TAB,    KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,                                                                              KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,      KC_BSLS,
    KC_NO,     MT_A,      MT_S,      MT_D,      MT_F,      KC_G,                                                                              KC_H,      MT_J,      MT_K,      MT_L,      MT_SCLN,   KC_QUOT,
    KC_LSFT,   KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,                                                                              KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_SLSH,   KC_RSFT,
               XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                                                                                                 XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
              //  KC_LCTL,   KC_LALT,   KC_LGUI,   KC_LSFT,                                                                                                 KC_RSFT,   KC_RGUI,   KC_RALT,   KC_RCTL,
                                                           OSL(UNI),  XXXXXXX,                                                     XXXXXXX,   XXXXXXX,
                                                                      XXXXXXX,                                                     XXXXXXX,
                                                LTHMB,     MO(NAV),   KC_BTN1,                                                     XXXXXXX,   KC_ENTER,  SPC_THMB
  ),

  [THMB] = LAYOUT_kinesis(
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,         XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                                                                           XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                                                                           XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                                                                           XXXXXXX,   KC_RSFT,   KC_RGUI,   KC_RALT,   KC_RCTL,   XXXXXXX,
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                                                                           XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
               XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                                                                                                 XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
                                                           XXXXXXX,   XXXXXXX,                                                     XXXXXXX,   XXXXXXX,
                                                                      XXXXXXX,                                                     XXXXXXX,
                                                KC_BSPC,   KC_DEL,    XXXXXXX,                                                     XXXXXXX,   XXXXXXX,   _ENTRY_
  ),

  [NAV] = LAYOUT_kinesis(
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,         XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                                                                           XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,  XXXXXXX,
    XXXXXXX,   XXXXXXX,   HS_SCRN,   XXXXXXX,   HS_WARP,   XXXXXXX,                                                                           XXXXXXX,   HS_PTAB,   KC_ESC,    HS_NTAB,   XXXXXXX,  XXXXXXX,
    XXXXXXX,   KC_LCTL,   KC_LALT,   KC_LGUI,   KC_LSFT,   XXXXXXX,                                                                           KC_LEFT,   KC_DOWN,   KC_UP,     KC_RIGHT,  XXXXXXX,  XXXXXXX,
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                                                                           KC_HOME,   KC_PGDN,   KC_PGUP,   KC_END,    XXXXXXX,  XXXXXXX,
               XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                                                                                                 HS_SCDN,   HS_SCUP,   HS_BTN1,   XXXXXXX,
                                                           XXXXXXX,  XXXXXXX,                                                      XXXXXXX,   XXXXXXX,
                                                                     XXXXXXX,                                                      XXXXXXX,
                                                XXXXXXX,   _ENTRY_,  XXXXXXX,                                                      XXXXXXX,   XXXXXXX,  XXXXXXX
  ),

  [SYM] = LAYOUT_kinesis(
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,         XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                                                                           KC_CIRC,   KC_AMPR,   KC_ASTR,   XXXXXXX,   XXXXXXX,   XXXXXXX,
    XXXXXXX,   KC_EXLM,   KC_AT,     KC_HASH,   KC_DLR,    KC_PERC,                                                                           KC_ESC,    KC_LCBR,   KC_TAB,    KC_RCBR,   XXXXXXX,   XXXXXXX,
    XXXXXXX,   KC_LCTL,   KC_LALT,   KC_LGUI,   KC_LSFT,   XXXXXXX,                                                                           KC_PIPE,   KC_LPRN,   KC_MINUS,  KC_RPRN,   XXXXXXX,   XXXXXXX,
    XXXXXXX,   KC_BSLS,   XXXXXXX,   XXXXXXX,   XXXXXXX,   KC_TILD,                                                                           KC_GRV,    KC_LBRC,   KC_UNDS,   KC_RBRC,   XXXXXXX,   XXXXXXX,
               _______,   _______,   _______,   _______,                                                                                                 _______,   _______,   _______,   _______,
                                                           XXXXXXX,   XXXXXXX,                                                     XXXXXXX,   XXXXXXX,
                                                                      XXXXXXX,                                                     XXXXXXX,
                                                _ENTRY_,   XXXXXXX,   XXXXXXX,                                                     XXXXXXX,   XXXXXXX,   XXXXXXX
  ),

  [UNI] = LAYOUT_kinesis(
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,         XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                                                                           XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                                                                           HS_CHRM,   HS_MEET,   HS_TYPR,   HS_SLAK,   HS_CODE,   HS_TERM,
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                                                                           HS_RTM,    KC_MPRV,   KC_MPLY,   KC_MNXT,   HS_SPFY,   XXXXXXX,
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                                                                           XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
               XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                                                                                                 XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
                                                           _ENTRY_,   XXXXXXX,                                                     XXXXXXX,   XXXXXXX,
                                                                      XXXXXXX,                                                     XXXXXXX,
                                                XXXXXXX,   XXXXXXX,   XXXXXXX,                                                     XXXXXXX,   XXXXXXX,   XXXXXXX
  ),
  
  // Move app selections do a dedicated app layer separate from the Universal layer? Put mouse keys on the universal layer.

};


// Needs a lot of setup: https://docs.qmk.fm/#/feature_unicode?id=unicode-support
// Maybe just use Hammerspoon instead to output the emoji?

// enum unicode_names {
//     BANG,
//     IRONY,
//     SNEK,
//     THUMBS_UP,
// };

// const uint32_t PROGMEM unicode_map[] = {
//     [BANG]  = 0x203D,  // ‽
//     [IRONY] = 0x2E2E,  // ⸮
//     [SNEK]  = 0x1F40D, // 🐍
//     [THUMBS_UP] = 0x1F44D // 
// };

// Replace Option-v with a thumbs up instead of square root/checkmark
// const key_override_t delete_key_override = ko_make_basic(MOD_MASK_ALT, KC_V, UC(THUMBS_UP));

// // This globally defines all key overrides to be used
// const key_override_t **key_overrides = (const key_override_t *[]){
//     &delete_key_override,
//     NULL // Null terminate the array of overrides!
// };


// void caps_word_set_user(bool active) {
//     if (active) {
//         // Do something when Caps Word activates.
//         led_set()
//     } else {
//         // Do something when Caps Word deactivates.
//     }
// }


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MT_A:
        case MT_S:
        case MT_D:
        case MT_F:
        case MT_J:
        case MT_K:
        case MT_L:
        case MT_SCLN:
            return 250; // This is how long you need to hold for just a bare modifier (e.g. for Cmd-Click); PERMISSIVE_HOLD will allow fast keyboard shortcuts as long as the modifier is released last.
        default:
            return TAPPING_TERM;
    }
}


// const uint16_t PROGMEM combo_fast_backspace[] = {SPC_THMB, MO(SYM), COMBO_END};
// combo_t key_combos[] = {
//     COMBO(combo_fast_backspace, KC_BSPC),
// };
// uint16_t COMBO_LEN = sizeof(key_combos) / sizeof(key_combos[0]);

// bool fn_held;
// void dance_layers(qk_tap_dance_state_t *state, void *user_data)
// {
//   if (state->pressed)
//   {
//     layer_on(_FL);
//     fn_held = true;
//   }
//   switch (state->count)
//   {
//   case 1: //off all layers, just base on
//     if (!state->pressed)
//     {
//       layer_off(_ML);
//       layer_off(_FL);
//       fn_held = false;
//     }
//     break;
//   case 2: //function layer on
//     layer_on(_FL);
//     layer_off(_ML);
//     break;
//   case 3: //mouse layer on
//     layer_on(_ML);
//     layer_off(_FL);
//     break;
//   }
// }
// void dance_layers_finish(qk_tap_dance_state_t *state, void *user_data)
// {
//   if (fn_held)
//   {
//     layer_off(_FL);
//     fn_held = false;
//   }
// }


/* Return an integer that corresponds to what kind of tap dance should be executed.
 *
 * How to figure out tap dance state: interrupted and pressed.
 *
 * Interrupted: If the state of a dance is "interrupted", that means that another key has been hit
 *  under the tapping term. This is typically indicitive that you are trying to "tap" the key.
 *
 * Pressed: Whether or not the key is still being pressed. If this value is true, that means the tapping term
 *  has ended, but the key is still being pressed down. This generally means the key is being "held".
 *
 * One thing that is currenlty not possible with qmk software in regards to tap dance is to mimic the "permissive hold"
 *  feature. In general, advanced tap dances do not work well if they are used with commonly typed letters.
 *  For example "A". Tap dances are best used on non-letter keys that are not hit while typing letters.
 *
 * Good places to put an advanced tap dance:
 *  z,q,x,j,k,v,b, any function key, home/end, comma, semi-colon
 *
 * Criteria for "good placement" of a tap dance key:
 *  Not a key that is hit frequently in a sentence
 *  Not a key that is used frequently to double tap, for example 'tab' is often double tapped in a terminal, or
 *    in a web form. So 'tab' would be a poor choice for a tap dance.
 *  Letters used in common words as a double. For example 'p' in 'pepper'. If a tap dance function existed on the
 *    letter 'p', the word 'pepper' would be quite frustating to type.
 *
 * For the third point, there does exist the 'TD_DOUBLE_SINGLE_TAP', however this is not fully tested
 *
 */
td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
        else return TD_TRIPLE_HOLD;
    } else return TD_UNKNOWN;
}



// Create an instance of 'td_tap_t' for the 'lthmb' tap dance.
static td_tap_t lthmb_tapstate = {
    .is_press_action = true,
    .state = TD_NONE
};

// When a tap dance key is pressed/released
void lthmb_finished(qk_tap_dance_state_t *state, void *user_data) {
    lthmb_tapstate.state = cur_dance(state);
    switch (lthmb_tapstate.state) {
        case TD_SINGLE_TAP: set_oneshot_layer(SYM, ONESHOT_START); break;
        case TD_SINGLE_HOLD: layer_on(SYM); break;
        case TD_DOUBLE_TAP: set_oneshot_layer(NAV, ONESHOT_START); break;
        case TD_DOUBLE_HOLD: layer_on(NAV); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP: set_oneshot_layer(NAV, ONESHOT_START); break;
        case TD_TRIPLE_TAP: set_oneshot_layer(UNI, ONESHOT_START); break;
        case TD_TRIPLE_HOLD: layer_on(UNI); break;
        default: break;
    }
}

// When TAPPING_TERM expires AND tap dance key is released
void lthmb_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (lthmb_tapstate.state) {
        case TD_SINGLE_TAP: clear_oneshot_layer_state(ONESHOT_PRESSED); break;
        case TD_SINGLE_HOLD: layer_off(SYM); break;
        case TD_DOUBLE_TAP: clear_oneshot_layer_state(ONESHOT_PRESSED); break;
        case TD_DOUBLE_HOLD: layer_off(NAV); break;
        case TD_DOUBLE_SINGLE_TAP: clear_oneshot_layer_state(ONESHOT_PRESSED); break;
        case TD_TRIPLE_TAP: clear_oneshot_layer_state(ONESHOT_PRESSED); break;
        case TD_TRIPLE_HOLD: layer_off(UNI); break;
        default: break;
    }
    lthmb_tapstate.state = TD_NONE;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_LTHMB] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lthmb_finished, lthmb_reset)
};
