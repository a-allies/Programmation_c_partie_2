/*!
 * \file imageRGB .c
 * \brief definition of fonctions associated to the RGB Image structure
 * \author ...
 * \date ...
 */

#include "imageRGB.h"


/*!
 * Allocate an image as a rectangle whose size is specified.
 * \param[in] w image width
 * \param[in] h image height
 * \return a pointer on the new image
 */
ImageRGB *allocateImage( unsigned int h, unsigned int w)
{
    ImageRGB *img = (ImageRGB *) calloc(1, sizeof(ImageRGB));
    if (img==NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire pour l'imageRGB dans allocateImage()\n");
        return img;
    }

    img->raw_data = (PixelRGB *) calloc(h*w, sizeof(PixelRGB));
    if (img->raw_data==NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire pour le raw data dans allocateImage()\n");
        return img;
    }

    img->width = w;
    img->height = h;

    return img;
}

/*!
 * \fn unsigned int getWidth(ImageRGB *image)
 * Returns the width of teh image
 * \param[in] image the image
 * \return unsigned int the image width
 */

unsigned int getWidth(ImageRGB *image) {
    if (image==NULL) return 0;
    return image->width;
}

/*!
 * \fn unsigned int getHeight(ImageRGB *image)
 * Returns the height of teh image
 * \param[in] image the image
 * \return unsigned int the image height
 */
unsigned int getHeight(ImageRGB *image) {
    if (image==NULL) return 0;
    return image->height;
}

/*!
 *  Free the memore allocated for a structure
 * \param[in] image ImageRGB to be deleted
 */
void  freeImage(ImageRGB * image) {

    if (image==NULL) return;

    if (image->raw_data==NULL) {
        free( (void *) image);
        return;
    }

    image->width = 0;
    image->height = 0;
    free((void *) image->raw_data);
    free( (void *) image);
}


/*!
 * \fn void setPixel(ImageRGB *image, unsigned  int r, unsigned  int c , PixelRGB p)
 *  Copy a Pixel at a specified location in the raw data.
 *  c is the column number, r the row number of the Pixel to be set.
 *  Its position in the raw data is given by (c + r*width) since the rows are stored continuously.
 * \param[out] image ImageRGB to be modified
 * \param[in] c The column number of the Pixel to be set
 * \param[in] r The row number of the Pixel to be set
 * \param[in] p Pixel value to set at this location
 */
void setPixel(ImageRGB *image, unsigned int r, unsigned int c , PixelRGB p) {
    if (image==NULL || r>=image->height || c>=image->width) return ;

    image->raw_data[image->width*r+c] = p;
}

/*!
 * \fn PixelRGB getPixel(ImageRGB *image, unsigned int r, unsigned  int c)
 *  Give the pixel value of  specified location in the raw data.
 *  Its position in the raw data is given by (c + r*width) since the rows are stored continuously.
 * \param[in] image ImageRGB to read
 * \param[in] c The column number of the Pixel to read
 * \param[in] r The row number of the Pixel to read
 * \return PixelRGB Pixel value at this location
 */

PixelRGB getPixel(ImageRGB *image, unsigned int r, unsigned int c) {
    if (image==NULL || r>=image->height || c>=image->width) return (PixelRGB) {'\0', '\0', '\0'};

    return image->raw_data[image->width*r+c];
}

/*!
 * \fn ImageRGB* createCross(int length)
 * The resulting image is a red square with a blue cross inside.
 * \param[in] length the square size
 * \return a pointer on the new image
 */

ImageRGB* createCross(int length) {
    unsigned int i = 0;
    unsigned int j = 0;
    ImageRGB *img = NULL;
    PixelRGB pxl_bleu = {255, 0, 0};
    PixelRGB pxl_rouge = {0, 0, 255};

    if (length<=0) return NULL;

    img = allocateImage(length, length);

    for (i=0; i<(unsigned int)length; i++) {
        for (j=0; j<(unsigned int)length; j++) {
            if (i==j || j== ( (unsigned int) length)-1-i ) {
                setPixel(img, i, j, pxl_bleu);
            }
            else {
                setPixel(img, i, j, pxl_rouge);
            }
        }
    }

    return img;
}

/*!
 * \fn void modifyImage(ImageRGB * image, PixelRGB pix_initial, PixelRGB pix_final)
 *  Modify an image by replacing every pixel with a given value by another one
 * \param[in,out] image ImageRGB to be modified
 * \param[in] pix_initial initial value in the image to be replaced
 * \param[in] pix_final the new value for those pixels
 */
void modifyImage(ImageRGB * image, PixelRGB pix_initial, PixelRGB pix_final) {
    unsigned int i = 0;
    unsigned int j = 0;

    if (image==NULL) return;

    for (i=0; i<image->height; i++) {
        for (j=0; j<image->width; j++) {
            PixelRGB pixel_actuel = getPixel(image, i, j);
            if ( pixel_actuel.blue == pix_initial.blue
                &&
                pixel_actuel.green == pix_initial.green
                &&
                pixel_actuel.red == pix_initial.red
                ) setPixel(image, i, j, pix_final);
        }
    }
}
