
/*!
* \file test.c
* \brief Provides basic unit testing functions definitions
*/

#include <stdio.h>
#include <string.h>
#include "test.h"

/*!
* \brief Displays a test whose result has to be checked by the user.
* The test message is displayed in blue.
* \param[in] message the message indicating what it is tested  and what value should be expected
*/
void display_test_check_by_user(char * message)
{
    printf("\033[36m%s\033[0m :\n",message);
}

/*!
* \brief Displays the result of a test returning an int
* The test message is displayed in green is the test has passed, in red otherwise.
* \param[in] message the message indicating what it is tested
* \param[in] expected_value the expected value
* \param[in] obtained_value the tested value
*/
void display_test_int(char * message, int expected_value, int obtained_value)
{
    (expected_value == obtained_value)? fprintf(stdout,"\033[32m%s : %s\033[0m\n",message,"PASSED"):fprintf(stdout,"\033[31m%s : %s\033[0m\n",message,"FAILED");
}


/*!
* \brief Displays the result of a test returning an int
* The test message is displayed in green is the test has passed, in red otherwise.
* \param[in] message the message indicating what it is tested
* \param[in] expected_value the expected value
* \param[in] obtained_value the tested value
*/
void display_test_uint(char * message, unsigned int expected_value, unsigned int obtained_value)
{
    (expected_value == obtained_value)? fprintf(stdout,"\033[32m%s : %s\033[0m\n",message,"PASSED"):fprintf(stdout,"\033[31m%s : %s\033[0m\n",message,"FAILED");
}

/*!
* \brief Displays the result of a test returning a string
* The test message is displayed in green is the test has passed, in red otherwise.
* \param[in] message the message indicating what it is tested
* \param[in] expected_value the expected value
* \param[in] obtained_value the tested value
*/
void display_test_string(char * message, char * expected_value, char * obtained_value)
{
(strcmp(expected_value,obtained_value) == 0 )?
fprintf(stdout,"\033[32m%s : %s\033[0m\n",message,"PASSED"):
fprintf(stdout,"\033[31m%s : %s\033[0m\n",message,"FAILED");
}


/*!
* \brief Displays the result of a test returning an float
* The test message is displayed in green is the test has passed, in red otherwise.
* \param[in] message the message indicating what it is tested
* \param[in] expected_value the expected value
* \param[in] obtained_value the tested value
*/
void display_test_float(char * message, float expected_value, float obtained_value)
{
    (expected_value == obtained_value)? fprintf(stdout,"\033[32m%s : %s\033[0m\n",message,"PASSED"):fprintf(stdout,"\033[31m%s : %s\033[0m\n",message,"FAILED");
}
