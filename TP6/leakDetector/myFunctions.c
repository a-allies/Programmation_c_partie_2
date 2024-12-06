/*!
 * \file  myFunctions.c
 * \brief
 * \author Muriel Pressigout
 * \date 16/12/2013
 * A few functions on strings
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MEMCHECK

#include "myAlloc.h"
#include "myFunctions.h"


/*!
 * \fn char * mystrcpy(char ** dest, char * src)
 *   This function copies a string.
 *   It allocates enough space to store the src string in the dest string.
 * \return char * the address of the dest string
 */
char * mystrcpy(char ** dest, char * src)
{
    if(*dest!=NULL)
        free((void*)*dest);
    *dest = (char * ) malloc(strlen(src)+1);
    strcpy(*dest,src);
    return *dest;
}

/*!
 * \fn char * mystrinv(char ** dest, char * src)
 *   This function inverses a string.
 *   It allocates enough space to store the result in the dest string.
 * \return char * the address of the dest string
 */
char * mystrinv(char ** dest, char * src)
{
    int length=strlen(src);
    int i;

    if(*dest!=NULL)
        free((void*)*dest);
    *dest = (char * ) malloc(length+1);

    i=0;
    while(src[i]!='\0')
    {
        (*dest)[length-i]=src[i];
        i++;
    }
    (*dest)[length]='\0';
    return *dest;
}

