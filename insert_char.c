#include"headers.h"
#include"prototypes.h"
char *insert_char(int ch, char *ma)
{
	int ndc;
	ndc=0;
//	printf("Inside %s function.\n",__func__);
	if(ma)
	{
		ndc= strlen(ma);
//		printf("Old length of ma=%d\n",ndc);
	}							
	ma =realloc(ma, ndc+2);
	*(ma+ndc) = ch;
	*(ma+ndc+1) = '\0';
	ndc= strlen(ma);
//	printf("After intertion length of ma=%d\n",ndc);
	return ma;
}
