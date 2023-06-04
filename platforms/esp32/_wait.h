#pragma once

#include <inttypes.h>

extern void wait_ms(uint32_t ms);
#define wait_us(us) wait_ms(us / 1000)
#define waitInputPinDelay()
