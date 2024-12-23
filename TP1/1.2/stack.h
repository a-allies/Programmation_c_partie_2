/*!
 * \file    stack.h
 * \brief   Declarations of structures and assoiated functiosn to handle a stack of int
 *
 */

#ifndef STACK_H_INC
#define STACK_H_INC

#include "application.h"
#include <stdarg.h>

/*!
* Maximal number of values in the stack
*/
#define STACK_MAX_SIZE 50

/*!
* Value of the top index when the stack is empty
*/
#define INIT_TOP -1

typedef enum{NUMBER, BINARY_OPERATOR}Type_element;


typedef struct{
  int top;                  /*!< index of the top value in the stack (initialized to INIT_TOP)  */
  int data[STACK_MAX_SIZE]; /*!< Array with the stack values*/
}Stack;

void init_stack(Stack * s);
void delete_stack(Stack * s);

Boolean isEmpty(Stack * s);
Boolean isFull(Stack * s);

int push(Stack * s, int value);
int pop(Stack * s);

void display_stack(Stack * s);


int test_stack(void);


int fill_stack(Stack *s, int n_element, ...);

#endif
