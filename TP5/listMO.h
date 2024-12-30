
/*!
* \file listMO.h
* \brief File with the definition of the list as studied in labs 6 and 7
*/
#ifndef LISTMO_H
#define LISTMO_H

#include "multimedia-object.h"
/*!
* \brief the data element type for the int list
*/
typedef struct NodeList{
    MultimediaObject value; /*!< the MultimediaObject*/
    struct NodeList * next; /*!< the address of the next element in the list*/
}NodeList;

/*!
* \brief the list type
*/
typedef struct{
    NodeList * first;       /*!< the address of the first element in the list*/
    NodeList * current;     /*!< the address of the current element in the list*/
    NodeList * last;        /*!< the address of the last element in the list*/
}List;

    /*group 1: create a list and basic operations*/
    void initList(List * l);
    int isEmpty(List * l);
    int insertFirst(List * l, char * name, char * path, int day, int month, int year, TypeMultimediaObject type);

    int isFirst(List * l);
    int isLast(List * l);
    int isOutOfList(List * l);
    char * getCurrentName (List * l);
    char * getCurrentPath (List * l);
    Date getCurrentDate (List * l);
    TypeMultimediaObject getCurrentType (List * l);

    void setOnFirst(List * l);
    void setOnLast(List * l);
    void setOnNext (List * l);

    void printList(List * l);
    int nbElement(List * l);

    /*group 2 : find an element*/
    int find(List * l, char* name);

    /*group 3 : suppress a given an element*/
    int deleteValue(List *l, char * name);

    /*group 4 : suppress all information in the list */
    void freeList(List * n);

    /* unit test*/
    void test_list();

#endif
