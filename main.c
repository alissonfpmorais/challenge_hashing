#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define ERROR (-1)
#define EMPTY_CELL 0
#define USED_CELL 1
#define REMOVED_CELL 2

typedef struct {
    char name[30];
    int age;
    int key;
    int status; // 0 -> EMPTY_CELL, 1 -> USED_CELL, 2 -> REMOVED_CELL
} Person;

int calcHash(int key, int attempt, int size) {
    return (key + attempt) % size;
}

int hashInsert(Person *persons, int key, int size) {
    for (int attempt = 0; attempt < size; ++attempt) {
        int pos = calcHash(key, attempt, size);
        Person person = *(persons + pos);

        if(person.status != USED_CELL) return pos;
    }

    return ERROR;
}

int hashSearch(Person* persons, int key, int size) {
    for(int attempt = 0; attempt < size; ++attempt) {
        int pos = calcHash(key, attempt, size);
        Person person = *(persons + pos);

        if(person.status == USED_CELL) { if(person.key == key) return pos; }
        else if(person.status == EMPTY_CELL) break;
    }

    return ERROR;
}

int hashRemove(Person* persons, int key, int size) {
    for(int attempt = 0; attempt < size; ++attempt) {
        int pos = calcHash(key,  attempt, size);
        Person person = *(persons + pos);

        if(person.status == USED_CELL) { if(person.key == key) return pos; }
        else if(person.status == EMPTY_CELL) break;
    }

    return ERROR;
}

void printPerson(Person* person) {
    printf("Nome: %s", person->name);
    printf("\n");
    printf("Idade: %d", person->age);
    printf("\n");
    printf("Chave: %d", person->key);
    printf("\n");
    printf("Status: %d", person->status);
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

void listAllPersons(Person* persons, int size) {
    for(int i = 0; i < size; i++) {
        Person* person = persons + i;
        printPerson(person);
    }
}

int askKey() {
    int key;

    printf("Digite a chave: ");
    scanf("%d", &key);

    return key;
}

void removePerson(Person* persons, int size) {
    printf("\n");

    int key = askKey();
    int pos = hashRemove(persons, key, size);

    if(pos != ERROR) removePersonFromDB(persons, pos);
    else printf("Não foi possível remover!\n");

    printf("\n");
    printf("\n");
}

void searchPerson(Person* persons, int size) {
    printf("\n");

    int key = askKey();
    int pos = hashSearch(persons, key, size);

    if(pos != ERROR) getPersonFromDB(persons, pos);
    else printf("Não foi possível encontrar!\n");

    printf("\n");
    printf("\n");
}

void addPerson(Person* persons, int size) {
    printf("\n");

    Person* person = getPersonInfo();
    int pos = hashInsert(persons, person->key, size);

    if(pos != ERROR) addPersonToDB(persons, person, pos);
    else printf("Não foi possível adicionar!\n");

    printf("\n");
    printf("\n");
}

int getUserOption() {
    int answer;

    printf("[1] p/ inserção\n");
    printf("[2] p/ busca\n");
    printf("[3] p/ remoção\n");
    printf("[4] p/ listagem\n");
    printf("[0] p/ encerrar\n");
    printf("Digite a operação desejada: ");
    scanf("%d", &answer);

    return answer;
}

void menu(Person* persons, int size) {
    int answer;

    while((answer = getUserOption()) > 0) {
        switch(answer) {
            case 1:
                addPerson(persons, size);
                break;

            case 2:
                searchPerson(persons, size);
                break;

            case 3:
                removePerson(persons, size);
                break;

            case 4:
                listAllPersons(persons, size);
                break;

            default:
                break;
        }
    }
}

int main() {
    int size = 10;
    Person* persons = (Person*) malloc(sizeof(Person) * size);

    menu(persons, size);

    free(persons);

    return 0;
}