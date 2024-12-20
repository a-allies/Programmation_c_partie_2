
#include "consumer.h"

#include "init_conso_prod.h"
#include <stddef.h>


int consume ( Products * p)
{
    if(NULL!=p)
    {
    	if(!isEmpty(p))
    	{
    		unsigned int value = p->products[p->next_conso];
    		p->next_conso = (p->next_conso+1)%NBPRODUCT;
    		if(p->next_conso == p->next_prod)
    			p->isEmpty = 1;
    		p->isFull = 0;	
    		return value;	
    	}
    	return -1;
    }
}

