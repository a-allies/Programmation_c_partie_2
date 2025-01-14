/*!
* \file crypto.h
* \brief File containing encryption and decryption related functions.
* \author kdesnos
*/

#ifndef CRYPTO_H
#define CRYPTO_H

#include "list.h"

/*!
* \brief Pseudo-random number generator.
*
* Given a key and a seed, this generator will generate a pseudo-random number.
* The generated number should be used as the next seed when calling the pseudo-
* random number generator in an iterative loop.
*
* \param[in] key Parameter specifying how the pseudo-random number generator
*            should work.
* \param[in] seed Value used to compute the next.
* \return a pseudo random char value.
*/
char pseudoRandomNumber(unsigned char key, char seed );

/*!
* \brief Decrypt a message.
*
* This function decrypts a message from a List using the key and seed passed as
* parameters. The decrypted message is displayed in the console.
*
* \param[in] key Parameter specifying how the pseudo-random number generator
*            should work.
* \param[in] seed Value used to compute the next.
* \param[in,out] l The List in which the encrypted message is stored.
*/
void decrypt(unsigned char key, char seed, List *l);

#endif 
