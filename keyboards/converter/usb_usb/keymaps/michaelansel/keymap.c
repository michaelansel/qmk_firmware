#include QMK_KEYBOARD_H

#define _ENTRY_ KC_TRANSPARENT // Alias for the key that got us into this layer

#define BASE 0
#define NAV 2 // Navigation/Focus control
#define SYM 3 // Symbols
#define UNI 4 // Universal/media keys
#define NUM 5 // Keypad layer / Number pad

// Home row mods
#if 0
#define HR_A     LCTL_T(KC_A)
#define HR_S     LALT_T(KC_S)
#define HR_D     LGUI_T(KC_D)
#define HR_F     LSFT_T(KC_F)
#define HR_J     RSFT_T(KC_J)
#define HR_K     RGUI_T(KC_K)
#define HR_L     RALT_T(KC_L)
#define HR_SCLN  RCTL_T(KC_SCLN)
#else
#define HR_A     KC_A
#define HR_S     KC_S
#define HR_D     KC_D
#define HR_F     KC_F
#define HR_J     KC_J
#define HR_K     KC_K
#define HR_L     KC_L
#define HR_SCLN  KC_SCLN
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
#define HS_MCTR HYPR(KC_P) // Move mouse to the center of the screen
#define HS_MENU HYPR(KC_Q) // Open interactive hammerspoon menu system
// TODO UNI-r left mouse click for selecting whatever window is already under the mouse (shortcut for single action in warpd)


#ifdef TAP_DANCE_ENABLE
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
    TD_LTHMB,
    TD_CUT_COPY_PASTE,
};

td_state_t cur_dance(tap_dance_state_t *state);

// For the x tap dance. Put it here so it can be used in any keymap
void lthmb_finished(tap_dance_state_t *state, void *user_data);
void lthmb_reset(tap_dance_state_t *state, void *user_data);

// #define LTHMB TD(TD_LTHMB)
#define LTHMB MO(SYM)
#define CPY_PST TD(TD_CUT_COPY_PASTE)

#else // TAP_DANCE_ENABLE

#define LTHMB MO(SYM)
#define CPY_PST KC_NO

#endif // TAP_DANCE_ENABLE

#define LTHMB1 LTHMB
#define LTHMB2 MO(NAV)



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
    KC_ESC,    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,         XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   QK_BOOT,
    XXXXXXX,   KC_1,      KC_2,      KC_3,      KC_4,      KC_5,                                                                              KC_6,      KC_7,      KC_8,      KC_9,      KC_0,      KC_MINS,
    XXXXXXX,   KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,                                                                              KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,      KC_BSLS,
    XXXXXXX,   HR_A,      HR_S,      HR_D,      HR_F,      KC_G,                                                                              KC_H,      HR_J,      HR_K,      HR_L,      HR_SCLN,   KC_QUOT,
    KC_LSFT,   KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,                                                                              KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_SLSH,   KC_RSFT,
               XXXXXXX,   XXXXXXX,   XXXXXXX,   MO(NUM),                                                                                                 XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
              //  KC_LCTL,   KC_LALT,   KC_LGUI,   KC_LSFT,                                                                                                 KC_RSFT,   KC_RGUI,   KC_RALT,   KC_RCTL,
                                                           OSL(UNI),  HS_BTN1,                                                     HS_MCTR,   OSL(UNI),
                                                                      HS_SCUP,                                                     XXXXXXX,
                                                LTHMB1,    LTHMB2,    HS_SCDN,                                                     XXXXXXX,   KC_ENTER,  KC_SPC
  ),

  [NAV] = LAYOUT_kinesis(
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,         XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                                                                           XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,  XXXXXXX,
    XXXXXXX,   XXXXXXX,   HS_SCRN,   XXXXXXX,   HS_WARP,   XXXXXXX,                                                                           XXXXXXX,   HS_PTAB,   XXXXXXX,   HS_NTAB,   XXXXXXX,  XXXXXXX,
    XXXXXXX,   KC_LCTL,   KC_LALT,   KC_LGUI,   KC_LSFT,   XXXXXXX,                                                                           KC_LEFT,   KC_DOWN,   KC_UP,     KC_RIGHT,  XXXXXXX,  XXXXXXX,
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                                                                           KC_HOME,   KC_PGDN,   KC_PGUP,   KC_END,    XXXXXXX,  XXXXXXX,
               XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                                                                                                 HS_SCDN,   HS_SCUP,   HS_BTN1,   HS_MCTR,
                                                           XXXXXXX,  XXXXXXX,                                                      XXXXXXX,   XXXXXXX,
                                                                     XXXXXXX,                                                      XXXXXXX,
                                                XXXXXXX,   _ENTRY_,  XXXXXXX,                                                      XXXXXXX,   S(KC_ENT), XXXXXXX
  ),

  [SYM] = LAYOUT_kinesis(
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,         XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                                                                           KC_CIRC,   KC_AMPR,   KC_ASTR,   XXXXXXX,   XXXXXXX,   XXXXXXX,
    XXXXXXX,   KC_EXLM,   KC_AT,     KC_HASH,   KC_DLR,    KC_PERC,                                                                           KC_ESC,    KC_LCBR,   KC_TAB,    KC_RCBR,   KC_BSPC,   KC_DEL,
    XXXXXXX,   KC_LCTL,   KC_LALT,   KC_LGUI,   KC_LSFT,   KC_EQL,                                                                            KC_PIPE,   KC_LPRN,   KC_MINUS,  KC_RPRN,   KC_COLN,   XXXXXXX,
    XXXXXXX,   KC_BSLS,   KC_LT,     CPY_PST,   KC_GT,     KC_TILD,                                                                           KC_GRV,    KC_LBRC,   KC_UNDS,   KC_RBRC,   XXXXXXX,   XXXXXXX,
               _______,   _______,   _______,   MO(NUM),                                                                                                 _______,   _______,   _______,   _______,
                                                           XXXXXXX,   XXXXXXX,                                                     XXXXXXX,   KC_DEL,
                                                                      XXXXXXX,                                                     XXXXXXX,
                                                _ENTRY_,   XXXXXXX,   XXXXXXX,                                                     XXXXXXX,   G(KC_ENT), KC_BSPC
  ),

  [NUM] = LAYOUT_kinesis(
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,         XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                                                                           XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                                                                           XXXXXXX,   KC_7,      KC_8,      KC_9,      XXXXXXX,   XXXXXXX,
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                                                                           XXXXXXX,   KC_4,      KC_5,      KC_6,      KC_MINUS,  XXXXXXX,
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                                                                           XXXXXXX,   KC_1,      KC_2,      KC_3,      KC_SLSH,   XXXXXXX,
               XXXXXXX,   XXXXXXX,   XXXXXXX,   _ENTRY_,                                                                                                 KC_0,      XXXXXXX,   KC_DOT,    XXXXXXX,
                                                           XXXXXXX,   XXXXXXX,                                                     XXXXXXX,   XXXXXXX,
                                                                      XXXXXXX,                                                     XXXXXXX,
                                                _ENTRY_,   XXXXXXX,   XXXXXXX,                                                     XXXXXXX,   XXXXXXX,   KC_0
  ),

  [UNI] = LAYOUT_kinesis(
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,         XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                                                                           XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
    XXXXXXX,   XXXXXXX,   XXXXXXX,   HS_MENU,   XXXXXXX,   XXXXXXX,                                                                           HS_CHRM,   HS_MEET,   HS_TYPR,   HS_SLAK,   HS_CODE,   HS_TERM,
    XXXXXXX,   OSM(MOD_LCTL),   OSM(MOD_LALT),   OSM(MOD_LGUI),   OSM(MOD_LSFT),   XXXXXXX,                                                                           HS_RTM,    KC_MPRV,   KC_MPLY,   KC_MNXT,   HS_SPFY,   XXXXXXX,
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                                                                           XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
               XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                                                                                                 XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
                                                           HS_MENU,   XXXXXXX,                                                     XXXXXXX,   _ENTRY_,
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
        case HR_A:
        case HR_S:
        case HR_D:
        case HR_F:
        case HR_J:
        case HR_K:
        case HR_L:
        case HR_SCLN:
            return 250; // This is how long you need to hold for just a bare modifier (e.g. for Cmd-Click); PERMISSIVE_HOLD will allow fast keyboard shortcuts as long as the modifier is released last.
        default:
            return TAPPING_TERM;
    }
}

#ifdef COMBO_ENABLE

const uint16_t PROGMEM combo_osm_ctl[] = {HR_A, HR_SCLN, COMBO_END};
const uint16_t PROGMEM combo_osm_alt[] = {HR_S, HR_L, COMBO_END};
const uint16_t PROGMEM combo_osm_gui[] = {HR_D, HR_K, COMBO_END};
const uint16_t PROGMEM combo_osm_sft[] = {HR_F, HR_J, COMBO_END};
const uint16_t PROGMEM combo_rthumbs[] = {KC_ENTER,  KC_SPC, COMBO_END};
const uint16_t PROGMEM combo_lthumbs[] = {LTHMB1,  LTHMB2, COMBO_END};
combo_t key_combos[] = {
    // COMBO(combo_osm_ctl, OSM(MOD_LCTL)),
    // COMBO(combo_osm_alt, OSM(MOD_LALT)),
    // COMBO(combo_osm_gui, OSM(MOD_LGUI)),
    // COMBO(combo_osm_sft, OSM(MOD_LSFT)),
};
uint16_t COMBO_LEN = sizeof(key_combos) / sizeof(key_combos[0]);

// bool fn_held;
// void dance_layers(tap_dance_state_t *state, void *user_data)
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
// void dance_layers_finish(tap_dance_state_t *state, void *user_data)
// {
//   if (fn_held)
//   {
//     layer_off(_FL);
//     fn_held = false;
//   }
// }

#endif // COMBO_ENABLE

#ifdef TAP_DANCE_ENABLE
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
td_state_t cur_dance(tap_dance_state_t *state) {
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
void lthmb_finished(tap_dance_state_t *state, void *user_data) {
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
void lthmb_reset(tap_dance_state_t *state, void *user_data) {
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

tap_dance_action_t tap_dance_actions[] = {
    [TD_LTHMB] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lthmb_finished, lthmb_reset),
    [TD_CUT_COPY_PASTE] = ACTION_TAP_DANCE_DOUBLE(G(KC_C), G(KC_V)),
};

#endif // TAP_DANCE_ENABLE

typedef struct {
    bool layers[16];
    struct {
        bool ctrl;
        bool opt;
        bool cmd;
        bool shft;
    } osm;
} my_indicators_t;
my_indicators_t my_indicators;

led_t physical_led_state;

static uint16_t my_indicators_blink_timer;
void show_my_indicators(void) {
    led_t leds = physical_led_state;
    bool blink_time = timer_elapsed(my_indicators_blink_timer) > 200;

    if (my_indicators.osm.ctrl) {
        if (blink_time) leds.caps_lock = !leds.caps_lock;
    } else {
        leds.caps_lock = (my_indicators.layers[SYM]);
    }

    if (my_indicators.osm.cmd) {
        if (blink_time) leds.num_lock = !leds.num_lock;
    } else {
        leds.num_lock = (my_indicators.layers[NAV]);
    }

    if (my_indicators.osm.shft) {
        if (blink_time) leds.scroll_lock = !leds.scroll_lock;
    } else {
        leds.scroll_lock = (my_indicators.layers[UNI]);
    }

    if (blink_time) my_indicators_blink_timer = timer_read();
    physical_led_state = leds;
    led_update_ports(leds);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    my_indicators.layers[SYM] = IS_LAYER_ON_STATE(state, SYM);
    my_indicators.layers[NAV] = IS_LAYER_ON_STATE(state, NAV);
    my_indicators.layers[UNI] = IS_LAYER_ON_STATE(state, UNI);
    show_my_indicators();
    return state;
}

bool led_update_user(led_t led_state) {
    // Block normal signals from reaching the LEDs (i.e. from the computer)
    return false;
}

void oneshot_mods_changed_user(uint8_t mods) {
    my_indicators.osm.ctrl = (mods & MOD_MASK_CTRL);
    my_indicators.osm.opt = (mods & MOD_MASK_ALT);
    my_indicators.osm.cmd = (mods & MOD_MASK_GUI);
    my_indicators.osm.shft = (mods & MOD_MASK_SHIFT);

    show_my_indicators();
}

void housekeeping_task_user(void) {
    show_my_indicators();
}
