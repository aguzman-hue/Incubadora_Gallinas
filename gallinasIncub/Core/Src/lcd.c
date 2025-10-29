/*
 * lcd.c
 *
 *  Created on: Oct 27, 2025
 *      Author: PC
 */

#include "lcd.h"
#include "stm32f3xx_hal.h"
#include <string.h>
#include <stdio.h>

#define RS_PORT GPIOA
#define RS_PIN  GPIO_PIN_4
#define E_PORT  GPIOA
#define E_PIN   GPIO_PIN_5
#define D4_PORT GPIOA
#define D4_PIN  GPIO_PIN_6
#define D5_PORT GPIOA
#define D5_PIN  GPIO_PIN_7
#define D6_PORT GPIOB
#define D6_PIN  GPIO_PIN_7   // ✅ corregido
#define D7_PORT GPIOB
#define D7_PIN  GPIO_PIN_10

static void lcd_send_nibble(uint8_t nibble);
static void lcd_send_cmd(uint8_t cmd);
static void lcd_send_data(uint8_t data);

void lcd_init(void) {
  HAL_Delay(50);
  lcd_send_cmd(0x33);
  lcd_send_cmd(0x32);
  lcd_send_cmd(0x28); // 4-bit, 2 lines
  lcd_send_cmd(0x0C); // Display ON, cursor OFF
  lcd_send_cmd(0x06); // Entry mode
  lcd_clear();
  lcd_setCursor(0, 0);
  lcd_print("LCD OK");
  HAL_Delay(1000);
  lcd_clear();
}

void lcd_clear(void) {
  lcd_send_cmd(0x01);
  HAL_Delay(2);
}

void lcd_setCursor(uint8_t row, uint8_t col) {
  uint8_t addr = (row == 0) ? 0x80 + col : 0xC0 + col;
  lcd_send_cmd(addr);
}

void lcd_print(char *str) {
  while (*str) lcd_send_data(*str++);
}

void lcd_print_int(uint16_t num) {
  char buf[6];
  sprintf(buf, "%u", num);
  lcd_print(buf);
}

void lcd_print_line(uint8_t row, char *str) {
  lcd_setCursor(row, 0);
  lcd_print(str);
}

void lcd_print_status(char *estado) {
  lcd_clear();
  lcd_setCursor(1, 0);
  lcd_print(estado);
}

static void lcd_send_cmd(uint8_t cmd) {
  HAL_GPIO_WritePin(RS_PORT, RS_PIN, GPIO_PIN_RESET);
  lcd_send_nibble(cmd >> 4);
  lcd_send_nibble(cmd & 0x0F);
  HAL_Delay(2);
}

static void lcd_send_data(uint8_t data) {
  HAL_GPIO_WritePin(RS_PORT, RS_PIN, GPIO_PIN_SET);
  lcd_send_nibble(data >> 4);
  lcd_send_nibble(data & 0x0F);
  HAL_Delay(2);
}

static void lcd_send_nibble(uint8_t nibble) {
  HAL_GPIO_WritePin(D4_PORT, D4_PIN, (nibble >> 0) & 1);
  HAL_GPIO_WritePin(D5_PORT, D5_PIN, (nibble >> 1) & 1);
  HAL_GPIO_WritePin(D6_PORT, D6_PIN, (nibble >> 2) & 1);
  HAL_GPIO_WritePin(D7_PORT, D7_PIN, (nibble >> 3) & 1);

  HAL_GPIO_WritePin(E_PORT, E_PIN, GPIO_PIN_SET);
  HAL_Delay(1);
  HAL_GPIO_WritePin(E_PORT, E_PIN, GPIO_PIN_RESET);
}
