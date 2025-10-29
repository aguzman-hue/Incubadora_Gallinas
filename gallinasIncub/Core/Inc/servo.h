#ifndef SERVO_H
#define SERVO_H

#include <stdint.h>

void servo_init(void);
void servo_set_angle(uint8_t angle); // ángulo entre 0 y 180

#endif
