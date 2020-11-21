#include"headers.h"
#include"prototypes.h"
int decompress7(char *buff)
{
	int cfd,dfd;	//file discriptor of Compressed file & De_compressed file
	int ret;
//	int i=1;	
	unsigned char ch1,ch2,ch3,byt; 
	
//      Opening Compressed & De_compressed_file here............

        cfd=open("Compressed_File",O_RDONLY);
        if(cfd==-1)
        {
                perror("open");
                exit(EXIT_FAILURE);
        }

        dfd=open("De_Compressed_File",O_TRUNC | O_CREAT | O_WRONLY);
        if(dfd==-1)
        {
                perror("open");
                exit(EXIT_FAILURE);
        }

//     de_Compressing file here...........
	
	while(1)
        {
                ch1^=ch1; ch2^=ch2;
                ret=read(cfd,&ch1,1);
		if(ret==0)
			break;
		ch2=ch1;
                ch1 >>= 1;
			if(ch1==127)
			break;	
                byt^=byt;
                byt=*(buff+ch1);
	        write(dfd,&byt,1);	// 1st char wrote
//		printf("%d=====wrote character is :%c,line: %d\n",i++,byt,__LINE__);
		
		ch2 <<= 7;
		ch2 >>= 1;
		ch1^=ch1;
		ret=read(cfd,&ch1,1);
		if(ret==0)
			break;
		ch3^=ch3;
		ch3=ch1;
		ch1>>=2;
		ch2|=ch1;
			if(ch2==127)
			break;	
                byt=*(buff+ch2);
                write(dfd,&byt,1);		//2nd wrote
//		printf("%d=====wrote character is :%c,line: %d\n",i++,byt,__LINE__);

		ch3<<=6; ch3>>=1;
		ch1^=ch1; ch2^=ch2;
		ret=read(cfd,&ch1,1);
		if(ret==0)
			break;
		ch2=ch1;
		ch1>>=3; 
		ch3|=ch1; 
			if(ch3==127)
			break;
                byt=*(buff+ch3);
                write(dfd,&byt,1);		//3th wrote
//		printf("%d=====wrote character is :%c,line: %d\n",i++,byt,__LINE__);

		ch2<<=5; 
		ch2>>=1; 
		ch1^=ch1; ch3^=ch3;
		ret=read(cfd,&ch1,1);
		if(ret==0)
			break;
		ch3=ch1;
		ch1>>=4;
		ch2|=ch1;
			if(ch2==127)
			break;
		
                byt=*(buff+ch2);
                write(dfd,&byt,1);		//4th wrote
//		printf("%d=====wrote character is :%c,line: %d\n",i++,byt,__LINE__);

		ch2^=ch2; ch1^=ch1;
		ch3<<=4; ch3>>=1;
		ret=read(cfd,&ch1,1);
		if(ret==0)
			break;
		ch2=ch1;
		ch1>>=5;
		ch3|=ch1;
			if(ch3==127)	
			break;

                byt=*(buff+ch3);
                write(dfd,&byt,1);		//5th wrote
//		printf("%d=====wrote character is :%c,line: %d\n",i++,byt,__LINE__);

		ch2<<=3; ch2>>=1;
		ch3^=ch3; ch1^=ch1;
		ret=read(cfd,&ch1,1);
		if(ret==0)
			break;
		ch3=ch1;
		ch1>>=6;
		ch2|=ch1;
			if(ch2==127)	
			break;
                byt=*(buff+ch2);
                write(dfd,&byt,1);		//6th wrote
//		printf("%d=====wrote character is :%c,line: %d\n",i++,byt,__LINE__);
		ch3 <<= 2; ch3>>=1;
		ch2^=ch2; ch1^=ch1;
		ret=read(cfd,&ch1,1);
		if(ret==0)
			break;
		ch2=ch1;
		ch1>>=7;
		ch3|=ch1;
			if(ch3==127)	
			break;
                byt=*(buff+ch3);
                write(dfd,&byt,1);		//7th wrote
		ch2<<=1; ch2>>=1;
			if(ch2==127)	
			break;
                byt=*(buff+ch2);
                write(dfd,&byt,1);		//8th wrote
		

        }
                close(cfd);
                close(dfd);
	printf("\n__________DONE!!!!!___________\n");
        printf("==>> Extraction of the given file done <<== \n");
        printf("==>> ________De_Compression_File______ <<== \n");

	return 0;
}

