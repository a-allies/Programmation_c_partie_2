/*!
* \file image-proba.c
* \brief File implementing the function to read an image and estimate the probabilities
*/
#include <stdio.h>
#include "image-proba.h"

/*! \fn int readProbaFromFile(char* name, float pb[NBVALUES])
* \brief Read the square image made of values between 0 and NBVALUES -1, stored as short int.
* \param[in] name the name of the binary file to be read
* \param[out] pb the probabilities array
* \return int 1 if everything is ok, 0 otherwise
*/
int readProbaFromFile(const char* name, float pb[NBVALUES])
{

    unsigned int i = 0;
    unsigned int j = 0;
    unsigned int k = 0;
    unsigned int longueur = 0;
    unsigned int nb = 0;
    FILE *fichier = fopen(name, "rb");
    if(fichier==NULL) {
        fprintf(stderr, "Erreur d'ouverture du fichier-> fin programme\n");
        return -1;
    }
for(k; k<NBVALUES; k++) pb[k] = 0;

    longueur = getImageSideLengthFromFile(name);
    for (i; i<longueur; i++) {
        for (j; j<longueur; j++) {
            fread( (void *) &nb, sizeof(uint16_t), 1, fichier);
            pb[nb]+=1;
        }

        j = 0;
    }
    k = 0;
    for (k; k<NBVALUES; k++) {
        pb[k] = pb[k]/(64*64);
    }


    return 1;
}

