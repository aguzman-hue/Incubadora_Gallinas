#ifndef INC_KEYPAD_H_
#define INC_KEYPAD_H_

#include <stdint.h>
#include "stm32f3xx_hal.h"

void keypad_init(void);
char keypad_read(void);

#endif /* INC_KEYPAD_H_ */



