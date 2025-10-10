// Copyright 2022 mjohns
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    BASE,
    NAV
};

#define CTL_ESC LCTL_T(KC_ESC)
#define CTL_CAP LCTL_T(KC_CAPS)
#define ALT_BSP LALT_T(KC_BSPC)
#define LT_SCLN LT(NAV, KC_SCLN)

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
    { k50, k40, k41, k42, k43, KC_NO},                                          \
    { k48, k52, k51, k49, k53, KC_NO},                                          \
                                                                                \
    {k06, k07, k08, k09, k0A, k0B },                                            \
    {k16, k17, k18, k19, k1A, k1B },                                            \
    {k26, k27, k28, k29, k2A, k2B },                                            \
    {k36, k37, k38, k39, k3A, k3B },                                            \
    {k58, k44, k45, k46, k47, KC_NO },                                          \
    {k57, k55, k56, k59, k54, KC_NO },                                          \
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT(
        KC_GRV,  KC_1,    KC_2,   KC_3,    KC_4,    KC_5,                                         KC_6, KC_7,    KC_8,    KC_9,   KC_0,    KC_HOME,
        KC_TAB,  KC_Q,    KC_W,   KC_E,    KC_R,    KC_T,                                         KC_Y, KC_U,    KC_I,    KC_O,   KC_P,    KC_BSLS,
        CTL_CAP, KC_A,    KC_S,   KC_D,    KC_F,    KC_G,                                         KC_H, KC_J,    KC_K,    KC_L,   LT_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,   KC_C,    KC_V,    KC_B,                                         KC_N, KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
                 KC_MINS, KC_EQL, KC_LBRC, KC_RBRC,                                                     KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT,
                                                               TT(NAV), KC_DEL,    KC_PGUP, KC_RCTL,
                                                     KC_BSPC, CTL_ESC, KC_LGUI,    KC_PGDN, KC_ENT, KC_SPC,
                                                                       KC_LALT,    KC_RALT
    ),
    [NAV] = LAYOUT(
        QK_BOOT, KC_NO,   KC_MPRV, KC_MPLY, KC_MNXT, KC_NO,                                           KC_BRIU, KC_P7,   KC_P8,  KC_P9,   KC_NO,   QK_BOOT,
        _______, KC_VOLU, KC_WBAK, MS_UP,   KC_WFWD, MS_WHLU,                                         KC_BRID, KC_P4,   KC_P5,  KC_P6,   KC_PMNS, _______,
        _______, KC_VOLD, MS_LEFT, MS_DOWN, MS_RGHT, MS_WHLD,                                         KC_PPLS, KC_P1,   KC_P2,  KC_P3,   KC_PSLS, _______,
        KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_NO,                                           KC_PAST, KC_PCMM, KC_P0,  KC_PDOT, KC_PENT, _______,
                 KC_F5,   KC_F6,   KC_F7,   KC_F8,                                                             KC_F9,   KC_F10, KC_F11,  KC_F12,
                                                              _______, _______,    KC_HOME, _______,
                                                     KC_BTN1, KC_BTN2, _______,    KC_END,  _______, _______,
                                                                       _______,    ALT_BSP 
    )
};
