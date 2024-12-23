
/*!
* \file test.h
* \brief Provides basic unit testing functions declaration
*/

#ifndef TEST_H_INC
#define TEST_H_INC


void display_test_check_by_user(char * message);

void display_test_int(char * message, int expected_value, int obtained_value);
void display_test_uint(char * message, unsigned int expected_value, unsigned int obtained_value);

void display_test_string(char * message, char * expected_value, char * obtained_value);


void display_test_float(char * message, float expected_value, float obtained_value);


#endif
