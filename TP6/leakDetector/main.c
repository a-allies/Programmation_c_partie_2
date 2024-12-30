/*!
 * \file  main.c
 * \brief
 * \author Muriel Pressigout
 * \date 16/12/2013
 * This executive tests dynamic memory management
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*!
 * \def MEMCHECK
 * \brief MEMCHECK enables the overloading of the malloc and free functions
 */
#define MEMCHECK

#include "myAlloc.h"
#include "myFunctions.h"


/*!
 * \fn int main()
 *   Principal function
 *   It tests dynamic memory allocation/deallocation
 * \return int 0 if everything is ok
 */
int main()
{
    char word [] = "bonjour";
    char * t = NULL;
    char * s = NULL;
    int check;


    t= (char * ) malloc(50);
    s= (char * ) malloc(50);

    mystrcpy(&t,word);
    mystrinv(&s,word);

    free(t);

#ifdef MEMCHECK
    if(myCheck())
        printf("There are unfreed memory blocks \n");
#endif
	system("pause");
    return 0;
}

