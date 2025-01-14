/*!
* \file list.c
* \brief File with the definition of the doubly-linked list.
* \author kdesnos
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

ListNode *getFirst(List *l) {
    if (l==NULL || l->current==NULL) return NULL;

    ListNode *res = l->current;
    while (res->previous!=NULL) {
        res = res->previous;
    }
    return res;
}


ListNode * newListNode(ListNode * p, ListNode * n)
{

    ListNode *noeud = (ListNode *) calloc(1, sizeof(ListNode));
    if (noeud==NULL) {
        fprintf(stderr, "Erreur allocation memoire dans newListNode()\n");
        return NULL;
    }
    noeud->letter = '\0';
    noeud->previous = p;
    noeud->next = n;
    return noeud;
}
void freeListNode(ListNode * n)
{
    if (n==NULL) return;
    n->letter = '\0';
    n->previous = NULL;
    n->next = NULL;
    free(n);

}

void initList(List * l)
{

    l->current = newListNode(NULL,NULL);
    l->current->letter = '\0';
}

void next (List * l)
{
    if (l==NULL) return;

    ListNode *noeud_suivant = l->current->next;

    if(noeud_suivant==NULL) {
        ListNode *noeud_actuel = l->current;
        noeud_suivant = newListNode(noeud_actuel,NULL);
        noeud_actuel->next = noeud_suivant;
        noeud_suivant->previous = noeud_actuel;
    }

    l->current = l->current->next;
}
void previous(List *l)
{
    if (l==NULL) return;

    ListNode *noeud_precedent = l->current->previous;

    if(noeud_precedent==NULL) {
        ListNode *noeud_actuel = l->current;
        noeud_precedent = newListNode(NULL, noeud_actuel);
        noeud_actuel->previous = noeud_precedent;
        noeud_precedent->next = noeud_actuel;
    }

    l->current = l->current->previous;
}


void deleteCurrent(List * l)
{
    if (l==NULL) return;

    ListNode *noeud_a_supprimer = l->current;
    if (noeud_a_supprimer==NULL) return;

    ListNode *noeud_suivant = noeud_a_supprimer->next;
    ListNode *noeud_precedent = noeud_a_supprimer->previous;
    if (noeud_precedent==NULL && noeud_suivant==NULL) return;

    if (noeud_suivant!=NULL) {
        freeListNode(noeud_a_supprimer);
        l->current = noeud_suivant;
        noeud_suivant->previous = noeud_precedent;
        if (noeud_precedent==NULL) return;
        noeud_precedent->next = noeud_suivant;
        return;
    }

    freeListNode(noeud_a_supprimer);
    noeud_precedent->next = noeud_suivant;
    l->current = noeud_precedent;

}

void setCurrentLetter (List * l, char c)
{
    if (l==NULL || l->current==NULL) return;
    l->current->letter = c;
}

char getCurrentLetter (List * l)
{
    if (l==NULL || l->current==NULL) return '\0';
    return l->current->letter;
}

void printList(List * l)
{
    if (l==NULL || l->current==NULL) return;

    fprintf(stdout, "Liste : ");
    ListNode *n = getFirst(l);
    while (n!=NULL) {
        if (n==l->current) fprintf(stdout, "[%c] ", getCurrentLetter(l));
        else fprintf(stdout, "%c ", n->letter);
        n = n->next;
    }
    fprintf(stdout, "\n");
}


void testList()
{
    List *l = (List *) calloc(1, sizeof(List));
    initList(l);
    next(l);
    l->current = l->current->previous;
    previous(l);
    setCurrentLetter(l, 'a');
    next(l);
    setCurrentLetter(l, 'b');
    next(l);
    setCurrentLetter(l, 'c');
    printList(l);
    previous(l);
    previous(l);
    printList(l);
    deleteCurrent(l);
    printList(l);
    deleteCurrent(l);
    printList(l);
    deleteCurrent(l);
    printList(l);
    free(l);


}
