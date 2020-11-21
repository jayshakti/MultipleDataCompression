#include"headers.h"
#include"prototypes.h"
int findloc(char ch, char *ma)
{
	int i,len;
//	printf("Inside %s function\n",__func__);
     	i=0;
	len = strlen(ma);
	while(i<len)
	{
		if(ch == *(ma+i))
		{
//			printf("loc of %c is %d in m_array\n",ch,i);
			return i;
          	}
		i++;
	}
	return -1;
	
}
