#include "unp.h"
ssize_t 
readn(int fd, void *vptr, size_t n){
	size_t nleft;
	ssize_t nread;
	char *ptr;

	ptr = vptr;
	nleft = n;
	while(nleft > 0){
		if ((nread = read(fd, ptr, nleft)) < 0)
		{
			if (errno == EINTR)
			{
				nread = 0;
			}else{
				return (-1);
			}
		}
		nleft -= nread;
		ptr += nread;
	}
	return(n - nleft);
}