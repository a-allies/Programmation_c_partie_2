/*!
* \file image-proba.h
* \brief File defining the function to read an square image whose pixels are between 0 and 7 and estimate the probability
*/
#ifndef IMAGE_PROBA_H
#define IMAGE_PROBA_H

#include "image.h"


/*! \def NBVALUES
* \brief Range of image values: between 0 and NBVALUES-1
*/
#define NBVALUES 8

int readProbaFromFile(const char* name, float pb[NBVALUES]);

#endif
