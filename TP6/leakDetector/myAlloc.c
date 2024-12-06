

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "myAlloc.h"
#include "memoryList.h"

List l = {
	{{ NULL , NULL ,0 , NULL } ,&( l . sentinel_end ) , NULL } , /* sentinel_begin */
	&( l . sentinel_begin ) , /* current */
	{{ NULL , NULL ,0 , NULL } , NULL ,&( l . sentinel_begin ) } /* sentinel_end */
};

/*!
 * \brief Redefines the malloc function behavior
 * In addition of the memory allocation, this function adds an element in the list of the allocated blocks
 * \param[in] size the size of the block to be allocated
 * \param[in] file the file name where the memory allocation is required
 * \param[in] func the function name where the memory allocation is required
 * \param[in] line the line number where the memory allocation is required
 * \return void * the address of the allocated block
*/
void* myMalloc(unsigned int size, const char* file,  const char * func, int line)
{
	void * allocated_block;

	allocated_block = malloc ( size );

	if (allocated_block != NULL)
	{
        	insertSort(&l, file, func, line, allocated_block);
        	printf("In file %s,\n\t function %s,\n\t\t line %d :\n\t\t\t allocated block at memory address: %p\n",file,func,line,allocated_block);
	}

	return allocated_block;
}


/*!
 * \brief Redefines the free function behavior
 * In addition of the memory deallocation, this function  deletes an element in the list of the allocated blocks.
 * \param[in] block the address of the block to be deallocated
 * \param[in] file the file name where the memory deallocation is required
 * \param[in] func the function name where the memory deallocation is required
 * \param[in] line the line number where the memory deallocation is required
*/
void myFree ( void* block, const char* file,  const char * func, int line)
{
    if(block != NULL)
    {
        deleteValue(&l, block);
        free(block);
        printf("In file %s,\n\t function %s,\n\t\t line %d :\n\t\t\t freed block at memory address: %p\n",file, func, line, block);
    }
}

/*!
 * \fn  int myCheck()
 * \brief Check if every allocated block has been freed
 * It relies on the counter of allocated blocks
 * \return int the number of allocated blocks
*/
int myCheck()
{
    return countElement(&l);
}

void myGarbageCollector() {
	if (isEmpty(&l)==1) return;

	setOnFirst(&l);
	while (isEmpty(&l)!=1) {
		deleteValue(&l, getCurrentAddress(&l));
	}

}
