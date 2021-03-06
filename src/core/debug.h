#include "FreeRTOS.h"

/**
 * @init_debug_print_sem Init a semaphore to protect debug_print().
 *
 * Init a semaphore that protects debug_print against concurrent accesses.
 */
void init_debug_print_sem();

/**
 * @debug_print Print a debug message on the UART.
 *
 * Print a message to UART0. The message, after formatting, cannot exceed 32 bytes.
 * This function supports the same arguments as printf.
 */
void debug_print(const char *fmt, ...);

/**
 * @LEDTask Blink a LED every second.
 *
 * @param pvParameters Set to NULL.
 */
void LEDTask(void *pvParameters);

/**
 * @ReadIOTask Read a digital io every second (for testing purpose)
 *
 * @param pvParameters Set to NULL.
 */
void ReadIOTask(void *pvParameters);

/**
 * @ReadAnalogTask Read an analog input every second (for testing purpose)
 *
 * @param pvParameters Set to NULL.
 */
void ReadAnalogTask(void *pvParameters);

/**
 * @SFM3000Task Test SFM3000 (with I2C communication for testing purpose)
 *
 * @param pvParameters Set to NULL.
 */
void SFM3000Task(void *pvParameters);