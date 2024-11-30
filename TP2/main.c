/*!
* \file main.c
* \brief main program to read data from file and build the corresponding Huffman coding
*/

#include <stdio.h>
#include "image.h"
#include "image-proba.h"
#include "test.h"

/*! \fn int main()
* \brief Test the imageSquare module
* \return 0 if everything was ok, weird things otherwise
*/
int main()
{
    float probabilities[NBVALUES];

    ImageSquare * im = NULL;


    if((im = createImageSquare(4))!=NULL)
    {
        display_test_int("Test createImageSquare (getImageSideSize)", 4, getImageSideSize(im));
        display_test_int("Test createImageSquare (getPixel)", 0, getPixel(im, 3, 3));
        setPixel(im,3,3,5);
        display_test_int("Test setPixel", 5, getPixel(im, 3, 3));
        randomlyBinarize(im);
        displayImageSquare(im);
        freeImage(im);
    }

    if((im = loadImageSquare("IM1.IM")) !=NULL)
    {
        display_test_int("Test loadImageSquare (getImageSideSize)", 64, getImageSideSize(im));
        display_test_int("Test loadImageSquare (getPixel)", 5, getPixel(im, 3, 3));
        display_test_int("Test loadImageSquare (getPixel)", 4, getPixel(im, 63, 62));
        freeImage(im);
    }

    if(readProbaFromFile("IM1.IM",probabilities)==1)
    {
        unsigned int i;
        printf("**** Probabilities: ");
        for(i = 0; i<NBVALUES ; i++)
            printf("%d:%f %s",i,probabilities[i],((i==NBVALUES-1)?"\n":" - "));

        display_test_float("Test readProbaFromFile", 387./(64*64), probabilities[0]);
        display_test_float("Test readProbaFromFile", 859./(64*64), probabilities[1]);
        display_test_float("Test readProbaFromFile", 42./(64*64), probabilities[2]);
        display_test_float("Test readProbaFromFile", 1603./(64*64), probabilities[3]);
        display_test_float("Test readProbaFromFile", 187./(64*64), probabilities[4]);
        display_test_float("Test readProbaFromFile", 598./(64*64), probabilities[5]);
        display_test_float("Test readProbaFromFile", 266./(64*64), probabilities[6]);
        display_test_float("Test readProbaFromFile", 154./(64*64), probabilities[7]);

    }

    if(readProbaFromFile("IM2.IM",probabilities)==1)
    {
        unsigned int i;
        printf("**** Probabilities: ");
        for(i = 0; i<NBVALUES ; i++)
            printf("%d:%f %s",i,probabilities[i],((i==NBVALUES-1)?"\n":" - "));

        display_test_float("Test readProbaFromFile", 134./(64*64), probabilities[0]);
        display_test_float("Test readProbaFromFile", 243./(64*64), probabilities[1]);
        display_test_float("Test readProbaFromFile", 61./(64*64), probabilities[2]);
        display_test_float("Test readProbaFromFile", 334./(64*64), probabilities[3]);
        display_test_float("Test readProbaFromFile", 2482./(64*64), probabilities[4]);
        display_test_float("Test readProbaFromFile", 163./(64*64), probabilities[5]);
        display_test_float("Test readProbaFromFile", 517./(64*64), probabilities[6]);
        display_test_float("Test readProbaFromFile", 162./(64*64), probabilities[7]);
    }

    return 0;
}
