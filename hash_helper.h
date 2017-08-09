//
// Created by alisson on 08/08/17.
//

#ifndef CHALLENGE_HASHING_HASH_HELPER_H
#define CHALLENGE_HASHING_HASH_HELPER_H

#include "person.h"
#include "status.h"

#define LINEAR 1
#define QUADRATIC 2
#define DOUBLE_HASHING 3

int hashInsert(Person* persons, int key, int size, int method);
int hashSearch(Person* persons, int key, int size, int method);
int hashRemove(Person* persons, int key, int size, int method);

#endif //CHALLENGE_HASHING_HASH_HELPER_H
