// This file is all the QMK hooks/interfaces
#include "michaelansel.h"

layer_state_t layer_state_set_user(layer_state_t state) {
    // Save layer state for LED indicators
    my_indicators.layers[SYM] = IS_LAYER_ON_STATE(state, SYM);
    my_indicators.layers[NAV] = IS_LAYER_ON_STATE(state, NAV);
    my_indicators.layers[UNI] = IS_LAYER_ON_STATE(state, UNI);

    // Update LED indicators immediately
    show_my_indicators();

    return state;
}

bool led_update_user(led_t led_state) {
    // Block normal signals from reaching the LEDs (i.e. from the computer)
    return false;
}

void oneshot_mods_changed_user(uint8_t mods) {
    // Save OSM state for LED indicators
    my_indicators.osm.ctrl = (mods & MOD_MASK_CTRL);
    my_indicators.osm.opt = (mods & MOD_MASK_ALT);
    my_indicators.osm.cmd = (mods & MOD_MASK_GUI);
    my_indicators.osm.shft = (mods & MOD_MASK_SHIFT);

    // Update LED indicators immediately
    show_my_indicators();
}

void housekeeping_task_user(void) {
    // Ensure LED indicators always match recorded state
    show_my_indicators();
}

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
            // This is how long you need to hold for just a bare modifier (e.g. for Cmd-Click);
            // PERMISSIVE_HOLD will allow fast keyboard shortcuts as long as the modifier is released last.
            return 250;
        default:
            return TAPPING_TERM;
    }
}
