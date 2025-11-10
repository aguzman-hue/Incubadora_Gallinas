/*
 * lcd.c
 *
 *  Created on: Nov 10, 2025
 *      Author: PC
 */

#include "stm32f3xx_hal.h"
#include "lcd.h"

#define RS_Pin GPIO_PIN_0
#define EN_Pin GPIO_PIN_1
#define D4_Pin GPIO_PIN_2
#define D5_Pin GPIO_PIN_3
#define D6_Pin GPIO_PIN_4
#define D7_Pin GPIO_PIN_5
#define LCD_Port GPIOA

static void lcd_send_nibble(uint8_t nibble);
static void lcd_pulse_enable(void);

void lcd_init(void) {
  HAL_Delay(50);
  lcd_send_nibble(0x03); HAL_Delay(10);
  lcd_send_nibble(0x03); HAL_Delay(10);
  lcd_send_nibble(0x03); HAL_Delay(10);
  lcd_send_nibble(0x02); HAL_Delay(10);

  lcd_send_cmd(0x28); // 4-bit, 2 lines
  lcd_send_cmd(0x0C); // Display ON
  lcd_send_cmd(0x06); // Entry mode
  lcd_send_cmd(0x01); // Clear
  HAL_Delay(10);
}

void lcd_clear(void) {
  lcd_send_cmd(0x01);
  HAL_Delay(10);
}

void lcd_setCursor(uint8_t row, uint8_t col) {
  uint8_t addr = (row == 0) ? 0x80 + col : 0xC0 + col;
  lcd_send_cmd(addr);
}

void lcd_print(char *str) {
  while (*str) lcd_send_data(*str++);
}

void lcd_send_cmd(uint8_t cmd) {
  HAL_GPIO_WritePin(LCD_Port, RS_Pin, GPIO_PIN_RESET);
  lcd_send_nibble(cmd >> 4);
  lcd_send_nibble(cmd & 0x0F);
  HAL_Delay(10);
}

void lcd_send_data(uint8_t data) {
  HAL_GPIO_WritePin(LCD_Port, RS_Pin, GPIO_PIN_SET);
  lcd_send_nibble(data >> 4);
  lcd_send_nibble(data & 0x0F);
  HAL_Delay(10);
}

static void lcd_send_nibble(uint8_t nibble) {
  HAL_GPIO_WritePin(LCD_Port, D4_Pin, (nibble & 0x01) ? GPIO_PIN_SET : GPIO_PIN_RESET);
  HAL_GPIO_WritePin(LCD_Port, D5_Pin, (nibble & 0x02) ? GPIO_PIN_SET : GPIO_PIN_RESET);
  HAL_GPIO_WritePin(LCD_Port, D6_Pin, (nibble & 0x04) ? GPIO_PIN_SET : GPIO_PIN_RESET);
  HAL_GPIO_WritePin(LCD_Port, D7_Pin, (nibble & 0x08) ? GPIO_PIN_SET : GPIO_PIN_RESET);
  lcd_pulse_enable();
}

static void lcd_pulse_enable(void) {
  HAL_GPIO_WritePin(LCD_Port, EN_Pin, GPIO_PIN_RESET);
  HAL_Delay(1);
  HAL_GPIO_WritePin(LCD_Port, EN_Pin, GPIO_PIN_SET);
  HAL_Delay(1);
  HAL_GPIO_WritePin(LCD_Port, EN_Pin, GPIO_PIN_RESET);
  HAL_Delay(1);
}

