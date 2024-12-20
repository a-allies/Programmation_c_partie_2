/*!
* \file main-Huffman.c
* \brief main program to read data from file and build the corresponding Huffman coding
*/

#include <stdio.h>
#include <stdlib.h>

#include "binary_tree.h"
#include "list.h"
#include "huffman_method.h"

int main()
{
    char filename[FILENAME_MAX];
    char filename_checked[FILENAME_MAX];
    float pb[NBVALUES] ={0.11,0.01,0.09,0.3,0.05,0.15,0.22,0.07};
    int i;
    list lp;
    nodeTree * root;

    /* Read probabilities from image file */
    printf("Name of the file : ");
    fgets(filename,FILENAME_MAX-1,stdin);
    sscanf(filename,"%[a-zA-Z0-9.-_ ]%*[^\n\r]",filename_checked);
    readProbaFromFile(filename_checked,pb);
    printf("Probabilities :\n");
    for(i=0 ; i<NBVALUES ; i++)
    {
        printf("proba[%1d]= %5.3f\n",i,pb[i]);
    }

    /* Create initial list with the leaves of the Huffman tree*/
    initList(&lp);
    fillList(&lp,pb);
    printList(&lp);

    /* build Huffman Tree */
    root=buildHuffmanTree(&lp);

    /* Travel in the tree to print the codewords for each probability */
    printCodewords(root);

    /*free memory*/
    deleteList(&lp);

    return 0;
}
