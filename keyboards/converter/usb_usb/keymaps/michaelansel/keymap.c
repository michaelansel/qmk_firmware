#include QMK_KEYBOARD_H

#define _ENTRY_ KC_TRANSPARENT // Alias for the key that got us into this layer

#define BASE 0
#define NAV 2 // Navigation/Focus control
#define SYM 3 // Symbols
#define UNI 4 // Universal/media keys

#define BSPC_SYM LT(SYM, KC_BSPC)
#define DEL_NAV LT(NAV, KC_DEL)

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
    KC_ESC,    KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,     KC_F6,     KC_F7,     KC_F8,           KC_F9,     KC_F10,    KC_F11,    KC_F12,    XXXXXXX,   XXXXXXX,   XXXXXXX,
    KC_EQL,    KC_1,      KC_2,      KC_3,      KC_4,      KC_5,                                                                              KC_6,      KC_7,      KC_8,      KC_9,      KC_0,      KC_MINS,
    KC_TAB,    KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,                                                                              KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,      KC_BSLS,
    KC_NO,     KC_A,      KC_S,      KC_D,      KC_F,      KC_G,                                                                              KC_H,      KC_J,      KC_K,      KC_L,      KC_SCLN,   KC_QUOT,
    KC_LSFT,   KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,                                                                              KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_SLSH,   KC_RSFT,
               KC_LCTL,   KC_LALT,   KC_LGUI,   KC_LSFT,                                                                                                 KC_RSFT,   KC_RGUI,   KC_RALT,   KC_RCTL,
                                                           MO(UNI),   XXXXXXX,                                                     XXXXXXX,   XXXXXXX,
                                                                      XXXXXXX,                                                     XXXXXXX,
                                                BSPC_SYM,  DEL_NAV,   XXXXXXX,                                                     XXXXXXX,   KC_ENTER,  KC_SPC
  ),

  [NAV] = LAYOUT_kinesis(
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,         XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                                                                           XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,  XXXXXXX,
    XXXXXXX,   XXXXXXX,   HS_SCRN,   XXXXXXX,   HS_WARP,   XXXXXXX,                                                                           XXXXXXX,   HS_PTAB,   KC_ESC,    HS_NTAB,   XXXXXXX,  XXXXXXX,
    XXXXXXX,   KC_LCTL,   KC_LALT,   KC_LGUI,   KC_LSFT,   XXXXXXX,                                                                           KC_LEFT,   KC_DOWN,   KC_UP,     KC_RIGHT,  XXXXXXX,  XXXXXXX,
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                                                                           KC_HOME,   KC_PGDN,   KC_PGUP,   KC_END,    XXXXXXX,  XXXXXXX,
               _______,   _______,   _______,   _______,                                                                                                 _______,   _______,   _______,   _______,
                                                           XXXXXXX,  XXXXXXX,                                                      XXXXXXX,   XXXXXXX,
                                                                     XXXXXXX,                                                      XXXXXXX,
                                                XXXXXXX,   _ENTRY_,  XXXXXXX,                                                      XXXXXXX,   XXXXXXX,  XXXXXXX
  ),

  [SYM] = LAYOUT_kinesis(
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,         XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                                                                           XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                                                                           KC_ESC,    KC_LCBR,   KC_TAB,    KC_RCBR,   XXXXXXX,   XXXXXXX,
    XXXXXXX,   KC_LCTL,   KC_LALT,   KC_LGUI,   KC_LSFT,   XXXXXXX,                                                                           XXXXXXX,   KC_LPRN,   KC_MINUS,  KC_RPRN,   XXXXXXX,   XXXXXXX,
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                                                                           KC_GRV,    KC_LBRC,   KC_UNDS,   KC_RBRC,   XXXXXXX,   XXXXXXX,
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

};


// Needs a lot of setup: https://docs.qmk.fm/#/feature_unicode?id=unicode-support

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
