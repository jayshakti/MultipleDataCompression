#include"headers.h"
#include"prototypes.h"
int decompress6(char *buff)
{
	int cfd,dfd,ret,i=1;
	unsigned char ch,ch1,ch2,byt;
	cfd=open("Compressed_File",O_RDONLY);
	if(cfd==-1)
	{
		perror("open");
		exit(EXIT_FAILURE);

	}

	dfd=open("De_Compressed_File",O_CREAT|O_WRONLY|O_TRUNC);
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
		ch1=ch;
		ch>>=2;
			if(ch==63)
			break;
		byt^=byt;
		byt=*(buff+ch);
//		printf("i=%d wrote character is :%c   Line: %d\n",i++,byt,__LINE__);
		write(dfd,&byt,1);			//wrote 1st char to the dfd.
		
		ch1<<=6;
		ch1>>=2;
		ch^=ch; 
		ret=read(cfd,&ch,1);
//		printf("__________________  %d\n",ch);
			if(ret==0)
			break;
		ch2=ch;
		ch>>=4;
		ch1|=ch;
			if(ch1==63)
			break;
		byt^=byt;
		byt=*(buff+ch1);
//		printf("i=%d wrote character is :%c   Line: %d\n",i++,byt,__LINE__);
		write(dfd,&byt,1);			//wrote 2nd char to the dfd.
		
		ch1^=ch1; ch^=ch;
		ch2<<=4;
		ch2>>=2;
		ret=read(cfd,&ch,1);
//		printf("__________________  %d\n",ch);
			if(ret==0)
			break;
		ch1=ch;
		ch>>=6;
		ch2|=ch;
			if(ch2==63)
			break;
		byt^=byt;
		byt=*(buff+ch2);
		write(dfd,&byt,1);			//wrote 6th  char to the dfd.
//		printf("i=%d wrote character is :%c   Line: %d\n",i++,byt,__LINE__);
	
		ch1<<=2;  ch1>>=2;
			if(ch1==63)
			break;
		byt^=byt;
		byt=*(buff+ch1);
		write(dfd,&byt,1);			//wrote 7th char to the dfd.
//		printf("i=%d wrote character is :%c   Line: %d\n",i++,byt,__LINE__);
	}
	close(cfd);
	close(dfd);
	printf("\n__________DONE!!!!!___________\n");
        printf("==>> Extraction of the given file done <<== \n");
        printf("==>> ________De_Compression_File______ <<== \n");

	return 0;
}
