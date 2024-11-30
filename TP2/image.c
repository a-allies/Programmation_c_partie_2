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
ImageSquare* createImageSquare(unsigned int length)
{
    int i = 0 ;

    ImageSquare *ptr_img = (ImageSquare *) calloc(1, sizeof(ImageSquare));
    if(ptr_img==NULL) {
        fprintf(stderr, "Erreur lors de l'allocation mémoire de l'image\n");
        exit(-1);
    }

    ptr_img->rows = (uint16_t **) calloc(length, sizeof(uint16_t *));
    for(i; i<length; i++) {
        ptr_img->rows[i] = (uint16_t *) calloc(1, sizeof(uint16_t)*length);
        if(ptr_img->rows[i]==NULL) {
            fprintf(stderr, "Erreur lors de l'allocation mémoire de l'attribut rows de l'image\n");
            exit(-1);
        }
    }

    ptr_img->side_size = length;
    return ptr_img;
}

/*! \fn unsigned int getImageSideSize(const ImageSquare * im)
* \brief Returns the number of rows (or columns) of the square image
* \param[in] im a square image already allocated and filled
* \return unsigned int the length
*/
unsigned int getImageSideSize(const ImageSquare * im)
{
    if(im==NULL) return -1;
    return im->side_size;
}


/*! \fn uint16_t getPixel(const ImageSquare * im, unsigned int row, unsigned int col)
* \brief Returns the pixel value indexed by a row and column number.
* \param[in] im a square image already allocated and filled
* \param[in] row the row index of the pixel
* \param[in] col the column index of the pixel
* \return uint16_t the pixel value
*/
 uint16_t getPixel(const ImageSquare * im, unsigned int row, unsigned int col)
{
    if(im==NULL) return -1;
    return im->rows[row][col];
}

/*! \fn void setPixel(ImageSquare * im, unsigned int row, unsigned int col, uint16_t pixval)
* \brief Set the pixel value indexed by a row and column number.
* \param[in,out] im a square image already allocated and filled
* \param[in] row the row index of the pixel
* \param[in] col the column index of the pixel
* \param[in] pixval the newvalue of the pixel
*/
 void setPixel(ImageSquare * im, unsigned int row, unsigned int col, uint16_t pixval)
{
    if(im==NULL) {
        fprintf(stderr, "Image nulle -> fin programme\n");
        exit(-1);
    }
    im->rows[row][col] = pixval;
}

/*! \fn void randomlyBinarize(ImageSquare * im)
* \brief Fill the image with pixel whose value is randomly either 0 either 1.
 * At the first call of randomlyBinarize, the random seed is initialized with the current time.
* \param[in,out] im a square image already allocated
* \return unsigned int the pixel value
*/
void randomlyBinarize(ImageSquare * im)
{
    int i = 0 ;
    int j = 0;
    if(im==NULL) {
        fprintf(stderr, "Image nulle -> fin programme\n");
        exit(-1);
    }

    srand(time(NULL));
    for(i; i<im->side_size; i++) {
        for(j; j<im->side_size; j++) {
            setPixel(im, i, j, rand()%2);
        }
        j = 0;
    }
}

/*! \fn void displayImageSquare(const ImageSquare * im)
* \brief Display on standard output as a matrix the image content
* \param[in] im a square image already allocated
*/
void displayImageSquare(const ImageSquare * im)
{
    int i = 0;
    int j = 0;
    if(im==NULL) {
        fprintf(stderr, "Image nulle -> fin programme\n");
        exit(-1);
    }

    for(i; i<im->side_size; i++) {
        for(j; j<im->side_size; j++) {
            fprintf(stdout, "%u ", getPixel(im, i, j) );
        }
        j = 0;
        printf("\n");
    }
    printf("\n");
}
/*! \fn unsigned int getImageSideLengthFromFile(const char * filename)
* \brief Estimates the number row (and consequently columns) of the square image stored in a binary file.
 * A pixel is stored on 2 bytes and the file contents all rows consecutively
* \param[in] filename the name of the binary file to be read
* \return unsigned int side length of the square image
*/
unsigned int getImageSideLengthFromFile(const char * filename)
{
    unsigned int longueur = 0;

    FILE *fichier = fopen(filename, "rb");
    if(fichier==NULL) {
        fprintf(stderr, "Erreur d'ouverture du fichier-> fin programme\n");
        exit(-1);
    }

    fseek(fichier, 0, SEEK_END);
    longueur = ftell(fichier)/2;
    return (unsigned int )sqrt(longueur);
}

/*! \fn ImageSquare * loadImageSquare(const char * filename)
* \brief Create an ImageSquare and fill it from file
* \param[in] filename the name of the binary file to be read
* \return ImageSquare* the pointer on the new filled image structure
*/
ImageSquare * loadImageSquare(const char * filename)
{
    ImageSquare *img = NULL;
    unsigned int i = 0;
    unsigned int j = 0;
    unsigned int longueur = 0;
    u_int16_t nb = 0;
    FILE *fichier = fopen(filename, "rb");
    if(fichier==NULL) {
        fprintf(stderr, "Erreur d'ouverture du fichier-> fin programme\n");
        exit(-1);
    }

    longueur = getImageSideLengthFromFile(filename);
    img = createImageSquare(longueur);
    for (i; i<longueur; i++) {
        for (j; j<longueur; j++) {
            fread( (void *) &nb, sizeof(u_int16_t), 1, fichier);
            setPixel(img, i, j, nb);
        }
        j = 0;
    }

    return img;
}



/*! \fn void freeImage(ImageSquare * im)
* \brief deallocate memory of an ImageSquare and its fields
* \param[in] im  a imageSquare already allocated
*/
void freeImage(ImageSquare * im)
{
    unsigned int i = 0;
    if(im==NULL) return;

    for(i; i<im->side_size; i++) {
        free( (void *) im->rows[i] );
    }
    free( (void *) im);
    return;

}