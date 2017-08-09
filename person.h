//
// Created by alisson on 08/08/17.
//

#ifndef CHALLENGE_HASHING_PERSON_H
#define CHALLENGE_HASHING_PERSON_H

#include "status.h"

typedef struct {
    char name[30];
    int age;
    int key;
    int status; // 0 -> EMPTY_CELL, 1 -> USED_CELL, 2 -> REMOVED_CELL
} Person;

void printPerson(Person* person);
void removePersonFromDB(Person* persons, int pos);
void getPersonFromDB(Person* persons, int pos);
void addPersonToDB(Person *persons, Person *person, int pos);
void listAllPersons(Person* persons, int size);
void removePerson(Person* persons, int size, int method);
void searchPerson(Person* persons, int size, int method);
void addPerson(Person* persons, int size, int method);

#endif //CHALLENGE_HASHING_PERSON_H
