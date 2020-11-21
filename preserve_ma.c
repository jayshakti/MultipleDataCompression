
#include"headers.h"
#include"prototypes.h"
int preserve_ma(char *ma)
{

	int ekey,len;
	ekey=open("Encrypted_Key",O_TRUNC|O_WRONLY|O_CREAT);
        if(ekey==-1)
        {
                perror("open");
                exit(EXIT_FAILURE);
        }
        len = strlen(ma);
        write(ekey,ma,len);
	return 0;


}
