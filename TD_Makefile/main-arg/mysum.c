#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[], char* arge[])
{
	int i;
	int res = 0;
	char *e;
	for (i=1 ; i<argc ; ++i) { res+= strtol(argv[i], &e, 10); }
	printf("somme : %d\n", res);

	return 0 ;
}
