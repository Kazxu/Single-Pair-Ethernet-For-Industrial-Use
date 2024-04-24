#include "tcp_client.h"
// FUNKER IKKE MITT EGEN EXPERIMENT KODE
#define SERVER_IP "192.168.20.100"  // Change to your server's IP address
#define SERVER_PORT 40

static struct tcp_pcb *tcp_client_pcb;

static err_t tcp_client_sent(void *arg, struct tcp_pcb *tpcb, u16_t len) {
	printf("Data sent, length: %d\n", len);
	tcp_close(tpcb);
    return ERR_OK;
}

static err_t tcp_client_connected(void *arg, struct tcp_pcb *tpcb, err_t err) {
	 printf("Connection established\n");
	const char message[] = "5";

    if (err == ERR_OK) {
        tcp_sent(tpcb, tcp_client_sent);
        tcp_write(tpcb, message, sizeof(message)-1, TCP_WRITE_FLAG_COPY);
        tcp_output(tpcb);  // Send data immediately
        return ERR_OK;
    } else {
    	printf("Connection failed with err: %d\n", err);
        tcp_close(tpcb);
        return err;
    }
}

static void tcp_client_connection_err(void *arg, err_t err) {
	printf("TCP error: %d\n", err);
	struct tcp_pcb *tpcb = (struct tcp_pcb*) arg;
    if (tpcb) {
        tcp_close(tpcb);
    }
}

void tcp_client_send(void) {
    ip_addr_t server_ip;
    err_t err;

    tcp_client_pcb = tcp_new();
    if (tcp_client_pcb != NULL) {
        ipaddr_aton(SERVER_IP, &server_ip);
        tcp_bind(tcp_client_pcb, IP_ADDR_ANY, 0);
        tcp_client_pcb->state = ESTABLISHED;
        tcp_err(tcp_client_pcb, tcp_client_connection_err);

        err = tcp_connect(tcp_client_pcb, &server_ip, SERVER_PORT, tcp_client_connected);
        if (err != ERR_OK) {
            tcp_close(tcp_client_pcb);
        }
    } else {
        // Handle error
    }
}
