#include"headers.h"
#include"prototypes.h"
int openfile()
{
	int fd;
	char *filename;
	filename = (char *)malloc(20);
	if(!filename)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	printf("Enter file name to compress::");
	scanf("%s", filename);
	fd=open(filename,O_RDONLY);
	if(fd==-1)
	{
		perror("open");
		free(filename);
		exit(EXIT_FAILURE);
	}
	return fd;
}
