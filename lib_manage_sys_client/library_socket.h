#ifndef __LIBRARY_SOCKET_H__
#define __LIBRARY_SOCKET_H__

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include "global.h"

/* udp套接字初始化 */
int socket_udp_init(int *ser_sockfd, const char *ser_ip, unsigned short ser_port);
/* 发送文件 */
int socket_sendfile(int *ser_sockfd);

#endif
