/**
  ******************************************************************************
  * File Name          : gpio.c
  * Description        : This file provides code for the configuration
  *                      of all used GPIO pins.
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

/* Includes ------------------------------------------------------------------*/
#include "gpio.h"

/* USER CODE BEGIN 0 */

/* Store the IRQ callback and user parameter locally */
static          ADI_CB gpfIntCallback = NULL;
static void     *gpIntCBParam = NULL;
/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/** Configure pins as
        * Analog
        * Input
        * Output
        * EVENT_OUT
        * EXTI
*/
void GPIO_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    /* GPIO Ports Clock Enable */
    ETH_GPIO_ENABLE;
    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_GPIOE_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOH_CLK_ENABLE();
    __HAL_RCC_GPIOD_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOG_CLK_ENABLE();
    __HAL_RCC_GPIOF_CLK_ENABLE();

    /*Configure GPIO pin Output Level */
#if defined(EVAL_ADIN1110EBZ)
    HAL_GPIO_WritePin(BSP_LED1_PORT, BSP_LED1_PIN, GPIO_PIN_SET);
    HAL_GPIO_WritePin(BSP_LED2_PORT, BSP_LED2_PIN, GPIO_PIN_SET);
    HAL_GPIO_WritePin(BSP_LED3_PORT, BSP_LED3_PIN, GPIO_PIN_SET);
    HAL_GPIO_WritePin(BSP_LED4_PORT, BSP_LED4_PIN, GPIO_PIN_SET);

    HAL_PWREx_EnableVddIO2();
#else
    HAL_GPIO_WritePin(BSP_LED1_PORT, BSP_LED1_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(BSP_LED2_PORT, BSP_LED2_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(BSP_LED3_PORT, BSP_LED3_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(BSP_LED4_PORT, BSP_LED4_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(BSP_LED5_PORT, BSP_LED5_PIN, GPIO_PIN_RESET);
#endif
    HAL_GPIO_WritePin(ETH_SPI_SS_GPIO_Port, ETH_SPI_SS_Pin, GPIO_PIN_RESET);

    /*Configure GPIO pin : PtPin */
    HAL_GPIO_WritePin(ETH_RESET_GPIO_Port, ETH_RESET_Pin, GPIO_PIN_SET);
    GPIO_InitStruct.Pin = ETH_RESET_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(ETH_RESET_GPIO_Port, &GPIO_InitStruct);

    /*Configure GPIO pins : PEPin PEPin */
    GPIO_InitStruct.Pin = BSP_LED4_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(BSP_LED4_PORT, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = BSP_LED2_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(BSP_LED2_PORT, &GPIO_InitStruct);

    /*Configure GPIO pins : PBPin PBPin PBPin */
    GPIO_InitStruct.Pin = BSP_LED1_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(BSP_LED1_PORT, &GPIO_InitStruct);

#if !defined(EVAL_ADIN1110EBZ)
    GPIO_InitStruct.Pin = BSP_LED5_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(BSP_LED5_PORT, &GPIO_InitStruct);
#endif

    GPIO_InitStruct.Pin = BSP_LED3_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(BSP_LED3_PORT, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = ETH_SPI_SS_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(ETH_SPI_SS_GPIO_Port, &GPIO_InitStruct);

    /*Configure GPIO pins : PBPin PBPin PBPin dassdaada*/
    // Enable the GPIO Clock for Port C
    GPIO_InitStruct.Pin = CFG0_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_ANALOG_ADC_CONTROL;;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = CFG1_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(CFG1_GPIO_Port, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = CFG2_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_ANALOG_ADC_CONTROL;;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(CFG2_GPIO_Port, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = CFG3_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(CFG3_GPIO_Port, &GPIO_InitStruct);

    /*Configure GPIO pin : PtPin */
    GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Pin = ETH_INT_N_Pin;
    HAL_GPIO_Init(ETH_INT_N_GPIO_Port, &GPIO_InitStruct);






}

/* USER CODE BEGIN 2 */
void MX_Led_Toggle(void)
{
	HAL_GPIO_TogglePin(BSP_LED3_PORT, BSP_LED3_PIN);
#if !defined(EVAL_ADIN1110EBZ)
	HAL_GPIO_TogglePin(BSP_LED5_PORT, BSP_LED5_PIN);
#endif
	HAL_GPIO_TogglePin(BSP_LED1_PORT, BSP_LED1_PIN);
	HAL_GPIO_TogglePin(BSP_LED4_PORT, BSP_LED4_PIN);
	HAL_GPIO_TogglePin(BSP_LED2_PORT, BSP_LED2_PIN);
}
/* USER CODE END 2 */


uint32_t HAL_INT_N_Register_Callback(ADI_CB const *pfCallback, void *const pCBParam)
{
    HAL_NVIC_SetPriority(ETH_INT_N_IRQn, 0xF, 0);

    gpfIntCallback = (ADI_CB)pfCallback;
    gpIntCBParam = pCBParam ;

    return 0;
}

/**
  * @brief EXTI line detection callbacks
  * @param GPIO_Pin: Specifies the pins connected EXTI line
  * @retval None
  */

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
   if (GPIO_Pin == ETH_INT_N_Pin)
  {
    if (gpfIntCallback)
    {
        (*gpfIntCallback)(gpIntCBParam, 0, NULL);
    }
  }

}


uint32_t HAL_INT_N_DisableIRQ(void)
{
    HAL_NVIC_DisableIRQ(ETH_INT_N_IRQn);

    return 0;
}

uint32_t HAL_INT_N_EnableIRQ(void)
{
    HAL_NVIC_EnableIRQ(ETH_INT_N_IRQn);

    return 0;
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
