/*!
* \file memoryList.c
* \brief File with the functions required to manage the list of allocated blocks as studied in the leak detector lab
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "memoryList.h"

/*!
* \brief Free memory stored in a  MemoryBlock
* \param[in] b the address of the block structure to be freed.
*/
static void freeMemoryBlock(MemoryBlock *b)
{
    if(b->file != NULL)
        free((void*) b->file);
    if(b->function != NULL)
        free((void*) b->function);

    b->file = b->function = NULL;
}

/*!
* \brief Initialize data for a memory block
* \param[in] b the address of the block structure to be initialized. 
* \param[in] f the filename
* \param[in] fn the function name
* \param[in] l the line number
* \param[in] a the address of the allocated block
* \return MemoryBlock* the address of the initialised structure
*/
static MemoryBlock * initMemoryBlock(MemoryBlock *b,const char *f,  const char * fn, int l, void * a) {
    b->file = (char *)malloc(strlen(f)+1);
    b->function = (char *)malloc(strlen(fn)+1);
    if(b->file != NULL && b->function !=NULL) {
        strcpy(b->file,f);
        strcpy(b->function,fn);
        b->line = l;
        b->address = a;
    }
    else {
        freeMemoryBlock(b);
    }
    return b;
}

static NodeList * newNodeList(const char *f, const char *fn, int l, void *a, NodeList *n, NodeList *p) {
    NodeList *res = (NodeList *) calloc(sizeof(NodeList), 1);

    if (res==NULL) {
        return NULL;
    }

    res->previous = p;
    res->next = n;

    initMemoryBlock(&(res->b), f, fn, l, a);

    return res;
}

static void freeNodeList (NodeList * n) {
    if (n==NULL) return;

    freeMemoryBlock( &(n->b) );

    free(n);
}

void initList (List * l) {
    if (l==NULL) return;
    l->sentinel_begin.previous = NULL;
    l->sentinel_begin.next = &(l->sentinel_end);

    l->current = &(l->sentinel_begin);

    l->sentinel_end.previous = &(l->sentinel_begin);
    l->sentinel_end.next = NULL;
}

int isEmpty (List *l) {
    if (l==NULL) return 0;
    return l->sentinel_begin.next==&(l->sentinel_end) && l->sentinel_end.previous==&(l->sentinel_begin);
}

int isFirst(List * l) {
    if (l==NULL || isEmpty(l)) return 0;
    return l->current==l->sentinel_begin.next;
}
int isLast(List * l) {
    if (l==NULL || isEmpty(l)) return 0;
    return l->current==l->sentinel_end.previous;
}

int isOutOfList(List * l) {
    if (l==NULL) return 0;
    return l->current==&(l->sentinel_begin) || l->current==&(l->sentinel_end) || isEmpty(l);
}

void setOnFirst( List * l) {
    if (l==NULL) return ;
    if (isEmpty(l)) {
        l->current = &(l->sentinel_begin);
        return ;
    }
    l->current = l->sentinel_begin.next;
}

void setOnLast( List * l) {
    if (l==NULL) return ;
    if (isEmpty(l)) {
        l->current = &(l->sentinel_end);
        return ;
    }
    l->current = l->sentinel_end.previous;
}

void setOnNext(List * l) {
    if (l==NULL || isEmpty(l)) return;
    l->current = l->current->next;
}

void setOnPrevious( List * l) {
    if (l==NULL || isEmpty(l)) return;
    l->current = l->current->previous;
}

void * getCurrentAddress(List * l) {
    if (l==NULL || isEmpty(l)) return NULL;

    return l->current->b.address;
}

void printList(List * l) {
    if (l==NULL ||isEmpty(l)) return;

    fprintf(stdout, "Début liste : \n");
    setOnFirst(l);
    while(isOutOfList(l)==0) {
        fprintf(stdout,"File : %s, Function : %s\n Line %d, Adress %p\n \n",
            l->current->b.file, l->current->b.function, l->current->b.line, l->current->b.address);
        setOnNext(l);
    }
    fprintf(stdout, "Fin liste \n");
}

int countElement(List * l) {
    int nb = 0;

    if (l==NULL || isEmpty(l)) return nb;

    setOnFirst(l);
    while ( isOutOfList(l)==0 ) {
        nb+=1;
        setOnNext(l);
    }
    return nb;
}

int insertSort (List * l, const char *f, const char * fn, int ln, void * a) {

    if (l==NULL) return 0;

    NodeList *n = newNodeList(f, fn, ln, a, NULL, NULL);
    if (n==NULL) return 0;

    if (isEmpty(l)==1) {
        n->previous = &(l->sentinel_begin);
        l->sentinel_begin.next = n;
        n->next = &(l->sentinel_end);
        l->sentinel_end.previous = n;
        return  1;
    }

    setOnFirst(l);
    while( isOutOfList(l)==0 ) {
        if (
            strcmp(f, l->current->b.file)<0
            || ( strcmp(f, l->current->b.file)==0 && strcmp(fn, l->current->b.function)<0 )
            || ( strcmp(f, l->current->b.file)==0 && strcmp(fn, l->current->b.function)==0 && (ln-l->current->b.line) <0 )
            ) break;

        setOnNext(l);
    }

    n->previous = l->current->previous;
    l->current->previous->next = n;

    n->next = l->current;
    l->current->previous = n;

    return 1;
}

int find(List * l, void * a) {
    if(l==NULL || isEmpty(l)) return 0;

    setOnFirst(l);
    while ( isOutOfList(l)==0 ) {
        if (getCurrentAddress(l)==a) return 1;
        setOnNext(l);
    }

    return 0;
}

#include "test.h"

void * deleteValue(List *l ,void * a) {
    if (l==NULL || isEmpty(l) ) return NULL;

    int res_find = find(l, a);
    if (res_find==0) return NULL;

    l->current->previous->next = l->current->next;
    l->current->next->previous = l->current->previous;
    void *res = l->current->b.address;
    NodeList * n = l->current;
    freeNodeList(n);
    setOnFirst(l);
    return res;
}

void testMemoryList() {
    List *l  = (List *) calloc(sizeof(List), 1);

    if (l==NULL) {
        fprintf(stderr, "Erreur allocation mémoire de la liste dans testMemoryList() -> fin du programme\n");
        exit(-1);
    }

    initList(l);

    display_test_int("test initList -> doit être vide", 1, isEmpty(l));
    int res_insertion = insertSort(l , "fichierA.txt", "fonctionA", 1, (void *)0x1 );
    display_test_int("test insertSort()", 1, res_insertion);
    display_test_int("test isEmpty() sur la liste à 1 élément", 0, isEmpty(l));

    setOnFirst(l);
    display_test_int("test isFirst() -> liste à 1 seul élément", 1, isFirst(l));
    display_test_int("test isLast() -> liste à 1 seul élément", 1, isLast(l));

    display_test_int("test countElement() -> liste à 1 seul élément", 1, countElement(l));

    insertSort(l , "fichierA.txt", "fonctionB", 2, (void *)0x2 );
    insertSort(l , "fichierC.txt", "fonctionC", 3, (void *)0x3 );
    display_test_int("test countElement() -> liste à 3 éléments", 3, countElement(l));

    setOnFirst(l);
    display_test_string("test insertSort() et setOnFirst()", "fichierA.txt", l->current->b.file);
    setOnNext(l);
    display_test_string("test insertSort() et setOnNext()", "fonctionB", l->current->b.function);
    setOnLast(l);
    display_test_string("test insertSort() et setOnLast()", "fichierC.txt", l->current->b.file);

    int res_find = find(l, (void *)0x3);
    display_test_int("test find() -> élément présent", 1, res_find);
    display_test_string("test find() -> vérfication nom élément", "fichierC.txt", l->current->b.file);

    res_find = find(l, (void *) 0x4);
    display_test_int("test find() -> élément absent", 0, res_find);

    setOnFirst(l);
    display_test_int("test getCurrentAddress() du 1er élément", 0x1, (int) getCurrentAddress(l));

    void *adresse = deleteValue(l, (void *) 0x1);
    display_test_int("test deleteValue()", (int) 0x1, (int) adresse);
    display_test_int("test countElement() -> 2 éléments après deleteValue()", 2, countElement(l));

    setOnFirst(l);
    display_test_string("test setOnFirst() -> nom fichier", "fichierA.txt", l->current->b.file);

    setOnLast(l);
    display_test_string("test setOnLast() -> nomFichier", "fichierC.txt", l->current->b.file);

    setOnPrevious(l);
    display_test_string("test setOnPrevious() -> nom fichier", "fichierA.txt", l->current->b.file);

    setOnNext(l);
    display_test_int("test setOnNext() -> ligne", 3, l->current->b.line);

    display_test_check_by_user("test printList() -> liste à 2 éléments");
    printList(l);

    setOnFirst(l);
    while( isEmpty(l)== 0) {
        deleteValue(l, getCurrentAddress(l));
    }
    display_test_int("test isEmpty() après avoir supprimé tout les noeuds de la liste avec deleteValue()", 1, isEmpty(l));

    free(l);
}