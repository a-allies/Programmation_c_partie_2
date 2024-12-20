

#include "producer.h"

#include "init_conso_prod.h"


int produce (Products * p,  unsigned int value)
{
	if(!isFull(p))
	{
		p->products[p->next_prod] = value;
		p->next_prod = (p->next_prod+1)%NBPRODUCT;
		if(p->next_conso == p->next_prod)
			p->isFull  = 1;
		p->isEmpty = 0;	
		return 0;	//everything fine
	}
	return -1;	// can not add a value
}

