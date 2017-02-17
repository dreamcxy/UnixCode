#include "unp.h"
int main(int argc, char const *argv[])
{
	/* code */
	union {
		short s;
		char c[sizeof(short)];
	} un;
	un.s = 0x0102;
	printf("%s:", CPU_VENDOR_OS);
	if (sizeof(short) == 2)
	{
		/* code */
		if (un.c[0] == 1 && un.c[1] == 2)
		{
			/* code */
			printf("big-endian\n");
		} else if (un.c[0] == 2 && un.c[1] == 1)
		{
			printf("little-endian\n");
			/* code */
		} else {
			printf("unknown\n");
		}
	} else {
		printf("sizeof(short) = %lu\n", sizeof(short));
	}
	exit(0);
}