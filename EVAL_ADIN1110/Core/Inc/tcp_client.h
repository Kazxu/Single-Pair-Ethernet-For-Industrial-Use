/*
 * tcp_client.h
 *
 *  Created on: Apr 22, 2024
 *      Author: Davy Poon
 */
#ifndef TCP_CLIENT_H
#define TCP_CLIENT_H

#include "lwip/err.h"
#include "lwip/tcp.h"

#ifdef __cplusplus
extern "C" {
#endif

void tcp_client_send(void);

#ifdef __cplusplus
}
#endif

#endif // TCP_CLIENT_H

