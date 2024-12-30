
/*!
* \file list.c
* \brief File with the functions required to manage the list as studied in labs 6 and 7
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "listMO.h"


/*!
* \brief Allocate memory for the data element and initialize the structure members
* \param[in] name the name of the multimedia object
* \param[in] path the path of the multimedia object
* \param[in] day the day of creation of the multimedia object
* \param[in] month the  month of creation  of the multimedia object
* \param[in] year the  year of creation  of the multimedia object
* \param[in] type the type of the multimedia object
* \param[in] n the address of the setOnNext data element
* \return NodeList* the address of the new data element
*/
static NodeList *newNodeList(char * name, char * path, int day, int month, int year, TypeMultimediaObject type , NodeList *n)
{
    NodeList *newNL = (NodeList *) malloc(sizeof(NodeList));
    if(newNL != NULL)
    {
        fillMO(&(newNL->value),name,path,day,month,year,type);
        newNL->next = n;
    }
    else
        fprintf(stderr,"Erreur d'allocation memoire dans newNodeList()\n");
    return newNL;
}


/*!
* \brief Desallocate memory associated to a node
* \param[in] n the address of the  data element to be freed
*/
static void freeNodeList(NodeList *n)
{
    free((void *)n);
}

void initList(List * l) {
    if (l==NULL) return;
    l->first = NULL;
    l->current = NULL;
    l->last = NULL;
}

int isEmpty(List * l) {
    if (l==NULL) return -1;

    if (l->first==NULL) return 1;

    return 0;
}

int insertFirst(List * l, char * name, char * path, int day, int month, int year, TypeMultimediaObject type) {
    if (l==NULL) return 0;

    NodeList *n = newNodeList(name, path, day, month, year, type, l->first);

    MultimediaObject mo = {};
    fillMO(&mo, name, path, day, month, year, type);
    n->value = mo;

    if (isEmpty(l)) {
        l->first = n;
        l->current = n;
        l->last = n;
        return 1;
    }

    l->first = n;
    l->current = n;

    return 1;
}

int isFirst(List * l) {
    if (l==NULL) return -1;

    return l->current==l->first;
}

int isLast(List * l) {
    if (l==NULL) return -1;

    return l->current==l->last;
}

int isOutOfList(List * l) {
    if (l==NULL) return -1;

    return l->current==NULL;
}

char * getCurrentName (List * l) {
    if (l==NULL) return NULL;

    return l->current->value.name;
}
char * getCurrentPath (List * l) {
    if (l==NULL) return NULL;

    return l->current->value.path;
}

Date getCurrentDate (List * l) {
    if (l==NULL) return (Date) {-1, -1, -1};

    return l->current->value.date;
}

TypeMultimediaObject getCurrentType (List * l) {
    if (l==NULL) return UNDEFINED;

    return l->current->value.type;
}

void setOnFirst(List * l) {
    if (l==NULL) return;

    l->current = l->first;
}

void setOnLast(List * l) {
    if (l==NULL) return;

    l->current = l->last;
}

void setOnNext (List * l) {
    if (l==NULL) return;

    l->current = l->current->next;
}

void printList(List * l) {
    if (l==NULL) return;



    setOnFirst(l);

    if (isEmpty(l)) {
        fprintf(stdout, "Liste vide\n");
        return;
    }

    while (!isOutOfList(l)) {
        displayConsoleOM( &(l->current->value) );
        setOnNext(l);
    }
}

int nbElement(List * l) {
    int nb = 0;
    if (l==NULL) return nb;

    setOnFirst(l);
    while (!isOutOfList(l)) {
        nb++;
        setOnNext(l);
    }
    return nb;
}

int find(List * l, char* name) {
    if (l==NULL || isEmpty(l)) return 0;

    setOnFirst(l);
    while (!isOutOfList(l)) {
        if (strcmp(l->current->value.name, name)==0) return 1;
        setOnNext(l);
    }

    return 0;
}

static int deleteFirst(List *l) {
    if (l==NULL || isEmpty(l)) return 0;

    if (nbElement(l)==1) {
        freeNodeList(l->first);
        l->first = NULL;
        l->current = NULL;
        l->last = NULL;
        return 1;
    }

    NodeList *tmp = l->first;
    l->current = l->first->next;
    l->first = l->first->next;

    freeNodeList(tmp);
    return 1;

}

static int deleteCurrent(List *l) {
    if (l==NULL || isEmpty(l)) return 0;

    if (isFirst(l)) return deleteFirst(l);

    NodeList *n = l->current;

    setOnFirst(l);
    while (l->current->next!=n) setOnNext(l);

    l->current->next = n->next;
    freeNodeList(n);
    return 1;
}

int deleteValue(List *l, char * name) {
    if (l==NULL || isEmpty(l)) return 0;

    setOnFirst(l);
    while (!isOutOfList(l)) {
        if (strcmp(l->current->value.name, name)==0) {
            return deleteCurrent(l);
        }
        setOnNext(l);
    }

    return 0;
}

void freeList(List * n) {
    if (n==NULL || isEmpty(n)) return;

    setOnFirst(n);
    while (!isEmpty(n)) deleteFirst(n);
}

#include "test.h"
/*!
* \brief  Unit testing of the functions provided in the list.c file
*/
void test_list()
{
    List l1;
    int ret1;
    printf("Unit tests on the list module\n");

    /*group 1*/

    initList(&l1);
    display_test_int("Test isEmpty() on an empty list",1,isEmpty(&l1));
    display_test_int("Test isOutOfList() when the list is empty",1,isOutOfList(&l1));
    display_test_string("Test getCurrentName() when the list is empty",NULL,getCurrentName(&l1));
    display_test_check_by_user("Test printList on an isEmpty list");
    printList(&l1);

    ret1 = insertFirst(&l1,"WEI","data/fish.jpg",10,10,2014,PHOTO);
    display_test_int("Test insertFirst() on an empty list",1,ret1);

    ret1 = insertFirst(&l1,"WEI2","data/fishAndTree.jpg",11,10,2014,PHOTO);
    display_test_int("Test insertFirst() on a not-empty list",1,ret1);
    display_test_check_by_user("Test insertFirst : (list should be with WEI2 and WEI)");
    display_test_int("Test isEmpty() on an non-empty list",0,isEmpty(&l1));

    setOnLast(&l1);
    display_test_int("Test isLast() when  setOnLast",1,isLast(&l1));
    display_test_int("Test isFirst() when not on first",0,isFirst(&l1));
    display_test_int("Test isOutOfList() when  in the list",0,isOutOfList(&l1));
    display_test_string("Test getCurrentName() when in the list","WEI",getCurrentName(&l1));

    setOnNext(&l1);
    display_test_int("Test isOutOfList() when out of the non-empty list",1,isOutOfList(&l1));
    display_test_string("Test getCurrentName() when out of a non-empty list",NULL,getCurrentName(&l1));

    setOnFirst(&l1);
    display_test_int("Test isFirst() when setOnFirst ",1,isFirst(&l1));
    display_test_int("Test isLast() when  not on last",0,isLast(&l1));
    display_test_string("Test getCurrentName() when in the list","WEI2",getCurrentName(&l1));

    setOnNext(&l1);
    display_test_int("Test setOnNext()",1,isLast(&l1));

    /*group 2*/
    insertFirst(&l1, "Image1", "~/Images/image1.png", 1, 1, 2024, PHOTO);
    insertFirst(&l1, "Image2", "~/Images/image2.png", 2, 2, 2024, PHOTO);

    ret1 = find(&l1, "Image2");
    display_test_int("find() sur un élément présent dans la liste", 1, ret1 );

    ret1 = find(&l1, ":)");
    display_test_int("find() sur un élément non présent dans la liste", 0, ret1 );

    /*group 3*/
    insertFirst(&l1, "Image1", "~/Images/image1.png", 1, 1, 2024, PHOTO);
    insertFirst(&l1, "Image2", "~/Images/image2.png", 2, 2, 2024, PHOTO);

    ret1 = deleteFirst(&l1);
    display_test_int("deleteFirst() sur une liste non vide", 1,  ret1);
    display_test_string("La liste après utilisation de deleteFirst()", "Image1", getCurrentName(&l1));

    ret1 = deleteFirst(&l1);
    display_test_int("deleteFirst() la même liste (non vide)", 1, ret1);
    freeList(&l1);
    display_test_int("La liste doit être vide", 1, isEmpty(&l1));

    insertFirst(&l1, "Vidéo1", "Vidéos/Vidéo1.mp4", 3, 3, 2024, VIDEO);
    insertFirst(&l1, "Vidéo2", "Vidéos/Vidéo2.mp4", 4, 4, 2024, VIDEO);

    setOnFirst(&l1);
    deleteCurrent(&l1);

    display_test_string("deleteCurrent() quand current = first", "Vidéo1", getCurrentName(&l1));

    setOnFirst(&l1);
    deleteCurrent(&l1);

    display_test_int("deleteCurrent() sur l'élément restant", 1, isEmpty(&l1));

    insertFirst(&l1, "xxx", "~/xxx.y", 5, 5, 2024, UNDEFINED);
    insertFirst(&l1, "aaa", "~/aaa.b", 6, 6, 2024, UNDEFINED);

    ret1 = deleteValue(&l1, "aaa");
    display_test_int("deletevalue() sur élément restant", 1, ret1);
    display_test_string("La liste après deleteValue()", "xxx", getCurrentName(&l1));

    ret1 = deleteValue(&l1, ":)");
    display_test_int("deletevalue() sur un élément non présent dans la liste", 0, ret1);
    display_test_int("deleteValue() on a non-existing value", 0, ret1);

    /*group 4*/
    freeList(&l1);
    display_test_int("freeList() sur une liste non vide", 1, isEmpty(&l1) );

    /*group 5*/
    //bah non mdr
}