#include"headers.h"
#include"prototypes.h"
int compress7(int fd, char *ma)
{
	unsigned char ch,byt;
	unsigned char loc,cloc;	// here 'cloc' is a copied value of 'loc'
	int cfd,rret;
	cfd=open("Compressed_File",O_TRUNC|O_CREAT|O_WRONLY);
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
		loc<<=1;
		byt|=loc;
		ch^=ch;
		rret=read(fd,&ch,1);
		if(rret==0)
		{
			ch=255; loc=255;			
			ch>>=7;
			byt|=ch;				// ORing with byt
			write(cfd,&byt,1);			//writing into the cfd
			loc<<=2;
			write(cfd,&loc,1);
			break;
		}
//		printf("read character is :%c\n",ch);
		loc^=loc; cloc^=cloc;
		loc=findloc(ch,ma);
		cloc=loc;		//making a copy of loc into cloc
		loc<<=1; loc>>=7;
		byt|=loc;
		write(cfd,&byt,1);	//writing into the cfd ***************  1st ch.
		
		ch^=ch;	byt^=byt;
		cloc<<=2;
		byt|=cloc;
		rret=read(fd,&ch,1);
		if(rret==0)
		{
			ch=255;
			ch>>=6;
			byt|=ch;
			write(cfd,&byt,1);
			loc=255;
			loc<<=3;
			write(cfd,&loc,1);
			break;
		}
//		printf("read character is :%c\n",ch);
		loc^=loc; cloc^=cloc;
		loc=findloc(ch,ma);
		cloc=loc;
		loc<<=1; loc>>=6;
		byt|=loc;
		write(cfd,&byt,1);	//writing into the cfd *************************2rd ch.
		
		cloc<<=3;
		byt^=byt;
		byt|=cloc;
		rret=read(fd,&ch,1);
		if(rret==0)
		{	
			ch=255;
			ch>>=5;
			byt|=ch;
			write(cfd,&byt,1);	
			loc=255;
			loc<<=4;
			write(cfd,&loc,1);	
			break;
		}
//		printf("read character is :%c\n",ch);
		loc^=loc; cloc^=cloc;
		loc=findloc(ch,ma);
		cloc=loc;		//making a copy of loc into cloc
		loc<<=1; loc>>=5;
		byt|=loc;
		write(cfd,&byt,1);	//writing into the cfd *************************3rd ch.
		
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
			loc=255; 
			loc<<=5;
			write(cfd,&loc,1);	
			break;
		}
//		printf("read character is :%c\n",ch);
		loc^=loc; cloc^=cloc;
		loc=findloc(ch,ma);
		cloc=loc;				//making a copy of loc into cloc
		loc<<=1; loc>>=4;
		byt|=loc;
		write(cfd,&byt,1);			//writing into the cfd******************* 4th ch.
		
		ch^=ch;	byt^=byt;
		cloc<<=5;
		byt|=cloc;
		rret=read(fd,&ch,1);
		if(rret==0)
		{
			ch=255;
			ch>>=3;
			byt|=ch;
			write(cfd,&byt,1);
			loc=255;
			loc<<=6;
			write(cfd,&loc,1);
			break;
		}
//		printf("read character is :%c\n",ch);
		loc^=loc; cloc^=cloc;
		loc=findloc(ch,ma);
		cloc=loc;
		loc<<=1; loc>>=3;
		byt|=loc;
		write(cfd,&byt,1);			//writing into the cfd******************* 5th ch.
		
		cloc<<=6;
		byt^=byt;
		byt|=cloc;
		ch^=ch;
		rret=read(fd,&ch,1);
		if(rret==0)
		{
			ch=255;
			ch>>=2;
			byt|=ch;
			write(cfd,&byt,1);
			loc=255;
			loc<<=7;
			write(cfd,&loc,1);	
			break;
		}
//		printf("read character is :%c\n",ch);
		loc^=loc; cloc^=cloc;
		loc=findloc(ch,ma);
		cloc=loc;				//copy
		loc<<=1; loc>>=2;
		byt|=loc;
		write(cfd,&byt,1);			//writing into the cfd**************** 6th ch.
		
		byt^=byt;
		cloc<<=7;
		byt|=cloc;
		ch^=ch;
		rret=read(fd,&ch,1);
		if(rret==0)
		{
			ch=255;
			ch>>=1;
			byt|=ch;
			write(cfd,&byt,1);	
			break;
		}
//		printf("read character is :%c\n",ch);
		loc^=loc;
		loc=findloc(ch,ma);
		loc<<=1; loc>>=1;
		byt|=loc;
		write(cfd,&byt,1);			//writing into the cfd *********************** 7th ch.
	
	}
	close(cfd);
	printf("___________DONE!!!!!________\n");
	printf("==>> Given file is compressed. <<==\n");
	printf("==>> Compressed_File <<==\n");
	return 0;
}
