#pragma once

// Layers
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

// Tap dances
enum {
    TD_LTHMB,
    TD_CUT_COPY_PASTE,
};

#ifdef TAP_DANCE_ENABLE

// #define LTHMB TD(TD_LTHMB)
#define LTHMB MO(SYM)
#define CPY_PST TD(TD_CUT_COPY_PASTE)

#else // TAP_DANCE_ENABLE

#define LTHMB MO(SYM)
#define CPY_PST KC_NO

#endif // TAP_DANCE_ENABLE

#define LTHMB1 LTHMB
#define LTHMB2 MO(NAV)
