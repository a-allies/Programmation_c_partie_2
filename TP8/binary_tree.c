
/*!
* \file binary_tree.c
* \brief File implementing the binary Huffman tree structure as studied in Huffman coding practical work
*/

#include <stdlib.h>
#include <stdio.h>
#include "binary_tree.h"



static void printCode(char cod[CODESIZEMAX], int size_code, float pb)
{
   int i;
   printf("le code dont la proba. est  %5.3f est: ",pb);
   for (i=0;i<size_code;i++) 
   	printf(" %c", cod[i]);
   printf("\n");
}

nodeTree * newNodeTree(float p, nodeTree * l, nodeTree * r) {
    nodeTree *res = (nodeTree *) calloc(1, sizeof(nodeTree));
    if (res==NULL) {
        fprintf(stderr, "Erreur allocation mémoire du nodeTree dans newNodeTree()`\n");
        return res;
    }

    res->proba = p;
    res->left = l;
    res->right = r;
    return res;
}

void deleteNodeTree(nodeTree * n) {
    if (n==NULL) return;

    deleteNodeTree(n->left);
    deleteNodeTree(n->right);

    n->proba = 0;
    free(n);
}

nodeTree * buildParentNode(nodeTree *l, nodeTree *r) {
    if (l==NULL || r==NULL) return NULL;

    return newNodeTree(l->proba+r->proba, l, r);
}

static int isLeaf(nodeTree *n) {
    if (n==NULL) return 0;
    return n->left==NULL && n->right==NULL;
}

static void printCodeWordsAide(binary_tree t, int longueur_code, char code[CODESIZEMAX]) {
    if(t==NULL) return;

    if(isLeaf(t)) { 
        code[longueur_code] = '\0';
        printCode(code, longueur_code, t->proba); 
    }

    code[longueur_code] = '0';
    longueur_code++;
    printCodeWordsAide(t->left, longueur_code, code);
    longueur_code--;

    code[longueur_code] = '1';
    longueur_code++;
    printCodeWordsAide(t->right, longueur_code, code);
    longueur_code--;


}

void printCodewords(binary_tree t) {
    if(t==NULL) return;
    int longueur_code = 0;
    char code[CODESIZEMAX];
    printCodeWordsAide(t, longueur_code, code);
}

//version itérative

void printCodewords_(binary_tree t) {

    typedef struct {
        char code[CODESIZEMAX+1];
        int longueur_code;
        nodeTree noeud;
    } Tuple;

    Tuple pile[CODESIZEMAX];
    int sommet_pile = -1;

    if(t==NULL) return;

    sommet_pile++;
    Tuple tuple_initial =  {"", 0, *t};
    pile[sommet_pile] = tuple_initial;

    while(sommet_pile>=0) {
        Tuple tuple_actuel = pile[sommet_pile];
        sommet_pile--;
        char *code_actuel = tuple_actuel.code;
        int longueur_code_actuelle = tuple_actuel.longueur_code;
        nodeTree noeud_actuel = tuple_actuel.noeud;

        if(isLeaf(&noeud_actuel)) {
            printCode(code_actuel, longueur_code_actuelle, noeud_actuel.proba);
            continue;
        }

        if (noeud_actuel.left!=NULL) {
            int i =0;
            nodeTree noeud_gauche = *(noeud_actuel.left);
            int longueur_code_gauche = longueur_code_actuelle+1<=CODESIZEMAX ? longueur_code_actuelle+1 : CODESIZEMAX;
            Tuple tuple_gauche = {"", longueur_code_gauche, noeud_gauche };

            for (i=0; i<longueur_code_gauche; i++) tuple_gauche.code[i] = code_actuel[i];
            tuple_gauche.code[longueur_code_gauche-1] = '0';
            tuple_gauche.code[longueur_code_gauche] = '\0';

            sommet_pile++;
            pile[sommet_pile] = tuple_gauche;
        }

        if (noeud_actuel.right!=NULL) {
            int j =0;
            nodeTree noeud_droit = *(noeud_actuel.right);
            int longueur_code_droit = longueur_code_actuelle+1<=CODESIZEMAX ? longueur_code_actuelle+1 : CODESIZEMAX;
            Tuple tuple_droite = {"", longueur_code_droit, noeud_droit };

            for (j=0; j<longueur_code_droit; j++) tuple_droite.code[j] = code_actuel[j];
            tuple_droite.code[longueur_code_droit-1] = '1';
            tuple_droite.code[longueur_code_droit] = '\0';

            sommet_pile++;
            pile[sommet_pile] = tuple_droite;
        }

    }
}
