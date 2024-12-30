
#include "myDoubleTree.h"
#include <float.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/*!
* \brief Allocate memory for the node element and initialize the structure members
* \param[in] v the double for the value member
* \param[in] l the address of the left child
* \param[in] r the address of the right child
* \return DNode* the address of the new tree element
*/
DNode * initNode(double v, DNode * l, DNode * r)
{
    DNode * new = (DNode*) malloc(sizeof(DNode));
    if(new == NULL)
        return NULL;
    new->value = v;
    new->left = l;
    new->right = r;
    return new;
}

/*!
* \brief Desallocate memory associated to a node
* \param[in] n the address of the  data element to be freed
*/
static void freeNode(DNode * n)
{
    free((void*) n);
}


/*!
* \brief Suppress all elements from a tree
* \param[in] t the tree to be emptied
*/
void freeTree(DTree t)
{
    if(t!=NULL)
    {
        if(t->right != NULL)
            freeTree(t->right);

        if(t->left != NULL)
            freeTree(t->left);

        freeNode(t);
    }
}


/*!
* \brief Initialize an empty tree
* \param[out] t the tree to be initialized
*/
void initTree(DTree * t)
{
    *t = NULL;
}


/*!
* \brief Tests if it is an empty tree
* \param[in] t the tree to be tested
* \return int 1 if empty, 0 otherwise
*/
int isEmpty(DTree t)
{
    return t == NULL;
}

/*!
* \brief Tests if it is a leaf
* \param[in] t the tree to be tested
* \return int 1 if it is a leaf, 0 otherwise
*/
int isLeaf(DTree t)
{
    return t->left == NULL && t->right == NULL ;
}

/*!
* \brief Insert a new element containing the double value given as a parameter to get a sorted tree
* \param[in,out] t the tree
* \param[in] v the value to be inserted
* \return int 1 if everything was OK, 0 otherwise
*/
DTree addDouble(DTree  t, double v)
{
    if(isEmpty(t))
        t = initNode(v,NULL,NULL);
    else
    {
        double current_val = t->value;
        if(current_val == v)
            return t; /*already in the tree*/
        else
            if(current_val > v)
                t->left = addDouble(t->left,v);
            else
                t->right = addDouble(t->right,v);
    }
    return t;
}

/*!
* \brief Build a sorted tree from a sorted array
* \param[in] a the array of sorted values
* \param[in] n the number of values in the array
* \return DTree the new tree
*/
DTree buildBalancedTreeFromSortedArray(double * a, int n)
{
    if(n!=0)
        return initNode(a[n/2],buildBalancedTreeFromSortedArray(a,n/2),buildBalancedTreeFromSortedArray(a + n/2 + 1,(n-1)/2));
    return NULL;
}



/*!
* \brief Print the content of the current node of the tree
* \param[in] t the node to be displayed
* \param[in] depth its depth in the tree
*/
static void printTreeRec(DTree t, int depth)
{
	if(!isEmpty(t))
	{
        int i;
        printTreeRec(t->left,depth+1);
        for(i = 0; i< depth ; i++)
            printf("\t");
        printf("%f\n",t->value);
        printTreeRec(t->right,depth+1);
	}
}

/*!
* \brief Print the content of the tree
* \param[in] t the tree to be displayed
*/
void printTree(DTree t)
{
	if(!isEmpty(t))
	{
        printf("--------- Printing tree : --------- \n");
        printTreeRec(t,0);
        printf("--------- End of printing tree --------- \n\n");
	}
	else
        printf("This tree is empty \n");
}

int getHeight(DTree t) {
    int res = 0;
    if (isEmpty(t)) return res;

    res = getHeight(t->left)> getHeight(t->right) ? getHeight(t->left) : getHeight(t->right);
    return 1+res;

}

double findMax(DTree t) {
	if(isEmpty(t)) return -1;
	
	if(isEmpty(t->right)==0) findMax(t->right);
	return t->value;
}

double findMax_v2(DTree t) {
    double max_entre_gauche_et_droit = 0;
    if (isEmpty(t)) return -1;

    max_entre_gauche_et_droit = findMax(t->left)>findMax(t->right) ? findMax(t->left) : findMax(t->right);
    return t->value > max_entre_gauche_et_droit ? t->value : max_entre_gauche_et_droit ;
}

int isUnbalancedTree(DTree t) {
    int delta = 0;
    if(isEmpty(t)) return 0;

    delta = getHeight(t->left)-getHeight(t->right);
    if(delta>1 || delta<-1) return 1;
    return isUnbalancedTree(t->left) || isUnbalancedTree(t->right);
}

DTree rightRotation(DTree t) {
    if (isEmpty(t) || isEmpty(t->left)) return t;

    DTree res = t->left;  
    t->left = res->right; 
    res->right = t;
    return res;
}


DTree leftRotation(DTree t) {
    if (isEmpty(t) || isEmpty(t->right)) return t;

    DTree res = t->right;  
    t->right = res->left; 
    res->left = t;
    return res;
}

DTree reBalance(DTree t) {
    int delta = 0;

    if(isEmpty(t)) return t;

    t->left = reBalance(t->left);
    t->right = reBalance(t->right);

    delta = getHeight(t->left)-getHeight(t->right);
    
    if(delta>1) return rightRotation(t);
    if(delta<-1) return leftRotation(t);
    return t;
}

DTree removeNode(DTree t, double value) {
    double valeur_max_arbre_gauche = 0;
    if (isEmpty(t)) return t;

    if(t->value>value) {
        t->left = removeNode(t->left, value);
        return t;
    }    
    if(t->value<value) {
        t->right = removeNode(t->right, value);
        return t;
    }    

    if(isleaf(t)) {
        freeNode(t);
        return NULL;
    }

    if (isEmpty(t->left)) {
        DNode *n = t->right;
        freeNode(t);
        return n;
    }

    if (isEmpty(t->right)) {
        DNode *n = t->left;
        freeNode(t);
        return n;
    }

    valeur_max_arbre_gauche = findMax(t->left);
    t->left = removeNode(t->left, valeur_max_arbre_gauche);
    t->value = valeur_max_arbre_gauche;
    return t;
}
