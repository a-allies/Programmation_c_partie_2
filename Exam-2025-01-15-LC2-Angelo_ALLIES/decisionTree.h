/*! \file decisionTree.h
* \brief  Declaration of the decision tree type and functionalities
 */

#ifndef DECISIONTREE_H
#define DECISIONTREE_H

/*! Maximum label size */
#define MAXLABEL 100

/*!  Maximum number of choices/possibilities*/
#define MAXPOSSIBILITIES 5

/*!  The structure of a Node of the decision tree */
typedef struct NodeTree {
    char label[MAXLABEL];   /*!< The label of this node */
    int cost;              /*!< Its cost */
    float proba;             /*!< Its probability to happen */
    struct NodeTree * possibilities[MAXPOSSIBILITIES];  /*!< An array of pointers to each possibility */
    int nb_possibilities;  /*!< The actual number of possibilities in the array*/
}NodeTree;


/*!  A Tree is a pointer to a NodeTree */
typedef NodeTree * DecisionTree;


//functions to be coded during the exam
DecisionTree createDecisionTree(const char *label);

void freeTree(NodeTree * n);

int isAValidLeaf(const NodeTree * node);
int isAValidScenario(const NodeTree * node);

void computeTreeMeanCost(const DecisionTree tree);

/* Add here the prototype of function computeTreeGenericCost*/

//function with the tests. To be completed
int main_decisionTree();

//provided in decisionTree_teacher.o : do not code them
int addScenarioWith2Possibilities(DecisionTree t, const char *scenarioLabel, int scenarioCost, int cost1, float proba1, int cost2, float proba2);
int addScenarioWithNPossibilities(DecisionTree t, const char *scenarioLabel, int scenarioCost, int nb_possibilities,...);
DecisionTree buildValidTree();
void freeTree_teacher(NodeTree * n);
int writeDotFileDecisionTree(const DecisionTree tree, const char *filename);
int main_decisionTree_teacher();
float computeScenarioMeanCost_teacher(const NodeTree * node);
float computeScenarioOptimisticCost_teacher(const NodeTree * node);
DecisionTree createDecisionTree_teacher(const char *label);
int isAValidLeaf_teacher(const NodeTree * node);
int isAValidScenario_teacher(const NodeTree * node);
void computeTreeMeanCost_teacher(const DecisionTree tree);
void computeTreeGenericCost(const DecisionTree tree, float (*ptr_fonc_cout)(const NodeTree * node));

#endif //DECISIONTREE_H
