#ifndef PINMAP_H
#define PINMAP_H

// LCD 16x2 (modo 4 bits)
#define LCD_RS_PORT GPIOA
#define LCD_RS_PIN  GPIO_PIN_4
#define LCD_E_PORT  GPIOA
#define LCD_E_PIN   GPIO_PIN_5
#define LCD_D4_PORT GPIOA
#define LCD_D4_PIN  GPIO_PIN_6
#define LCD_D5_PORT GPIOA
#define LCD_D5_PIN  GPIO_PIN_7
#define LCD_D6_PORT GPIOB
#define LCD_D6_PIN  GPIO_PIN_7  // Corregido
#define LCD_D7_PORT GPIOB
#define LCD_D7_PIN  GPIO_PIN_10

// Buzzer
#define BUZZER_PORT GPIOA
#define BUZZER_PIN  GPIO_PIN_8  // PA8 según tu mapeo

// Servo
#define SERVO_TIM   htim1
#define SERVO_CH    TIM_CHANNEL_1

// Display 7 segmentos (segmentos A–G)
#define SEG_PORT    GPIOB
#define SEG_A_PIN   GPIO_PIN_0
#define SEG_B_PIN   GPIO_PIN_1
#define SEG_C_PIN   GPIO_PIN_2
#define SEG_D_PIN   GPIO_PIN_3
#define SEG_E_PIN   GPIO_PIN_4
#define SEG_F_PIN   GPIO_PIN_5
#define SEG_G_PIN   GPIO_PIN_6
#define SEG_DP_PORT GPIOA
#define SEG_DP_PIN  GPIO_PIN_0

// Dígitos multiplexados
#define DIGIT1_PIN  GPIO_PIN_1
#define DIGIT1_PORT GPIOA
#define DIGIT2_PIN  GPIO_PIN_2
#define DIGIT2_PORT GPIOA
#define DIGIT3_PIN  GPIO_PIN_3
#define DIGIT3_PORT GPIOA
#define DIGIT4_PIN  GPIO_PIN_8
#define DIGIT4_PORT GPIOB

#endif
