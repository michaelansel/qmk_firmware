#pragma once

// Layers
#define BASE 0
#define NUM 1 // Keypad layer / Number pad
#define NAV 2 // Navigation/Focus control
#define SYM 3 // Symbols
#define UNI 4 // Universal/media keys
#define WIN 5 // Window layout/navigation

// Home row mods
#ifdef HOME_ROW_MODS_ENABLE
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
#endif // HOME_ROW_MODS_ENABLE

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
#define LEADERK HYPR(KC_S) // Open Leader Key

// Magnet.app
#define MAG_L C(A(KC_LEFT))
#define MAG_R C(A(KC_RIGHT))
#define MAG_MAX C(A(KC_ENTER))
#define MAG_RST C(A(KC_BACKSPACE))

// Aerospace.app
/*

Two structural observations for layout design
The shift convention.
AeroSpace's default already establishes "unshifted = act on focus, shifted = act on window position."
Preserving this (workspace 1 vs. send-window-to-workspace 1, focus-left vs. move-left) lets you halve the number of bindings you have to actively memorize — the second half is always just "the first half + shift."

Directions want hjkl or arrows consistently.
Focus, move, swap, resize, and join-with all take the same four-direction argument.
If you use hjkl for focus but arrows for resize, you've doubled the cognitive load.
Pick one direction convention and apply it everywhere it appears in the cluster map — the rest of the layout is modifier differentiation.

*/
/*
# Workspace Navigation
- Workspace next/prev
  - Ctrl-L/R - reuse the standard Spaces keys

# Focus
- Focus LRUD
  - Mod?? hjkl
- Focus other monitor
  - ?? replace the right thumb cmd key

# Moving Windows
- Send to workspace (and follow); direct, next/prev; other monitor
- Move/Swap LRUD
  - Mod?? yuio

  # Layout
  - Toggle float/tile
  - Mod?? p
  - Toggle tiles/accordion
  - Mod?? ;
  - Toggle horizontal/vertical
  - Mod?? /
  - Join LRUD
  - Mod?? nm,.
  - Mod?? sdef (kinesis wasd equiv)
- Reset tree to flat
  - Mod?? b
- Equalize sizes
  - Mod?? g
- Fullscreen?
  - Mod?? t
*/
#define AE_EQLS C(A(KC_EQL)) // balance-sizes
#define AE_FULL C(A(S(KC_EQL))) // fullscreen
#define AE_FO_D C(A(KC_J)) // focus down
#define AE_FO_L C(A(KC_H)) // focus left
#define AE_FO_R C(A(KC_L)) // focus right
#define AE_FO_U C(A(KC_K)) // focus up
#define AE_JO_D C(A(G(KC_J))) // join-with down
#define AE_JO_L C(A(G(KC_H))) // join-with left
#define AE_JO_R C(A(G(KC_L))) // join-with right
#define AE_JO_U C(A(G(KC_K))) // join-with up
#define AE_MV_D C(A(S(KC_J))) // move down
#define AE_MV_L C(A(S(KC_H))) // move left
#define AE_MV_R C(A(S(KC_L))) // move right
#define AE_MV_U C(A(S(KC_K))) // move up
#define AE_TGAC C(A(KC_COMM)) // layout tiles accordion (change container style)
#define AE_TGFT C(A(KC_DOT)) // layout floating tiling
#define AE_TGRT C(A(KC_SLSH)) // layout horizontal vertical (change container orientation)
#define AE_TRST C(A(KC_QUOT)) // bash:make all workspace windows tiling, flatten-workspace-tree

// Tap dances
enum {
    TD_LTHMB,
    TD_CUT_COPY_PASTE,
    TD_RTM,
};

#ifdef TAP_DANCE_ENABLE

// #define LTHMB TD(TD_LTHMB)
#define LTHMB MO(SYM)
#define CPY_PST TD(TD_CUT_COPY_PASTE)
#define RTM TD(TD_RTM)

#else // TAP_DANCE_ENABLE

#define LTHMB MO(SYM)
#define CPY_PST KC_NO
#define RTM KC_NO

#endif // TAP_DANCE_ENABLE

#define LTHMB1 LTHMB
#define LTHMB2 MO(NAV)

enum custom_keycodes {
    MOD_FIX = SAFE_RANGE, // macro to press/release all modifiers to fix the OS missing a release
    NEXTSEN, // ". " and OSM LSFT
};
