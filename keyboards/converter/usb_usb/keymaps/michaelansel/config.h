#pragma once

// My custom flags
// #define HOME_ROW_MODS_ENABLE




#ifdef CAPS_WORD_ENABLE

// Use double left shift to trigger caps word mode
#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD

#endif // CAPS_WORD_ENABLE



#ifdef HOME_ROW_MODS_ENABLE

// Prioritize the hold action if it was obviously a hold, just done quickly
#define PERMISSIVE_HOLD
// Disable double-tap to repeat; my hold keys are selected to never require hold-to-repeat
#define TAPPING_FORCE_HOLD

// Require very long hold to trigger mod-tap keys (but with permissive hold, should still enable fast combos)
// #define IGNORE_MOD_TAP_INTERRUPT // this is now the default
#define TAPPING_TERM_PER_KEY

// Auto shift home row mod keys
#define RETRO_SHIFT

#endif // HOME_ROW_MODS


#define ONESHOT_TIMEOUT 1000  /* Time (in ms) before the one shot key is automatically released */
