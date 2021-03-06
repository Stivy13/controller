#ifndef MOTOR_CONTROL_H_
#define MOTOR_CONTROL_H_

#include "FreeRTOS.h"

#define MOTOR_NOTIF_LIM_DOWN 0x01
#define MOTOR_NOTIF_LIM_UP 0x02
#define MOTOR_NOTIF_HALT 0x04
#define MOTOR_NOTIF_MOVEMENT_FINISHED 0x08
#define MOTOR_NOTIF_START_CALIBRATION 0x10
#define MOTOR_NOTIF_START 0x20
#define MOTOR_NOTIF_EMERGENCY_STOP 0x40
#define MOTOR_NOTIF_OVER_PRESSURE 0x80

#define MOTOR_FULL_BITS 0xFFFFFFFF
#define MOTOR_USTEPS 16

typedef enum {
    motorInit,
    motorCalibrating,
    motorFlowCheck,
    motorStopped,
    motorRunning,
} MotorState_t;

typedef enum {
    calibDown,
    calibUp,
    calibPosEnd,
} CalibState_t;

typedef enum {
    flowVol,
    flowVolEnd
} FlowState_t;

typedef enum {
    insp,
    plateau,
    exp,
    cycleEnd,
    startNewCycle
} BreathState_t;

extern volatile MotorState_t motorState;
extern volatile CalibState_t calibState;
extern volatile BreathState_t breathState;
extern volatile FlowState_t flowState;

void init_motor();

/**
 * @MotorControlTask Control the motor.
 *
 * @param pvParameters Set to NULL.
 */
void MotorControlTask(void *pvParameters);


#endif // MOTOR_CONTROL_H_
