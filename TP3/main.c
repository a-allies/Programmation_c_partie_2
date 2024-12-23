#include <stdio.h>
#include <stdlib.h>
#include "BMPFile.h"
#include "imageRGB.h"
#include "test.h"
//#define MY_FILENAME_MAX 64
#define MY_FILENAME_MAX 24

int main () {
 //Question 2
  /*char filename [MY_FILENAME_MAX];
  ImageRGB * f = NULL;
  f = allocateImage (200 ,100);
  sprintf( filename,"image_test.bmp");
  writeBMPFile_teacher(filename, f, 0);
  */
//Question 5
      /*PixelRGB p0 = {0 ,0 ,0};
      PixelRGB p1 = {255 ,255 ,255};
      ImageRGB *f = readBMPFile_teacher("mask.bmp",0);
      modifyImage(f, p0, p1);
      writeBMPFile_teacher( "mask_unmasked.bmp" ,f ,0);
*/

    char filename[MY_FILENAME_MAX];
    ImageRGB* cross = NULL;
    ImageRGB* f = NULL;
    PixelRGB pixel_background = {4,4,4};
    PixelRGB pixel_white = {255,255,255};

    f = allocateImage(200,100);
    display_test_uint("Test allocateImage (getWidth)", 100, getWidth(f));
    display_test_uint("Test allocateImage (getHeight)", 200, getHeight(f));
    display_test_uint("Test allocateImage (getPixel)", 0, getPixel(f, 3, 3).red);
    setPixel(f,3,3,pixel_white);
    display_test_int("Test setPixel", 255, getPixel(f, 3, 3).blue);
    display_test_int("Test setPixel", 255, getPixel(f, 3, 3).green);
    display_test_int("Test setPixel", 255, getPixel(f, 3, 3).red);

    sprintf(filename,"test_allocate.bmp");
    writeBMPFile_teacher(filename, f, 0);
    freeImage(f);

    sprintf(filename,"mask.bmp");
    f = readBMPFile_teacher(filename,0);
    modifyImage(f,pixel_background,pixel_white);
    sprintf(filename,"result.bmp");
    writeBMPFile_teacher(filename,f,0);
    freeImage(f);


    cross = createCross(100);
    sprintf(filename,"cross.bmp");
    writeBMPFile_teacher(filename, cross, 0);
    f = readBMPFile_teacher(filename,0);
    sprintf(filename,"cross2.bmp");
    writeBMPFile_teacher(filename, f, 0);
    freeImage(f);

 return 0;
}
