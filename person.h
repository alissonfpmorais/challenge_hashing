//
// Created by alisson on 08/08/17.
//

#ifndef CHALLENGE_HASHING_PERSON_H
#define CHALLENGE_HASHING_PERSON_H

#include "status.h"

// Person structure
typedef struct {
    char name[30];
    int age;
    int key;
    int status; // 0 -> EMPTY_CELL, 1 -> USED_CELL, 2 -> REMOVED_CELL
} Person;

// Print person struct
void printPerson(Person* person);

// Remove person from DB (using array as database for while)
void removePersonFromDB(Person* persons, int pos);

// Get specific person from DB (using array as database for while)
void getPersonFromDB(Person* persons, int pos);

// Add person from DB (using array as database for while)
void addPersonToDB(Person* persons, Person* person, int pos);

// List all persons in DB (using array as database for while)
void listAllPersons(Person* persons, int size);

// Execute all necessary steps related to remove a person
void removePerson(Person* persons, int size, int method);

// Execute all necessary steps related to search a person
void searchPerson(Person* persons, int size, int method);

// Execute all necessary steps related to insert a person
void addPerson(Person* persons, int size, int method);

#endif //CHALLENGE_HASHING_PERSON_H
