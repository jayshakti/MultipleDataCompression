#include"headers.h"
#include"prototypes.h"
int compress(int cl, int fd, char *ma)
{
	switch(cl)
	{
		case 2:
			compress2(fd,ma);
			break;
		case 3:
			compress3(fd,ma);
			break;
		case 4:
			compress4(fd,ma);
			break;
		case 5:
			compress5(fd,ma);
			break;
		case 6:
			compress6(fd,ma);
			break;
		case 7:
			compress7(fd,ma);
			break;
		default :
			printf("Compression not possible\n");
	}
	return 0;
}
