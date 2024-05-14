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

//FOR Å ENDRE VÅR TCP SERVER er i TCPECHO_RAW.C
/* USER CODE BEGIN Includes */


#include "tcp_client.h"

uint32_t adcValue;
ADC_HandleTypeDef hadc1;


char buffer[10];

int main(void)
{

	SystemClock_Config();
	HAL_Init();
	ADC_Init();            // Initialize ADC


    uint32_t       error;
    uint32_t       heartbeatCheckTime = 0;

    adin1110_DeviceStruct_t dev;
    adin1110_DeviceHandle_t hDevice = &dev;

    // DEVICE INFO
    /* INKLUDERT

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

    boardDetails.ip_addr_fixed = IP_FIXED;//IP_DYNAMIC;

    error = discoveradin1110(&hDevice);
    DEBUG_RESULT("Failed to access ADIN1110", error, 0);

    //SETTER OP DRITT GREIER
    LwIP_StructInit(&myConn, &hDevice, boardDetails.mac);
    //INIT TCP PCB MED FORHOLD TIL DEVICE INFO OG TCP PCB
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
    tcpecho_raw_init();


    while(1)
    {
       HAL_ADC_Start(&hadc1);
        // Poll for conversion completion
       HAL_ADC_PollForConversion(&hadc1, 1000);
            // Get the ADC value
      toStringValue(HAL_ADC_GetValue(&hadc1), buffer, sizeof(buffer));
      HAL_ADC_Stop(&hadc1);

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



uint32_t Read_ADC_Value(void) {
    // Start the ADC conversion
    HAL_ADC_Start(&hadc1);

    // Poll for conversion completion
    HAL_ADC_PollForConversion(&hadc1, 1);
        // Get the ADC value
    return HAL_ADC_GetValue(&hadc1);


     // Return 0 if there was an error
}



/**
  * @brief ADC1 Initialization Function
  * @param None
  * @retval None
  */void ADC_Init(void) {
	    ADC_ChannelConfTypeDef sConfig = {0};

	    hadc1.Instance = ADC1;
	    hadc1.Init.ClockPrescaler = ADC_CLOCK_ASYNC_DIV1;
	    hadc1.Init.Resolution = ADC_RESOLUTION_12B;
	    hadc1.Init.ScanConvMode = DISABLE;  // For single channel
	    hadc1.Init.ContinuousConvMode = ENABLE;  // Continuous conversion
	    hadc1.Init.DiscontinuousConvMode = DISABLE;
	    hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
	    hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
	    hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
	    hadc1.Init.NbrOfConversion = 1;
	    hadc1.Init.DMAContinuousRequests = DISABLE;
	    hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
	    if (HAL_ADC_Init(&hadc1) != HAL_OK) {
	        //Error_Handler();
	    }

	    sConfig.Channel = ADC_CHANNEL_1;
	    sConfig.Rank = ADC_REGULAR_RANK_1;
	    sConfig.SamplingTime = ADC_SAMPLETIME_2CYCLES_5;
	    sConfig.SingleDiff = ADC_SINGLE_ENDED;
	    sConfig.OffsetNumber = ADC_OFFSET_NONE;
	    sConfig.Offset = 0;
	    sConfig.SamplingTime = ADC_SAMPLETIME_92CYCLES_5;  // Increase sampling time

	    if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK) {
	        //Error_Handler();
	    }
	}




#include <stdio.h> // For sprintf

void toStringValue(uint32_t adcValue, char* buffer, size_t bufferSize) {
    if (buffer != NULL && bufferSize > 0) {
        snprintf(buffer, bufferSize, "%lu\n", adcValue); //convert integer to string
    }
}
