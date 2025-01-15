#include <stdio.h>
#include <stdlib.h>

#include "decisionTree.h"

// to be modified in Q8
int main(void) {

    main_decisionTree();

    DecisionTree treeValid = buildValidTree();

   freeTree_teacher(treeValid);
    return 0;
}