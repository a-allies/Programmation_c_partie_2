#include "multimedia-object.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static Date createDate(int j, int m, int a)
{
    Date d;
    d.year = a;
    d.day = j;
    d. month = m;
    return d;
}

void fillMO (MultimediaObject * o, char * name, char * path, int day, int month, int year, TypeMultimediaObject type)
{
    if (o==NULL) return;

    strncpy( o->name, name, MY_NAME_MAX-1);
    o->name[MY_NAME_MAX-1] = '\0';

    strncpy( o->path, path, MY_PATH_MAX-1);
    o->path[MY_PATH_MAX-1] = '\0';

    o->type = type;
    o->date.day = day;
    o->date.month = month;
    o->date.year = year;

}

void changeNameMO(MultimediaObject *mo, char *nouveauNom) {
    strncpy(mo->name, nouveauNom, MY_NAME_MAX-1 );
    mo->name[MY_NAME_MAX-1] = '\0';
}

void displayConsoleOM( const MultimediaObject *mo) {
    fprintf(stdout, "Multimedia object : \n");
    fprintf(stdout, "name : %s\n", mo->name);
    fprintf(stdout, "path : %s\n", mo->path);
    fprintf(stdout, "date day/month/year: %d/%d/%d\n", mo->date.day, mo->date.month, mo->date.year);
    switch (mo->type) {
        case 0 : fprintf(stdout,"type : PHOTO\n"); break;
        case 1 : fprintf(stdout,"type : VIDEO\n"); break;
        default : fprintf(stdout,"type : UNDEFINED\n"); break;

    }
    fprintf(stdout,"\n");
}


#include "test.h"
/*!
* \brief  Unit testing of the functions provided in the multimedia-object.c file
*/
void test_MO()
{
	fprintf(stdout, "Tests unitaires du module multimedia-object :\n");

    MultimediaObject *mo = (MultimediaObject *) calloc(sizeof(MultimediaObject), 1);
    if (mo==NULL) {
        fprintf(stderr, "Erreur lors de l'allocation mémoire du MultimediaObject dans la fonction testMo() -> fin du porgramme\n");
        exit(-1);
    }
    fillMO(mo, "1er prénom", "ici", 1, 1, 2000, 0);

    display_test_string("Test du nom", "1er prénom", mo->name);
    display_test_string("Test du chemin d'accès", "ici", mo->path);
    changeNameMO(mo, "2ème et 3ème prénoms");
    display_test_check_by_user("Test de la mdoficationdu nom nom attendu : 2ème et 3ème prénoms");
    fprintf(stdout,"%s\n",mo->name);
    display_test_int("Test du jour", 1, mo->date.day);
    display_test_int("Test du mois", 1, mo->date.month);
    display_test_int("Test de l'année", 2000, mo->date.year);
    display_test_int("Test du type", 0, mo->type);

    free(mo);
}

