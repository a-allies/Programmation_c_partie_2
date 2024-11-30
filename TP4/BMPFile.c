/*!
 * \file BMPFile.c
 * \brief definition of functions to handle a BMP file using RGB colour space
 * \author ...
 * \date ...
 */

#include "BMPFile.h"
#include "imageRGB.h"

void displayFileHeader( FileHeader* eFichier) {
    fprintf(stdout, "File header : \n");
    fprintf(stdout, "identity : %s\n", eFichier->identity);
    fprintf(stdout, "file size : %u\n", eFichier->file_size);
    fprintf(stdout, "application id : %s\n",eFichier->application_id);
    fprintf(stdout, "raster adress : %u\n", eFichier->raster_address);
}

void displayDIBHeader( DIBHeader* eImage) {
    fprintf(stdout, "DIB Header : \n");
    fprintf(stdout, "size DIB Header: %u\n", eImage->size_DIBHeader);
    fprintf(stdout, "image width: %u\n", eImage->image_width);
    fprintf(stdout, "image height: %u\n", eImage->image_height);
    fprintf(stdout, "number Color Planes: %u\n", eImage->nbColorPlanes);
    fprintf(stdout, "number bits per pixel: %u\n", eImage->nbBitPerPixel);
    fprintf(stdout, "type compression: %u\n", eImage->typeCompression);
    fprintf(stdout, "size raw image: %u\n", eImage->size_raw_image);
    fprintf(stdout, "horizontal resolution: %d\n", eImage->hResolution);
    fprintf(stdout, "vertical resolution: %d\n", eImage->vResolution);
    fprintf(stdout, "number used colors: %u\n", eImage->nbUsedColours);
    fprintf(stdout, "number used colors: %u\n", eImage->nbImportantColours);
}


void writeBMPFile(char * nomFichier,ImageRGB* image, int verbose) {
    int i = 0;
    int j = 0;
    if (image==NULL) return;
    int valeur_padding = 4-(sizeof(PixelRGB)*image->width)%4;
    if (valeur_padding==4) valeur_padding = 0;

    FileHeader f = {"BM",
                    14+sizeof(DIBHeader)+
                    sizeof(PixelRGB)*image->height*image->width,
                    "0000",
                    14+sizeof(DIBHeader)};

    DIBHeader d = { sizeof(DIBHeader),
                    image->width,
                    image->height,
                    1,
                    24,
                    0,
        sizeof(PixelRGB)*image->height*image->width,
            2800,
            2800,
                    0,
                    0
    };

    if(verbose==1) {
        displayFileHeader(&f);
        displayDIBHeader(&d);
    }

    FILE *ptr_fichier = fopen(nomFichier, "wb");
    if (ptr_fichier==NULL) {
        fprintf(stderr, "Erreur d'ouverture du fichier en écriture -> fin programme\n");
        exit(-1);
    }


    fwrite(f.identity, sizeof(char), 2, ptr_fichier);
    fwrite(&(f.file_size), sizeof(uint32_t), 1, ptr_fichier);
    fwrite(f.application_id, sizeof(char), 4, ptr_fichier);
    fwrite(&(f.raster_address), sizeof(uint32_t), 1, ptr_fichier);


    fwrite(&(d.size_DIBHeader), sizeof(uint32_t), 1, ptr_fichier);
    fwrite(&(d.image_width), sizeof(uint32_t), 1, ptr_fichier);
    fwrite(&(d.image_height), sizeof(uint32_t), 1, ptr_fichier);
    fwrite(&(d.nbColorPlanes), sizeof(uint16_t), 1, ptr_fichier);
    fwrite(&(d.nbBitPerPixel), sizeof(uint16_t), 1, ptr_fichier);
    fwrite(&(d.typeCompression), sizeof(uint32_t), 1, ptr_fichier);
    fwrite(&(d.size_raw_image), sizeof(uint32_t), 1, ptr_fichier);
    fwrite(&(d.hResolution), sizeof(int32_t), 1, ptr_fichier);
    fwrite(&(d.vResolution), sizeof(int32_t), 1, ptr_fichier);
    fwrite(&(d.nbUsedColours), sizeof(uint32_t), 1, ptr_fichier);
    fwrite(&(d.nbImportantColours), sizeof(uint32_t), 1, ptr_fichier);



    i = image->height-1;

    for(i; i>=0; i--) {
        fwrite( &(image->raw_data[image->width*i]) , sizeof(PixelRGB), image->width, ptr_fichier);
        for (j; j<valeur_padding; j++) fputc(0,ptr_fichier);
        j = 0;
    }

    fclose(ptr_fichier);
}

void readFileHeader ( FILE * fp , FileHeader * eFichier ) {
    fread(eFichier->identity,sizeof(char), 2, fp);
    fread( &(eFichier->file_size), sizeof(uint32_t), 1, fp);
    fread(eFichier->application_id, sizeof(char), 4, fp);
    fread( &(eFichier->raster_address), sizeof(uint32_t), 1, fp);
}

void readDIBHeader ( FILE * fp , DIBHeader * eImage ) {
    fread( &(eImage->size_DIBHeader), sizeof(uint32_t), 1, fp);
    fread( &(eImage->image_width), sizeof(uint32_t), 1, fp);
    fread( &(eImage->image_height), sizeof(uint32_t), 1, fp);
    fread( &(eImage->nbColorPlanes), sizeof(uint16_t), 1, fp);
    fread( &(eImage->nbBitPerPixel), sizeof(uint16_t), 1, fp);
    fread( &(eImage->typeCompression), sizeof(uint32_t), 1, fp);
    fread( &(eImage->size_raw_image), sizeof(uint32_t), 1, fp);
    fread( &(eImage->hResolution), sizeof(int32_t), 1, fp);
    fread( &(eImage->vResolution), sizeof(int32_t), 1, fp);
    fread( &(eImage->nbUsedColours), sizeof(uint32_t), 1, fp);
    fread( &(eImage->nbImportantColours), sizeof(uint32_t), 1, fp);
}

ImageRGB * readRawImage ( FILE * fp , unsigned int address , int l , int h ) {
    int i = 0;
    ImageRGB *image = allocateImage(h, l);

    int valeur_padding = 4-(sizeof(PixelRGB)*l)%4;
    if (valeur_padding==4) valeur_padding = 0;

    fseek(fp, address, SEEK_SET);

    i = h-1;
    for (i; i>=0; i--) {
        fread( &(image->raw_data[i*l]), sizeof(PixelRGB)*l, 1 , fp);
        fseek(fp, valeur_padding,SEEK_CUR);
    }

    return image;
}

ImageRGB * readBMPFile ( char * filename , int verbose ) {
    FILE *ptr_fic = fopen(filename, "rb");
    if (ptr_fic==NULL) {
        fprintf(stderr, "Erreur d'ouverture du fichier en lecture -> fin du programme\n");
        exit(-1);
    }
    FileHeader *fh = (FileHeader *) calloc(14, 1);
    DIBHeader *dh =   (DIBHeader *) calloc(sizeof(DIBHeader), 1);;

    readFileHeader(ptr_fic, fh);
    readDIBHeader(ptr_fic, dh);

    if(verbose==1) {
        displayFileHeader(fh);
        displayDIBHeader(dh);
    }

    ImageRGB *img = readRawImage(ptr_fic, fh->raster_address, dh->image_width, dh->image_height );

    free( (void *) fh);
    free( (void *) dh);
    fclose(ptr_fic);

    return img;
}