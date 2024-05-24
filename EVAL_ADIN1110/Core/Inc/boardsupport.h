/*
 *---------------------------------------------------------------------------
 *
 * Copyright (c) 2020, 2021 Analog Devices, Inc. All Rights Reserved.
 * This software is proprietary to Analog Devices, Inc.
 * and its licensors.By using this software you agree to the terms of the
 * associated Analog Devices Software License Agreement.
 *
 *---------------------------------------------------------------------------
 */

#ifndef BOARDSUPPORT_H
#define BOARDSUPPORT_H

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

#include "stm32l4xx_hal.h"
#include "stm32l4xx_it.h"

#include "bsp_config.h"
#include "bsp_def.h"
#include "dma.h"
#include "spi.h"
#include "usart.h"
#include "gpio.h"
#include "sysclock.h"

/* Buffer for debug messages written to UART. */
extern char aDebugString[150u];

void common_Fail(char *FailureReason);
void common_Perf(char *InfoString);

#define DEBUG_MESSAGE(...) \
  do { \
    sprintf(aDebugString,__VA_ARGS__); \
    common_Perf(aDebugString); \
  } while(0)

#define DEBUG_RESULT(s,result,expected_value) \
  do { \
    if ((result) != (expected_value)) { \
      sprintf(aDebugString,"%s  %d", __FILE__,__LINE__); \
      common_Fail(aDebugString); \
      sprintf(aDebugString,"%s Error Code: 0x%08X\n\rFailed\n\r",(s),(result)); \
      common_Perf(aDebugString); \
      exit(0); \
    } \
  } while (0)

typedef void (* ADI_CB) (  /*!< Callback function pointer */
    void      *pCBParam,         /*!< Client supplied callback param */
    uint32_t   Event,            /*!< Event ID specific to the Driver/Service */
    void      *pArg);            /*!< Pointer to the event specific argument */

/*Functions prototypes*/
uint32_t        BSP_InitSystem                  (void);
uint32_t        BSP_SysNow                      (void);
uint32_t        BSP_RegisterIRQCallback         (ADI_CB const *intCallback, void * hDevice);
void            BSP_DisableIRQ                  (void);
void            BSP_EnableIRQ                   (void);
uint32_t        BSP_SetPinMDC                   (bool set);
uint32_t        BSP_SetPinMDIO                  (bool set);
uint16_t        BSP_GetPinMDInput               (void);
void            BSP_ChangeMDIPinDir             (bool output);
uint32_t        BSP_spi0_write_and_read         (uint8_t *pBufferTx, uint8_t *pBufferRx, uint32_t nbBytes);
uint32_t        BSP_spi0_register_callback      (ADI_CB const *pfCallback, void *const pCBParam);
uint32_t        BSP_spi2_write_and_read         (uint8_t *pBufferTx, uint8_t *pBufferRx, uint32_t nbBytes, bool useDma);
uint32_t        BSP_spi2_register_callback      (ADI_CB const *pfCallback, void *const pCBParam);

void            BSP_HWReset                     (bool set);
void            BSP_HeartBeat                   (void);
void            BSP_HeartBeatLed                (bool on);
void            BSP_ErrorLed                    (bool on);
void            BSP_FuncLed1                    (bool on);
void            BSP_FuncLed1Toggle              (void);
void            BSP_FuncLed2                    (bool on);
void            BSP_FuncLed2Toggle              (void);
void            BSP_LedToggleAll                (void);
void            BSP_delayMs                     (uint32_t delay);

extern uint32_t msgWrite                        (char * ptr);
extern HAL_StatusTypeDef submitTxBuffer         (uint8_t * buffer, int nbBytes);

#endif /* BOARDSUPPORT_H */
