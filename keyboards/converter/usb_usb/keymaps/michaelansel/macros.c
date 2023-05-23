#include "michaelansel.h"

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

