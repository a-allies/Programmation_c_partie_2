#include <stdlib.h>
#include <stdio.h>

#include "producer.h"
#include "consumer.h"

#include "init_conso_prod.h"


int main()
{
	Products p;
	int value;
	int i;
	
	init (&p);
	
	//producer is twice slower than consumer, unless (i==7) : producer becomes mad this time
	for (int i = 0; i < 10; i++)
	{
		if(produce(&p,i*10)!=-1)
			printf("Value produced \n");
		if( i==7)
			for (int j = 0 ; j < 2*NBPRODUCT; j++)
				if(produce(&p,i*10+j+1)!=-1)
					printf("Value produced \n");
				else
					printf("Value skipped \n");
		
		if((value = consume(&p)) !=-1)
			printf("Value read %u \n",value);
		else 
			printf("No value read\n");
		if((value = consume(&p)) !=-1)
			printf("Value read %u \n",value);
		else 
			printf("No value read\n");
		
	}

	return EXIT_SUCCESS;
}
