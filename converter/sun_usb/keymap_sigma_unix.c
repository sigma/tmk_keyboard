/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdint.h>
#include <stdbool.h>
#include <avr/pgmspace.h>

#include "keycode.h"
#include "util.h"
#include "keymap_common.h"

/* Sun type 5 keyboard, US Unix-style
,-------.  ,---,  ,---------------. ,---------------. ,---------------.   ,-----------. ,---------------.
|   76  |  | 0F|  | 05| 06| 08| 0A| | 0C| 0E| 10| 11| | 12| 07| 09| 0B|   | 16| 17| 15| | 2D| 02| 04| 30|
`-------'  `---'  `---------------' `---------------' `---------------'   `-----------' `---------------'
,-------.  ,-----------------------------------------------------------.  ,-----------. ,---------------.
| 01| 03|  | 1D| 1E| 1F| 20| 21| 22| 23| 24| 25| 26| 27| 28| 29| 58| 2A|  | 2C| 34| 60| | 62| 2E| 2F| 47|
|-------|  |-----------------------------------------------------------|  |------------ |---------------|
| 19| 1A|  |  35 | 36| 37| 38| 39| 3A| 3B| 3C| 3D| 3E| 3F| 40| 41| 2B  |  | 42| 4A| 7B| | 44| 45| 46|   |
|-------|  |-----------------------------------------------------------|  `-----------' |-----------| 7D|
| 31| 33|  |  4C  | 4D| 4E| 4F| 50| 51| 52| 53| 54| 55| 56| 57|   59   |                | 5B| 5C| 5D|   |
|-------|  |-----------------------------------------------------------|      ,---.     |-----------|---|
| 48| 49|  |   63   | 64| 65| 66| 67| 68| 69| 6A| 6B| 6C| 6D|    6E    |      | 14|     | 70| 71| 72|   |
|-------|  |-----------------------------------------------------------|  .-----------. |-----------| 5A|
| 5F| 61|  | 77 | 13| 78 |*73 |       79         |*74 |*75| 7A | 43| 0D|  | 18| 1B| 1C| |   5E  | 32|   |
`-------'  `-----------------------------------------------------------'  `-----------' `---------------'
*/
#define SUN_UNIX_US_KEYMAP( \
      K76,    K0F,  K05,K06,K08,K0A,   K0C,K0E,K10,K11,   K12,K07,K09,K0B,  K16,K17,K15,  K2D,K02,K04,K30, \
    K01,K03,  K1D,K1E,K1F,K20,K21,K22,K23,K24,K25,K26,K27,K28,K29,K58,K2A,  K2C,K34,K60,  K62,K2E,K2F,K47, \
    K19,K1A,  K35, K36,K37,K38,K39,K3A,K3B,K3C,K3D,K3E,K3F,K40,K41,   K2B,  K42,K4A,K7B,  K44,K45,K46,K7D, \
    K31,K33,  K4C,  K4D,K4E,K4F,K50,K51,K52,K53,K54,K55,K56,K57,      K59,                K5B,K5C,K5D,     \
    K48,K49,  K63,   K64,K65,K66,K67,K68,K69,K6A,K6B,K6C,K6D,         K6E,      K14,      K70,K71,K72,K5A, \
    K5F,K61,  K77,K13, K78,                  K79,           K7A, K43, K0D,  K18,K1B,K1C,  K5E,    K32      \
) { \
    { KC_NO,    KC_##K01, KC_##K02, KC_##K03, KC_##K04, KC_##K05, KC_##K06, KC_##K07 }, \
    { KC_##K08, KC_##K09, KC_##K0A, KC_##K0B, KC_##K0C, KC_##K0D, KC_##K0E, KC_##K0F }, \
    { KC_##K10, KC_##K11, KC_##K12, KC_##K13, KC_##K14, KC_##K15, KC_##K16, KC_##K17 }, \
    { KC_##K18, KC_##K19, KC_##K1A, KC_##K1B, KC_##K1C, KC_##K1D, KC_##K1E, KC_##K1F }, \
    { KC_##K20, KC_##K21, KC_##K22, KC_##K23, KC_##K24, KC_##K25, KC_##K26, KC_##K27 }, \
    { KC_##K28, KC_##K29, KC_##K2A, KC_##K2B, KC_##K2C, KC_##K2D, KC_##K2E, KC_##K2F }, \
    { KC_##K30, KC_##K31, KC_##K32, KC_##K33, KC_##K34, KC_##K35, KC_##K36, KC_##K37 }, \
    { KC_##K38, KC_##K39, KC_##K3A, KC_##K3B, KC_##K3C, KC_##K3D, KC_##K3E, KC_##K3F }, \
    { KC_##K40, KC_##K41, KC_##K42, KC_##K43, KC_##K44, KC_##K45, KC_##K46, KC_##K47 }, \
    { KC_##K48, KC_##K49, KC_##K4A, KC_NO,    KC_##K4C, KC_##K4D, KC_##K4E, KC_##K4F }, \
    { KC_##K50, KC_##K51, KC_##K52, KC_##K53, KC_##K54, KC_##K55, KC_##K56, KC_##K57 }, \
    { KC_##K58, KC_##K59, KC_##K5A, KC_##K5B, KC_##K5C, KC_##K5D, KC_##K5E, KC_##K5F }, \
    { KC_##K60, KC_##K61, KC_##K62, KC_##K63, KC_##K64, KC_##K65, KC_##K66, KC_##K67 }, \
    { KC_##K68, KC_##K69, KC_##K6A, KC_##K6B, KC_##K6C, KC_##K6D, KC_##K6E, KC_NO    }, \
    { KC_##K70, KC_##K71, KC_##K72, KC_NO,    KC_NO,    KC_NO   , KC_##K76, KC_##K77 }, \
    { KC_##K78, KC_##K79, KC_##K7A, KC_##K7B, KC_NO,    KC_##K7D, KC_NO,    KC_NO    }  \
}

#ifdef KEYMAP_SECTION_ENABLE
const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] __attribute__ ((section (".keymap.keymaps"))) =
#else
const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] PROGMEM =
#endif
{

    /* transparent keymap */
    /* 
     * SUN_UNIX_US_KEYMAP(
     *   TRNS,       TRNS,      TRNS, TRNS, TRNS, TRNS,    TRNS, TRNS, TRNS, TRNS,     TRNS, TRNS,TRNS,TRNS,   TRNS,TRNS,TRNS,  TRNS,TRNS,TRNS,TRNS,
     * TRNS, TRNS,   TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,TRNS, TRNS, TRNS,TRNS,   TRNS,TRNS,TRNS,  TRNS,TRNS,TRNS,TRNS,
     * TRNS, TRNS,   TRNS,  TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,  TRNS,     TRNS,TRNS,TRNS,  TRNS,TRNS,TRNS,TRNS,
     * TRNS, TRNS,   TRNS,   TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,     TRNS,                        TRNS,TRNS,TRNS,
     * TRNS, TRNS,   TRNS,      TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,       TRNS,             TRNS,       TRNS,TRNS,TRNS,TRNS,
     * TRNS, TRNS,   TRNS,    TRNS, TRNS,                     TRNS,                         TRNS,TRNS, TRNS,   TRNS,TRNS,TRNS,  TRNS,     TRNS
     * ),
     */

    // 0: default
    SUN_UNIX_US_KEYMAP(
        HELP,        FN10,  F1, F2, F3, F4,      F5, F6, F7, F8,      F9, F10,F11,F12,  PSCR,SLCK,PAUS,  MUTE,VOLD,VOLU,PWR,
    STOP,   FN4,     ESC,1,  2,  3,  4,  5,  6,  7,  8,  9,  0, MINS, EQL, BSLS,  GRV,  INS, HOME,PGUP,  NLCK,PSLS,PAST,PMNS,
    MENU,   FN3,     TAB, Q,  W,  E,  R,  T,  Y,  U,  I,  O,  P,   LBRC,RBRC,    BSPC,  DEL, END, PGDN,  P7,  P8, P9,  PPLS,
    SELECT, FN1,     LCTL, A,  S,  D,  F,  G,  H,  J,  K,  L,  SCLN,QUOT,        ENT,                    P4,  P5, P6,
    FN9,    FN2,     LSFT,  Z,  X,  C,  V,  B,  N,  M,  COMM,DOT,SLSH,           RSFT,       UP,         P1,  P2, P3,  PENT,
    FN5,    FN0,     CAPS, LGUI, LALT,               SPC,              RGUI,APP, RALT,  LEFT,DOWN,RGHT,  P0,      PDOT
    ),

    // 1: txt
    SUN_UNIX_US_KEYMAP(
      TRNS,       TRNS,      TRNS, TRNS, TRNS, TRNS,    TRNS, TRNS, TRNS, TRNS,     TRNS, TRNS,TRNS,TRNS,   TRNS,TRNS,TRNS,  TRNS,TRNS,TRNS,TRNS,
    TRNS, TRNS,   TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,TRNS, TRNS, TRNS,TRNS,   TRNS,TRNS,TRNS,  TRNS,TRNS,TRNS,TRNS,
    TRNS, TRNS,   TRNS,  TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,  TRNS,     TRNS,TRNS,TRNS,  TRNS,TRNS,TRNS,TRNS,
    TRNS, TRNS,   TRNS,   TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,     TRNS,                        TRNS,TRNS,TRNS,
    TRNS, TRNS,   FN6,       TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,       TRNS,             TRNS,       TRNS,TRNS,TRNS,TRNS,
    TRNS, TRNS,   TRNS,    TRNS, TRNS,                     TRNS,                         TRNS,TRNS, TRNS,   TRNS,TRNS,TRNS,  TRNS,     TRNS
    ),

    // 2: code
    SUN_UNIX_US_KEYMAP(
      TRNS,       TRNS,      TRNS, TRNS, TRNS, TRNS,    TRNS, TRNS, TRNS, TRNS,     TRNS, TRNS,TRNS,TRNS,   TRNS,TRNS,TRNS,  TRNS,TRNS,TRNS,TRNS,
    TRNS, TRNS,   TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,TRNS, TRNS, TRNS,TRNS,   TRNS,TRNS,TRNS,  TRNS,TRNS,TRNS,TRNS,
    TRNS, TRNS,   TRNS,  TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,  TRNS,     TRNS,TRNS,TRNS,  TRNS,TRNS,TRNS,TRNS,
    TRNS, TRNS,   TRNS,   TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,     TRNS,                        TRNS,TRNS,TRNS,
    TRNS, TRNS,   FN7,       TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,       FN8,              TRNS,       TRNS,TRNS,TRNS,TRNS,
    TRNS, TRNS,   TRNS,    TRNS, TRNS,                     TRNS,                         TRNS,TRNS, TRNS,   TRNS,TRNS,TRNS,  TRNS,     TRNS
    ),
};

enum function_id {
    LSHIFT_LPAREN,
    RSHIFT_RPAREN,
};

/*
 * Fn action definition
 */
#ifdef KEYMAP_SECTION_ENABLE
const uint16_t fn_actions[] __attribute__ ((section (".keymap.fn_actions"))) =
#else
const uint16_t fn_actions[] PROGMEM =
#endif
{
    [0] = ACTION_MODS_KEY(MOD_LGUI, KC_X),
    [1] = ACTION_MODS_KEY(MOD_LGUI, KC_C),
    [2] = ACTION_MODS_KEY(MOD_LGUI, KC_V),
    [3] = ACTION_MODS_KEY(MOD_LGUI, KC_Z),
    [4] = ACTION_MODS_KEY(MOD_LGUI|MOD_LSFT, KC_Z),
    [5] = ACTION_LAYER_TOGGLE(1),
    [6] = ACTION_MODS_ONESHOT(MOD_LSFT),
    [7] = ACTION_FUNCTION_TAP(LSHIFT_LPAREN),         // Function: LShift with tap '('
    [8] = ACTION_FUNCTION_TAP(RSHIFT_RPAREN),         // Function: RShift with tap ')'
    [9] = ACTION_LAYER_TOGGLE(2),
    [10] = ACTION_MODS_KEY(MOD_LGUI, KC_GRV),
};

/*
 * user defined action function
 */
void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    keyevent_t event = record->event;
    tap_t tap = record->tap;

    switch (id) {
        case LSHIFT_LPAREN:
            // LShft + tap '('
            // NOTE: cant use register_code to avoid conflicting with magic key bind
            if (event.pressed) {
                if (tap.count == 0 || tap.interrupted) {
                    add_mods(MOD_BIT(KC_LSHIFT));
                    //layer_on(1);
                } else {
                    add_mods(MOD_BIT(KC_LSHIFT));
                    add_key(KC_9);
                    send_keyboard_report();
                    del_mods(MOD_BIT(KC_LSHIFT));
                    del_key(KC_9);
                    send_keyboard_report();
                }
            } else {
                if (tap.count == 0 || tap.interrupted) {
                    del_mods(MOD_BIT(KC_LSHIFT));
//                    layer_off(1);
                }
            }
            break;
        case RSHIFT_RPAREN:
            // RShift + tap ')'
            if (event.pressed) {
                if (tap.count == 0 || tap.interrupted) {
                    add_mods(MOD_BIT(KC_RSHIFT));
                } else {
                    add_mods(MOD_BIT(KC_RSHIFT));
                    add_key(KC_0);
                    send_keyboard_report();
                    del_mods(MOD_BIT(KC_RSHIFT));
                    del_key(KC_0);
                    send_keyboard_report();
                }
            } else {
                if (tap.count == 0 || tap.interrupted) {
                    del_mods(MOD_BIT(KC_RSHIFT));
                }
            }
            break;
    }
}
