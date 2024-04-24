 /******************************************************************************
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

#ifndef __SYSCLOCK_H
#define __SYSCLOCK_H

#ifdef __cplusplus
extern "C" {
#endif
#include "stm32l4xx_ll_rcc.h"
#include "bsp_config.h"
 
HAL_StatusTypeDef SystemClock_Config(void);

#ifdef __cplusplus
}
#endif
#endif /*__SYSCLOCK_H*/

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
