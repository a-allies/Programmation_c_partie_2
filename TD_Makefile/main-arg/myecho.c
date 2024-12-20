#include <stdio.h>
int main (int argc, char *argv[], char* arge[])
{
	int i;
    printf("Program : %s with %d arguments\n", argv[0],argc-1);
	for (i=1 ; i<argc ; ++i)
		printf("argv[%d] : \033[34m%s\033[0m\n",i,argv[i]);

	return 0 ;
}
