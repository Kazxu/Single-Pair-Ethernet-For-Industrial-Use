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
#ifndef LWIP_ADIN1110__H
#define LWIP_ADIN1110__H

#include "adin1110.h"

#include "lwip/netif.h"


#define IP_FIXED 1
#define IP_DYNAMIC 0
#define MAX_P_QUEUE_SZ 1518
#define MAX_P_QUEUE 5


typedef struct _pQueue
{

  uint8_t pData[MAX_P_QUEUE][MAX_P_QUEUE_SZ];
  int lenData[MAX_P_QUEUE];
  int32_t nRdQ;

  int32_t nWrQ;

} pQueue_t;

typedef struct
{
    uint8_t adin1110Error;// problem with the phy
    uint8_t ip_addr_fixed;//DHCP or fixed IP
    uint8_t ip_addr[4];/*IP address*/
    uint8_t net_mask[4];/*network mask*/
    uint8_t gateway[4];/*IP address*/
    uint8_t mac[6];/*MAC address*/
 }board_t;

typedef struct Lwip_adin1110_s
{
    adin1110_DeviceHandle_t* hDevice;
    struct netif netif;
    uint8_t* macAddress;
} LwIP_ADIN1110_t;


uint32_t sys_now(void);
adi_eth_Result_e LwIP_StructInit(LwIP_ADIN1110_t* eth, adin1110_DeviceHandle_t* hDevice,  uint8_t macAddress[6]);
void LwIP_Init( LwIP_ADIN1110_t* eth,  board_t *boardDetails);
err_t LwIP_ADIN1110LinkInput(struct netif *netif);
uint32_t discoveradin1110(adin1110_DeviceHandle_t *hDevice);
void cbLinkChange(void *pCBParam, uint32_t Event, void *pArg);
#endif /*LWIP_ADIN1110__H*/
