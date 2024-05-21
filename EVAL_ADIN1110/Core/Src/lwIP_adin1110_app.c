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

#include "lwIP_adin1110_app.h"
#include "adin1110.h"
#include "netif/etharp.h"
#include "lwip/ip_addr.h"
#include "lwip/snmp.h"
#include "lwip/dhcp.h"
#include "lwip/init.h"
#include "lwip/timeouts.h"
#include "lwip/arch.h"
#include "lwip/apps/httpd.h"

#define ADIN1110_INIT_ITER  (5)
/* Extra 4 bytes for FCS and 2 bytes for the frame header */
#define MAX_FRAME_BUF_SIZE  (MAX_FRAME_SIZE + 4 + 2)

/* Frame size in bytes, applies to each of the transmitted frames. */
/* The value should be between 64 and 1518. */
#define FRAME_SIZE          (1518)

/* Number of buffer descriptors to use for both Tx and Rx in this example */
#define BUFF_DESC_COUNT     (5)

#define ETHERNET_MTU        (1500)

HAL_ALIGNED_PRAGMA(4)
static uint8_t          rxBuf[BUFF_DESC_COUNT][MAX_FRAME_BUF_SIZE] HAL_ALIGNED_ATTRIBUTE(4);
static adi_eth_BufDesc_t       rxBufDesc[BUFF_DESC_COUNT];

HAL_ALIGNED_PRAGMA(4)
static uint8_t          txBuf[BUFF_DESC_COUNT][MAX_FRAME_BUF_SIZE] HAL_ALIGNED_ATTRIBUTE(4);


adi_eth_BufDesc_t       txBufDesc[BUFF_DESC_COUNT];
bool                    txBufAvailable[BUFF_DESC_COUNT];
int                     txBufIndex = 0;

#define MAX_PQ 1
HAL_ALIGNED_PRAGMA(4)
pQueue_t pQ[MAX_PQ] HAL_ALIGNED_ATTRIBUTE(4);;

/* Define name of the network interface. */
#define IFNAME0         'e'
#define IFNAME1         '0'
#define HOSTNAME         "ADI_10BASE-T1L_Demo"
#define NETIF_LINK_SPEED_IN_BPS 10000000


/*Function Prototypes*/
static void            initPQueue(pQueue_t* pQ);
static void*           readPQ(pQueue_t* pQ);
static void            writePQ(pQueue_t* pQ, uint8_t *ethFrame, int lenEthFrame);
static uint32_t        pDataAvailable(pQueue_t* pQ);

/* Example configuration */
uint8_t devMem[ADIN1110_DEVICE_SIZE];

adin1110_DriverConfig_t drvConfig = {
    .pDevMem    = (void *)devMem,
    .devMemSize = sizeof(devMem),
    .fcsCheckEn = false,
};

adi_eth_LinkStatus_e    linkStatus;


bool linkStatusChanged;
adi_eth_LinkStatus_e linkState ;



static void txCallback(void *pCBParam, uint32_t Event, void *pArg)
{
    txBufAvailable[0] = true;
}

static void rxCallback(void *pCBParam, uint32_t Event, void *pArg)
{
    adin1110_DeviceHandle_t hDevice = (adin1110_DeviceHandle_t)pCBParam;
    adi_eth_BufDesc_t       *pRxBufDesc;

    pRxBufDesc = (adi_eth_BufDesc_t *)pArg;

    uint16_t frmLen = pRxBufDesc->trxSize;

    int unicast = ((pRxBufDesc->pBuf[0] & 0x01) == 0);

    LINK_STATS_INC(link.recv);
    MIB2_STATS_NETIF_ADD(netif, ifinoctets, p->tot_len);
    if (unicast)
    {
      MIB2_STATS_NETIF_INC(netif, ifinucastpkts);
    }
    else
    {
      MIB2_STATS_NETIF_INC(netif, ifinnucastpkts);
    }

    writePQ(&pQ[0], pRxBufDesc->pBuf, frmLen);
    /* Since we're not doing anything with the Rx buffer in this example, */
    /* we are re-submitting it to the queue. */
    rxBufDesc[0].pBuf = &rxBuf[0][0];
    rxBufDesc[0].bufSize = MAX_FRAME_BUF_SIZE;
    rxBufDesc[0].cbFunc = rxCallback;
    adin1110_SubmitRxBuffer(hDevice, pRxBufDesc);
}

void cbLinkChange(void *pCBParam, uint32_t Event, void *pArg)
{
    adi_eth_LinkStatus_e    linkStatus;

    linkStatus = *(adi_eth_LinkStatus_e *)pArg;
    linkState = linkStatus;
    linkStatusChanged = true;
    (void)linkStatus;
}


uint32_t adi_phy_GetLinkStatus(uint8_t *status)
{
    uint32_t    result = 0;

    *status = (linkState ==  ADI_ETH_LINK_STATUS_UP)?  1: 0;
    return result;
}


uint32_t sys_now(void)
{
  return BSP_SysNow();
}

err_t LwIP_ADIN1110LinkInput(struct netif *netif)
{
    if (pDataAvailable(&pQ[0]) == 0)
    {
      return ERR_OK;
    }
    else
    {
      struct pbuf *p = (struct pbuf *)readPQ(&pQ[0]);
      if (p == NULL)
      {
        return ERR_MEM;
      }

      if (netif->input(p, netif) != ERR_OK)
      {
        LWIP_DEBUGF(NETIF_DEBUG, ("IP input error\r\n"));
        pbuf_free(p);
        p = NULL;
      }
    }
   return  ERR_OK;
}


static err_t low_level_output(struct netif *netif, struct pbuf *p)
{
   LwIP_ADIN1110_t* eth = (LwIP_ADIN1110_t*) netif->state;

    adin1110_DeviceHandle_t *hDevice =   eth->hDevice;

    struct pbuf *pp;
    uint16_t frameLen = 0;
    int total_len = 0;

    for(pp = p, total_len = 0; pp != NULL; pp = pp->next)
    {
      frameLen =  pp->len ;

      if(frameLen < 2)
      {
        continue;
      }

      memcpy(txBuf[txBufIndex] + total_len  ,(unsigned char*) pp->payload, frameLen);
      total_len += frameLen ;

      if(total_len >= MAX_FRAME_BUF_SIZE)
      {
        return ERR_VAL;
      }
    }

    LINK_STATS_INC(link.xmit);
    MIB2_STATS_NETIF_ADD(netif, ifoutoctets, total_len);

    if(total_len < MIN_FRAME_SIZE) // Pad to minimum ETH size
    {
      total_len = MIN_FRAME_SIZE;
    }

    txBufDesc[txBufIndex].pBuf = &txBuf[txBufIndex][0];
    txBufDesc[txBufIndex].trxSize = total_len;
    txBufDesc[txBufIndex].bufSize = MAX_FRAME_BUF_SIZE;
    txBufDesc[txBufIndex].egressCapt = ADI_MAC_EGRESS_CAPTURE_NONE;
    txBufDesc[txBufIndex].cbFunc = txCallback;

    if ((txBufDesc[txBufIndex].pBuf[0] & 1) != 0)
    {
      /* broadcast or multicast packet*/
      MIB2_STATS_NETIF_INC(netif, ifoutnucastpkts);
    }
    else
    {
      /* unicast packet */
      MIB2_STATS_NETIF_INC(netif, ifoutucastpkts);
    }

    while(adin1110_SubmitTxBuffer(*hDevice, &txBufDesc[txBufIndex]) == ADI_ETH_QUEUE_FULL)
    {
      ;;
    }

    if(txBufIndex ++ >= 1 )
    {
      txBufIndex = 0;
    }
   return ERR_OK;
}

static err_t LwIP_ADIN1110LinkOutput(struct netif *netif, struct pbuf *p)
{
    low_level_output(netif, p);
    return ERR_OK;
}


static u16_t ssiHandler(const char* tag, char *insertBuffer, int insertBufferLen)
{
  return 1;
}


adi_eth_Result_e LwIP_StructInit(LwIP_ADIN1110_t* eth, adin1110_DeviceHandle_t* hDevice, uint8_t macAddress[6])
{
  eth->hDevice = hDevice;
  eth->macAddress =  macAddress;


  return ADI_ETH_SUCCESS;
}

static err_t LwipADIN1110Init(struct netif *netif)
{
   LwIP_ADIN1110_t* eth = (LwIP_ADIN1110_t*) netif->state;

   netif->output = etharp_output;
   netif->linkoutput = LwIP_ADIN1110LinkOutput;
   netif->name[0] = IFNAME0;
   netif->name[1] = IFNAME1;
   netif->mtu = ETHERNET_MTU;
   netif->flags = NETIF_FLAG_BROADCAST | NETIF_FLAG_ETHARP | NETIF_FLAG_LINK_UP;

#if LWIP_NETIF_HOSTNAME
    /* Initialize interface hostname */
    netif->hostname = HOSTNAME;
#endif /* LWIP_NETIF_HOSTNAME */


   netif->flags = NETIF_FLAG_BROADCAST | NETIF_FLAG_ETHARP | NETIF_FLAG_ETHERNET | NETIF_FLAG_IGMP;
   MIB2_INIT_NETIF(netif, snmp_ifType_ethernet_csmacd, NETIF_LINK_SPEED_IN_BPS);

   memcpy(netif->hwaddr, eth->macAddress, sizeof(netif->hwaddr));
   netif->hwaddr_len = sizeof(netif->hwaddr);

   return ERR_OK;
}


static adi_eth_Result_e ADIN1110Init(LwIP_ADIN1110_t* eth)
{
    adi_eth_Result_e        result;
    adin1110_DeviceHandle_t *hDevice =   eth->hDevice;
    uint8_t  brcstMAC[6] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};

    result = adin1110_AddAddressFilter(*hDevice, brcstMAC, NULL, 0);
    DEBUG_RESULT("adin1110_AddAddressFilter", result, ADI_ETH_SUCCESS);

    result = adin1110_AddAddressFilter(*hDevice, eth->macAddress, NULL, 0);
    DEBUG_RESULT("adin1110_AddAddressFilter", result, ADI_ETH_SUCCESS);

    result = adin1110_SyncConfig(*hDevice);
    DEBUG_RESULT("adin1110_SyncConfig", result, ADI_ETH_SUCCESS);

    result = adin1110_RegisterCallback(*hDevice, cbLinkChange, ADI_MAC_EVT_LINK_CHANGE);
    DEBUG_RESULT("adin1110_RegisterCallback (ADI_MAC_EVT_LINK_CHANGE)", result, ADI_ETH_SUCCESS);

        /* Prepare Rx buffers */
    for (uint32_t i = 0; i < 1; i++)
    {
        txBufAvailable[i] = true;

        rxBufDesc[i].pBuf = &rxBuf[i][0];
        rxBufDesc[i].bufSize = MAX_FRAME_BUF_SIZE;
        rxBufDesc[i].cbFunc = rxCallback;

        result = adin1110_SubmitRxBuffer(*hDevice, &rxBufDesc[i]);
    }

    result = adin1110_Enable(*hDevice);
    DEBUG_RESULT("Device enable error", result, ADI_ETH_SUCCESS);

    initPQueue(&pQ[0]);

  return result;
}


void LwIP_Init( LwIP_ADIN1110_t* eth,  board_t *boardDetails)
{
    ADIN1110Init(eth);
    lwip_init();
    http_set_ssi_handler(ssiHandler, NULL, 0);
    httpd_init();
    if (boardDetails->ip_addr_fixed == 1)
    {
      ip4_addr_t ip, mask, gw;
      // Add our network interface to the netif_list and set it as default
      IP4_ADDR(&ip, boardDetails->ip_addr[0], boardDetails->ip_addr[1], boardDetails->ip_addr[2], boardDetails->ip_addr[3]);
      IP4_ADDR(&mask,  boardDetails->net_mask[0], boardDetails->net_mask[1], boardDetails->net_mask[2], boardDetails->net_mask[3]);
      IP4_ADDR(&gw,   boardDetails->gateway[0], boardDetails->gateway[1], boardDetails->gateway[2], boardDetails->gateway[3]);

      netif_add(&eth->netif, &ip, &mask, &gw, eth,
      LwipADIN1110Init, ethernet_input);

      netif_set_default(&eth->netif);
      netif_set_up(&eth->netif);
    }
    else
    {
    	//NETIF SETUP GREIER
      netif_add(&eth->netif, IPADDR_ANY, IPADDR_ANY, IPADDR_ANY, eth,
      LwipADIN1110Init, ethernet_input);

      netif_set_default(&eth->netif);
      netif_set_up(&eth->netif);

      dhcp_start(&eth->netif);
    }
//   netif_set_status_callback(&eth->netif, LwipADIN1110NetifStatusCallback);
}

void initPQueue(pQueue_t* pQ)
{
    pQ->nWrQ = 0;
    pQ->nRdQ = 0;
}


uint32_t pDataAvailable(pQueue_t* pQ)
{
  if (pQ->nWrQ != pQ->nRdQ)
  {
    return 1;
  }
  return 0;
}

void writePQ(pQueue_t* pQ, uint8_t *ethFrame, int lenEthFrame)
{
    memcpy(&pQ->pData[pQ->nWrQ][0] , ethFrame, lenEthFrame);
    pQ->lenData[pQ->nWrQ] = lenEthFrame;
    pQ->nWrQ++;
    pQ->nWrQ %= MAX_P_QUEUE;
}

void* readPQ(pQueue_t* pQ)
{
    int ehtFrmLen = pQ->lenData[pQ->nRdQ] ;
    struct pbuf* p = pbuf_alloc(PBUF_RAW, MAX_FRAME_BUF_SIZE, PBUF_RAM);
    memcpy(((uint8_t*) p->payload) , &pQ->pData[pQ->nRdQ][0], ehtFrmLen);

    pQ->nRdQ++;
    pQ->nRdQ %= MAX_P_QUEUE;

    return (void*)p;
}


uint32_t discoveradin1110(adin1110_DeviceHandle_t *hDevice)
{
    adi_eth_Result_e        result;
    uint32_t                error = 1;

    /****** Driver Init *****/
    for (uint32_t i = 0; i < ADIN1110_INIT_ITER; i++)
    {
        result = adin1110_Init(*hDevice, &drvConfig);
        if (result == ADI_ETH_SUCCESS)
        {
            error = 0;
            break;
        }
    }
   // DEBUG_RESULT("No MACPHY device found", result, ADI_ETH_SUCCESS);
    return error;
}
