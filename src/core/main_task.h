#ifndef MAINTASK_H_
#define MAINTASK_H_

#include "FreeRTOS.h"
#include "task.h"

// tidal vol in tens of mL
#define DEFAULT_TIDAL_VOL 30
#define MAX_TIDAL_VOL 60
#define MIN_TIDAL_VOL 20
#define INC_TIDAL_VOL 2

// breath per min
#define DEFAULT_BPM 15
#define MAX_BPM 30
#define MIN_BPM 12
#define INC_BPM 1

// I:E ratio
#define DEFAULT_IE 1
#define MAX_IE 3
#define MIN_IE 1
#define INC_IE 1

// Pmax
#define DEFAULT_PMAX 38
#define MAX_PMAX 40
#define MIN_PMAX 30
#define INC_PMAX 1

#define ALARM_AUTO_UNMUTE_SEC 120 * 1000L

// Alarm notification values
#define ALARM_NOTIF_LOW_PRESSURE 0x01
#define ALARM_NOTIF_ABN_VOLUME 0x02
#define ALARM_NOTIF_ABN_FREQ 0x04

#define ALARM_NOTIF_OVERPRESSURE 0x08
#define ALARM_NOTIF_NO_PRESSURE 0x10
#define ALARM_NOTIF_HIGH_PRESSURE 0x20
#define ALARM_NOTIF_HIGH_TEMP 0x40

#define ALARM_NOTIF_PATIENT_CONNECTED 0x80

// in tens of ml
extern uint8_t tidal_vol;
extern uint8_t bpm;
extern uint8_t ie;
extern uint8_t p_max;
extern uint8_t extra_param;

void initMainTask();
void MainTask(void *pvParameters);
/* returns 1 if the global state is stop or run, otherwise 0 */
uint8_t stoppedOrRunning();

#endif // MAINTASK_H_
