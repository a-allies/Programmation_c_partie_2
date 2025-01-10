/*!
* \file vertexList.h
* \brief File with the definition of the vertices list
*/

#ifndef VERTEXLIST_H
#define VERTEXLIST_H

#include "graphComponents.h"

void initVertexList(VertexList * g);
void deleteVertexList(VertexList *g);

void printVertexList(VertexList *g);

int emptyVertexList(VertexList *g);
int outOfVertexList(VertexList *g);
void setOnFirstVertex(VertexList *g);
void nextVertex(VertexList *g);
Vertex * getCurrentVertex(VertexList *g);
int firstVertex(VertexList *g);

int addVertex(VertexList *g, char val);
int deleteVertex(VertexList *g, char val);

Vertex * findVertex(VertexList *g, char v);

#endif
