#ifndef MY_GLOBALS_PROD_CONSO_H_INC
#define MY_GLOBALS_PROD_CONSO_H_INC

/*! define the size of the product array */
#define NBPRODUCT 4

/*! Struct to manage production and consommation*/
typedef struct Products{

	unsigned int  products [NBPRODUCT];
	int next_conso;
	int next_prod;
	int isFull;
	int isEmpty;
} Products ;
#endif
