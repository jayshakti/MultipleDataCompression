#include"headers.h"
#include"prototypes.h"
int main()
{
	while(1)
	{
		int ch;	//choice
		printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
		printf("~~~~~~~~~MAIN MENU~~~~~~~~~~\n");
		printf("!!!!  1.Compression     !!!!\n!!!!  2.Decompression   !!!!\n!!!!  3.Exit\t\t!!!!");
		printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
		printf("\nEnter your choice::");
		scanf(" %d",&ch);
		operations(ch);
	}
	return 0;
}


