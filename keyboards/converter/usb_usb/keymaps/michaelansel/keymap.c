#include QMK_KEYBOARD_H
#include "michaelansel.h"
#include "led.c"
#include "quantum.c"
#include "macros.c"
#include "kinesis.h"

#define _ENTRY_ KC_TRANSPARENT // Alias for the key that got us into this layer

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

  // Plain character entry
  [BASE] = LAYOUT_kinesis(
    KC_ESC,    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,         MOD_FIX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   QK_BOOT,
    XXXXXXX,   KC_1,      KC_2,      KC_3,      KC_4,      KC_5,                                                                              KC_6,      KC_7,      KC_8,      KC_9,      KC_0,      KC_MINS,
    XXXXXXX,   KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,                                                                              KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,      KC_BSLS,
    XXXXXXX,   HR_A,      HR_S,      HR_D,      HR_F,      KC_G,                                                                              KC_H,      HR_J,      HR_K,      HR_L,      HR_SCLN,   XXXXXXX,
    XXXXXXX,   KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,                                                                              KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_SLSH,   XXXXXXX,
            //    DM_PLY1,   DM_PLY2,   XXXXXXX,   MO(NUM),                                                                                                 XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
               KC_LCTL,   KC_LALT,   KC_LGUI,   KC_LSFT,                                                                                                 KC_RSFT,   KC_RGUI,   KC_RALT,   KC_RCTL,
                                                           MO(WIN),   XXXXXXX,                                                     XXXXXXX,   OSL(UNI),
                                                                      XXXXXXX,                                                     XXXXXXX,
                                                LTHMB1,    LTHMB2,    XXXXXXX,                                                     XXXXXXX,   KC_ENTER,  LT(SYM, KC_SPC)
  ),

  // Secondary lmod: Cursor movement
  [NAV] = LAYOUT_kinesis(
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,         XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                                                                           XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,  XXXXXXX,
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                                                                           XXXXXXX,   HS_PTAB,   XXXXXXX,   HS_NTAB,   XXXXXXX,  XXXXXXX,
    XXXXXXX,   KC_LCTL,   KC_LALT,   KC_LGUI,   KC_LSFT,   XXXXXXX,                                                                           KC_LEFT,   KC_DOWN,   KC_UP,     KC_RIGHT,  XXXXXXX,  XXXXXXX,
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                                                                           KC_HOME,   KC_PGDN,   KC_PGUP,   KC_END,    XXXXXXX,  XXXXXXX,
               XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                                                                                                 HS_SCDN,   HS_SCUP,   HS_BTN1,   HS_MCTR,
                                                           XXXXXXX,  XXXXXXX,                                                      XXXXXXX,   XXXXXXX,
                                                                     XXXXXXX,                                                      XXXXXXX,
                                                XXXXXXX,   _ENTRY_,  XXXXXXX,                                                      XXXXXXX,   S(KC_ENT), XXXXXXX
  ),

  // Primary lmod: Special character entry
  [SYM] = LAYOUT_kinesis(
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,         XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                                                                           KC_CIRC,   KC_AMPR,   KC_ASTR,   XXXXXXX,   XXXXXXX,   XXXXXXX,
    XXXXXXX,   KC_EXLM,   KC_AT,     KC_HASH,   KC_DLR,    KC_PERC,                                                                           KC_ESC,    KC_LCBR,   KC_TAB,    KC_RCBR,   KC_QUOT,   XXXXXXX,
    XXXXXXX,   KC_LCTL,   KC_LALT,   KC_LGUI,   KC_LSFT,   KC_EQL,                                                                            KC_PIPE,   KC_LPRN,   KC_MINUS,  KC_RPRN,   KC_COLN,   XXXXXXX,
    XXXXXXX,   KC_BSLS,   KC_LT,     CPY_PST,   KC_GT,     TD(TD_NUM_LHT),                                                                           KC_GRV,    KC_LBRC,   KC_UNDS,   KC_RBRC,   LSFT(KC_SLSH),   XXXXXXX,
               _______,   _______,   _______,   _______,                                                                                          _______,   _______,   _______,   _______,
                                                           XXXXXXX,   XXXXXXX,                                                     XXXXXXX,   KC_DEL,
                                                                      XXXXXXX,                                                     XXXXXXX,
                                                _ENTRY_,   XXXXXXX,   XXXXXXX,                                                     XXXXXXX,   G(KC_ENT), KC_BSPC
  ),

  // Numpad?
  [NUM] = LAYOUT_kinesis(
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,         XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                                                                           XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                                                                           XXXXXXX,   KC_7,      KC_8,      KC_9,      XXXXXXX,   XXXXXXX,
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                                                                           XXXXXXX,   KC_4,      KC_5,      KC_6,      KC_MINUS,  XXXXXXX,
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                                                                           XXXXXXX,   KC_1,      KC_2,      KC_3,      KC_SLSH,   XXXXXXX,
               XXXXXXX,   XXXXXXX,   XXXXXXX,   _ENTRY_,                                                                                                 XXXXXXX,   XXXXXXX,   KC_DOT,    XXXXXXX,
                                                           XXXXXXX,   XXXXXXX,                                                     XXXXXXX,   XXXXXXX,
                                                                      XXXXXXX,                                                     XXXXXXX,
                                                _ENTRY_,   XXXXXXX,   XXXXXXX,                                                     XXXXXXX,   XXXXXXX,   KC_0
  ),

  // Ternary lmod: window layout navigation
  [WIN] = LAYOUT_kinesis(
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,         XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                                                                           XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
    XXXXXXX,   AE_FMON,   XXXXXXX,   XXXXXXX,   XXXXXXX,   AE_FULL,                                                                           AE_MV_L,   AE_MV_D,   AE_MV_U,   AE_MV_R,   AE_TGFT,   XXXXXXX,
    XXXXXXX,   OSM(MOD_LCTL),   OSM(MOD_LALT),   OSM(MOD_LGUI),   OSM(MOD_LSFT),   AE_EQLS,                                                                           AE_FO_L,   AE_FO_D,   AE_FO_U,   AE_FO_R,   AE_TGAC,   XXXXXXX,
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   AE_TRST,                                                                           AE_JO_L,   AE_JO_D,   AE_JO_U,   AE_JO_R,   AE_TGRT,   XXXXXXX,
               XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                                                                                                 XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
                                                           _ENTRY_,   XXXXXXX,                                                     XXXXXXX,   HS_MENU,
                                                                      XXXXXXX,                                                     XXXXXXX,
                                                XXXXXXX,   XXXXXXX,   XXXXXXX,                                                     XXXXXXX,   XXXXXXX,   LEADERK
  ),

  // Move app selections to a dedicated app layer separate from the Universal layer? Put mouse keys on the universal layer.
  [UNI] = LAYOUT_kinesis(
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,         XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                                                                           XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
    XXXXXXX,   XXXXXXX,   XXXXXXX,   HS_MENU,   XXXXXXX,   XXXXXXX,                                                                           HS_CHRM,   HS_MEET,   LK_OPEN_TYPORA,   HS_SLAK,   HS_CODE,   HS_TERM,
    XXXXXXX,   OSM(MOD_LCTL),   OSM(MOD_LALT),   OSM(MOD_LGUI),   OSM(MOD_LSFT),   XXXXXXX,                                                                           RTM,    KC_MPRV,   KC_MPLY,   KC_MNXT,   HS_SPFY,   XXXXXXX,
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   C(KC_B),                                                                           XXXXXXX,   MAG_L,     MAG_MAX,   MAG_R,     MAG_RST,   XXXXXXX,
               XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                                                                                                 XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
            //    DM_REC1,   DM_REC2,   DM_RSTP,   XXXXXXX,                                                                                                 XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
                                                           HS_MENU,   XXXXXXX,                                                     XXXXXXX,   _ENTRY_,
                                                                      XXXXXXX,                                                     XXXXXXX,
                                                XXXXXXX,   XXXXXXX,   XXXXXXX,                                                     XXXXXXX,   XXXXXXX,   XXXXXXX
  ),


};
