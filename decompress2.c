#include"headers.h"
#include"prototypes.h"
int decompress2(char *buff)
{
	int cfd,dfd;	//file discriptor of compressed file & De_compressed file
	int ret;	//return value of read()
	unsigned char ch1,ch2,byt; 
	
//      Opening Compressed & De_compressed_file here............

        cfd=open("Compressed_File",O_RDONLY);
        if(cfd==-1)
        {
                perror("open");
                exit(EXIT_FAILURE);
        }

        dfd=open("De_Compressed_File",O_CREAT|O_WRONLY);
        if(dfd==-1)
        {
                perror("open");
                exit(EXIT_FAILURE);
        }

//     de_Compressing file here...........

        while(1)
        {
                ch1^=ch1;
                ch2^=ch2;
                ret=read(cfd,&ch1,1);
                if(ret==0)
			break;

                ch2=ch1;
                ch1 >>= 6;
                byt^=byt;
                byt=*(buff+ch1);
//              printf("%d=%c\n",__LINE__,byt);
                write(dfd,&byt,1);
                
		ch1^=ch1;
		ch1=ch2;
                ch2 <<= 2;
                ch2 >>= 6;
		if(ch2==3)
			break;
        
	        byt^=byt;
                byt=*(buff+ch2);
//	        printf("%d=%c\n",__LINE__,byt);
                write(dfd,&byt,1);
                ch2^=ch2;
                ch2=ch1;
                ch1 <<=4;
		ch1>>=6;
		if(ch1==3)
			break;
                byt^=byt;
                byt=*(buff+ch1);
//              printf("%d=%c\n",__LINE__,byt);
                write(dfd,&byt,1);

                ch2 <<= 6;
                ch2 >>= 6;
		if(ch2==3)
			break;
        
	        byt^=byt;
                byt=*(buff+ch2);
//              printf("%d=%c\n",__LINE__,byt);
                write(dfd,&byt,1);
	}
                close(cfd);
                close(dfd);
	
        printf("\n==>> _______DONE!!!!!!__________ 	<<==\n");
        printf("==>> Extraction of the given file done 	<<==\n");
	printf("==>> _________Decompressed_File_________<<==\n");

	return 0;
}

