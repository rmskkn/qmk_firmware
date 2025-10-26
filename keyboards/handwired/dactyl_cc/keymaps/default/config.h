// Copyright 2022 mjohns
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#undef MATRIX_ROW_PINS
#undef MATRIX_COL_PINS
#undef MATRIX_ROW_PINS_RIGHT
#undef MATRIX_COL_PINS_RIGHT

// C7 is a 6th row, 6x6 matrix
// Left side
#define MATRIX_ROW_PINS             { GP21, GP16, GP14, GP13, GP12, GP9 }
#define MATRIX_COL_PINS             { GP8, GP6, GP5, GP4, GP3, GP2 }

//Right side
#define MATRIX_ROW_PINS_RIGHT       { GP14, GP13, GP12, GP9, GP8, GP23 }
#define MATRIX_COL_PINS_RIGHT       { GP20, GP22, GP26, GP27, GP28, GP29 }

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* Enables This makes it easier for fast typists to use dual-function keys */
#define PERMISSIVE_HOLD

/* mouse config */
#define MOUSEKEY_DELAY          0
// Lowering MOUSEKEY_INTERVAL raises the cursor speed significantly, you may want to lower MOUSEKEY_MAX_SPEED (default: 10)
#define MOUSEKEY_INTERVAL       20
#define MOUSEKEY_MAX_SPEED       7
#define MOUSEKEY_WHEEL_DELAY 0

/* layer config */
#define TAPPING_TOGGLE 1

#define MASTER_RIGHT

//#define SERIAL_DEBUG
/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
