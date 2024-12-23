#include "BMPFile.h"

void displayFileHeader(FileHeader* eFichier) {
    if (eFichier==NULL) return;

    fprintf(stdout, "File header : \n");
    fprintf(stdout, "identity : %s\n", eFichier->identity);
    fprintf(stdout, "file size : %u\n", eFichier->file_size);
    fprintf(stdout, "application id : %s\n", eFichier->application_id);
    fprintf(stdout, "raster adress : %u\n", eFichier->raster_address);
    fprintf(stdout, "\n");
}

void displayDIBHeader(DIBHeader* eImage) {
    if (eImage==NULL) return;

    fprintf(stdout, "DIB Header : \n");
    fprintf(stdout, "size : %u\n", eImage->size_DIBHeader);
    fprintf(stdout, "image width : %u\n", eImage->image_width);
    fprintf(stdout, "image height : %u\n", eImage->image_height);
    fprintf(stdout, "nb of colors planes : %u\n", eImage->nbColorPlanes);
    fprintf(stdout, "nb of bit(s) per pixel : %u\n", eImage->nbBitPerPixel);
    fprintf(stdout, "type compression : %u\n", eImage->typeCompression);
    fprintf(stdout, "size of the raw image : %u\n", eImage->size_raw_image);
    fprintf(stdout, "horizontal resolution : %d\n", eImage->hResolution);
    fprintf(stdout, "vertical resolution : %d\n", eImage->vResolution);
    fprintf(stdout, "nb of used colours : %u\n", eImage->nbUsedColours);
    fprintf(stdout, "nb of important colours : %u\n", eImage->nbImportantColours);
    fprintf(stdout, "\n");
}

void writeBMPFile(char * nomFichier, ImageRGB* image, int verbose) {
    unsigned int hauteur = 0;
    unsigned int largeur = 0;
    unsigned int i = 0;
    unsigned int j = 0;
    unsigned int valeur_padding = 0;

    if (image==NULL || image->raw_data==NULL) {
        fprintf(stderr, "Erreur image nulle ou image raw date nul dans writeBMPFile()\n");
        return;
    }

    FILE *fichier = fopen(nomFichier, "wb");
    if (fichier==NULL) {
        fprintf(stderr, "Erreur d'ouverture du fichier dans writeBMPFile()\n");
        return;
    }

    valeur_padding = 4 - ( image->width*sizeof(PixelRGB) %4 );
    if (valeur_padding==4) {
        valeur_padding=0;
    }

    hauteur = image->height;
    largeur = image->width;

    FileHeader fh = {
        "BM",
        sizeof(FileHeader)+sizeof(DIBHeader)+image->height*image->width*sizeof(PixelRGB),
    "100",
        sizeof(FileHeader)+sizeof(DIBHeader)
    };

    DIBHeader dh = {
        sizeof(DIBHeader),
        image->width,
        image->height,
        1,
        24,
        0,
        image->height*image->width*sizeof(PixelRGB),
        2800,
        2800,
        0,
        0
    };

    if (verbose==1) {
        displayFileHeader(&fh);
        displayDIBHeader(&dh);
    }

    fwrite( (void *) &fh, sizeof(FileHeader), 1, fichier);
    fwrite( (void *) &dh, sizeof(DIBHeader), 1, fichier);

    for (i=hauteur; i>=1; i--) {
        fwrite( (void *) &(image->raw_data[largeur*(i-1)]), sizeof(PixelRGB), image->width, fichier);

        for (j=0; j<valeur_padding; j++) {
            fputc(0, fichier);
        }

    }

    fclose(fichier);
}

void readFileHeader(FILE * fp, FileHeader * eFichier) {
    fread( (void *) eFichier, sizeof(FileHeader), 1, fp);
}

void readDIBHeader(FILE * fp, DIBHeader *eImage) {
    fread( (void *) eImage, sizeof(DIBHeader), 1, fp);
}

ImageRGB * readRawImage(FILE * fp, unsigned int address, int l, int h) {
    ImageRGB *img = allocateImage(h, l);
    unsigned int i = h;

    unsigned int valeur_padding = 4 - ( l*sizeof(PixelRGB) %4 );
    if (valeur_padding==4) {
        valeur_padding=0;
    }

    fseek(fp, address, SEEK_SET);

    for (i; i>=1; i--) {
        fread( (void *) &(img->raw_data[l*(i-1)]), sizeof(PixelRGB), l, fp);
        fseek(fp, valeur_padding, SEEK_CUR);
    }

    return img;
}

ImageRGB * readBMPFile( char *filename, int verbose) {
    if (filename==NULL) return NULL;

    FILE *fp = fopen(filename, "rb");
    if (fp==NULL) {
        fprintf(stderr, "Erreur d'ouverture du fichier dans readBMPFile()\n");
        return NULL;
    }

    FileHeader *fh = (FileHeader *) calloc(1, sizeof(FileHeader));
    if (fh==NULL) {
        fprintf(stderr, "Erreur d'allocation du FileHeader dans readBMPFile()\n");
        return NULL;
    }
    readFileHeader(fp, fh);

    DIBHeader *dh = (DIBHeader *) calloc(1, sizeof(DIBHeader));
    if (dh==NULL) {
        fprintf(stderr, "Erreur d'allocation du DIBHeader dans readBMPFile()\n");
        return NULL;
    }
    readDIBHeader(fp, dh);

    if (verbose==1) {
        displayFileHeader(fh);
        displayDIBHeader(dh);
    }

    unsigned int adresse_debut_raw_image = fh->raster_address;
    unsigned int hauteur = dh->image_height;
    unsigned int largeur = dh->image_width;

    free( (void *) fh);
    free( (void *) dh);

    ImageRGB *img = readRawImage(fp ,adresse_debut_raw_image, largeur, hauteur);

    fclose(fp);

    return img;
}