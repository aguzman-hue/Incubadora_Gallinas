/*
 * servo.c
 *
 *  Created on: Oct 28, 2025
 *      Author: Ana
 */

#include "servo.h"
#include "stm32f3xx_hal.h"
#include "tim.h" // Para acceder a htim4

#define SERVO_MIN_PULSE 500   // 0° → 0.5 ms
#define SERVO_MAX_PULSE 2500  // 180° → 2.5 ms
#define SERVO_PERIOD     20000 // 20 ms (50 Hz)

void servo_init(void) {
  // Ya configurado en CubeMX como PWM en TIM4_CH1
  HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1);
  servo_set_angle(0); // Posición inicial
}

void servo_set_angle(uint8_t angle) {
  if (angle > 180) angle = 180;

  uint32_t pulse = SERVO_MIN_PULSE + ((SERVO_MAX_PULSE - SERVO_MIN_PULSE) * angle) / 180;

  __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1, pulse);
}
