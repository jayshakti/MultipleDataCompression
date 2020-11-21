#include"headers.h"
#include"prototypes.h"
int compression()
{
	char *ma;
	int fd,ndc,cl;
	int ekey;
	printf("Inside %s function.\n",__func__);
	fd=openfile();
//	printf("fd:%d\n",fd);
	ma = create_masterarray(fd);
	if(!ma)
	{
		exit(EXIT_FAILURE);
		return -1;
	}
	printf("\nMaster array is::%s\n\n",ma);
	preserve_ma(ma);
	ndc = strlen(ma);
	cl = codelength(ndc);
	printf("Code length is::%d\n",cl);
	compress(cl,fd,ma);
	return 0;
}
