#include "dijkstra.h"
#include <stdio.h>

static  Vertex * renvoyer_sommet(Graph *g, char label) {
    Vertex * sommet = NULL;

    setOnFirstVertex(g);
    while (!outOfVertexList(g)) {
        if (g->current->label == label) {
            sommet = g->current;
            break;
        }
        nextVertex(g);
    }
    return sommet;
}

static int initialisation_dijkstra(Graph *g, Vertex *origine) {
    if (g->first==NULL || g->last==NULL) {
        fprintf(stderr, "liste des sommets du graphe nulle dans initialisation_dijkstra()\n");
        return 0;
    }

    Vertex *sommet = NULL;
    setOnFirstVertex(g);
    while (!outOfVertexList(g)) {
        sommet = g->current;
        sommet->already_visited = 0;
        sommet->dist_to_origin = MY_INFINITY;

        nextVertex(g);
    }

    origine->dist_to_origin = 0;
    return 1;
}

static Vertex * sommet_proche_origine(Graph *g) {
    int distance = MY_INFINITY;
    Vertex *voisin_origine = NULL;

    Vertex *sommet = NULL;
    setOnFirstVertex(g);
    while (!outOfVertexList(g)) {
        sommet = g->current;
        if (sommet->dist_to_origin<distance && !(sommet->already_visited)) {
            distance = sommet->dist_to_origin;
            voisin_origine = sommet;
        }
        nextVertex(g);
    }

    return voisin_origine;
}

static void actualisation_distance(Vertex *sommet) {
    EdgeList *liste_arcs = &(sommet->connect);

    Vertex *sommet_voisin = NULL;
    setOnFirstEdge(liste_arcs);
    while (!outOfEdgeList(liste_arcs)) {
        sommet_voisin = liste_arcs->current->v;
        if ( (sommet_voisin->dist_to_origin > sommet->dist_to_origin+liste_arcs->current->dist) && !(sommet_voisin->already_visited)) {
            sommet_voisin->dist_to_origin = sommet->dist_to_origin+liste_arcs->current->dist;
            deleteEdgeList( &(sommet_voisin->path) );
            copyEdgeList( &(sommet_voisin->path), &(sommet->path) );
            addEdge( &(sommet_voisin->path), sommet_voisin, liste_arcs->current->dist);
        }
        nextEdge(liste_arcs);
    }
}

int shortestPathDijkstra(Graph *g, char val1, char val2) {
    if (g==NULL) {
        fprintf(stderr, "Le graphe est NULL dans shortestPathDijkstra()\n");
        return -1;
    }

    if (val1=='\0' || val2 =='\0') {
        fprintf(stdout, "un des deux sommets est NULL dans shortestPathDijkstra()\n");
        return -1;
    }

    if (val1==val2) {
        return 0;
    }

    Vertex *origine = renvoyer_sommet(g, val1);
    Vertex *cible = renvoyer_sommet(g, val2);
    if (origine==NULL || cible==NULL) {
        fprintf(stderr, "%c ou %c est nul -> arrêt alogirhtme\n", val1, val2);
        return -1;
    }

    int statut_initialisation = initialisation_dijkstra(g, origine);
    if (statut_initialisation==0) {
        fprintf(stderr, "Erreur lors de l'étape d'initialisation\n");
        return -1;
    }

    Vertex *sommet_actuel = NULL;
    do {
        sommet_actuel = sommet_proche_origine(g);
        if (sommet_actuel==NULL) {
            break;
        }
        sommet_actuel->already_visited = 1;
        actualisation_distance(sommet_actuel);
    } while (sommet_actuel!=NULL);

    return cible->dist_to_origin;
}
