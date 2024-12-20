/*!
* \file binary_tree.h
* \brief File defining the binary Huffman tree structure as studied in Huffman coding practical work
*/

#ifndef BINARY_TREE_HH
#define  BINARY_TREE_HH

/*! \def CODESIZEMAX
* \brief The maximal codeword length
*/
#define CODESIZEMAX 100

/*!
* \brief Data element of a binary tree associated to a probability.
* If the left and right children are not null, its probability shall be equal to the sum of its children's probabilies.
*/
typedef struct nodeTree{
    float proba;                /*!< A pointer to a tree*/
    struct nodeTree * left;     /*!< A pointer to the left child, associated to the 0 bit*/
    struct nodeTree * right;    /*!< A pointer to the right child, associated to the 1 bit*/
}nodeTree;

/*!
*A tree is the top node
*/
typedef nodeTree * binary_tree;


nodeTree * newNodeTree(float p, nodeTree * l, nodeTree * r);
void deleteNodeTree(nodeTree * n);
nodeTree * buildParentNode(nodeTree *l, nodeTree *r);

void printCodewords(binary_tree t);

#endif
