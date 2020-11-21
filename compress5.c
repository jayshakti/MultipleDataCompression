#include"headers.h"
#include"prototypes.h"
int compress5(int fd, char *ma)
{
	unsigned char ch,byt,temp;
	unsigned char loc,cloc;	// here 'cloc' is a copied value of 'loc'
	int cfd,rret;
	cfd=open("Compressed_File",O_CREAT|O_WRONLY);
	if(cfd==-1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	lseek(fd,0,SEEK_SET);
	while(1)
	{
		ch^=ch;	byt^=byt;
		rret=read(fd,&ch,1);
		if(rret==0)
		{
			break;
		}
//		printf("read character is :%c\n",ch);
		loc^=loc;
		loc=findloc(ch,ma);
		loc<<=3;
		byt|=loc;
		ch^=ch;
		rret=read(fd,&ch,1);
		if(rret==0)
		{
			ch=255; temp=255;			
			ch<<=5;ch>>=5;
			byt|=ch;				// ORing with byt
			write(cfd,&byt,1);			//writing into the cfd
			temp<<=6;
			byt^=byt;
			byt|=temp;
			write(cfd,&byt,1);
			break;
		}
//		printf("read character is :%c\n",ch);
		loc^=loc; cloc^=cloc;
		loc=findloc(ch,ma);
		cloc=loc;		//making a copy of loc into cloc
		loc<<=3; loc>>=5;
		byt|=loc;
		write(cfd,&byt,1);	//writing into the cfd ***************  1st ch.
		
		ch^=ch;	byt^=byt;
		cloc<<=6;
		byt|=cloc;
		rret=read(fd,&ch,1);
		if(rret==0)
		{
			ch=255;
			ch<<=2;ch>>=2;
			byt|=ch;
			write(cfd,&byt,1);
			break;
		}
//		printf("read character is :%c\n",ch);
		loc^=loc;
		loc=findloc(ch,ma);
		loc<<=3; loc>>=2;
		byt|=loc;
		rret=read(fd,&ch,1);
		if(rret==0)
		{	
			ch=255;
			ch>>=7;
			byt|=ch;
			write(cfd,&byt,1);	
			temp=255;
			temp<<=4;
			byt^=byt;
			byt|=temp;
			write(cfd,&byt,1);	
			break;
		}
//		printf("read character is :%c\n",ch);
		loc^=loc; cloc^=cloc;
		loc=findloc(ch,ma);
		cloc=loc;		//making a copy of loc into cloc
		loc<<=3; loc>>=7;
		byt|=loc;
		write(cfd,&byt,1);	//writing into the cfd ************************* 2nd ch.
		
		ch^=ch;	byt^=byt;
		cloc<<=4;
		byt|=cloc;
		rret=read(fd,&ch,1);
		if(rret==0)
		{
			ch=255;
			ch>>=4;
			byt|=ch;
			write(cfd,&byt,1);	
			temp=255; temp<<=7;
			byt^=byt;
			byt|=temp;
			write(cfd,&byt,1);	
			break;
		}
//		printf("read character is :%c\n",ch);
		loc^=loc; cloc^=cloc;
		loc=findloc(ch,ma);
		cloc=loc;				//making a copy of loc into cloc
		loc<<=3; loc>>=4;
		byt|=loc;
		write(cfd,&byt,1);			//writing into the cfd******************* 3rd ch.
		
		ch^=ch;	byt^=byt;
		cloc<<=7;
		byt|=cloc;
		rret=read(fd,&ch,1);
		if(rret==0)
		{
			ch=255;
			ch>>=3; ch<<=2;
			byt|=ch;
			write(cfd,&byt,1);
			break;
		}
//		printf("read character is :%c\n",ch);
		loc^=loc;
		loc=findloc(ch,ma);
		loc<<=3; loc>>=1;
		byt|=loc;
		ch^=ch;
		rret=read(fd,&ch,1);
		if(rret==0)
		{
			ch=255;
			ch>>=6;
			byt|=ch;
			write(cfd,&byt,1);
			temp=255; temp<<=5;
			byt|=temp;
			write(cfd,&byt,1);	
			break;
		}
//		printf("read character is :%c\n",ch);
		loc^=loc; cloc^=cloc;
		loc=findloc(ch,ma);
		cloc=loc;				//copy
		loc<<=3; loc>>=6;
		byt|=loc;
		write(cfd,&byt,1);			//writing into the cfd**************** 4th ch.
		
		byt^=byt;
		cloc<<=5;
		byt|=cloc;
		ch^=ch;
		rret=read(fd,&ch,1);
		if(rret==0)
		{
			ch=255;
			ch>>=3;
			byt|=ch;
			write(cfd,&byt,1);	
			break;
		}
//		printf("read character is :%c\n",ch);
		loc^=loc;
		loc=findloc(ch,ma);
		loc<<=3; loc>>=3;
		byt|=loc;
		write(cfd,&byt,1);			//writing into the cfd *********************** 5th ch.
	
	}
	close(cfd);
	printf("___________DONE!!!!!________\n");
	printf("==>> Given file is compressed. <<==\n");
	printf("==>> Compressed_File <<==\n");
	return 0;
}
