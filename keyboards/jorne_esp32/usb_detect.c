// Copyright 2023 Roman Skakun (@galaxywarrior)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "quantum.h"
#include "usb_util.h"

// The USB connection is not allowed under this configuration
bool usb_connected_state(void) {
    return false;
}