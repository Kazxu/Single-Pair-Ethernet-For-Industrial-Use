/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#include "stm32l4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

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
#define D06_Pin GPIO_PIN_8
#define D06_GPIO_Port GPIOB
#define uC_BOOT_Pin GPIO_PIN_3
#define uC_BOOT_GPIO_Port GPIOH
#define JTAG_TRST_Pin GPIO_PIN_4
#define JTAG_TRST_GPIO_Port GPIOB
#define JTAG_TDO_SWO_Pin GPIO_PIN_3
#define JTAG_TDO_SWO_GPIO_Port GPIOB
#define JTAG_TDI_Pin GPIO_PIN_15
#define JTAG_TDI_GPIO_Port GPIOA
#define JTAG_TCK_SWCLK_Pin GPIO_PIN_14
#define JTAG_TCK_SWCLK_GPIO_Port GPIOA
#define JTAG_TMS_SWDIO_Pin GPIO_PIN_13
#define JTAG_TMS_SWDIO_GPIO_Port GPIOA
#define EE_MOSI_Pin GPIO_PIN_12
#define EE_MOSI_GPIO_Port GPIOA
#define LED_uC2_Pin GPIO_PIN_2
#define LED_uC2_GPIO_Port GPIOE
#define D07_Pin GPIO_PIN_9
#define D07_GPIO_Port GPIOB
#define D05_Pin GPIO_PIN_7
#define D05_GPIO_Port GPIOB
#define D09_Pin GPIO_PIN_6
#define D09_GPIO_Port GPIOB
#define D04_Pin GPIO_PIN_6
#define D04_GPIO_Port GPIOD
#define RAM_octospi_Pin GPIO_PIN_3
#define RAM_octospi_GPIO_Port GPIOD
#define D11_MOSI_Pin GPIO_PIN_12
#define D11_MOSI_GPIO_Port GPIOC
#define D13_SCLK_Pin GPIO_PIN_10
#define D13_SCLK_GPIO_Port GPIOC
#define EE_MISO_Pin GPIO_PIN_11
#define EE_MISO_GPIO_Port GPIOA
#define LED_uC1_Pin GPIO_PIN_13
#define LED_uC1_GPIO_Port GPIOC
#define D08_Pin GPIO_PIN_5
#define D08_GPIO_Port GPIOB
#define D19_SCL_Pin GPIO_PIN_14
#define D19_SCL_GPIO_Port GPIOG
#define D18_SDA_Pin GPIO_PIN_13
#define D18_SDA_GPIO_Port GPIOG
#define D03_Pin GPIO_PIN_2
#define D03_GPIO_Port GPIOD
#define D12_MISO_RX_Pin GPIO_PIN_11
#define D12_MISO_RX_GPIO_Port GPIOC
#define USB_UART_RX_Pin GPIO_PIN_10
#define USB_UART_RX_GPIO_Port GPIOA
#define uC_OSC32_IN_Pin GPIO_PIN_14
#define uC_OSC32_IN_GPIO_Port GPIOC
#define LED_uC3_Pin GPIO_PIN_6
#define LED_uC3_GPIO_Port GPIOE
#define D10_CS_N_Pin GPIO_PIN_12
#define D10_CS_N_GPIO_Port GPIOG
#define RAM_octospiG10_Pin GPIO_PIN_10
#define RAM_octospiG10_GPIO_Port GPIOG
#define RAM_ZZ_Pin GPIO_PIN_9
#define RAM_ZZ_GPIO_Port GPIOG
#define USB_UART_TX_Pin GPIO_PIN_9
#define USB_UART_TX_GPIO_Port GPIOA
#define T1L_LINK_ST_Pin GPIO_PIN_8
#define T1L_LINK_ST_GPIO_Port GPIOA
#define T1L_CFG1_Pin GPIO_PIN_9
#define T1L_CFG1_GPIO_Port GPIOC
#define uC_OSC32_OUT_Pin GPIO_PIN_15
#define uC_OSC32_OUT_GPIO_Port GPIOC
#define T1L_CFG0_Pin GPIO_PIN_8
#define T1L_CFG0_GPIO_Port GPIOC
#define T1L_RESET_N_Pin GPIO_PIN_7
#define T1L_RESET_N_GPIO_Port GPIOC
#define T1L_TS_CAPTURE_Pin GPIO_PIN_6
#define T1L_TS_CAPTURE_GPIO_Port GPIOC
#define uC_OSC_IN_Pin GPIO_PIN_0
#define uC_OSC_IN_GPIO_Port GPIOH
#define uC_OSC_OUT_Pin GPIO_PIN_1
#define uC_OSC_OUT_GPIO_Port GPIOH
#define CFG_uC3_Pin GPIO_PIN_11
#define CFG_uC3_GPIO_Port GPIOG
#define CFG_uC2_Pin GPIO_PIN_6
#define CFG_uC2_GPIO_Port GPIOG
#define SENSOR_SCL_Pin GPIO_PIN_7
#define SENSOR_SCL_GPIO_Port GPIOG
#define EE_CS_N_Pin GPIO_PIN_4
#define EE_CS_N_GPIO_Port GPIOA
#define EEQ_IO2_Pin GPIO_PIN_7
#define EEQ_IO2_GPIO_Port GPIOA
#define SENSOR_SDA_Pin GPIO_PIN_8
#define SENSOR_SDA_GPIO_Port GPIOG
#define LED_uC4_Pin GPIO_PIN_15
#define LED_uC4_GPIO_Port GPIOG
#define D02_Pin GPIO_PIN_2
#define D02_GPIO_Port GPIOA
#define EE_SCLK_Pin GPIO_PIN_5
#define EE_SCLK_GPIO_Port GPIOA
#define CFG_uC1_Pin GPIO_PIN_11
#define CFG_uC1_GPIO_Port GPIOF
#define T1L_MOSI_Pin GPIO_PIN_15
#define T1L_MOSI_GPIO_Port GPIOB
#define T1L_MISO_Pin GPIO_PIN_14
#define T1L_MISO_GPIO_Port GPIOB
#define T1L_SCLK_Pin GPIO_PIN_13
#define T1L_SCLK_GPIO_Port GPIOB
#define D01_TX_Pin GPIO_PIN_0
#define D01_TX_GPIO_Port GPIOA
#define EEQ_CLK_Pin GPIO_PIN_3
#define EEQ_CLK_GPIO_Port GPIOA
#define EEQ_IO3_Pin GPIO_PIN_6
#define EEQ_IO3_GPIO_Port GPIOA
#define CFG_uC0_Pin GPIO_PIN_2
#define CFG_uC0_GPIO_Port GPIOB
#define T1L_TS_TIMER_Pin GPIO_PIN_10
#define T1L_TS_TIMER_GPIO_Port GPIOB
#define T1L_INT_N_Pin GPIO_PIN_11
#define T1L_INT_N_GPIO_Port GPIOB
#define T1L_CS_N_Pin GPIO_PIN_12
#define T1L_CS_N_GPIO_Port GPIOB
#define D00_RX_Pin GPIO_PIN_1
#define D00_RX_GPIO_Port GPIOA
#define EEQ_IO1_Pin GPIO_PIN_0
#define EEQ_IO1_GPIO_Port GPIOB
#define EEQ_IO0_Pin GPIO_PIN_1
#define EEQ_IO0_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
