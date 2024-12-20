
#include "init_conso_prod.h"

#include <stddef.h>

void init (Products *p)
{
	if(NULL!=p)
	{	
		p->next_prod = 0;
		p->next_conso = 0;
		p->isFull = 0;
		p->isEmpty = 1;
	}
}


int isFull(Products *p)
{
	if (p==NULL) return -1;
	return p->isFull;
}


int isEmpty(Products *p)
{
	return p->isEmpty;
}
