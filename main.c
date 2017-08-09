#include <stdio.h>
#include <stdlib.h>
#include "hash_helper.h"

int getUserOption() {
    int answer = -1;

    while(answer < 0 || answer > 4) {
        printf("[1] p/ inserção\n");
        printf("[2] p/ busca\n");
        printf("[3] p/ remoção\n");
        printf("[4] p/ listagem\n");
        printf("[0] p/ encerrar\n");
        printf("Digite a operação desejada: ");
        scanf("%d", &answer);

        if(answer < 0 && answer > 4) printf("Esse valor não é válido. Tente novamente!\n\n");
    }

    printf("\n\n");

    return answer;
}

int getUserMethod() {
    int method = -1;

    while(method < 0 || method > 3) {
        printf("[1] p/ sondagem linear\n");
        printf("[2] p/ sondagem quadrática\n");
        printf("[3] p/ hashing duplo\n");
        printf("[0] p/ encerrar\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &method);

        if(method < 0 && method > 3) printf("Esse valor não é válido. Tente novamente!\n\n");
    }

    printf("\n\n");

    return method;
}

void menu(Person* persons, int size) {
    int answer = 0;
    int method = getUserMethod();

    while(((answer = getUserOption()) > 0) && method != 0) {
        if(answer == 1) {
            addPerson(persons, size, method);
        } else if(answer == 2) {
            searchPerson(persons, size, method);
        } else if(answer == 3) {
            removePerson(persons, size, method);
        } else if(answer == 4) {
            listAllPersons(persons, size);
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