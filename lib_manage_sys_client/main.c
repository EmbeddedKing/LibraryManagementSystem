#include "global.h"
#include "library_socket.h"

int main(int argc, char **argv)
{
  int cli_sockfd;
  cli_sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
  if (cli_sockfd < 0)
  {
    perror("socket");
    return -1;
  }

  struct sockaddr_in ser_addr;
	memset(&ser_addr, 0, sizeof(struct sockaddr_in));
	socklen_t ser_addrlen = sizeof(struct sockaddr_in);
	ser_addr.sin_family = AF_INET;
	ser_addr.sin_port = htons(6363);
	ser_addr.sin_addr.s_addr = inet_addr("192.168.0.244");

  sendto(cli_sockfd, "helloworld", strlen("helloworld"), 0, (struct sockaddr *)&ser_addr, ser_addrlen);
  close(cli_sockfd);
}
