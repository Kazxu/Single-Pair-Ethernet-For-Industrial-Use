/*
 *---------------------------------------------------------------------------
 *
 * Copyright (c) 2021 Analog Devices, Inc. All Rights Reserved.
 * This software is proprietary to Analog Devices, Inc.
 * and its licensors.By using this software you agree to the terms of the
 * associated Analog Devices Software License Agreement.
 *
 *---------------------------------------------------------------------------
 */

#include "main.h"
#include "lwIP_adin1110_app.h"
#include "lwip/timeouts.h"
#include "tcpecho_raw.h"
#include "lwip/init.h"
#include "netif/ethernet.h"
#include "lwip/dhcp.h"
#include "lwip/opt.h"
#include "lwip/sys.h"
#include "lwip/tcp.h"
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include "stm32l4xx_hal.h"  // Include the main HAL header
#include "tcp_client.h"
#include "string.h"
#include "stdio.h" // For sprintf

static void MX_ADC1_Init(void);
void toStringValue(uint32_t adcValue, char* buffer, size_t bufferSize);


uint32_t adcValue = 10;
ADC_HandleTypeDef hadc1;


char buffer[50];


int main(void)
{
	char temp[10];
	HAL_Init();
	SystemClock_Config();

	MX_ADC1_Init();            // Initialize ADC



    uint32_t       error;
    uint32_t       heartbeatCheckTime = 0;

    adin1110_DeviceStruct_t dev;
    adin1110_DeviceHandle_t hDevice = &dev;

    // DEVICE INFO
    /*
    adin1110_DeviceHandle_t* hDevice;
    struct netif netif;
    uint8_t* macAddress;
    */
    LwIP_ADIN1110_t myConn;

    //TCP STACK INFO I BOARD_T
    board_t boardDetails;


    adi_eth_LinkStatus_e linkStatus;
    //adi_eth_Result_e result;

    /****** System Init *****/
    error = BSP_InitSystem();
    DEBUG_RESULT("BSP_InitSystem", error, 0);

    BSP_HWReset(true);

    boardDetails.mac[0] =	0x00;
    boardDetails.mac[1] =	0xE0;
    boardDetails.mac[2] =	0x22;
    boardDetails.mac[3] =	0xFE;
    boardDetails.mac[4] =	0xDA;
    boardDetails.mac[5] =	0xC9;

    boardDetails.ip_addr[0] =   192;
    boardDetails.ip_addr[1] =   168;
    boardDetails.ip_addr[2] =   20;
    boardDetails.ip_addr[3] =   8;

    boardDetails.net_mask[0] =  255;
    boardDetails.net_mask[1] =  255;
    boardDetails.net_mask[2] =  255;
    boardDetails.net_mask[3] =  0;

    boardDetails.gateway[0] =   192;
    boardDetails.gateway[1] =   168;
    boardDetails.gateway[2] =   20;
    boardDetails.gateway[3] =   1;

    boardDetails.ip_addr_fixed = IP_FIXED;//IP_DYNAMIC OR FIXED;

    error = discoveradin1110(&hDevice);
    DEBUG_RESULT("Failed to access ADIN1110", error, 0);

    //SETUP
    LwIP_StructInit(&myConn, &hDevice, boardDetails.mac);
    //INIT TCP PCB -> DEVICE INFO OG TCP PCB
    /*
      netif_add(&eth->netif, &ip, &mask, &gw, eth,
      LwipADIN1110Init, ethernet_input);

      netif_set_default(&eth->netif);
      netif_set_up(&eth->netif);
     */
    LwIP_Init(&myConn, &boardDetails);
    LwIP_ADIN1110LinkInput(&myConn.netif);
    BSP_delayMs(500);

    netif_set_link_up(&myConn.netif);
    tcpecho_raw_init(buffer);

	sprintf(temp, "DEVICE OK \n");
	HAL_UART_Transmit(&huart1, (uint8_t *)temp, strlen(temp), HAL_MAX_DELAY);

    while(1)
    {

     HAL_ADC_Start(&hadc1);  // Start ADC conversion

     // Poll for conversion completion with a timeout of 20 ms
     HAL_ADC_PollForConversion(&hadc1, 1000);

     // Get the ADC value after conversion completion
     adcValue = HAL_ADC_GetValue(&hadc1);

     // Stop ADC conversion
     HAL_ADC_Stop(&hadc1);

     // Convert the integer ADC value to a string and store it in buffer
     snprintf(buffer, sizeof(buffer), "Value: %lu \r\n", adcValue);

     // Transmit the string via UART
     HAL_UART_Transmit(&huart1, (uint8_t *)buffer, strlen(buffer), HAL_MAX_DELAY);

     if (adcValue > 1 ){
    	  BSP_FuncLed2(true);
     }
     else BSP_FuncLed2(false);

     BSP_delayMs(500);

     uint32_t now  = BSP_SysNow();

  	if (now - heartbeatCheckTime >= 250)
  	      {
  	        heartbeatCheckTime = now;

  	        BSP_HeartBeat();

  	        adin1110_GetLinkStatus(hDevice, &linkStatus);

  	        if ( linkStatus == ADI_ETH_LINK_STATUS_UP )
  	        	BSP_FuncLed1(true);



  	        else
  	        	BSP_FuncLed1(false);

  	        sys_check_timeouts();
  	      }

  	      if ( LwIP_ADIN1110LinkInput(&myConn.netif) == 0)
  	    	  BSP_ErrorLed(false);
  	      else
  	    	  BSP_ErrorLed(true);

}




}


/**
  * @brief ADC1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC1_Init(void)
{

  /* USER CODE BEGIN ADC1_Init 0 */

  /* USER CODE END ADC1_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC1_Init 1 */

  /* USER CODE END ADC1_Init 1 */

  /** Common config
  */
  hadc1.Instance = ADC1;
  hadc1.Init.ClockPrescaler = ADC_CLOCK_ASYNC_DIV1;
  hadc1.Init.Resolution = ADC_RESOLUTION_12B;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.ScanConvMode = ADC_SCAN_DISABLE;
  hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  hadc1.Init.LowPowerAutoWait = DISABLE;
  hadc1.Init.ContinuousConvMode = DISABLE;
  hadc1.Init.NbrOfConversion = 1;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc1.Init.DMAContinuousRequests = DISABLE;
  hadc1.Init.Overrun = ADC_OVR_DATA_PRESERVED;
  hadc1.Init.OversamplingMode = DISABLE;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {

  }

  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_1;
  sConfig.Rank = ADC_REGULAR_RANK_1;
  sConfig.SamplingTime = ADC_SAMPLETIME_2CYCLES_5;
  sConfig.SingleDiff = ADC_SINGLE_ENDED;
  sConfig.OffsetNumber = ADC_OFFSET_NONE;
  sConfig.Offset = 0;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {

  }
  /* USER CODE BEGIN ADC1_Init 2 */

  /* USER CODE END ADC1_Init 2 */

}




