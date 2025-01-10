
/*!
* \file graph.h
* \brief File with the definition of the graph
*/

#ifndef GRAPH_H
#define GRAPH_H

#include "graphComponents.h"
#include "vertexList.h"
#include "edgeList.h"

/*!
* \brief the graph type
*/
typedef VertexList Graph;

void initGraph(Graph *g);
void deleteGraph(Graph *g);

void printGraph(Graph *g);
//int writeGraphViz(Graph *g, char * filename);


int addVertexGraph(Graph *g, char val);
Vertex * findVertexGraph(Graph * g, char val);
int deleteVertexGraph(Graph * g, char val);

int addEdgeGraph(Graph *g, char val1, char val2, int d);
Edge * findEdgeGraph(Graph * g, char val1, char val2);
int deleteEdgeGraph(Graph * g, char val1, char val2);

//int shortestPathDijkstra(Graph *g, char val1, char val2);

#endif
