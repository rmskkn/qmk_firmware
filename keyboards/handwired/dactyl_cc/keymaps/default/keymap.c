// Copyright 2022 mjohns
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "debug.h"

enum layers {
    COLEMAK,
/*  QWERTY, */
    NAV,
    SYM
};

#define CTL_ESC LCTL_T(KC_ESC)
#define CTL_CAP LCTL_T(KC_CAPS)
#define SHF_ENT SFT_T(KC_ENT)
#define ALT_SPC ALT_T(KC_SPC)
#define ALT_BSP LALT_T(KC_BSPC)
#define LT_SCLN LT(NAV, KC_SCLN)

// - Home row modifiers:
#define KC_GU_F LGUI_T(KC_F)          // Left Gui
#define KC_CT_V LCTL_T(KC_V)          // Left Ctrl
#define KC_AL_S LALT_T(KC_S)          // Left Alt
#define KC_LS_D LSFT_T(KC_D)          // Left Shift

#define KC_GU_J RGUI_T(KC_J)          // Right Gui
#define KC_AL_L RALT_T(KC_L)          // Left Alt
#define KC_CT_M RCTL_T(KC_M)          // Right Ctrl
#define KC_RS_K RSFT_T(KC_K)          // Right Shift

#undef LAYOUT
#define LAYOUT(                                                                \
    k00,k01,k02,k03,k04,k05,                       k06,k07,k08,k09,k0A,k0B,    \
    k10,k11,k12,k13,k14,k15,                       k16,k17,k18,k19,k1A,k1B,    \
    k20,k21,k22,k23,k24,k25,                       k26,k27,k28,k29,k2A,k2B,    \
    k30,k31,k32,k33,k34,k35,                       k36,k37,k38,k39,k3A,k3B,    \
        k40,k41,k42,k43,                               k44,k45,k46,k47,        \
                            k53, k52,      k55, k54,                           \
                       k50, k49, k51,      k56, k59, k58,                      \
                                 k48,      k57                                 \
    )                                                                          \
   /* matrix positions */                                                      \
{                                                                               \
    { k00, k01, k02, k03, k04, k05},                                            \
    { k10, k11, k12, k13, k14, k15},                                            \
    { k20, k21, k22, k23, k24, k25},                                            \
    { k30, k31, k32, k33, k34, k35},                                            \
    { KC_NO, k40, k41, k42, k43, k50},                                          \
    { KC_NO, k53, k49, k51, k52, k48},                                          \
                                                                                \
    {k06, k07, k08, k09, k0A, k0B },                                            \
    {k16, k17, k18, k19, k1A, k1B },                                            \
    {k26, k27, k28, k29, k2A, k2B },                                            \
    {k36, k37, k38, k39, k3A, k3B },                                            \
    {k58, k44, k45, k46, k47, KC_NO },                                          \
    {k57, k55, k56, k59, k54, KC_NO },                                          \
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [COLEMAK] = LAYOUT(
        KC_GRV,  KC_1,    KC_2,   KC_3,    KC_4,    KC_5,                                         KC_6, KC_7,    KC_8,    KC_9,   KC_0,    KC_HOME,
        KC_TAB,  KC_Q,    KC_W,   KC_F,    KC_P,    KC_B,                                         KC_J, KC_L,    KC_U,    KC_Y,   KC_SCLN, KC_BSLS,
        CTL_CAP, KC_A,    KC_R,   KC_S,    KC_T,    KC_G,                                         KC_M, KC_N,    KC_E,    KC_I,   KC_O,    KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,   KC_C,    KC_D,    KC_V,                                         KC_K, KC_H,    KC_COMM, KC_DOT, KC_SLSH, KC_RCTL,
                 KC_MINS, KC_EQL, KC_LBRC, KC_RBRC,                                                     KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT,
                                                              TT(NAV), KC_DEL,     KC_PGUP, KC_TAB,
                                                     LT(SYM, KC_BSPC), CTL_ESC,    KC_LGUI, KC_PGDN, SHF_ENT, ALT_SPC,
                                                                       KC_LALT,    KC_RALT
    ),
/*
    [QWERTY] = LAYOUT(
        KC_GRV,  KC_1,    KC_2,   KC_3,    KC_4,    KC_5,                                         KC_6, KC_7,    KC_8,    KC_9,   KC_0,    KC_HOME,
        KC_TAB,  KC_Q,    KC_W,   KC_E,    KC_R,    KC_T,                                         KC_Y, KC_U,    KC_I,    KC_O,   KC_P,    KC_BSLS,
        CTL_CAP, KC_A,    KC_AL_S,KC_LS_D, KC_GU_F, KC_G,                                         KC_H, KC_GU_J, KC_RS_K, KC_AL_L,LT_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,   KC_C,    KC_CT_V, KC_B,                                         KC_N, KC_CT_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
                 KC_MINS, KC_EQL, KC_LBRC, KC_RBRC,                                                     KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT,
                                                              _______, _______,    _______, _______,
                                                     _______, _______, _______,    _______, _______, _______,
                                                                       _______,    _______
*/
    [NAV] = LAYOUT(
        QK_BOOT, KC_NO,   KC_MPRV, KC_MPLY, KC_MNXT, KC_NO,                                           KC_BRIU, KC_P7,   KC_P8,  KC_P9,   KC_NO,   QK_BOOT,
        _______, KC_VOLU, KC_WBAK, KC_MS_U, KC_WFWD, KC_WH_U,                                         KC_BRID, KC_HOME, KC_UP,  KC_END,  KC_PMNS, _______,
        _______, KC_VOLD, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,                                         KC_PPLS, KC_LEFT, KC_DOWN,KC_RGHT, KC_PSLS, _______,
        KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_NO,                                           KC_PAST, KC_PCMM, KC_P0,  KC_PDOT, KC_PENT, _______,
                 KC_F5,   KC_F6,   KC_F7,   KC_F8,                                                             KC_F9,   KC_F10, KC_F11,  KC_F12,
                                                              _______, _______,    KC_HOME, _______,
                                                     KC_BTN1, KC_BTN2, _______,    KC_END,  KC_BTN1, KC_BTN2,
                                                                       _______,    ALT_BSP
    ),

     [SYM] = LAYOUT(
        KC_NO,   KC_NO,   _______, _______, _______, _______,                                         _______, KC_P7,   KC_P8,  KC_P9,   KC_NO,   _______,
        _______, _______, _______, _______, _______, _______,                                         KC_BRID, KC_P4,   KC_P5,  KC_P6,   KC_PMNS, _______,
        _______, KC_AMPR, KC_TILD, KC_LPRN, KC_RPRN, KC_EQL,                                          KC_SCLN, KC_LCBR, KC_RCBR, KC_ASTR,KC_P3,   KC_PSLS,
        KC_NO,   _______, _______, _______, _______, KC_NO,                                           KC_PAST, KC_PCMM, KC_P0,  KC_PDOT, KC_PENT, _______,
                 _______, _______, _______, _______,                                                           KC_F9,   KC_F10, KC_F11,  KC_F12,
                                                              _______, _______,    _______,  _______,
                                                     _______, _______, _______,    _______,  _______, _______,
                                                                       _______,    _______
    )
};

#if 0
void keyboard_post_init_user(void) {
  //debug_enable=true;
  //debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}


static const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        if (keycode < 60)
            dprintf("Key: %c\n", code_to_name[keycode]);
        else
            dprintf("Code: %u\n", keycode);
    }

    dprintf("Tap: %u\n", record->tap.count);

    return true;
}
#endif
