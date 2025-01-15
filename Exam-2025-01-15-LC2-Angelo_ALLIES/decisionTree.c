/*! \file decisionTree.c
 * \brief  Implementation of the decision tree functionalities
 */
#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#include <float.h>

#include "decisionTree.h"
#include "test.h"

/*! It creates a single node that will be the root of the decision tree. The created root has no scenario choice to begin with.
* \param[in] label: the node label.
* \return the new tree with only its root.
* */
DecisionTree createDecisionTree(const char *label) {
    if (label==NULL) {
        fprintf(stderr, "Label est NULL \n");
        return NULL;
    }

    NodeTree *n = (NodeTree *) calloc(1, sizeof(NodeTree));
    if (n==NULL) {
        fprintf(stderr, "erreur calloc nodeTree\n");
        return NULL;
    }
    strncpy(n->label, label, MAXLABEL-1);
    return n;

}

/*! It tests if the node given as a parameter is a valid leaf. A node is a valid leaf if it is a leaf and that its proba is in [0;1[
* \param[in] node: the node to be tested
* \return 1 if it ia valid leaf, 0 otherwise
* */
int isAValidLeaf(const NodeTree * node) {
    int i = 0;
    if (node==NULL) return 0;
    if (node->proba>=1 || node->proba<0) return 0;
    for (i=0; i<node->nb_possibilities; i++) {
        if (node->possibilities[i]!=NULL) return 0;
    }
    return 1;
}


/*! It tests if the node given as a parameter is a valid scenario. A node is a scenario if all its leaves are valid and that  (sum of the proba of all its leaves) = 1
* \param[in] node: the node to be tested
* \return 1 if it is a valid scenario, 0 otherwise
* */
int isAValidScenario(const NodeTree * node) {
    float somme_proba = 0;
    int i = 0;
    if (node==NULL) return 0;
    for (i=0; i<node->nb_possibilities; i++) {
        //if (node->possibilities[i]==NULL) break;
        if ( !(isAValidLeaf(node->possibilities[i]) ) ) return 0;
        somme_proba+=node->possibilities[i]->proba;
    }
    if (somme_proba!=1) return 0;
    return 1;
}

/*! It computes the mean cost of the scenario given in argument. The scenario must be a valid one. The mean cost of the scenario is equal to the cost of each leave + the cost of the strategy node. For this function, the cost of a leaf is equal to its cost*its proba.
* \param[in] node: the node to be estimated
* \return the estimated cost of the scenario node. If an error occurs, it returns -FLT_MAX
* */
float computeScenarioMeanCost(const NodeTree * node){
    int i = 0;
    float cout = 0;
    if (node==NULL) return -FLT_MAX;
    if (!isAValidScenario(node)) return -FLT_MAX;
    for (i=0; i<node->nb_possibilities; i++) {
        cout += node->possibilities[i]->proba * node->possibilities[i]->cost;
    }
    return cout+node->cost;

}

/*! It computes the best scenario for a decision tree on the mean cost criteria as in function computeScenarioMeanCost. It displays all the costs and at the end the best choice with the maximal cost. If the cost is negative, it displays a message to say that no strategy is found
* \param[in] tree: the tree to be evaluated
* */
void computeTreeMeanCost(const DecisionTree tree) {
    int i = 0;
    float cout_max = 0;
    if (tree==NULL) {
        fprintf(stdout, "tree is NULL\n");
        return;
    }
    for (i=0; i<tree->nb_possibilities; i++) {
        NodeTree *scenario_actuel = tree->possibilities[i];
        if (!isAValidScenario(scenario_actuel)) {
            fprintf(stdout, "Scenarion invalide -> arbre invalide\n");
            return;
        }
        float cout_actuel = computeScenarioMeanCost(scenario_actuel);
        fprintf(stdout, "Scenario %d : %f\n",i, cout_actuel);
        if (cout_actuel>cout_max) cout_max = cout_actuel;
    }
    if (cout_max<0) {
        fprintf(stdout, "No strategy is found\n");
        return;
    }
    fprintf(stdout, "Cout max : %f\n", cout_max);

}



/* Add here the implementation of function computeTreeGenericCost*/

void computeTreeGenericCost(const DecisionTree tree, float (*ptr_fonc_cout)(const NodeTree * node)) {
    int i = 0;
    float cout_max = 0;

    if (tree==NULL) {
        fprintf(stdout, "l'arbre est NULL\n");
        return;
    }
    if (ptr_fonc_cout==NULL) {
        fprintf(stdout, "le pointeur de fonction de calcul de cout est is NULL\n");
        return;
    }

    for (i=0; i<tree->nb_possibilities; i++) {
        NodeTree *scenario_actuel = tree->possibilities[i];
        if (!isAValidScenario(scenario_actuel)) {
            fprintf(stdout, "Scenarion invalide -> arbre invalide\n");
            return;
        }
        float cout_actuel = ptr_fonc_cout(scenario_actuel);
        fprintf(stdout, "Scenario %d : %f\n",i, cout_actuel);
        if (cout_actuel>cout_max) cout_max = cout_actuel;
    }
    if (cout_max<0) {
        fprintf(stdout, "No strategy is found\n");
        return;
    }
    fprintf(stdout, "Cout max : %f\n", cout_max);
}



/*! It frees the memory from the node given as an argument to the leaves.
* \param[in] node: the node and its subnodes to be freed
* */

static void freeNodeTree(NodeTree * node) {
    if (node==NULL) return;
    free(node);
}
void freeTree(NodeTree * n) {
    int i = 0;
    if (n==NULL) return;
    i = n->nb_possibilities;
    for (i=0; i<n->nb_possibilities; i++) {
        if (n->possibilities[i]!=NULL) freeNodeTree(n->possibilities[i]);
    }
    freeNodeTree(n);

}

void freeTree_(NodeTree * n) {
    int i = 0;
    int j = 0;

    if (n==NULL) return;

    for (i=0; i<n->nb_possibilities; i++) {
        NodeTree *scenario_actuel = n->possibilities[i];

        if (scenario_actuel!=NULL) {
            NodeTree *possibilite_actuelle = NULL;
            for (j=0; j<scenario_actuel->nb_possibilities; j++) {
                possibilite_actuelle = scenario_actuel->possibilities[i];
                if (possibilite_actuelle!=NULL) {
                    free(possibilite_actuelle);
                }

                }
        }

        free(n->possibilities[i]);
    }
    free(n);
}


int main_decisionTree() {

    DecisionTree treeQ1 = NULL;
    DecisionTree treeValid = NULL;
    DecisionTree unvalidTreeInfTo1 = NULL;

    //Q1 createDecisionTree

    printf("******** Test Q1\n");
    treeQ1 = createDecisionTree("Which marketing strategy?");
    display_test_int("Test createDecisionTree",0,treeQ1==NULL);
    display_test_int("Test createDecisionTree : label",0,strcmp(treeQ1->label,"Which marketing strategy?"));
    display_test_int("Test createDecisionTree : no scenario",0,treeQ1->nb_possibilities);
    writeDotFileDecisionTree(treeQ1,"treeQ1.dot");



    printf("******** Test Q2\n");
    treeValid = buildValidTree();
    writeDotFileDecisionTree(treeValid,"treeValid.dot");
    display_test_int("Test isAValidLeaf on a valid leaf",1,isAValidLeaf(treeValid->possibilities[0]->possibilities[0]));
    display_test_int("Test isAValidLeaf on a node that is not a leaf",0,isAValidLeaf(treeValid->possibilities[0]));
    unvalidTreeInfTo1 = createDecisionTree_teacher("Which marketing strategy?");
    addScenarioWith2Possibilities(unvalidTreeInfTo1,"GoogleAds",-5000,30000,0.8,15000,-0.2);
    display_test_int("Test isAValidLeaf on an unvalid leaf (proba constraint)",0,isAValidLeaf(unvalidTreeInfTo1->possibilities[0]->possibilities[1]));


    //Q3 isAValidScenario

    printf("******** Test Q3\n");
    display_test_int("Test isAValidScenario on a valid scenario",1,isAValidScenario(treeValid->possibilities[0]));
    display_test_int("Test isAValidScenario on a node that is a leaf",0,isAValidScenario(treeValid->possibilities[0]->possibilities[0]));
    unvalidTreeInfTo1->possibilities[0]->possibilities[1]->proba=0.1;
    display_test_int("Test isAValidScenario on an unvalid scenario because of sum proba !=1" ,0,isAValidScenario(unvalidTreeInfTo1->possibilities[0]));
    writeDotFileDecisionTree(unvalidTreeInfTo1,"treeUnValid.dot");


    //Q4 computeScenarioMeanCost

    printf("******** Test Q4\n");
    display_test_float("Test computeScenarioMeanCost on a valid scenario",22000,computeScenarioMeanCost(treeValid->possibilities[0]));
    display_test_float("Test computeScenarioMeanCost on an unvalid scenario",-FLT_MAX,computeScenarioMeanCost(unvalidTreeInfTo1->possibilities[0]));


    //Q5 computeTreeMeanCost

    printf("******** Test Q5\n");
    printf(" ******* computeTreeMeanCost treeQ1\n");
    computeTreeMeanCost(treeQ1);
    printf(" \n******* computeTreeMeanCost treeValid\n");
    computeTreeMeanCost(treeValid);
    printf(" \n******* computeTreeMeanCost unvalidTreeInfTo1\n");
    computeTreeMeanCost(unvalidTreeInfTo1);


    //Q6 computeTreeGenericCost
    printf("******** Test Q6 avec computeScenarioMeanCost()\n");
    printf(" ******* computeTreeMeanCost treeQ1\n");
    computeTreeGenericCost(treeQ1, computeScenarioMeanCost);
    printf(" \n******* computeTreeMeanCost treeValid\n");
    computeTreeGenericCost(treeValid, computeScenarioMeanCost);
    printf(" \n******* computeTreeMeanCost unvalidTreeInfTo1\n");
    computeTreeGenericCost(unvalidTreeInfTo1, computeScenarioMeanCost);
    fprintf(stdout, "\n");
    printf("******** Test Q6 avec computeScenarioOptimistCost_teacher()\n");
    printf(" ******* computeTreeMeanCost treeQ1\n");
    computeTreeGenericCost(treeQ1, computeScenarioOptimisticCost_teacher);
    printf(" \n******* computeTreeMeanCost treeValid\n");
    computeTreeGenericCost(treeValid, computeScenarioOptimisticCost_teacher);
    printf(" \n******* computeTreeMeanCost unvalidTreeInfTo1\n");
    computeTreeGenericCost(unvalidTreeInfTo1, computeScenarioOptimisticCost_teacher);

    printf("\n******** Test Q7\n");


    //Q7

    freeTree(treeQ1);
    freeTree(treeValid);
    freeTree(unvalidTreeInfTo1);
    fprintf(stdout, "Fin test Q7\n");

   return 0;
}
