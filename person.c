//
// Created by alisson on 08/08/17.
//

#include <stdio.h>
#include <stdlib.h>
#include "person.h"
#include "hash_helper.h"

Person* getPersonInfo() {
    Person* person = (Person*) malloc(sizeof(Person));

    printf("Digite o nome: ");
    scanf("%s", person->name);
    printf("Digite a idade: ");
    scanf("%d", &person->age);
    printf("Digite a chave: ");
    scanf("%d", &person->key);
    person->status = USED_CELL;

    return person;
}

int askKey() {
    int key;

    printf("Digite a chave: ");
    scanf("%d", &key);

    return key;
}

void printPerson(Person* person) {
    printf("Nome: %s", person->name);
    printf("\n");
    printf("Idade: %d", person->age);
    printf("\n");
    printf("Chave: %d", person->key);
    printf("\n");

    if(person->status == EMPTY_CELL) printf("Status: Não utilizada");
    else if(person->status == USED_CELL) printf("Status: Em uso");
    else if(person->status == REMOVED_CELL) printf("Status: Removida");

    printf("\n");
    printf("--------------------------------");
    printf("\n");
}

void removePersonFromDB(Person* persons, int pos) {
    Person* person = persons + pos;
    person->status = REMOVED_CELL;
}

void getPersonFromDB(Person* persons, int pos) {
    Person* person = persons + pos;
    printPerson(person);
}

void addPersonToDB(Person *persons, Person *person, int pos) {
    Person* location = persons + pos;
    *location = *person;
}

void listAllPersons(Person* persons, int size) {
    for(int i = 0; i < size; i++) {
        Person* person = persons + i;
        printPerson(person);
    }

    printf("\n\n");
}

void removePerson(Person* persons, int size, int method) {
    printf("\n");

    int key = askKey();
    int pos = hashRemove(persons, key, size, method);

    if(pos != ERROR) removePersonFromDB(persons, pos);
    else printf("Não foi possível remover!\n");

    printf("\n\n");
}

void searchPerson(Person* persons, int size, int method) {
    printf("\n");

    int key = askKey();
    int pos = hashSearch(persons, key, size, method);

    if(pos != ERROR) getPersonFromDB(persons, pos);
    else printf("Não foi possível encontrar!\n");

    printf("\n\n");
}

void addPerson(Person* persons, int size, int method) {
    printf("\n");

    Person* person = getPersonInfo();
    int pos = hashInsert(persons, person->key, size, method);

    if(pos != ERROR) addPersonToDB(persons, person, pos);
    else printf("Não foi possível adicionar!\n");

    printf("\n\n");
}