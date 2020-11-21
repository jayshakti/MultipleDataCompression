#include"headers.h"
#include"prototypes.h"
int compress6(int fd, char *ma)
{
	unsigned int dfd;	// fd of the new Compressed_file	
	unsigned int ret,rret;	// return type of lseek funtion
	unsigned char ch,byt,cloc,loc,temp;
	printf("Inside %s function\n",__func__);
	dfd=open("Compressed_File",O_WRONLY|O_CREAT);
	if(dfd==-1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	ret=lseek(fd,0,SEEK_SET);
	if(ret == -1)
	{
		perror("lseek");
		exit(EXIT_FAILURE);
	}

	while(1)
	{
		ch ^= ch;
		byt ^= byt;
		rret=read(fd,&ch,1);				// 1st char read.
		if(rret == 0)
			break;
//		printf("read ch is = %c\n",ch);
		loc ^= loc;
		loc=findloc(ch,ma);
//		printf("location =%d\n",loc);
		loc <<= 2;	
		byt |= loc;
		ch ^= ch;
		rret=read(fd,&ch,1);				// 2nd char read.
		if(rret == 0)
		{
			ch=255;
			ch>>=6;
			byt|=ch;
			write(dfd,&byt,1);        	
//			printf("_____________%d\n",byt);
			loc=255;
			loc<<=4;
			write(dfd,&loc,1);        	
//			printf("_____________%d\n",loc);
			break;
		}
//		printf("read ch is = %c\n",ch);
		loc ^= loc;
		loc=findloc(ch,ma);
//		printf("location =%d\n",loc);
		cloc=loc;
		loc <<= 2; loc >>= 6;
		byt |= loc;
		write(dfd,&byt,1);        		////wrote 1st char.
//		printf("_____________%d\n",byt);
		
		cloc<<=4;
		byt^=byt;
		byt|=cloc;
		ch ^= ch;
		rret=read(fd,&ch,1);				// 2nd char read.
		if(rret == 0)
		{
			ch=255;
			ch>>=4;
			byt|=ch;
			write(dfd,&byt,1);        	
//			printf("_____________%d\n",byt);
			loc=255;
			loc<<=6;
			write(dfd,&loc,1);        	
//			printf("_____________%d\n",loc);
			break;
		}
//		printf("read ch is = %c\n",ch);
		loc ^= loc;
		cloc^=cloc;
		loc=findloc(ch,ma);
//		printf("location =%d\n",loc);
		cloc=loc;
		loc <<= 2; loc >>= 4;
		byt|=loc;
		write(dfd,&byt,1);        		////wrote 2nd char.
//		printf("_____________%d\n",byt);
			
		cloc<<=6;
		byt^=byt;
		byt|=cloc;
		ch ^= ch;
		rret=read(fd,&ch,1);				// 2nd char read.
		if(rret == 0)
		{
			ch=255;
			ch>>=2;
			byt|=ch;
			write(dfd,&byt,1);        	
//			printf("_____________%d\n",byt);
			break;
		}
//		printf("read ch is = %c\n",ch);
		loc ^= loc;
		loc=findloc(ch,ma);
//		printf("location =%d\n",loc);
		loc <<= 2; loc >>=2;
		byt|=loc;
		write(dfd,&byt,1);        			////wrote 3rd char
///		printf("_____________%d\n",byt);
													
	}
	close(dfd);
	printf("\n__________DONE____________\n");
	printf("==>> Given file is compressed. <<==\n");
	printf("==>>______Compressed_File_____ <<==\n");
	return 0;
}
