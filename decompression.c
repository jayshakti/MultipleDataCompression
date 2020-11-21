#include"headers.h"
#include"prototypes.h"
int decompression()
{
	int efd,mfd;		//file discriptors(fd) of Encrypted_key,Master_key
	int elen;		//returned value of lseek
	int cd_len;		//code length of Master_key
	char *buff;

//	MAKING A DUPLICATE COPY OF ENCRYPTED_KEY...............

	efd=open("Encrypted_Key",O_RDONLY);
	if(efd==-1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	elen=lseek(efd,0,SEEK_END);
	cd_len=codelength(elen);
	printf("cd_len=%d\n",cd_len);
	lseek(efd,0,SEEK_SET);
	buff=(char *)malloc(sizeof(char)*elen);
	read(efd,buff,elen);
//	mfd=open("Master_Key",O_WRONLY|O_CREAT|O_TRUNC);
//	No need to make copy of the Encrypted_key.
//	Just read into buffer and pass it to the decompress()
//	write(mfd,buff,elen);
//	close(mfd);
	close(efd);
	decompress(cd_len,buff);
	return 0;

}
