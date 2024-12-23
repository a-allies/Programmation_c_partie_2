/*!
* \file image-proba.c
* \brief File implementing the function to read an image and estimate the probabilities
*/
#include <stdio.h>
#include "image-proba.h"
#include "image.h"

/*! \fn int readProbaFromFile(char* name, float pb[NBVALUES])
* \brief Read the square image made of values between 0 and NBVALUES -1, stored as short int.
* \param[in] name the name of the binary file to be read
* \param[out] pb the probabilities array
* \return int 1 if everything is ok, 0 otherwise
*/

int readProbaFromFile(const char* name, float pb[NBVALUES])  {
  unsigned int i = 0;
  unsigned int j = 0;
  unsigned int k = 0;
  uint16_t valeur_pixel = 0;
  unsigned int taille = 0;

  FILE *fichier = fopen(name, "rb");
  if (fichier==NULL) {
    return 0;
  }

  taille = getImageSideLengthFromFile(name);

  if (taille==0) {
    return 0;
  }
  ImageSquare *img = createImageSquare(taille);

  if (img==NULL) {
    return 0;
  }

  for (k=0; k<NBVALUES; k++) {
    pb[k] = 0;
  }

  for (i=0; i<taille; i++) {
    for (j=0; j<taille; j++) {
      fread( (void *) &(valeur_pixel), sizeof(uint16_t), 1, fichier);
      setPixel(img, i, j, valeur_pixel);
      pb[valeur_pixel]++;
    }
  }

  k = 0;
  for (k=0; k<NBVALUES; k++) {
    pb[k] = pb[k]/( (float) taille*taille);
  }
  return 1;
}

int readProbaFromFile_(const char* name, float pb[NBVALUES])  {
  unsigned int i = 0;
  unsigned int j = 0;
  unsigned int k = 0;
  unsigned int taille = 0;

  ImageSquare *img = loadImageSquare(name);

  if (img==NULL) {
    return 0;
  }

  taille = getImageSideLengthFromFile(name);

  if (taille==0) {
    return 0;
  }

  for (k=0; k<NBVALUES; k++) {
    pb[k] = 0;
  }

  for (i=0; i<taille; i++) {
    for (j=0; j<taille; j++) {
      pb[getPixel(img, i, j)]++;
    }
  }
  k = 0;
  for (k=0; k<NBVALUES; k++) {
    pb[k] = pb[k]/( (float) taille*taille);
  }
  return 1;
}

