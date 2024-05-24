/**
  ******************************************************************************
  * File Name          : SPI.c
  * Description        : This file provides code for the configuration
  *                      of the SPI instances.
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
#include "spi.h"

/* USER CODE BEGIN 0 */
HAL_StatusTypeDef   status;

/* Store the IRQ callback and user parameter locally */
static          ADI_CB gpfSpiCallback = NULL;
static void     *gpSpiCBParam = NULL;
/* USER CODE END 0 */

SPI_HandleTypeDef hEthSpi;
DMA_HandleTypeDef hDmaEthSpiTx;
DMA_HandleTypeDef hDmaEthSpiRx;

/* ETH_SPI init function */
HAL_StatusTypeDef ETH_SPI_Init(void)
{
  HAL_StatusTypeDef   result = HAL_OK;

  hEthSpi.Instance = ETH_SPI;
  hEthSpi.Init.Mode = SPI_MODE_MASTER;
  hEthSpi.Init.Direction = SPI_DIRECTION_2LINES;
  hEthSpi.Init.DataSize = SPI_DATASIZE_8BIT;
  hEthSpi.Init.CLKPolarity = SPI_POLARITY_LOW;
  hEthSpi.Init.CLKPhase = SPI_PHASE_1EDGE;
  hEthSpi.Init.NSS = SPI_NSS_SOFT;
  hEthSpi.Init.BaudRatePrescaler = BSP_CLK_CFG_SPI_BAUDPRESCALER;
  hEthSpi.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hEthSpi.Init.TIMode = SPI_TIMODE_DISABLE;
  hEthSpi.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hEthSpi.Init.CRCPolynomial = 7;
  hEthSpi.Init.CRCLength = SPI_CRC_LENGTH_DATASIZE;
  hEthSpi.Init.NSSPMode = SPI_NSS_PULSE_DISABLE;

  status = HAL_OK;
  result = HAL_SPI_Init(&hEthSpi);

  if (status != HAL_OK)
  {
      result = status;
  }

  return result;
}

void HAL_SPI_MspInit(SPI_HandleTypeDef* spiHandle)
{
  HAL_StatusTypeDef   result = HAL_OK;

  GPIO_InitTypeDef GPIO_InitStruct = {0};

  if(spiHandle->Instance == ETH_SPI)
  {
    ETH_SPI_CLK_ENABLE();

    GPIO_InitStruct.Pin = ETH_SPI_CLK_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = ETH_SPI_CLK_AF;
    HAL_GPIO_Init(ETH_SPI_CLK_GPIO_Port, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = ETH_SPI_MOSI_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = ETH_SPI_MOSI_AF;
    HAL_GPIO_Init(ETH_SPI_MOSI_GPIO_Port, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = ETH_SPI_MISO_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = ETH_SPI_MISO_AF;
    HAL_GPIO_Init(ETH_SPI_MISO_GPIO_Port, &GPIO_InitStruct);

    HAL_I2CEx_EnableFastModePlus(I2C_FASTMODEPLUS_PB9);

    /* SPI DMA Init */
    /* SPI_TX Init */
    hDmaEthSpiTx.Instance = DMA1_Channel1;
    hDmaEthSpiTx.Init.Request = ETH_SPI_DMA_REQ_TX;
    hDmaEthSpiTx.Init.Direction = DMA_MEMORY_TO_PERIPH;
    hDmaEthSpiTx.Init.PeriphInc = DMA_PINC_DISABLE;
    hDmaEthSpiTx.Init.MemInc = DMA_MINC_ENABLE;
    hDmaEthSpiTx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hDmaEthSpiTx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
    hDmaEthSpiTx.Init.Mode = DMA_NORMAL;
    hDmaEthSpiTx.Init.Priority = DMA_PRIORITY_LOW;
    result = HAL_DMA_Init(&hDmaEthSpiTx);
    if (result != HAL_OK)
    {
      goto end;
    }

    __HAL_LINKDMA(spiHandle,hdmatx,hDmaEthSpiTx);

    /* SPI_RX Init */
    hDmaEthSpiRx.Instance = DMA1_Channel2;
    hDmaEthSpiRx.Init.Request = ETH_SPI_DMA_REQ_RX;
    hDmaEthSpiRx.Init.Direction = DMA_PERIPH_TO_MEMORY;
    hDmaEthSpiRx.Init.PeriphInc = DMA_PINC_DISABLE;
    hDmaEthSpiRx.Init.MemInc = DMA_MINC_ENABLE;
    hDmaEthSpiRx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hDmaEthSpiRx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
    hDmaEthSpiRx.Init.Mode = DMA_NORMAL;
    hDmaEthSpiRx.Init.Priority = DMA_PRIORITY_LOW;
    result = HAL_DMA_Init(&hDmaEthSpiRx);
    if (result != HAL_OK)
    {
      goto end;
    }

    __HAL_LINKDMA(spiHandle,hdmarx,hDmaEthSpiRx);

    /* For interrupt-based SPI operation */
    HAL_NVIC_SetPriority(ETH_SPI_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(ETH_SPI_IRQn);
  }

end:
  return;
}

void HAL_SPI_MspDeInit(SPI_HandleTypeDef* spiHandle)
{

  if (spiHandle->Instance == ETH_SPI)
  {
    /* Peripheral clock disable */
    ETH_SPI_CLK_DISABLE();

    /* SPI GPIO Configuration */
    HAL_GPIO_DeInit(ETH_SPI_MOSI_GPIO_Port, ETH_SPI_MOSI_Pin);
    HAL_GPIO_DeInit(ETH_SPI_MISO_GPIO_Port, ETH_SPI_MISO_Pin);
    HAL_GPIO_DeInit(ETH_SPI_CLK_GPIO_Port, ETH_SPI_CLK_Pin);
    HAL_GPIO_DeInit(ETH_SPI_SS_GPIO_Port, ETH_SPI_SS_Pin);

    /* SPI DMA DeInit */
    HAL_DMA_DeInit(spiHandle->hdmatx);
    HAL_DMA_DeInit(spiHandle->hdmarx);
  }
}


HAL_StatusTypeDef HAL_SPI_Write_Read(uint8_t *pBufferTx, uint8_t *pBufferRx, uint32_t nbBytes, bool useDma)
{
    HAL_StatusTypeDef   status;

    /* Assert SS. */
    HAL_GPIO_WritePin(ETH_SPI_SS_GPIO_Port, ETH_SPI_SS_Pin, GPIO_PIN_RESET);

    if (useDma)
    {
        status = HAL_SPI_TransmitReceive_DMA(&hEthSpi, (uint8_t *)pBufferTx, (uint8_t *)pBufferRx, nbBytes);
    }
    else
    {
        status = HAL_SPI_TransmitReceive_IT(&hEthSpi, (uint8_t *)pBufferTx, (uint8_t *)pBufferRx, nbBytes);
    }

    return status;
}

uint32_t HAL_SPI_Register_Callback(ADI_CB const *pfCallback, void *const pCBParam)
{
    gpfSpiCallback = (ADI_CB)pfCallback;
    gpSpiCBParam = pCBParam ;

    return 0;
}

/**
  * @brief  TxRx Transfer completed callback.
  * @param  hspi: SPI handle
  * @note   This example shows a simple way to report end of DMA TxRx transfer, and
  *         you can add your own implementation.
  * @retval None
  */
void HAL_SPI_TxRxCpltCallback(SPI_HandleTypeDef *hspi)
{
    if (hspi->Instance == ETH_SPI)
    {
        /* Deassert SS */
        HAL_GPIO_WritePin(ETH_SPI_SS_GPIO_Port, ETH_SPI_SS_Pin, GPIO_PIN_SET);

        (*gpfSpiCallback)(gpSpiCBParam, 0, NULL);
    }
}

/**
  * @brief  SPI error callbacks.
  * @param  hspi: SPI handle
  * @note   This example shows a simple way to report transfer error, and you can
  *         add your own implementation.
  * @retval None
  */
void HAL_SPI_ErrorCallback(SPI_HandleTypeDef *hspi)
{
  if (hspi->Instance == ETH_SPI)
  {
    HAL_GPIO_WritePin(ETH_SPI_SS_GPIO_Port, ETH_SPI_SS_Pin, GPIO_PIN_SET);//deassert SS

    (*gpfSpiCallback)(gpSpiCBParam, 1, NULL);
  }
}
/* USER CODE END 1 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/