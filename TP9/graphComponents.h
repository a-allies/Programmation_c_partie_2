/*!
* \file graphComponents.h
* \brief File with the definition of the vertices and edges
*/
#ifndef GRAPHCOMPONENTS_H
#define GRAPHCOMPONENTS_H

#include <limits.h>

/*!
 * A constant to define infinity to find the smallest path between two vertices of a graph
*/
#define MY_INFINITY INT_MAX

/*!
* \brief the vertex type
*/
typedef struct Vertex Vertex;
/*!
* \brief the edge type
*/
typedef struct Edge Edge;
/*!
* \brief the edges list type
*/
typedef struct EdgeList EdgeList;
/*!
* \brief the vertices list type
*/
typedef struct VertexList VertexList;


/*!
* \brief the edge list structure.
* It describes the successor vertices of a vertex.
*/
struct EdgeList{
    Edge *first;    /*!< the address of the first element in the list*/
    Edge *current;  /*!< the address of the current element in the list*/
    Edge *last;     /*!< the address of the last element in the list*/
};

/*!
* \brief the vertex structure
*/
struct Vertex{
    char label;             /*!< the vertex label*/
    EdgeList connect;       /*!< the successor vertices linked to this vertex*/
    struct Vertex *next_v;  /*!< the address of the next element in the list*/
    int already_visited;    /*!< a flag to indicate whether the vertex has been processed or not in the Dijkstra's algorithm.*/
    int dist_to_origin;     /*!< the distance from the origin vertex in the Dijkstra's algorithm. */
    EdgeList path;          /*!< the path followed to get the minimal distance from the origin vertex in the Dijkstra's algorithm. */
};

/*!
* \brief the vertices list structure
*/
struct VertexList{
    Vertex *first;      /*!< the address of the first element in the list*/
    Vertex *current;    /*!< the address of the current element in the list*/
    Vertex *last;       /*!< the address of the last element in the list*/
};


/*!
* \brief the edge structure
*/
struct Edge{
    Vertex *v;              /*!< the successor vertex*/
    int dist;               /*!< The distance between the two vertices*/
    struct Edge *next_e;    /*!< the address of the next element in the list*/
};



#endif


