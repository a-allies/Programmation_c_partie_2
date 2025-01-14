/*!
* \file file.c
* \brief To manipulate files and doubly-linked list.
* \author kdesnos
*/

#include <stdio.h>
#include "list.h"


void saveList(List* l, char* fileName)
{
    if (l==NULL) {
        fprintf(stderr, "List * NULL dans saveList()\n");
        return;
    }

    if (l->current==NULL) {
        fprintf(stderr, "Le current de lsit est NULL dans saveList()\n");
        return;
    }

    if (fileName==NULL) {
        fprintf(stderr, "filename NULL dans saveList()\n");
        return;
    }

    FILE *fichier = fopen(fileName, "wb");
    if (fichier==NULL) {
        fprintf(stderr, "Erreur d'ouverture du fichier dans saveList()\n");
        return;
    }

    ListNode *n = getFirst(l);
    int indice = 0;
    while (n!=l->current) {
        n = n->next;
        indice++;
    }

    fseek(fichier, 0, SEEK_SET);
    while (n!=NULL) {
        fwrite(&indice, sizeof(int), 1, fichier);
        fwrite(&n->letter ,sizeof(char), 1, fichier);
        indice++;
        n = n->next;
    }
    fclose(fichier);
}


void loadList(List* l, char* fileName)
{
    int idxCurrent;
    char buf;
    ListNode * cur;
    FILE * f;

    /* Open the file for reading */
    f = fopen(fileName, "rb");
    if(f == NULL)
    {
        printf("Error while opening file %s for reading.\n", fileName);
        return;
    }

    /* Read current position in list */
    fread(&idxCurrent, sizeof(int), 1, f);

    /* Initialize list (with an node) */
    initList(l);

    /* Read the content of the list */
    while(fread(&buf,sizeof(char),1,f))
    {
        setCurrentLetter(l, buf);

        /* Check if the new node is the current */
        if(idxCurrent == 0)
        {
            cur = l->current;
        }
        idxCurrent--;

        /* Create the node for the next iteration */
        next(l);
    }

    /* Delete the extra element added to the list during last iteration of
     * while.
     */
    deleteCurrent(l);
    l->current = cur;

    fclose(f);
}

