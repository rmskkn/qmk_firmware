#pragma once

#include <inttypes.h>

static __inline__ uint8_t __interrupt_disable__(void) {return 1;}
static __inline__ void __interrupt_enable__(const uint8_t *__s) { (void)__s; }
static __inline__ int __interrupt_lock__(void) { return 0; }
static __inline__ void __interrupt_unlock__(const void *__s) {}

#define ATOMIC_BLOCK(type) for (type, __ToDo = 1; __ToDo; __ToDo = 0)
#define ATOMIC_FORCEON uint8_t status_save __attribute__((__cleanup__(__interrupt_enable__))) = __interrupt_disable__()
#define ATOMIC_RESTORESTATE int status_save __attribute__((__cleanup__(__interrupt_unlock__))) = __interrupt_lock__()

#define ATOMIC_BLOCK_RESTORESTATE ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
#define ATOMIC_BLOCK_FORCEON ATOMIC_BLOCK(ATOMIC_FORCEON)
