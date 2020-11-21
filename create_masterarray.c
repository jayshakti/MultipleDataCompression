#include"headers.h"
#include"prototypes.h"
char *create_masterarray(int fd)
{
	char ch,ch1;
	int flag,first=1,ret=1;
	char *ma;
	ma=NULL;
//	printf("Inside %s function.\n",__func__);
	printf("ma = %p\n",ma);
	while(ret)
	{
		flag = 1;
		ret=read(fd,&ch,1);
     		if(ch == 10)
		{
			ret=read(fd,&ch1,1);
			if(ret==0)
			{
				break;
			}
			else
			{
				lseek(fd,-1,SEEK_CUR);
			}
		}
 //   		printf("\nRead char is %d\n",ch);
		if(!ma)
		ma=insert_char(ch, ma);
		else
		{
			flag=unique_char(ch, ma);
			if(flag)
			ma=insert_char(ch, ma);
		}
	}	
	return ma;
}
