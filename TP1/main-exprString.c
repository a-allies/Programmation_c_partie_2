/*!
 * \file    main-exprString.c
 * \brief   main program to evaluation postfix expressions given as a string
 *
 * \author ...
 * \date ...
 */

#include <stdio.h>
#include <stdlib.h>
#include "application.h"
#include "stack.h"
#include "evaluation.h"


/*!
 * \fn int main(void)
 * \return EXIT_SUCCESS if everything is ok
 */
int main(void){
    test_evalString();
    return EXIT_SUCCESS;
}
