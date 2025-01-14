/*!
* \file file.h
* \brief To manipulate files and doubly-linked list.
* \author kdesnos
*/

#include "list.h"

#ifndef FILE_H
#define FILE_H

/*!
* \brief Loads a List contained in a binary file. 
*
* This function initializes a list : it fills it with data read from a given
* file and set the current pointer to a given position. 
* Structure of the binary data in the file is presented in saveList() documentation.
*
* It is assumed that the received pointer l points towards a previously allocated
* List.
*
* \param[in,out] l the List which is to be filled with data read from the file.
* \param[in] fileName the path to the file containing the data.
*/
void loadList(List* l, char* fileName);

/*!
* \brief Saves a List into a binary file.
*
* This function creates a file and fills it with data read from a given
* List. 
*
* Binary data in the file is structured as follows:<ul>
* <li>the file starts with an int: corresponding to the index of the current ListNode in the List
* (where 0 corresponds to the first ListNode, 1 to the second one, ...).</li>
* <li>This int value is followed by the char values, starting from the first node to the last one.
*</li></ul>
*
* <b>The List structure must not be modified in any way when calling this
* function, ie the current element should remain the same than before calling saveList.</b>
*
* \param[in] l the List which is to be saved into the file.
* \param[in] fileName the path to the file where the List is saved.
*/
void saveList(List* l, char* fileName);

#endif /* FILE_H*/
