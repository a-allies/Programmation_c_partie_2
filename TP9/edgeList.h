/*!
* \file edgeList.h
* \brief File with the definition of the successors list
*/

#ifndef EDGELIST_H
#define EDGELIST_H

#include "graphComponents.h"


void initEdgeList(EdgeList * c);
void deleteEdgeList(EdgeList *c);

void printEdgeList(EdgeList *c);

int emptyEdgeList(EdgeList *c);
int outOfEdgeList(EdgeList *c);
void setOnFirstEdge(EdgeList *c);
void nextEdge(EdgeList *c);
Edge * getCurrentEdge(EdgeList *c);

int addEdge(EdgeList *c, Vertex *v, int d);
int copyEdgeList(EdgeList * dest, EdgeList *src);

Edge * findEdge(EdgeList *c, Vertex * v);
int deleteEdge(EdgeList *c, Vertex * v);

#endif
