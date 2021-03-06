#ifndef VOLUME_H_
#define VOLUME_H_

#include <stdint.h>


// Total volume in standard ml
extern volatile int32_t volume;

// Instantaneous flow in standard ml/s
extern volatile int32_t flow;

void init_volume();

// Return 0 if volume updated, otherwise return 1
uint8_t poll_volume();

void reset_volume();


#endif // VOLUME_H_
