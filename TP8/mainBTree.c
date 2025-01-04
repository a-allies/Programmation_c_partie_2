/*!
* \file main.c
* \brief main program to build a Huffman tree
*/

#include <stdio.h>
#include <stdlib.h>

#include "binary_tree.h"


int main()
{
    //float pb[] ={0.11,0.01,0.09,0.3,0.05,0.15,0.22,0.07};
    //int nb = sizeof(pb)/sizeof (pb[0]);

    nodeTree * root = NULL;

    nodeTree *g1 = newNodeTree(0.1, NULL, NULL);
    nodeTree *d1 = newNodeTree(0.2, NULL, NULL);
    nodeTree *g2 = newNodeTree(0.3, NULL, NULL);
    nodeTree *d2 = newNodeTree(0.4, NULL, NULL);
    nodeTree *g = buildParentNode(g1, d1);
    nodeTree *d = buildParentNode(g2, d2);
    root = buildParentNode(g, d);
    printCodewords(root);
    deleteNodeTree(root);


    return 0;
}
