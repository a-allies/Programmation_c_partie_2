
/*!
* \file list.h
* \brief File defining the list structure as studied in Huffman coding practical work
*/

#ifndef LIST_H
#define LIST_H

#include "image.h"
#include "binary_tree.h"

/*!
* \brief Data element of a list, containing a tree
*/
typedef struct nodeList{
	 nodeTree * t;              /*!< A pointer to a tree*/
	 struct nodeList * next;    /*!< A pointer to the next element in the list*/
}nodeList;



/*!
* \brief list of tree nodes
*/
typedef struct{
	 nodeList *first; /*!< A pointer to the first list element*/
	 nodeList *current; /*!< A pointer to the current list element*/
	 nodeList *last; /*!< A pointer to the last list element*/
}list;


void initList(list *l);
void deleteList(list *l);

int empty(list * l);
int first(list * l);
int last(list * l);
int outOfList(list * l);

void setOnFirst(list * l);
void setOnLast(list * l);
void next (list * l);
nodeTree * getCurrentTree(list * l);

void printList(list * l);


int insertSort(list * l, nodeTree * p);

nodeTree * removeFirst(list * l);


#endif
