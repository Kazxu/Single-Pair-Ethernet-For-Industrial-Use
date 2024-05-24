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

#ifndef BSP_CONFIG_H
#define BSP_CONFIG_H



#if defined(EVAL_ADIN1110EBZ)
#define ETH_RESET_Pin GPIO_PIN_7
#define ETH_RESET_GPIO_Port GPIOC
#else
#define ETH_RESET_Pin GPIO_PIN_8
#define ETH_RESET_GPIO_Port GPIOB
#endif


#define ETH_SPI                 SPI2
#define ETH_SPI_IRQn            SPI2_IRQn
#define ETH_SPI_IRQ_HANDLER     SPI2_IRQHandler
#define ETH_SPI_CLK_ENABLE		__HAL_RCC_SPI2_CLK_ENABLE
#define ETH_SPI_CLK_DISABLE 	__HAL_RCC_SPI2_CLK_DISABLE

#define ETH_SPI_SS_Pin          GPIO_PIN_12
#define ETH_SPI_SS_GPIO_Port    GPIOB
#define ETH_SPI_MOSI_Pin        GPIO_PIN_15
#define ETH_SPI_MOSI_GPIO_Port  GPIOB
#define ETH_SPI_MOSI_AF         GPIO_AF5_SPI2
#if defined(USE_NUCLEO)
#define ETH_SPI_MISO_Pin        GPIO_PIN_2
#define ETH_SPI_MISO_GPIO_Port  GPIOC
#else
#define ETH_SPI_MISO_Pin        GPIO_PIN_14
#define ETH_SPI_MISO_GPIO_Port  GPIOB
#endif
#define ETH_SPI_MISO_AF         GPIO_AF5_SPI2
#define ETH_SPI_CLK_Pin         GPIO_PIN_13
#define ETH_SPI_CLK_GPIO_Port   GPIOB
#define ETH_SPI_CLK_AF          GPIO_AF5_SPI2


#define ETH_SPI_DMA_REQ_TX      DMA_REQUEST_SPI2_TX
#define ETH_SPI_DMA_REQ_RX      DMA_REQUEST_SPI2_RX

#if defined(EVAL_ADIN1110EBZ)
#define ETH_INT_N_Pin           GPIO_PIN_11
#define ETH_INT_N_GPIO_Port     GPIOB
#else
#define ETH_INT_N_Pin           GPIO_PIN_12
#define ETH_INT_N_GPIO_Port     GPIOA
#endif
#define ETH_INT_N_IRQn          EXTI15_10_IRQn
#define ETH_INT_N_IRQ_HANDLER   EXTI15_10_IRQHandler

#if defined(EVAL_ADIN1110EBZ)
#define BSP_LED1_PORT           GPIOC
#define BSP_LED1_PIN            GPIO_PIN_13
#define BSP_LED2_PORT           GPIOE
#define BSP_LED2_PIN            GPIO_PIN_2
#define BSP_LED3_PORT           GPIOE
#define BSP_LED3_PIN            GPIO_PIN_6
#define BSP_LED4_PORT           GPIOG
#define BSP_LED4_PIN            GPIO_PIN_15
#else
#define BSP_LED1_PORT           GPIOB
#define BSP_LED1_PIN            GPIO_PIN_6
#define BSP_LED2_PORT           GPIOE
#define BSP_LED2_PIN            GPIO_PIN_6
#define BSP_LED3_PORT           GPIOB
#define BSP_LED3_PIN            GPIO_PIN_11
#define BSP_LED4_PORT           GPIOE
#define BSP_LED4_PIN            GPIO_PIN_2
#define BSP_LED5_PORT           GPIOB
#define BSP_LED5_PIN            GPIO_PIN_10
#endif

#define ETH_GPIO_ENABLE         do { \
                                    __HAL_RCC_GPIOA_CLK_ENABLE(); \
                                    __HAL_RCC_GPIOB_CLK_ENABLE(); \
                                    __HAL_RCC_GPIOC_CLK_ENABLE(); \
                                    __HAL_RCC_GPIOD_CLK_ENABLE(); \
                                    __HAL_RCC_GPIOE_CLK_ENABLE(); \
                                    __HAL_RCC_GPIOF_CLK_ENABLE(); \
                                    __HAL_RCC_GPIOG_CLK_ENABLE(); \
                                    __HAL_RCC_GPIOH_CLK_ENABLE(); \
                                } while(0)

/* Assign one of the symbols defined below to configure SYSCLK/SCLK frequencies */
#define BSP_CLK_CFG             (BSP_CLK_CFG_96_24)

#define BSP_CLK_CFG_96_24       (0)
#define BSP_CLK_CFG_25_12P5     (1)
#define BSP_CLK_CFG_120_15      (2)
#define BSP_CLK_CFG_100_25      (3)
#define BSP_CLK_CFG_80_5        (4)
#define BSP_CLK_CFG_100_12P5    (5)

#if (BSP_CLK_CFG == BSP_CLK_CFG_96_24)

#define BSP_CLK_CFG_PLLN                (48)
#define BSP_CLK_CFG_PLLR                (RCC_PLLR_DIV2)
#define BSP_CLK_CFG_APB1CLKDIV          (RCC_HCLK_DIV2)
#define BSP_CLK_CFG_SPI_BAUDPRESCALER   (SPI_BAUDRATEPRESCALER_2)
#define BSP_CLK_CFG_FLASH_LATENCY       (FLASH_LATENCY_4)

#elif (BSP_CLK_CFG == BSP_CLK_CFG_25_12P5)

#define BSP_CLK_CFG_PLLN                (25)
#define BSP_CLK_CFG_PLLR                (RCC_PLLR_DIV4)
#define BSP_CLK_CFG_APB1CLKDIV          (RCC_HCLK_DIV1)
#define BSP_CLK_CFG_SPI_BAUDPRESCALER   (SPI_BAUDRATEPRESCALER_2)
#define BSP_CLK_CFG_FLASH_LATENCY       (FLASH_LATENCY_1)

#elif (BSP_CLK_CFG == BSP_CLK_CFG_120_15)

#define BSP_CLK_CFG_PLLN                (60)
#define BSP_CLK_CFG_PLLR                (RCC_PLLR_DIV2)
#define BSP_CLK_CFG_APB1CLKDIV          (RCC_HCLK_DIV4)
#define BSP_CLK_CFG_SPI_BAUDPRESCALER   (SPI_BAUDRATEPRESCALER_2)
#define BSP_CLK_CFG_FLASH_LATENCY       (FLASH_LATENCY_5)

#elif (BSP_CLK_CFG == BSP_CLK_CFG_100_25)

#define BSP_CLK_CFG_PLLN                (50)
#define BSP_CLK_CFG_PLLR                (RCC_PLLR_DIV2)
#define BSP_CLK_CFG_APB1CLKDIV          (RCC_HCLK_DIV2)
#define BSP_CLK_CFG_SPI_BAUDPRESCALER   (SPI_BAUDRATEPRESCALER_2)
#define BSP_CLK_CFG_FLASH_LATENCY       (FLASH_LATENCY_4)

#elif (BSP_CLK_CFG == BSP_CLK_CFG_80_5)

#define BSP_CLK_CFG_PLLN                (40)
#define BSP_CLK_CFG_PLLR                (RCC_PLLR_DIV2)
#define BSP_CLK_CFG_APB1CLKDIV          (RCC_HCLK_DIV1)
#define BSP_CLK_CFG_SPI_BAUDPRESCALER   (SPI_BAUDRATEPRESCALER_16)
#define BSP_CLK_CFG_FLASH_LATENCY       (FLASH_LATENCY_3)

#elif (BSP_CLK_CFG == BSP_CLK_CFG_100_12P5)

#define BSP_CLK_CFG_PLLN                (50)
#define BSP_CLK_CFG_PLLR                (RCC_PLLR_DIV2)
#define BSP_CLK_CFG_APB1CLKDIV          (RCC_HCLK_DIV2)
#define BSP_CLK_CFG_SPI_BAUDPRESCALER   (SPI_BAUDRATEPRESCALER_4)
#define BSP_CLK_CFG_FLASH_LATENCY       (FLASH_LATENCY_4)

#else

// FIXME: assert error

#endif

#endif /* BSP_CONFIG_H */
