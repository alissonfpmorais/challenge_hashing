//
// Created by alisson on 08/08/17.
//

#include "hash_helper.h"

int linearIteration(int key, int attempt, int size) {
    return (key + attempt) % size;
}

int quadraticIteration(int key, int attempt, int size) {
    int c1 = 183;
    int c2 = 8192;

    int partial1 = c1 * attempt;
    int partial2 = c2 * (attempt * attempt);

    return (key + partial1 + partial2) % size;
}

int doubleHashing(int key, int attempt, int size) {
    int h1 = linearIteration(key, attempt, size);
    int h2 = quadraticIteration(key, attempt, size);

    return (h1 + (attempt * h2)) % size;
}

int getHashValueForMethod(int method, int key, int attempt, int size) {
    switch(method) {
        case LINEAR:
            return linearIteration(key, attempt, size);

        case QUADRATIC:
            return quadraticIteration(key, attempt, size);

        case DOUBLE_HASHING:
            return doubleHashing(key, attempt, size);

        default:
            return ERROR;
    }
}

int hashInsert(Person* persons, int key, int size, int method) {
    for (int attempt = 0; attempt < size; ++attempt) {
        int pos = getHashValueForMethod(method, key, attempt, size);
        Person person = *(persons + pos);

        if(person.status != USED_CELL) return pos;
    }

    return ERROR;
}

int hashSearch(Person* persons, int key, int size, int method) {
    for(int attempt = 0; attempt < size; ++attempt) {
        int pos = getHashValueForMethod(method, key, attempt, size);
        Person person = *(persons + pos);

        if(person.status == USED_CELL) { if(person.key == key) return pos; }
        else if(person.status == EMPTY_CELL) break;
    }

    return ERROR;
}

int hashRemove(Person* persons, int key, int size, int method) {
    for(int attempt = 0; attempt < size; ++attempt) {
        int pos = getHashValueForMethod(method, key, attempt, size);
        Person person = *(persons + pos);

        if(person.status == USED_CELL) { if(person.key == key) return pos; }
        else if(person.status == EMPTY_CELL) break;
    }

    return ERROR;
}
