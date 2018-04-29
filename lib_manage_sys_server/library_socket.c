#include "library_socket.h"

int socket_udp_init(int *ser_sockfd, const char *ser_ip, unsigned short ser_port)
{
  (*ser_sockfd) = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
  if ((*ser_sockfd) < 0)
  {
    return SOCKINITERR;
  }

  struct sockaddr_in ser_addr;
  struct sockaddr_in cli_addr;
  socklen_t ser_addrlen = sizeof(struct sockaddr_in);
  socklen_t cli_addrlen = sizeof(struct sockaddr_in);
  memset(&ser_addr, 0, sizeof(struct sockaddr_in));
  ser_addr.sin_family = AF_INET;
  ser_addr.sin_port = htons(ser_port);
  ser_addr.sin_addr.s_addr = inet_addr(ser_ip);
  int ret = 0;
  ret = bind((*ser_sockfd), (struct sockaddr *)&ser_addr, ser_addrlen);
  if (ret < 0)
  {
    return SOCKINITERR;
  }
  char recvbuf[100] = {0};
  recvfrom((*ser_sockfd), recvbuf, sizeof(recvbuf), 0, (struct sockaddr *)&cli_addr, &cli_addrlen);
  printf("recv = %s\n", recvbuf);
  return SOCKINITSUCCESS;
}
