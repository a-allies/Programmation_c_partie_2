/*!
* \file huffman_method.h
* \brief File defining the functions to build a Huffman tree
*/

#ifndef HUFFMAN_METHOD_H
#define HUFFMAN_METHOD_H

#include "binary_tree.h"
#include "list.h"

#include "image-proba.h"

int fillList(list * lp, float pb[NBVALUES]);
nodeTree * buildHuffmanTree(list *lp);

#endif
