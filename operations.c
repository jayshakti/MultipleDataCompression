#include"headers.h"
#include"prototypes.h"
int operations(int choice)
{
	
	switch(choice)
	{
		case 1:
			compression();
			break;
		case 2:
			decompression();
			break;
		case 3:
			exit(EXIT_FAILURE);
		default :
			printf("\nInvalid choice\n");
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			exit(EXIT_FAILURE);
			
	}
	
	return 0;
	
}		

