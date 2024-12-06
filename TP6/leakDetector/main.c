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

#include "memoryList.h"
#include "myAlloc.h"
#include "myFunctions.h"


/*!
 * \fn int main()
 *   Principal function
 *   It tests dynamic memory allocation/deallocation
 * \return int 0 if everything is ok
 */
 
int main() {
   char word[] = "bonjour";
    char *t = NULL;
    char *s = NULL;
    int check;

    t = (char *) malloc(50);
    s = (char *) malloc(50);
    //char *c = (char *) malloc(50);
    mystrcpy(&t, word);
    mystrinv(&s, word);

    free(t);

#ifdef MEMCHECK
    printf("There are %d unfreed memory blocks\n", check = myCheck());
    if (check) {
        printf("m\n");
        myGarbageCollector();
        printf("There are %d unfreed memory blocks\n", check = myCheck());
    }
#endif
    testMemoryList();
    return 0;
}