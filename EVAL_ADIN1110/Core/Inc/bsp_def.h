/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : bsp_def.h (was "main.h")
  * @brief          : BSP definitions (was "Header for main.c file").
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/**
  *  Portions Copyright (c) 2020, 2021 Analog Devices, Inc.
  */

/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef BSP_DEF_H
#define BSP_DEF_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

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

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define EEPROM_CS_Pin             GPIO_PIN_4
#define EEPROM_CS_GPIO_Port       GPIOA
#define EEPROM_MISO_Pin           GPIO_PIN_7
#define EEPROM_MISO_GPIO_Port     GPIOA
#define EEPROM_SCK_Pin            GPIO_PIN_5
#define EEPROM_SCK_GPIO_Port      GPIOA
#define EEPROM_MISOA6_Pin         GPIO_PIN_6
#define EEPROM_MISOA6_GPIO_Port   GPIOA
#define CFG2_Pin                  GPIO_PIN_2
#define CFG2_GPIO_Port            GPIOB
#define CFG3_Pin                  GPIO_PIN_5
#define CFG3_GPIO_Port            GPIOB
#define AltSS_Pin                 GPIO_PIN_9
#define CFG0_Pin                  GPIO_PIN_0
#define CFG0_GPIO_Port            GPIOB
#define CFG1_Pin                  GPIO_PIN_1
#define CFG1_GPIO_Port            GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* BSP_DEF_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
