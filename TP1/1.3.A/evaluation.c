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
        res = op1 + op2;
        break;
      case SUBSTRACT:
        res = op2 - op1;
        break;
      case MULTIPLY:
	res = op2*op1;
	break;
      case DIVIDE:
	if(op1==0) {
		fprintf(stderr, "erreur division par zéro\n");
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


Boolean add(Stack *s){
  return binary_operator(s, ADD);
}

Boolean substract(Stack *s){
  return binary_operator(s, SUBSTRACT);
}

Boolean multiply(Stack *s) {
  return binary_operator(s, MULTIPLY);
}  

Boolean divide(Stack *s) {
  return binary_operator(s, DIVIDE);
}	

/*!
 * \fn int test_eval(void)
 * Tests evaluation of postfix expressions
 * \return EXIT_SUCCESS if everything is ok
 */
int test_eval(void){

    Stack s;
    init_stack(&s);
    push(&s,1);
    push(&s,2);
    substract(&s);
    display_test_int("Test substract()",-1,pop(&s)); push(&s,-1); /*the push is to put back the popped value for the test*/
    push(&s,3);
    add(&s);
    display_test_int("Test add()",2,pop(&s)); push(&s,2); /*the push is to put back the popped value for the test*/
    push(&s,4);
    push(&s,5);
    add(&s);
    add(&s);

    display_test_check_by_user("Test substract() and add() : (display stack should be 0 11)");
    display_stack(&s);
    /* to be completed when multiply is implemented*/
    push(&s, 0);
    multiply(&s);
    display_test_int("Test multiply()", 0, pop(&s)); push(&s,0); /*the push is to put back the popped value for the test*/
    
    delete_stack(&s);
    init_stack(&s);
    push(&s, 2);
    push(&s, 3);

    multiply(&s);
    display_test_int("Test multiply()", 6, pop(&s)); push(&s,6); /*the push is to put back the popped value for the test*/
    delete_stack(&s);

    /* to be completed when divide is implemented*/
    init_stack(&s);
    push(&s, 1);
    push(&s, 0);
    display_test_check_by_user("Test divide() : (display should be : erreur division par zero)");
    divide(&s);

    push(&s, 6);
    push(&s, 2);
    divide(&s);
    display_test_int("Test divide()", 3, pop(&s)); push(&s,3); /*the push is to put back the popped value for the test*/
     
    delete_stack(&s);

    /* Test the 3 9 3 - 4 * 3 / + expression*/
    init_stack(&s);
    push(&s, 3);
    push(&s, 9);
    push(&s, 3);
    substract(&s);
    push(&s, 4);
    multiply(&s);
    push(&s, 3);
    divide(&s);
    add(&s);
    display_test_int("Test expression infixe de l'énoncé", 11, pop(&s)); push(&s,11); /*the push is to put back the popped value for the test*/
    delete_stack(&s);

    return(EXIT_SUCCESS);
}

