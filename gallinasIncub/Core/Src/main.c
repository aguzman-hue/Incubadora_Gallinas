#include "main.h"
#include "gpio.h"
#include "lcd.h"
#include "keypad_logic.h"
#include "buzzer.h"
#include "servo.h"
#include "display7seg.h"
#include "adc.h"
#include "tim.h"
#include "stm32f3xx_hal.h"
#include "stm32f3xx_hal_pwr.h"  // Este activa PWR macros





#ifdef USE_FULL_ASSERT
void assert_failed(uint8_t *file, uint32_t line) {
  while (1) {}
}
#endif


void SystemClock_Config(void)
  {
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
    RCC_OscInitStruct.HSIState = RCC_HSI_ON;
    RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
    RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
    RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL12;
    RCC_OscInitStruct.PLL.PREDIV = RCC_PREDIV_DIV1;
    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
    {
      Error_Handler();
    }

    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                                |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
    {
      Error_Handler();
    }
  }


void Error_Handler(void) {
  while (1) {
    // Error loop
  }
  }


int main(void) {
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  MX_ADC1_Init();
  MX_TIM4_Init();            // PWM para servo
  HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1);

  lcd_init();
  buzzer_init();
  servo_init();
  display7seg_init();
  keypad_logic_init();

  lcd_print_line(0, "Tiempo:");
  lcd_print_line(1, "Ingresa min o A-D");

  while (1) {
    keypad_logic_update();

    if (entrada_finalizada()) {
      uint16_t tiempo = get_tiempo_confirmado();  // en segundos

      lcd_clear();
      lcd_print_line(0, "Confirmado:");
      lcd_setCursor(1, 0);
      lcd_print_int(tiempo);
      lcd_print(" seg");

      // Simulación de cuenta regresiva
      while (tiempo > 0) {
        lcd_setCursor(0, 0);
        lcd_print("Restante:");
        lcd_setCursor(1, 0);
        lcd_print_int(tiempo);
        lcd_print("s ");

        displayNumber(tiempo);  // Mostrar en display 7 segmentos

        if (tiempo % 5 == 0) {
          uint16_t temp = read_temperature();
          lcd_setCursor(0, 0);
          lcd_print("Temp:");
          lcd_print_int(temp);
        }

        HAL_Delay(1000); // Simula 1 segundo
        tiempo--;
      }

      // Fin del ciclo
      lcd_clear();
      lcd_print("Fin del ciclo");
      buzzer_on();
      HAL_Delay(2000);
      buzzer_off();
      servo_set_angle(90); // Ejemplo: abrir compuerta

      reset_entrada();
      lcd_clear();
      lcd_print_line(0, "Tiempo:");
      lcd_print_line(1, "Ingresa min o A-D");
    }
  }
}

