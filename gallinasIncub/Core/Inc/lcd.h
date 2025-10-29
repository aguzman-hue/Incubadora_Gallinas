#ifndef LCD_H
#define LCD_H

#include <stdint.h>

void lcd_init(void);
void lcd_clear(void);
void lcd_setCursor(uint8_t row, uint8_t col);
void lcd_print(char *str);
void lcd_print_int(uint16_t num);
void lcd_print_line(uint8_t row, char *str);
void lcd_print_status(char *estado);

#endif
