
/*!
* \file memoryList.h
* \brief File with the definition of a list of allocated blocks as studied in the leak detector lab
*/
#ifndef MEMORYLIST_H
#define MEMORYLIST_H

/*!
* \brief the structure to store information about a memory block
*/
typedef struct {
    char * file;	        /*!< the filename where the memory has been allocated*/
    char * function;	    	/*!< the function name the memory has been allocated*/
    int line;		        /*!< the number of the line where the memory has been allocated*/
    void * address;	        /*!< the address of the allocated block*/
}MemoryBlock;

/*!
* \brief the data element type for the  list of allocated blocks
*/
typedef struct NodeList{
    MemoryBlock b;	/*!< information about the allocated block*/
    struct NodeList * next;	/*!< the address of the next element in the list*/
    struct NodeList * previous;	/*!< the address of the previous element in the list*/
}NodeList;

/*!
* \brief the list type
*/
typedef struct{
    NodeList sentinel_begin;       /*!< the sentinel node at the beginning*/
    NodeList * current;     /*!< the address of the current element in the list*/
    NodeList sentinel_end;        /*!< the sentinel node at the end*/
}List;

void initList(List * l);
int isEmpty(List * l);
int isFirst(List * l);
int isLast(List * l);
int isOutOfList(List * l);
void setOnFirst( List * l);
void setOnLast( List * l);
void setOnNext( List * l);
void setOnPrevious( List * l);
void * getCurrentAddress(List * l);
void printList(List * l);
int countElement(List * l);
int insertSort (List * l, const char *f, const char * fn, int ln, void * a);
int find(List * l, void * a);
void * deleteValue(List *l ,void * a);
void testMemoryList();

#endif
