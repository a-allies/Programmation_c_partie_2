/*!
* \file crypto.c
* \brief File containing encryption and decryption related functions.
* \author kdesnos
*/

#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include "crypto.h"


void decrypt(unsigned char key, char seed, List *l)
{
    if (l==NULL) {
        fprintf(stderr, "List * est NULL dans decrypt()\n");
        return;
    }

    if (l->current==NULL) {
        fprintf(stderr, "l->current est NULL dans decrypt()\n");
        return;
    }

    char lettre_actuelle = '-';
    int nb = seed;
    int i = 0;
    do {
        lettre_actuelle = getCurrentLetter(l);
        fprintf(stdout, "%c", lettre_actuelle);
        deleteCurrent(l);
        nb = pseudoRandomNumber(key, nb);

        if (nb==0) continue;

        if (nb>0) {
            for (i=0; i<nb; i++) {
                l->current = l->current->next;
            }
        }

        if (nb<0) {
            for (i=0; i<-nb; i++) {
                l->current = l->current->previous;
            }
        }

    } while (lettre_actuelle!='\0');
}

char pseudoRandomNumber(unsigned char key,char seed)
{
    int i;
    char res = seed >> 1;
    char newBit = 0x7f;

    for(i=0; i<8; i++)
    {
        if(((key>>i)&0x01) != 0)
        {
            newBit ^= (seed & key) << (7-i);
        }
    }

    res = (newBit & 0x80) | (res & 0x7f);

    return res;
}


