/*!
 * \file imageRGB.h
 * \brief Declaration of RGB Image structure and associated functions
 * \author ...
 * \date ...
 */

#ifndef IMAGERGB_H_INC
#define IMAGERGB_H_INC

#include <stdio.h>
#include <stdlib.h>

/** enum typedef to define MyBoolean type
* A Boolean variable can have FALSE or TRUE value
*/
typedef enum {MYFALSE=0,MYTRUE=1}MyBoolean;

/** struct typedef to define a Pixel using RGB colour space
* A pixel is defined in RGB space : a byte for each color component (Blue, Green, Red)
*/
typedef struct{
      unsigned char blue;   /*!<the blue component */
      unsigned char green;  /*!<the green component */
      unsigned char red;    /*!<the red component */
}PixelRGB;

/** struct typedef to define an Image using RBG colour space
* An image is defined as a grid of pixels.
* It needs to set its number of columns (width), number of rows (heigth).
* The pixel data is stored continuously in memory, row by row.
*/
typedef struct{
      unsigned int width;    /*!<the number of columns in the pixel grid*/
      unsigned int height;   /*!<the number of lines in the pixel grid*/
      PixelRGB * raw_data; /*!<the pixel grid*/
}ImageRGB;

unsigned int getWidth(ImageRGB *image);
unsigned int getHeight(ImageRGB *image);
void setPixel(ImageRGB *image, unsigned int r, unsigned int c , PixelRGB p);
PixelRGB getPixel(ImageRGB *image, unsigned int r, unsigned int c);
ImageRGB * allocateImage(unsigned int h, unsigned int w);
void  freeImage(ImageRGB * i);
ImageRGB* createCross(int length);

void modifyImage(ImageRGB * image, PixelRGB pix_initial, PixelRGB pix_final);

#endif
