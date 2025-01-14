/*!
* \file line.c
* \brief Implementation of functions for manipulating the metro and bus lines.
* \author kdesnos
*/

#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#include "line.h"

#include "line_ref.h"

/**
 * \brief Initialize the Line.
 *v
 * Initialize the line by:
 * - Allocating the needed string an copying the given line name.
 * - Allocating the needed string an copying the given color to it.
 * - Creating a new Station with the given headName (using the createStation() function from line_ref.o).
 * - Setting the line head to this new Station.
 * - Setting the line current station to the head.
 *
 * This function does not allocate memory for the Line structure itself,
 * but only for some of its attributes.
 * Previous attribute values of the Line pointed by the received pointer are ignored.
 *
 * \param[in,out] l the Line to initialize.
 * \param[in] lineName name of the initialized Line.
 * \param[in] color the color code of the Line.
 * \param[in] headName name of the head Station.
 */
void initLine(Line *l, const char *name, const char *color, const char *headName) {
    if (l==NULL) {
        fprintf(stderr, "Line * NULL dans initLine()\n");
        return;
    }

    if (name==NULL || color==NULL || headName==NULL) {
        fprintf(stderr, "Au moins un des 3 arguments char * est NULL dans initLine()\n");
        return;
    }

    int longueur_name = strlen(name)+1;
    l->name = (char *) calloc(longueur_name, sizeof(char));
    if (l->name==NULL) {
        fprintf(stderr, "Erreur calloc pour name dans initLine()\n");
        return;
    }
    strncpy(l->name, name, longueur_name);

    int longueur_color = strlen(color)+1;
    l->color = (char *) calloc(longueur_color, sizeof(char));
    if (l->color==NULL) {
        fprintf(stderr, "Erreur calloc pour color dans initLine()\n");
        free(l->name);
        return;
    }
    strncpy(l->color, color, longueur_color);

    Station *st = createStation(headName);
    if (st==NULL) {
        fprintf(stderr, "Erreur de création de la station dans initLine()\n");
        free(l->name);
        free(l->color);
        return;
    }

    l->head = st;
    l->current = st;
}

/**
 * \brief Move the current Station in the given Direction.
 *
 * See Direction comments for more info.
 *
 * \param[in] l the Line on which we move the current Station.
 * \param[in] dir the Direction to use.
 * \return 1 if the move was successful, -1 otherwise.
 */
int moveCurrent(Line *l, Direction dir) {
    if (l==NULL) {
        fprintf(stderr, "Line * NULL dans moveCurrent()\n");
        return -1;
    }

    if (dir>2 || dir <0) {
        fprintf(stderr, "Direction invalide dans moveCurrent()\n");
        return -1;
    }

    switch (dir) {
        case 0 :
            if (l->current == l->head || l->current->previous==NULL) {
                l->current = NULL;
                return 1;
            }
            l->current = l->current->previous;
            break;
        case 1 :
            if (l->current->next == NULL) {
                l->current = NULL; return 1;
            }
            l->current = l->current->next;
            break;
        case 2 :
            if (l->current == l->head) return 1;
            l->current = l->head;
            break;
    }
    return 1;
}

int outOfLine(Line *l) {
    if (l==NULL) return -1;
    return l->current == NULL;
}

/**
 * \brief Add a new Station at the end of the Line.
 *
 * This function creates and adds a new Station with the given name at
 * the end of the Line, that is, the opposite end to the head.
 *
 * \param[in] l Line to which the Station is added.
 * \param[in] n name of the new Station.
 */
void addStation(Line *l, char *name) {
    if (l==NULL) {
        fprintf(stderr, "Line * NULL dans addStation()\n");
        return ;
    }

    if (name==NULL) {
        fprintf(stderr, "name NULL dans addStation()\n");
        return;
    }

    l->current = l->head;
    while (l->current->next!=NULL) {
        moveCurrent(l, 1);
    }
    l->current->next = createStation(name);

    Station * nouvelleStation = l->current->next;
    if (nouvelleStation==NULL) {
        fprintf(stderr, "Erreur de creation de station dans addStation()\n");
        return;
    }

    nouvelleStation->previous = l->current;
    nouvelleStation->next = NULL;
}

/**
 * \brief Get a Station with the given name.
 *
 * Return the pointer to the Station with the given name on the Line.
 *
 * \param[in] l the Line within which the Station is searched.
 * \param[in] name the name of the searched Station.
 * \return a pointer to the Station if it is found, a NULL pointer otherwise.
 */
Station *getStation(Line *l, char *name) {
    if (l==NULL) {
        fprintf(stderr, "Line * NULL dans getStation()\n");
        return NULL;
    }

    if (name==NULL) {
        fprintf(stderr, "name NULL dans getStation()\n");
        return NULL;
    }

    l->current = l->head;

    l->current = l->head;
    while (!outOfLine(l)) {
        if (strcmp(l->current->name, name)==0 ) return l->current;
        moveCurrent(l, 1);
    }

    return NULL;
}

/**
 * \brief Add a connection to the given Line at the given Station.
 *
 * Add the given Line in the array of connections of the given Station.
 * This function does not add the reciprocal connection in the
 * corresponding Station of Line l.
 *
 * The function does nothing if the given Line is already in the array of
 * connections of the given Station.
 *
 * \param[in,out] s The Station whose array of connections is updated.
 * \param[in] l the Line added to the array of connections.
 * \return the total number of connections of the Station on success,
 *         0 in case the given station was not added to the array,
 *         whatever the cause of failure is.
 */
int addConnection(Station *s, Line *l) {
    int i = 0;

    if (s==NULL) {
        fprintf(stderr, "Station * NULL dans addConneicton()\n");
        return 0;
    }

    if (l==NULL) {
        fprintf(stderr, "Line * NULL dans addConneicton()\n");
        return 0;
    }

    for (i = 0; i<MAX_NB_CONNECTIONS; i++) {
        Line *current = s->connections[i];
        if (current==NULL) {
            s->connections[i] = l;
            return i+1;
        }
        if (current==l) return i+1;
    }
    return 0;

}


/*static int longueur_ligne(Line *l) {
    int longueur = 0;

    if (l==NULL) { return -1;}

    l->current = l->head;
    while (l->current->next!=NULL) {
        longueur++;
        moveCurrent(l, 1);
    }
    return longueur;
}*/
/**
 * \brief Create all connections between the two lines.
 *
 * This method automatically scans the given lines and fills the connections
 * attribute for the Stations appearing in the two Lines, based on their names.
 * Each connection must have its reciprocal.
 *
 * \param[in,out] l0 the first Line whose connections must be updated.
 * \param[in,out] l1 the second Line whose connections must be updated.
 * \return the number of connection pairs created.
 */
int createConnections(Line *l0, Line *l1) {
    int nb_paires = 0;

    if (l0==NULL || l1==NULL) {
        fprintf(stderr, "Au moins une des deux Line * est NULL dans addConneicton()\n");
        return nb_paires;
    }

    l0->current = l0->head;
    while (!outOfLine(l0)) {

        l1->current = l1->head;
        while (!outOfLine(l1)) {
            if (strcmp(l0->current->name, l1->current->name)==0) {
                addConnection(l0->current, l1);
                addConnection(l1->current, l0);
                nb_paires++;
            }
            moveCurrent(l1, 1);
        }

        moveCurrent(l0,1);
    }
    return nb_paires;
}

/**
 * \brief Create all connections between all given lines.
 *
 * This function automatically create all the connections between all lines in
 * the given table.
 *
 * \param[in,out] lines array of pointer to the Lines whose connections are created.
 * \param[in] nbLines number of Lines contained in the lines array.
 * \return the total number of connection pairs created.
 */
int createAllConnections(Line *lines[], int nbLines) {
    int i = 0;
    int j = 0;
    int nb_paires = 0;

    if (lines==NULL || *lines==NULL) {
        fprintf(stderr, "Lines ou *lines est NULL\n");
        return nb_paires;
    }

    if (nbLines<=1) {
        return nb_paires;
    }

    for (i=0; i<nbLines; i++) {
        for (j=i+1; j<nbLines; j++) {
            nb_paires+= createConnections(lines[i], lines[j]);
        }
    }
    return  nb_paires;
}

/**
 * \brief Print a customizable text file from a network of lines.
 *
 * The purpose of this function is to print in a file a textual representation of a network of Line.
 * The function will print content in the following order:
 *
 * 1. Header: header string given as a parameter.
 * 2. Iteratively, for each Line l in lines:
 *   1. Line: Call to printLine() for l.
 *   2. Stations: call to printStation() for each Station of Line l.
 * 3. Footer: footer string given as a parameter.
 *
 * \param[in,out] file Pointer to the file where text will be generated.
 * \param[in] header String to print as a header in the generated file.
 * \param[in] footer String to print as a footer in the generated file.
 * \param[in] printLine Pointer to the function used for printing Line info.
 * \param[in] printStation Pointer to the function used for printing Station info.
 * \param[in] lines Array of pointer to the Lines to print.
 * \param[in] nbLines Number of Lines contained in the lines array.
 */
void genericPrint(FILE* file, const char* header, const char* footer,
                  void (*printLine)(FILE*,Line*), void (*printStation)(FILE*,Line*,Station*),
                  Line *lines[], int nbLines){

    int i = 0;

    fprintf(file, "%s\n", header);

    for (i=0; i<nbLines; i++) {
        printLine(file, lines[i]);
        lines[i]->current = lines[i]->head;
        while (!outOfLine(lines[i])) {
            printStation(file, lines[i], lines[i]->current);
           moveCurrent(lines[i], 1);
        }
    }

    fprintf(file, "%s", footer);

}
