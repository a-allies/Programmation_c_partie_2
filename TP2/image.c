/*
// Created by mpressig on 03/11/2021.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include "image.h"

/*! \fn ImageSquare* createImageSquare(unsigned int length)
* \brief Allocate a square image structure and its fields. Initialize all pixel values to 0.
* \param[in] length the number of rows (and columns) of this image
* \return ImageSquare* the pointer on the new image structure
*/
ImageSquare* createImageSquare(unsigned int length) {
    unsigned int i = 0;
    ImageSquare *image = (ImageSquare *) calloc(1, sizeof(ImageSquare));
    if (image==NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire pour l'image dans createImageSquare()\n");
        return image;
    }

    image->rows = (uint16_t **) calloc(length, sizeof(uint16_t *));

    if (image->rows==NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire pour image->rows dans createImageSquare()\n");
        return image;
    }

    for (i=0; i<length; i++) {
        image->rows[i] = (uint16_t *) calloc(length, sizeof(uint16_t));

        if (image->rows[i]==NULL) {
            fprintf(stderr, "Erreur d'allocation mémoire pour image->rows[%d] dans createImageSquare()\n", i);
            free(image->rows);
            free(image);
            return NULL;
        }
    }

    image->side_size = length;

    return image;
}

/*! \fn unsigned int getImageSideSize(const ImageSquare * im)
* \brief Returns the number of rows (or columns) of the square image
* \param[in] im a square image already allocated and filled
* \return unsigned int the length
*/
unsigned int getImageSideSize(const ImageSquare * im) {
    if (im==NULL) return 0;
    return im->side_size;
}


/*! \fn uint16_t getPixel(const ImageSquare * im, unsigned int row, unsigned int col)
* \brief Returns the pixel value indexed by a row and column number.
* \param[in] im a square image already allocated and filled
* \param[in] row the row index of the pixel
* \param[in] col the column index of the pixel
* \return uint16_t the pixel value
*/
 uint16_t getPixel(const ImageSquare * im, unsigned int row, unsigned int col) {
    unsigned int taille = getImageSideSize(im);
    if (im==NULL || row>=taille || col>=taille || im->rows==NULL) return -1;
    return im->rows[row][col];
}

/*! \fn void setPixel(ImageSquare * im, unsigned int row, unsigned int col, uint16_t pixval)
* \brief Set the pixel value indexed by a row and column number.
* \param[in,out] im a square image already allocated and filled
* \param[in] row the row index of the pixel
* \param[in] col the column index of the pixel
* \param[in] pixval the newvalue of the pixel
*/
 void setPixel(ImageSquare * im, unsigned int row, unsigned int col, uint16_t pixval) {
    unsigned int taille = getImageSideSize(im);
    if (im==NULL || row>=taille || col>=taille || im->rows==NULL) return;
    im->rows[row][col] = pixval;
}

/*! \fn void randomlyBinarize(ImageSquare * im)
* \brief Fill the image with pixel whose value is randomly either 0 either 1.
 * At the first call of randomlyBinarize, the random seed is initialized with the current time.
* \param[in,out] im a square image already allocated
* \return unsigned int the pixel value
*/
void randomlyBinarize(ImageSquare * im) {
    unsigned int i = 0;
    unsigned int j = 0;
    unsigned int taille = getImageSideSize(im);
    if (im==NULL || im->rows==NULL) return;

    srand(time(NULL));
    for (i=0; i<taille; i++) {
        for (j=0; j<taille; j++) {
            setPixel(im, i, j, rand()%2);
        }
    }

}

/*! \fn void displayImageSquare(const ImageSquare * im)
* \brief Display on standard output as a matrix the image content
* \param[in] im a square image already allocated
*/
void displayImageSquare(const ImageSquare * im) {
    unsigned int i = 0;
    unsigned int j = 0;
    unsigned int taille = getImageSideSize(im);
    if (im==NULL || im->rows==NULL) return;

    for (i=0; i<taille; i++) {
        for (j=0; j<taille; j++) {
            fprintf(stdout, "%u ", getPixel(im, i, j));
        }
        fprintf(stdout, "\n");
    }
}
/*! \fn unsigned int getImageSideLengthFromFile(const char * filename)
* \brief Estimates the number row (and consequently columns) of the square image stored in a binary file.
 * A pixel is stored on 2 bytes and the file contents all rows consecutively
* \param[in] filename the name of the binary file to be read
* \return unsigned int side length of the square image
*/
unsigned int getImageSideLengthFromFile(const char * filename) {
    unsigned res = 0;
    FILE* fichier = fopen(filename, "rb");

    if (fichier==NULL) {
        fprintf(stderr, "Erreur d'ouverture du fichier en lecture dans getImageSideLengthFromFile()\n");
        return 0;
    }

    fseek(fichier, 0, SEEK_END);
    res = (unsigned int) sqrt(ftell(fichier)/2);
    fclose(fichier);
    return res;
}

/*! \fn ImageSquare * loadImageSquare(const char * filename)
* \brief Create an ImageSquare and fill it from file
* \param[in] filename the name of the binary file to be read
* \return ImageSquare* the pointer on the new filled image structure
*/
ImageSquare * loadImageSquare(const char * filename) {
    unsigned int i = 0;
    unsigned int j = 0;
    uint16_t valeur_pixel = 0;
    unsigned int taille = 0;
    ImageSquare *img = NULL;

    FILE* fichier = fopen(filename, "rb");

    if (fichier==NULL) {
        fprintf(stderr, "Erreur d'ouverture du fichier en lecture dans loadImageSquare()\n");
        return NULL;
    }

    taille = getImageSideLengthFromFile(filename);
    img = createImageSquare(taille);

    for (i=0; i<taille; i++) {
        for (j=0; j<taille; j++) {
            fread( (void *) &(valeur_pixel), sizeof(uint16_t), 1, fichier);
            setPixel(img, i, j, valeur_pixel );
        }
    }

    fclose(fichier);
    return img;
}



/*! \fn void freeImage(ImageSquare * im)
* \brief deallocate memory of an ImageSquare and its fields
* \param[in] im  a imageSquare already allocated
*/
void freeImage(ImageSquare * im) {
    unsigned int longueur = im->side_size;
    unsigned int i = 0;

    if (im==NULL) return;

    for (i=0; i<longueur; i++) {
        free( (void *) im->rows[i]);
    }

    free( (void *) im->rows);
    im->side_size = 0;
    free( (void *) im);
}