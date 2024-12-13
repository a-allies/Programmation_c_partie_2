#ifndef MYDOUBLETREE_H_INC
#define MYDOUBLETREE_H_INC

typedef struct DNode{
	double value;
	struct DNode *left;
	struct DNode *right;
}DNode;


typedef DNode * DTree;

/*provided*/
void initTree(DTree * t);
void freeTree(DTree t);
int isEmpty(DTree t);
int isLeaf(DTree t);
DTree addDouble(DTree  t, double v);
DTree buildBalancedTreeFromSortedArray(double * a, int n);
void printTree(DTree t);

/*to be done*/
int getHeight(DTree t);
double findMax(DTree t);
int isUnbalancedTree(DTree t);
DTree rightRotation(DTree t);
DTree leftRotation(DTree t);
DTree reBalance(DTree t);

/*optionnal*/
DTree removeNode(DTree t, double value);
DTree buildBalancedTreeFromUnsortedArray(double * a, int n);
double * readArrayFromFile(char *s, int * nb);
DTree readDTreeFromFile(char *s);

#endif

