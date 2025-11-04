#ifndef KEYPAD_LOGIC_H
#define KEYPAD_LOGIC_H

#include <stdint.h>
#include <stdbool.h>

typedef enum {
  KEYPAD_EVENT_NONE,
  KEYPAD_EVENT_CONFIRMADO,
  KEYPAD_EVENT_CANCELADO
} KeypadEvent;

void keypad_logic_init(void);
KeypadEvent keypad_logic_update(void);
bool entrada_finalizada(void);
uint16_t get_tiempo_confirmado(void);
void reset_entrada(void);

#endif
