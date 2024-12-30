#include "multimedia-object.h"
#include <string.h>
#include <stdio.h>

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
    if (o==NULL || name==NULL || path==NULL) return;

    strncpy(o->name, name, MY_NAME_MAX-1);
    strncpy(o->path, path, MY_PATH_MAX-1);
    o->date = createDate(day, month, year);
    if (type>2 || type<0) o->type = UNDEFINED;
    o->type = type;
}

int changeNameMO(MultimediaObject *mo, char *nouveauNom) {
    if (mo==NULL || nouveauNom==NULL) return 0;

    strncpy(mo->name,  nouveauNom, MY_NAME_MAX-1);
    return 1;
}

void displayConsoleOM(MultimediaObject *mo) {
    if (mo==NULL) return;

    fprintf(stdout, "Multimedia object :\n");
    fprintf(stdout,"Name : %s\n", mo->name);
    fprintf(stdout,"Path : %s\n", mo->path);
    fprintf(stdout, "Date : %d/%d/%d\n", mo->date.day, mo->date.month, mo->date.year);

    switch (mo->type) {
        case PHOTO:
            fprintf(stdout, "Type : PHOTO\n");
            break;
        case VIDEO:
            fprintf(stdout, "Type : VIDEO\n");
            break;
        default:
            fprintf(stdout, "Type : UNDEFINED\n");
            break;
    }

    fprintf(stdout, "\n");

}

#include "test.h"
/*!
* \brief  Unit testing of the functions provided in the multimedia-object.c file
*/
void test_MO()
{
	printf("Tests unitaires du module multimedia-object :\n");
    MultimediaObject mo = {};
    fillMO(&mo, "Photo1.png", "/Documents", 1, 1, 1, PHOTO);
    display_test_string("test name", "Photo1.png", mo.name);
    display_test_string("test path", "/Documents", mo.path);
    display_test_int("test date day", 1, mo.date.day);
    display_test_int("test date month", 1, mo.date.month);
    display_test_int("test date year", 1, mo.date.year);
    changeNameMO(&mo, "abc");
    display_test_string("test name après changeNameMO()", "abc", mo.name);
    mo.type = 1;
    changeNameMO(&mo, "video.mp4");
    display_test_check_by_user("type de mo : video et nom = video.mp4 :");
    displayConsoleOM(&mo);

}

