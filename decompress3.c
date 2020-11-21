#include"headers.h"
#include"prototypes.h"
int decompress3(char *buff)
{
	int cfd,dfd,ret,i=1;
	unsigned char ch,ch1,ch2,byt;
	cfd=open("Compressed_File",O_RDONLY);
	if(cfd==-1)
	{
		perror("open");
		exit(EXIT_FAILURE);

	}

	dfd=open("De_Compressed_File",O_TRUNC|O_CREAT|O_WRONLY);
	if(dfd==-1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	
//	Decompression Starts here!!!!!!!!!!!
	
	while(1)
	{
		
		ch^=ch;
		ret=read(cfd,&ch,1);
//		printf("__________________  %d\n",ch);
		if(ret==0)
		break;
		ch2=ch; 
		ch1=ch;
		ch>>=5;
			if(ch==7)
			break;
		byt^=byt;
		byt=*(buff+ch);
//		printf("i=%d wrote character is :%c   Line: %d\n",i++,byt,__LINE__);
		write(dfd,&byt,1);			//wrote 1st char to the dfd.
		
		ch1<<=3;
		ch1>>=5;
			if(ch1==7)
			break;
		byt^=byt;
		byt=*(buff+ch1);
//		printf("i=%d wrote character is :%c   Line: %d\n",i++,byt,__LINE__);
		write(dfd,&byt,1);			//wrote 2st char to the dfd.

		ch2<<=6;
		ch^=ch; ch1^=ch1;
		ret=read(cfd,&ch,1);
//		printf("__________________  %d\n",ch);
			if(ret==0)
			break;
		ch1=ch;
		ch>>=7;
		ch<<=5;
		ch2|=ch;
		ch2>>=5;
			if(ch2==7)
			break;
		byt^=byt;
		byt=*(buff+ch2);
//		printf("i=%d wrote character is :%c   Line: %d\n",i++,byt,__LINE__);
		write(dfd,&byt,1);			//wrote 3st char to the dfd.
		
		ch2^=ch2; ch^=ch;
		ch=ch1; 
		ch2=ch1;
		ch1<<=1; ch1>>=5;
			if(ch1==7)
			break;
		byt^=byt;
		byt=*(buff+ch1);
//		printf("i=%d wrote character is :%c   Line: %d\n",i++,byt,__LINE__);
		write(dfd,&byt,1);			//wrote 4th char to the dfd.
		
		ch<<=4; ch>>=5;
			if(ch==7)
			break;
		byt^=byt;
		byt=*(buff+ch);
		write(dfd,&byt,1);			//wrote 5th char to the dfd.
//		printf("i=%d wrote character is :%c   Line: %d\n",i++,byt,__LINE__);

		ch2<<=7;
		ch2>>=5;
		ch^=ch; ch1^=ch1;
		ret=read(cfd,&ch,1);
//		printf("__________________  %d\n",ch);
			if(ret==0)
			break;
		ch1=ch;
		ch>>=6;
		ch2|=ch;
			if(ch2==7)
			break;
		byt^=byt;
		byt=*(buff+ch2);
		write(dfd,&byt,1);			//wrote 6th  char to the dfd.
//		printf("i=%d wrote character is :%c   Line: %d\n",i++,byt,__LINE__);
	
		ch2^=ch2;
		ch2=ch1;
		ch1<<=2;  ch1>>=5;
			if(ch1==7)
			break;
		byt^=byt;
		byt=*(buff+ch1);
		write(dfd,&byt,1);			//wrote 7th char to the dfd.
//		printf("i=%d wrote character is :%c   Line: %d\n",i++,byt,__LINE__);
		ch2<<=5; ch2>>=5;
			if(ch2==7)
			break;
		byt^=byt;
		byt=*(buff+ch2);
		write(dfd,&byt,1);			//wrote 2st char to the dfd.
//		printf("i=%d wrote character is :%c   Line: %d\n",i++,byt,__LINE__);
	}
	close(cfd);
	close(dfd);
	printf("\n__________DONE!!!!!___________\n");
        printf("==>> Extraction of the given file done <<== \n");
        printf("==>> ________De_Compression_File______ <<== \n");

	return 0;
}
