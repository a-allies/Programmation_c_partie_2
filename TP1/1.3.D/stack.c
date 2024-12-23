/*!
 * \file  stack.c
 * \brief Declaration of the functions required to handle a stack of int and int operators
 */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "test.h"


/*!
 * Initialize the stack
 * \param[in] s the stack to be initialized
 */
void init_stack(Stack * s)
{
    s->top = INIT_TOP;
}

/*!
 * Empty the stack
 * \param[in] s the stack to be deleted
 */
void delete_stack(Stack * s)
{
    init_stack(s);
}

/*!
 * Tests if the stack is empty
 * \param[in] s the stack to be tested
 * \return Booelan TRUE if empty, FALSE otherwise
 */
Boolean isEmpty(Stack * s)
{
    return (s->top == INIT_TOP)? TRUE: FALSE;
}

/*!
 * Tests if the stack is full
 * \param[in] s the stack to be tested
 * \return Booelan TRUE if full  FALSE otherwise
 */
Boolean isFull(Stack * s)
{
    return (s->top == STACK_MAX_SIZE -1)? TRUE: FALSE;
}

/*!
 * Add a value at the top of the stack
 * \param[out] s the stack to be modified
 * \param[in] value the value to be added
 * \return int 1 if everything was OK, 0 otherwise
 */
int push(Stack * s, int value)
{
    if((s!=NULL))
    {
        if((isFull(s) == FALSE))
        {
            ++(s->top);
            s->data[s->top] = value;
            return 1;
        }
        fprintf(stderr, "Can not push a value : full stack (overflow)\n");
        return 0;
    }
    fprintf(stderr, "Can not push a value :  stack is null\n");
    return 0;
}

/*!
 * Remove the top value  of the stack
 * \param[out] s the stack to be modified
 * \return int the value to be removed. Returns 0 if an error occurs.
 */
int pop(Stack * s)
{
    if((s!=NULL))
    {
        if((isEmpty(s) == FALSE))
        {
            --(s->top);
            return s->data[s->top +1];
        }
        fprintf(stderr, "Can not pop a value : empty stack\n");
        return 0;
    }
    fprintf(stderr, "Can not pop a value :  stack is null\n");
    return 0;
}

/*!
 * Display the stack content
 * \param[int] s the stack to be printed
 */
void display_stack(Stack * s)
{
  int i;
  printf("***** Stack content:\n");
  for (i=0; i<=s->top; i++)
    printf("\t%3d  %d\n",i,s->data[i]);
}


int fill_stack(Stack *s, int n_element, ...) {
	int i = 0;
	va_list liste_parametres;

	if(s==NULL) return 0;
	if(n_element>=STACK_MAX_SIZE) {
		fprintf(stdout, "Nombre d'éléments à insérer > capacité de la pile -> sortie de la fonction");
		return 0;
	}

	va_start(liste_parametres, n_element);
	
	for(i; i<n_element; i++) {
		s->data[i] =  va_arg(liste_parametres, int);
		s->top = i;
	}

	va_end(liste_parametres);
	return 1;	
}

/*!
 * \fn int test_stack(void)
 * Tests stack functionnalities
 * \return EXIT_SUCCESS if everything is ok
 */
int test_stack(void){

    Stack s;

/*provided*/
    init_stack(&s);
    display_test_int("Test isEmpty() on an empty stack",1,isEmpty(&s));
    display_test_int("Test isFull() on an empty stack",0,isFull(&s));
    display_test_int("Test pop() on an empty stack",0,pop(&s));
    display_test_check_by_user("Test init_stack : (stack should be empty)");
    display_stack(&s);

    push(&s,2);
    display_test_check_by_user("Test push() : (display stack should be 0 2)");
    display_stack(&s);
    display_test_int("Test isEmpty() on a stack after one push",0,isEmpty(&s));
    display_test_int("Test isFull() on a stack after one push",0,isFull(&s));
    display_test_int("Test pop() on a stack after one push",2,pop(&s));

    display_test_int("Test isEmpty() on a stack after one push and one pop",1,isEmpty(&s));
    display_test_int("Test isFull() on a stack after one push and one pop",0,isFull(&s));
    display_test_int("Test pop() on a stack after one push and one pop",0,pop(&s));

    push(&s,1);
    push(&s,2);
    push(&s,3);
    pop(&s);
    push(&s,4);
    display_test_check_by_user("Test push : (display stack should be  0 1 - 1 2 - 2 4)");
    display_stack(&s);

    /* Uncomment when fill_stack is implemented*/
    init_stack(&s);
    fill_stack(&s,0);
    display_test_check_by_user("Test fill_stack (add 0 element): (display stack should be  empty)");
    display_stack(&s);
    display_test_int("Test fill_stack() (add 0 element)",1,isEmpty(&s));
    display_test_int("Test fill_stack() (add 0 element)",0,isFull(&s));
    display_test_int("Test fill_stack (add 0 element)",0,pop(&s));

    fill_stack(&s,4,1,2,3,4);
    display_test_check_by_user("Test fill_stack (add 4 elements): (display stack should be  0 1 - 1 2 - 2 3 - 3 4)");
    display_stack(&s);
    display_test_int("Test fill_stack() (add 4 elements)",0,isEmpty(&s));
    display_test_int("Test fill_stack() (add 4 elements)",0,isFull(&s));
    display_test_int("Test fill_stack (add 4 elements)",4,pop(&s));



  return(EXIT_SUCCESS);
}




