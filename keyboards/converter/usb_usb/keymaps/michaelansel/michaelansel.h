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

// Aerospace.app -- two-step scheme: hyper chord activates action mode, then verb key
// Direction keys (AE_DIR_*) read which mod is held to select the verb:
//   no mod=focus  shift=move  gui=swap  alt=join  shift+gui=resize
#define AE_CHORD HYPR(KC_SPC) // Ctrl+Shift+Alt+Gui+Space -> Aerospace action mode
// Delay between chord and action key; gives Aerospace time to process the mode
// transition. 30ms matches ZMK's wait-ms=20 plus USB report overhead margin.
#define AE_CHORD_DELAY 250

// Leader Key sequences
#define LEADER_KEY_APP_SEQUENCES(X) \
    X(LK_OPEN_TYPORA, "on") /* Open Typora */

// Tap dances
enum {
    TD_LTHMB,
    TD_CUT_COPY_PASTE,
    TD_RTM,
    TD_NUM_LHT,
    TD_AE_SEND,
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
    MOD_FIX = SAFE_RANGE,
    #define YIELD(KEY, SEQUENCE) KEY,
    LEADER_KEY_APP_SEQUENCES(YIELD)
    #undef YIELD
    // Aerospace direction cluster -- verb determined by mod held at keypress
    AE_DIR_L, AE_DIR_D, AE_DIR_R, AE_DIR_U,
    // Aerospace letter mnemonics
    AE_CLOSE,   // W  -- close window
    AE_WS_P,    // U  -- workspace prev
    AE_WS_N,    // O  -- workspace next
    AE_TGFT,    // P  -- float <-> tile
    AE_TGAC,    // ;  -- tiles <-> accordion
    AE_TGRT,    // /  -- horizontal <-> vertical
    AE_EQLS,    // G  -- balance sizes
    AE_TRST,    // B  -- reset tree
    AE_DFSP,    // M  -- dfs-prev
    AE_FMON,    // H  -- focus-monitor next
    AE_DFNS,    // .  -- dfs-next
    AE_BANDF,   // '  -- back-and-forth
    AE_FULL,    // Enter -- fullscreen
    // Send mode (tap-dance TD_AE_SEND)
    AE_SEND, AE_SEND_EMPTY, AE_SEND_FLW,
};
