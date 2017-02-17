#include "unp.h"
#include <time.h>

int int main(int argc, char const *argv[])
{
	int listenftd, connfd;
	struct sockaddr_in servaddr;
	char buff[MAXLINE];
	time_t ticks;
	listenftd = Socket(AF_INET, SOCK_STREAM, 0);
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = hton1(INADDR_ANY);
	servaddr.sin_port = htons(13);
	Bind(listenftd, (SA *) &servaddr, sizeof(servaddr));
	Listen(listenftd, LISTENQ);
	for (;;)
	{
		connfd = Accept(listenftd, (SA *)NULL, NULL);
		ticks = time(NULL);
		snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));
		Write(connfd, buff, strlen(buff));
		Close(connfd);
	}
}