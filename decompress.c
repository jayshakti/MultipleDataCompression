#include"headers.h"
#include"prototypes.h"
int decompress(int cd_len,char *buff)
{
	switch(cd_len)
	{
		case 2:
			decompress2(buff);
			break;
		case 3:
			decompress3(buff);
			break;
		case 4:
			decompress4(buff);
			break;
		case 5:
			decompress5(buff);
			break;
		case 6:
			decompress6(buff);
			break;
		case 7:
			decompress7(buff);
			break;
	}
	return 0;
}
