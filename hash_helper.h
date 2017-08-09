//
// Created by alisson on 08/08/17.
//

#ifndef CHALLENGE_HASHING_HASH_HELPER_H
#define CHALLENGE_HASHING_HASH_HELPER_H

#include "person.h"
#include "status.h"

// Methods of hashing
#define LINEAR 1
#define QUADRATIC 2
#define DOUBLE_HASHING 3

// Get an available position to insert person
int hashInsert(Person* persons, int key, int size, int method);

// Get position of searched person
int hashSearch(Person* persons, int key, int size, int method);

// Get position to remove desired person
int hashRemove(Person* persons, int key, int size, int method);

#endif //CHALLENGE_HASHING_HASH_HELPER_H
