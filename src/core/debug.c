#include <stdarg.h>
#include <stdio.h>

#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

#include "hal/uart.h"
#include "hal/io.h"
#include "hal/pins.h"
#include "hal/i2c.h"
#include "hal/time.h"
#include "core/volume.h"


SemaphoreHandle_t debug_print_semaphore;

void init_debug_print_sem() {
    debug_print_semaphore = xSemaphoreCreateMutex();
}

void debug_print(const char *fmt, ...)
{
    char buffer[32];

    va_list args;
    va_start(args, fmt);
    vsnprintf(buffer, sizeof(buffer), fmt, args);
    va_end(args);

    char *c = buffer;
    const int timeout_ticks = 100;
    if (xSemaphoreTake(debug_print_semaphore, timeout_ticks) == pdTRUE)
    {
        while (*c != '\0')
        {
            // TODO: put mutex on uart_transmit
            uart_transmit(*c);
            c++;
        }
        xSemaphoreGive(debug_print_semaphore);
    }
    else
    {
        // What to do here ?
    }
}

void SFM3000Task(void *pvParameters)
{
    init_volume();

    vTaskDelay(100 / portTICK_PERIOD_MS);


    while (1)
    {

        TickType_t xLastWakeTime;
        const TickType_t xFrequency = pdMS_TO_TICKS(200); // which is around 38 ms on scope

        poll_volume();
        debug_print("vol: %lu\r\n", volume);

        //debug_print("current time [us] %lu\r\n", time_us());

        vTaskDelayUntil( &xLastWakeTime, xFrequency );
    }
}
