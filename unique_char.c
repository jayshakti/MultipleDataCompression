#include"headers.h"
#include"prototypes.h"
int unique_char(int ch, char *ma)
{
	int ndc,i;
	ndc=0;
//	printf("Inside %s function.\n",__func__);
	ndc = strlen(ma);
	i=0;
	while(i<ndc)
	{
		if(*(ma+i)==ch)
		{
//			printf("Nope it's not Unique.\n");
			return 0;
		}
		i++;
	}
//	printf("Yaah it's Unique.\n");
	return 1;

}
