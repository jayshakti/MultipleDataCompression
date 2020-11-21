#include"headers.h"
#include"prototypes.h"
int compress2(int fd, char *ma)
{
	unsigned char ch, loc,byt;
	int cfd,rret;
//	printf("Inside %s function.\n",__func__);
	cfd=creat("Compressed_File",O_WRONLY|O_CREAT|O_TRUNC);	
	if(cfd==-1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	rret=lseek(fd,0,SEEK_SET);
	if(rret==-1)
	{
		perror("lseek");
		exit(EXIT_FAILURE);
	}
	while(1)
	{
		byt ^= byt;
		ch ^= ch;
		rret=read(fd,&ch,1);
		if(rret == 0)
			break;

		loc ^= loc;
		loc=findloc(ch,ma);
//		printf("Location of %c in ma is %d\n",ch,loc);
		loc <<= 6;
		byt |= loc;
		ch ^= ch;
		rret=read(fd,&ch,1);
		if(rret==0)
		{
			ch=255;
			ch<<=6;	ch>>=2;
			byt=byt|ch;
			write(cfd,&byt,1);
			break;
		}

		loc ^= loc;
		loc=findloc(ch,ma);
	//	printf("Location of %c in ma is %d\n",ch,loc);
		loc <<= 6;
		loc >>= 2;
		byt |= loc;
		ch ^= ch;
		rret=read(fd,&ch,1);
		if(rret==0)
		{
			ch=255;
			ch<<=6;	ch>>=4;
			byt=byt|ch;
			write(cfd,&byt,1);
			break;
		}

		loc ^= loc;
		loc=findloc(ch,ma);
	//	printf("Location of %c in ma is %d\n",ch,loc);
		loc <<= 6;
		loc >>= 4;
		byt |= loc;
		ch ^= ch;
		rret=read(fd,&ch,1);
		if(rret==0)
		{
			ch=255;
			ch<<=6;	ch>>=6;
			byt=byt|ch;
			write(cfd,&byt,1);
			break;
		}

		loc ^= loc;
		loc=findloc(ch,ma);
	//	printf("Location of %c in ma is %d\n",ch,loc);
		loc <<= 6;
		loc >>= 6;
		byt |= loc;
		rret=write(cfd, &byt ,1);
		if (rret < 0)
		{
			perror("write");
			exit(EXIT_FAILURE);
		}
	}
          
	close(cfd);
	printf("\n\n___________DONE!!!!______________");
	printf("\n==>> Given file is compressed <<==\n");
	printf("==>> Compressed_File <<==\n");

	return 0;
}
