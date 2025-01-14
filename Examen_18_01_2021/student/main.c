/*!
* \file main.c
* \brief Test program for the exam.
* \author kdesnos
*/

#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "line.h"
#include "line_ref.h"

/// Declaration only, implementation of the function at the end of the file.
void testGenericPrint();

int main(void){

    //testGenericPrint();
    Line lc;
    initLine(&lc, "C3", "green", "CDG");
    addStation(&lc, "Republique");
    addStation(&lc, "Parlement");
    printLine(&lc);

    Station *s = getStation(&lc, "CDG");
    fprintf(stdout, "%s\n", s->name);
    lc.current = lc.head;
    fprintf(stdout, "current : %s\n", lc.current->name);
    moveCurrent(&lc, 1);
    fprintf(stdout, "current : %s\n", lc.current->name);
    moveCurrent(&lc, 0);
    fprintf(stdout, "current : %s\n", lc.current->name);

    return 0;
}

void testGenericPrint(){
    Line la;
    initLine_ref(&la, "C4", "red", "Republique");
    addStation_ref(&la, "BeauxArts");
    addStation_ref(&la, "Strasbourg");
    addStation_ref(&la, "Baud");
    addStation_ref(&la, "INSA");
    addStation_ref(&la, "IUT");
    
    printLine(&la);

    Line lb;
    initLine_ref(&lb, "40", "blue", "Gare");
    addStation_ref(&lb, "BeauxArts");
    addStation_ref(&lb, "Baud");
    addStation_ref(&lb, "INSA");
    addStation_ref(&lb, "ChampBlanc");
    
    printLine(&lb);

    Line lc;
    initLine_ref(&lc, "C3", "green", "CDG");
    addStation_ref(&lc, "Republique");
    addStation_ref(&lc, "Parlement");
    
    printLine(&lc);

    Line * lines[] = {&la, &lb, &lc};

    int nbConnections = createAllConnections_ref(lines, 3);
    
    printf("Nb connections created: %d\n", nbConnections);

    int nbConnections2 = createAllConnections(lines, 3);

    printf("Nb connections created moi : %d\n", nbConnections2);

    fprintf(stdout, "\n \n \n \n ");
    genericPrint_ref(stdout, NULL, NULL, printLineConsole, printStationConsole, lines, 3);
    fprintf(stdout, "\n \n \n \n ");

    FILE *fichier = fopen("result_ref.dot", "w");
    if (fichier==NULL) {
        fprintf(stderr, "erreur ouverture du fichier result.dot en écriture\n");
    }
    genericPrint_ref(fichier, dotHeader, dotFooter, printLineDot, printStationDot, lines, 3);
    fclose(fichier);

    FILE *fichier2 = fopen("result.dot", "w");
    if (fichier2==NULL) {
        fprintf(stderr, "erreur ouverture du fichier2 result.dot en écriture\n");
    }
    genericPrint(fichier2, dotHeader, dotFooter, printLineDot, printStationDot, lines, 3);
    fclose(fichier2);
}
