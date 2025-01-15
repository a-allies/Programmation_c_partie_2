#include <stdio.h>
#include "decisionTree.h"
#include <unistd.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int c = 0;
    int t= 0;

    opterr = 0;

    while ( (c = getopt(argc, argv, "t") ) !=-1) {
        switch (c) {
            case 't':
                t=1;
            break;

            case '?':
               fprintf (stderr,"Option caractère inconnu \\x%x'.\n",optopt);
            break;
            default:
                abort();
        }
    }


    if (t) {
        main_decisionTree();
        return 0;
    }

    DecisionTree treeValid = NULL;
    treeValid = buildValidTree();
    computeTreeMeanCost(treeValid);
    return 0;
}