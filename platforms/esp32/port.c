#include <stdint.h>
#include <stdbool.h>
#include "gpio.h"

uint8_t readPin(pin_t pin)
{
    return MATRIX_INPUT_PRESSED_STATE;
}

void soft_serial_target_init(void) {

}

void soft_serial_initiator_init(void) {

}


bool soft_serial_transaction(int sstd_index) {
    return false;
}

void platform_setup(void) {

}

void protocol_setup(void) {

}

void protocol_pre_init(void) {
   
}

void protocol_post_init(void) {

}

void protocol_pre_task(void) {

}

void protocol_post_task(void) {
#ifdef CONSOLE_ENABLE
    console_task();
#endif
#ifdef MIDI_ENABLE
    midi_ep_task();
#endif
#ifdef VIRTSER_ENABLE
    virtser_task();
#endif
#ifdef RAW_ENABLE
    raw_hid_task();
#endif
}