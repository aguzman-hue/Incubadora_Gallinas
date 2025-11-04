#include "main.h"
#include "adc.h"
#include "tim.h"
#include "gpio.h"

/* USER CODE BEGIN Includes */
#include "lcd.h"
#include "keypad_logic.h"
#include "buzzer.h"
#include "servo.h"
/* USER CODE END Includes */

void SystemClock_Config(void)
{
  // configuración del reloj (CubeMX la genera)
}

int main(void)
{
  HAL_Init();
  SystemClock_Config();

  MX_GPIO_Init();
  MX_TIM4_Init();
  MX_ADC1_Init();
  MX_TIM1_Init();

  lcd_init();
  buzzer_init();
  servo_init();
  keypad_logic_init();

  HAL_TIM_PWM_Start(&htim1_sm, TIM_CHANNEL_3); // PWM para servo

  lcd_clear();
  lcd_print_line(0, "Tiempo:");
  lcd_print_line(1, "Ingrese segs");

  while (1)
  {
    KeypadEvent evento = keypad_logic_update();

    if (evento == KEYPAD_EVENT_CONFIRMADO)
    {
      uint16_t tiempo = get_tiempo_confirmado();

      lcd_clear();
      lcd_print_line(0, "CONFIRMADO");
      lcd_print_number(1, tiempo);
      HAL_Delay(1500);

      for (uint16_t i = tiempo; i > 0; i--)
      {
        lcd_clear();
        lcd_print_line(0, "Contando...");
        lcd_print_number(1, i);
        HAL_Delay(1000);

        if (i % 5 == 0)
        {
          lcd_clear();
          lcd_print_line(0, "Midiendo temp...");
          HAL_Delay(1500);

          uint16_t temp_adc = read_temperature();
          lcd_clear();
          lcd_print_line(0, "Temp ADC:");
          lcd_print_number(1, temp_adc);
          HAL_Delay(1000);

          if (temp_adc < 471) // ≈38°C
          {
            lcd_clear();
            lcd_print_line(0, "ALERTA");
           // buzzer_beep(2);
            HAL_Delay(1500);
          }
        }
      }

      lcd_clear();
      lcd_print_line(0, "Ciclo finalizado");
      HAL_Delay(1500);

      lcd_clear();
      lcd_print_line(0, "Girando servo...");
      servo_set_speed(100);
      HAL_Delay(1000);
      servo_set_speed(-100);
      HAL_Delay(1000);
      servo_set_speed(0);

      reset_entrada();
      lcd_clear();
      lcd_print_line(0, "Tiempo:");
      lcd_print_line(1, "Ingrese segs");
    }

    if (evento == KEYPAD_EVENT_CANCELADO)
    {
      lcd_clear();
      lcd_print_line(0, "Cancelado");
      HAL_Delay(1000);
      lcd_print_line(0, "Tiempo:");
      lcd_print_line(1, "Ingrese segs");
    }
  }
}

#ifdef USE_FULL_ASSERT
void assert_failed(uint8_t *file, uint32_t line)
{
  // Podés dejarlo vacío o imprimir algo si querés
}
#endif

void Error_Handler(void)
{
  __disable_irq();
  while (1) {}
}
