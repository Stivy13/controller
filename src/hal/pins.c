#include "hal/pins.h"

/* ==== PHYSICAL PIN MAPPING  ==== */
// See: https://www.arduino.cc/en/Hacking/PinMapping2560 */ 

struct pin_config DIO_PIN_CONFIG[] = {
    {DIO_PIN_STARTSTOP, IO_PORTA, 0},
    {DIO_PIN_MAINPOWER, IO_PORTA, 1},
    {DIO_PIN_AUXPOWER,  IO_PORTA, 2},
    {DIO_PIN_DEBUGLED,  IO_PORTA, 3}
};

// The order of declaration in this array needs to be the same as for aio_pin
struct pin_config AIO_PIN_CONFIG[] = {
    {AIO_PIN_PRESSURE, IO_PORTF, 0},
};

