/*!
 * \file BMPFile.h
 * \brief declaraion des fonctions associees a un fichier image
 * \date ...
 */

#ifndef BMPFILE_INC_H
#define  BMPFILE_INC_H

#include <stdint.h>
#include <math.h>
#include "imageRGB.h"

/**
To avoid padding (issue with sizeof(FileHeader) otherwise -> if padding enabled, replace sizeof(FileHeader) with the value 14 )
*/
#pragma pack(1)

/** A struct typedef to store the content of the BMP file header
*/
typedef struct {
 char identity[2];              /*!<"BM" for a Windows BitMap*/
 uint32_t  file_size;           /*!<4 bytes for an unsigned int*/
 char application_id[4];        /*!<4 bytes for the id of the application which creates the file*/
 uint32_t raster_address;       /*!<4 bytes corresponding to the adress in the file where the image data begins*/
}FileHeader;


/** A struct typedef to store the content of the DIB  header
*/
typedef struct {
  uint32_t size_DIBHeader;      /*!<DIB Header size*/
  uint32_t image_width;         /*!<Image width in pixels = number of columns*/
  uint32_t image_height;        /*!<Image height in pixels = number of rows*/
  uint16_t nbColorPlanes;       /*!<set to 1*/
  uint16_t nbBitPerPixel;       /*!<set to 24 for the practical work (3 bytes for RGB)*/
  uint32_t typeCompression;     /*!<set to  0 for RGB colour space*/
  uint32_t size_raw_image;      /*!<total image data size = nb pixel * size of a pixel*/
  int32_t hResolution;          /*!<horizontal resolution. Equals to  2800 fo this PW*/
  int32_t vResolution;          /*!<vertical resolution. Equals to  2800 fo this PW*/
  uint32_t nbUsedColours;       /*!<set to 0 for this PW*/
  uint32_t nbImportantColours;  /*!<set to 0 for this PW*/
}DIBHeader;

void displayFileHeader(FileHeader* eFichier);
void displayDIBHeader(DIBHeader* eImage);
ImageRGB* readBMPFile_teacher(char * nomFichier, int verbose);
void writeBMPFile_teacher(char * nomFichier,ImageRGB* image, int verbose);


#endif
