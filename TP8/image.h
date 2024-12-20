
/*!
* \file image.h
* \brief File defining the image characteristics
*/
#ifndef IMAGE_H
#define IMAGE_H

#include <inttypes.h>   /* uint16_t*/

/*! \struct ImageSquare
 * \brief structure handling a square image
 */
typedef struct {
    uint16_t ** rows;        /*!< Arrays of the addresses of each row */
    unsigned int side_size; /*!< Length of one side of the square image */
}ImageSquare;

ImageSquare * createImageSquare(unsigned int length);
unsigned int getImageSideSize(const ImageSquare * im);
uint16_t getPixel(const ImageSquare * im, unsigned int row, unsigned int col);
void setPixel(ImageSquare * im, unsigned int row, unsigned int col, uint16_t pixval);
void freeImage(ImageSquare * im);

void randomlyBinarize(ImageSquare * im);
void displayImageSquare(const ImageSquare * i);
ImageSquare * loadImageSquare(const char * filename);
unsigned int getImageSideLengthFromFile(const char * filename);

#endif

