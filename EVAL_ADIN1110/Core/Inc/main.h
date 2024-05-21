/*
 *---------------------------------------------------------------------------
 *
 * Copyright (c) 2020 Analog Devices, Inc. All Rights Reserved.
 * This software is proprietary to Analog Devices, Inc.
 * and its licensors.By using this software you agree to the terms of the
 * associated Analog Devices Software License Agreement.
 *
 *---------------------------------------------------------------------------
 */

#ifndef MAIN_H
#define MAIN_H

#include <stdbool.h>
#include "adin1110.h"
#include "boardsupport.h"
#include "lwip/tcp.h"

extern struct tcp_pcb *global_tpcb;  // Declaration of the global TCP control block, BRUKES FOR Å FÅ LOV Å BRUKE SAME T PCB
// TIL GLOBAL

void send_eval_string_msg(struct tcp_pcb *tpcb);  // Function prototype for sending messages

#endif /* MAIN_H */
