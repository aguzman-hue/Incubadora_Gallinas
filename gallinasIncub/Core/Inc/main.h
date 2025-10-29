/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f3xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Private defines */
// LCD Pins
#define RS_Pin GPIO_PIN_4
#define RS_GPIO_Port GPIOA
#define E_Pin  GPIO_PIN_5
#define E_GPIO_Port GPIOA
#define D4_Pin GPIO_PIN_6
#define D4_GPIO_Port GPIOA
#define D5_Pin GPIO_PIN_7
#define D5_GPIO_Port GPIOA
#define D6_Pin GPIO_PIN_7  // Corregido
#define D6_GPIO_Port GPIOB
#define D7_Pin GPIO_PIN_10
#define D7_GPIO_Port GPIOB

// Buzzer
#define Buzzer_Pin GPIO_PIN_9
#define Buzzer_GPIO_Port GPIOA

// Servo
#define Servo_Pin GPIO_PIN_8
#define Servo_GPIO_Port GPIOA

// Sensor de temperatura
#define TempSensor_Pin GPIO_PIN_11
#define TempSensor_GPIO_Port GPIOB

// Display 7 segmentos
#define SEG_A_Pin GPIO_PIN_0
#define SEG_B_Pin GPIO_PIN_1
#define SEG_C_Pin GPIO_PIN_2
#define SEG_D_Pin GPIO_PIN_3
#define SEG_E_Pin GPIO_PIN_4
#define SEG_F_Pin GPIO_PIN_5
#define SEG_G_Pin GPIO_PIN_6
#define SEG_DP_Pin GPIO_PIN_0  // PA0

#define DIG1_Pin GPIO_PIN_1  // PA1
#define DIG2_Pin GPIO_PIN_2  // PA2
#define DIG3_Pin GPIO_PIN_3  // PA3
#define DIG4_Pin GPIO_PIN_8  // PB8

// Keypad
#define ROW_PORT GPIOC
#define COL_PORT GPIOB
#define ROW_PINS {GPIO_PIN_0, GPIO_PIN_1, GPIO_PIN_2, GPIO_PIN_3}
#define COL_PINS {GPIO_PIN_0, GPIO_PIN_1, GPIO_PIN_2, GPIO_PIN_3}
/* USER CODE END Private defines */


/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define B1_Pin GPIO_PIN_13
#define B1_GPIO_Port GPIOC
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA

/* USER CODE BEGIN Private defines */
// LCD Pins
#define RS_Pin GPIO_PIN_4
#define RS_GPIO_Port GPIOA
#define E_Pin  GPIO_PIN_5
#define E_GPIO_Port GPIOA
#define D4_Pin GPIO_PIN_6
#define D4_GPIO_Port GPIOA
#define D5_Pin GPIO_PIN_7
#define D5_GPIO_Port GPIOA
#define D6_Pin GPIO_PIN_7
#define D6_GPIO_Port GPIOB
#define D7_Pin GPIO_PIN_10
#define D7_GPIO_Port GPIOB

// Buzzer
#define Buzzer_Pin GPIO_PIN_9
#define Buzzer_GPIO_Port GPIOA

// Servo (TIM1_CH1 → PA8, si lo usás así)
#define Servo_Pin GPIO_PIN_8
#define Servo_GPIO_Port GPIOA

// Sensor de temperatura (ADC1_IN14 → PB11)
#define TempSensor_Pin GPIO_PIN_11
#define TempSensor_GPIO_Port GPIOB

// Display 7 segmentos (si usás pines específicos, podés agregarlos aquí también)

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
