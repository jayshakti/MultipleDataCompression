#include"headers.h"
#include"prototypes.h"
int compress3(int fd, char *ma)
{
	unsigned int dfd;	// fd of the new Compressed_file	
	unsigned int ret,rret;	// return type of lseek funtion
	unsigned char ch,byt,cloc,loc,temp;
	printf("Inside %s function\n",__func__);
	dfd=open("Compressed_File",O_TRUNC|O_WRONLY|O_CREAT);
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
//		printf("0----=%d\n",loc);
		loc <<= 5;	
		byt |= loc;
		ch ^= ch;
		rret=read(fd,&ch,1);				// 2nd char read.
		if(rret == 0)
		{
			ch=255;
			ch<<=5;
			ch>>=3;
			byt|=ch;
			write(dfd,&byt,1);        	
//			printf("_____________%d\n",byt);
			break;
		}
//		printf("read ch is = %c\n",ch);
		loc ^= loc;
		loc=findloc(ch,ma);
//		printf("1----=%d\n",loc);
		loc <<= 5; loc >>= 3;
		byt |= loc;
		ch ^= ch;
		rret=read(fd,&ch,1);			// 3rd char read.
		if(rret == 0)
		{	
			ch=255;
			ch>>=6; 
			byt|=ch;
			write(dfd,&byt,1);        	
			temp=255;
			temp<<=7;
			byt|=temp;
			write(dfd,&byt,1);        	
//			printf("_____________%d\n",byt);
			break;
		}
//		printf("read ch is = %c\n",ch);
		loc ^= loc;
		cloc ^= cloc;
		loc=findloc(ch,ma);
//		printf("2----=%d\n",loc);
		cloc=loc;
		loc <<= 5; loc >>= 6;
//	printf("11=====%d\n",loc);
		byt |= loc;
		write(dfd,&byt,1);       	//writing 1 char (1+2+3)
//		printf("_____________%d\n",byt);
		
		cloc <<= 7;
//		printf("11=====%d\n",cloc);
		byt ^= byt;
		byt |= cloc;
		ch ^= ch;
		rret=read(fd,&ch,1);			//4th char read.
		if(rret == 0)
		{
			ch=255;
			ch>>=1;
			byt|=ch;
			write(dfd,&byt,1);        	
//			printf("_____________%d\n",byt);
			break;
		}
//		printf("read ch is = %c\n",ch);
		loc ^= loc;
		loc=findloc(ch,ma);		
//		printf("3----=%d\n",loc);
		loc <<= 5; loc >>= 1;
		byt |= loc;
		ch ^= ch;
		rret=read(fd,&ch,1);			// 5th char read.
		if(rret == 0)
		{
			ch=255;
			ch>>=4;
			byt|=ch;
			write(dfd,&byt,1);        	
//			printf("_____________%d\n",byt);
			break;
		}
//		printf("read ch is = %c\n",ch);
		loc ^= loc;
		loc=findloc(ch,ma);		
//		printf("4----=%d\n",loc);
		loc <<= 5; loc >>= 4;
		byt |= loc;
		ch ^= ch;
		rret=read(fd,&ch,1);			// 6th char read.
		if(rret == 0)
		{
			ch=255;
			ch>>=7;
			byt|=ch;
			write(dfd,&byt,1);        
			temp=255;
			temp<<=6;	
			byt|=temp;
			write(dfd,&byt,1);        
//			printf("_____________%d\n",byt);
			break;
		}
//		printf("read ch is = %c\n",ch);
		loc ^= loc; cloc ^= cloc;
		loc=findloc(ch,ma);		
//		printf("5----=%d\n",loc);
		cloc = loc;
		loc <<= 5; loc >>=7;
		byt |= loc;
			
		write(dfd,&byt,1);		//writing 2nd byt (4+5+6
//		printf("_____________%d\n",byt);
		cloc <<= 6;
		byt ^= byt;
		byt |= cloc;
		ch ^= ch;
		rret=read(fd,&ch,1);		// 7th char read.
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
//		printf("6----=%d\n",loc);
		loc <<= 5; loc >>= 2;
		byt |= loc;
		ch ^= ch;
		rret=read(fd,&ch,1);		// 8th char read.
		if(rret == 0)
		{
			ch=255;
			ch>>=5;
			byt|=ch;
			write(dfd,&byt,1);        
//			printf("_____________%d\n",byt);
			break;
		}
//		printf("read ch is = %c\n",ch);
		loc ^= loc;
		loc=findloc(ch,ma);		
//		printf("7----=%d\n",loc);
		loc <<= 5; loc >>= 5;
		byt |= loc;
		write(dfd,&byt,1);		// writing 3rd byt (7+8)*/
//		printf("_____________%d\n",byt);
	}
	close(dfd);
	printf("\n__________DONE____________\n");
	printf("==>> Given file is compressed. <<==\n");
	printf("==>>______Compressed_File_____ <<==\n");
	return 0;
}
