/*!
 * \file  evaluation.c
 * \brief  Definition of functions to process a stack of int as a post-fix expression
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "application.h"
#include "evaluation.h"
#include "stack.h"
#include "test.h"

static Boolean binary_operator(Stack *s, int operation){

  int op1,op2; /*the operands*/
  int res; /*the result*/

  if (isEmpty(s)){
    fprintf(stderr,"Empty stack : can not proceed to the binary operation\n");
    return(FALSE);
  }
  op1=pop(s);

  if (isEmpty(s)){
    fprintf(stderr,"Empty stack : can not proceed to the binary operation\n");
    return(FALSE);
  }
  op2=pop(s);

  /* computation*/
  switch(operation){
      case ADD:
        res = op2 + op1;
        break;
      case SUBSTRACT:
        res = op2 - op1;
        break;
      case MULTIPLY:
        res = op2*op1;
        break;
      case DIVIDE:
        if(op1==0) {
          fprintf(stderr,"Erreur : Division par zéro\n");
          return(FALSE);
        }
        res = op2/op1;
        break;
      default:
        fprintf(stderr,"Unknown operator\n");
        return(FALSE);
  }

  /* Put the result in the stack */
  push(s,res);

  return(TRUE);
}

/*Boolean add(Stack *s){
  return binary_operator(s, ADD);
}

Boolean substract(Stack *s){
  return binary_operator(s, SUBSTRACT);
}

Boolean multiply(Stack *s){
  return binary_operator(s, MULTIPLY);
}

Boolean divide(Stack *s){
  return binary_operator(s, DIVIDE);
}*/


static Boolean binary_operator_pf(Stack *s, int (*op)(int ,int)) {
  int op1,op2 = 0; 
  int res = 0; 

  if (isEmpty(s)){
    fprintf(stderr,"Empty stack : can not proceed to the binary operation\n");
    return(FALSE);
  }
  op1=pop(s);

  if (isEmpty(s)){
    fprintf(stderr,"Empty stack : can not proceed to the binary operation\n");
    return(FALSE);
  }
  op2=pop(s); 

  res = op(op2, op1);
  push(s, res);
  return(TRUE);
}

int add_p(int a, int b){
  return a+b;
}

int substract_p(int a, int b){
  return a-b;
}

int multiply_p(int a, int b){
  return a*b;
}

int divide_p(int a, int b){
  if(b==0) {
    fprintf(stderr,"Erreur : Division par zéro\n");
    return(FALSE);
  }
  return a/b;
}


Boolean add(Stack *s){
  return binary_operator_pf(s, add_p);
}

Boolean substract(Stack *s){
  return binary_operator_pf(s, substract_p);
}

Boolean multiply(Stack *s){
  return binary_operator_pf(s, multiply_p);
}

Boolean divide(Stack *s){
  return binary_operator_pf(s, divide_p);
}

/*!
 * \fn int test_eval(void)
 * Tests evaluation of postfix expressions
 * \return EXIT_SUCCESS if everything is ok
 */
int test_eval(void){

    Stack s;

    push(&s,5);
    push(&s,2);
    multiply(&s);
    display_test_int("essai multiplication", 10, pop(&s));
    delete_stack(&s);

    push(&s,6);
    push(&s,2);
    divide(&s);
    display_test_int("essai division", 3, pop(&s));
    delete_stack(&s);
    
    /*push(&s,6);
    push(&s,0); //essai division par zéro
    divide(&s); 
    */
    push(&s,3);
    push(&s,9);
    push(&s,3);
    substract(&s);
    push(&s,4);
    multiply(&s);
    push(&s,3);
    divide(&s);
    add(&s);
    display_test_int("3 9 3 - 4 * 3 / +" ,11, pop(&s));
   
    return(EXIT_SUCCESS);
}

