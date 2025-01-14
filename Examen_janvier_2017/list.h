/*!
* \file list.h
* \brief File with the definition of the doubly-linked list.
* \author kdesnos
*/

#ifndef LIST_H
#define LIST_H


/*!
* \brief the data element type for the list
*/
typedef struct ListNode
{
    char letter;                    /*!< value for the current node*/
    struct ListNode * previous;     /*!< the address of the previous element (predecessor) in the list*/
    struct ListNode * next;         /*!< the address of the next element (successor) in the list*/
} ListNode;

/*!
* \brief the doubly-linked list type
*/
typedef struct
{
    ListNode * current;     /*!< the address of the current element in the list*/
} List;


/*!
* \brief Allocate and return a new ListNode.
*
* The newly created ListNode must be associated to a default null character
* value: '\0'.
*
* \param[in] p the predecessor of the created ListNode.
* \param[in] n the successor of the created ListNode.
* \return the allocated ListNode
*/
ListNode * newListNode(ListNode * p, ListNode * n);


/*!
* \brief Free the given ListNode.
*
* Free the memory associated to the given ListNode.
*
* \param[in] n The ListNode whose memory is to be deallocated.
*/
void freeListNode(ListNode * n);


/*!
* \brief Initialize a List.
*
* Initialize a List structure by:<br>
* 1. Create a new ListNode (with default value `\0')<br>
* 2. Making the List current pointer points to this new ListNode.<br>
*<br>
* This function does not allocate memory for the List structure itself. It is
* assumed that the received pointer l points towards a previously allocated List.
*
* \param[in,out] l the List to initialize.
*/
void initList(List * l);

/*!
* \brief Move the current pointer forward.
*
* Move the current pointer of the given List forward. 
* If the current ListNode is the last node of the List, a new ListNode with default value '\0' is automatically added before moving the current pointer.
*
* \param[in,out] l the List whose current pointer is to be moved forward.
*/
void next (List * l);

/*!
* \brief Move the current pointer backward.
*
* Move the current pointer of the given List backward. 
* If the current ListNode is the first node of the List, a new ListNode  with default value '\0' is automatically added before moving the current pointer.
*
* \param[in,out] l the List whose current pointer is to be moved backward.
*/
void previous(List *l);

/*!
* \brief Delete the current ListNode of the List if the list has more than one node.
*
* If the list has more than one node, deallocate the memory associated to the current ListNode. 
* After deleting the node, the current pointer is moved to its successor in the list, if any. 
* If there is no successor to the deleted node, the current pointer is moved to the
* predecessor in the list. 
*
* If the current node is the only node in the list, this function does nothing.
*
* \param[in] l the List whose current element is to be deleted if the list has more than one node.
*/
void deleteCurrent(List * l);

/*!
* \brief Set the letter associated to the current ListNode.
*
* Set the letter associated to the current ListNode if there is one. 
* Otherwise, this function does nothing.
*
* \param[in,out] l the List whose current ListNode is updated.
* \param[in] c the letter that will be associated to the current ListNode.
*/
void setCurrentLetter (List * l, char c);

/*!
* \brief Get the letter associated to the current ListNode.
* If no value is found, return '\0'
*
* \param[in] l the List whose current ListNode value is retrieved.
*/
char getCurrentLetter (List * l);

/*!
* \brief Print a representation of the List in the console.
*
* This function prints a representation of the given List in the console.
* Characters associated to the ListNode are to be printed one after the other,
* separated by a space. The current ListNode of the List must be printed
* between square brackets. <br>
* Output example for a list with the current pointer on the third node:<br>
* <code>h e [l] l o</code><br>
* <br>
* <b>The List structure must not be modified in any way when calling this
* function, ie the current element should remain the same than before calling printList.</b>
*
* \param[in,out] l the List to be displayed.
*/
void printList(List * l);

void testList();
ListNode *getFirst(List *l);
#endif /* LIST_H*/
