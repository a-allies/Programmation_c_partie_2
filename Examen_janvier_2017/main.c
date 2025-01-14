/*!
* \file main.c
* \brief Main program to test all implemented functionalities.
* \author kdesnos
*/

#include <stdio.h>
#include "list.h"
#include "file.h"
#include "crypto.h"
#include <stdlib.h>

/*!
* \brief Test program
*/
int main()
{
     testList();

    List l;
    char seed = -50;
    unsigned char key = 0x09;
    loadList(&l, "encrypted-message.bin");
    decrypt(key,seed,&l);

     return 0;
}
