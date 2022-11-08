#pragma once

// Use double left shift to trigger caps word mode
#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD

// Prioritize the hold action if it was obviously a hold, just done quickly
#define PERMISSIVE_HOLD
// Disable double-tap to repeat; my hold keys are selected to never require hold-to-repeat
#define TAPPING_FORCE_HOLD

// Require very long hold to trigger mod-tap keys (but with permissive hold, should still enable fast combos)
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_TERM_PER_KEY


#define ONESHOT_TIMEOUT 1000  /* Time (in ms) before the one shot key is automatically released */
