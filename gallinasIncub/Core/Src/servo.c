/*
 * servo.c
 *
 *  Created on: Oct 28, 2025
 *      Author: Ana
 */

#include "servo.h"
#include "stm32f3xx_hal.h"
#include "tim.h"
#include <stdint.h>

#define SERVO_MIN_PULSE 500   // 0° → 0.5 ms
#define SERVO_MAX_PULSE 2500  // 180° → 2.5 ms
#define SERVO_PERIOD     20000 // 20 ms (50 Hz)

void servo_init(void) {

  HAL_TIM_PWM_Start(&htim1_sm, TIM_CHANNEL_3);
 // servo_set_angle(0); // Posición inicial
}

void servo_set_speed(int8_t speed) {
  // speed: -100 (giro máximo izquierda) a +100 (giro máximo derecha)
  // 0 = detenido
  uint32_t pulse = 1500 + (speed * 9); // escala lineal
  __HAL_TIM_SET_COMPARE(&htim1_sm, TIM_CHANNEL_3, pulse);
}
