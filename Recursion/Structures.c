#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define FALSE 0
#define TRUE 1

typedef struct {
    char name[10];
    int age;
    float salary;
} humanBeing;

int humansEqual(humanBeing, humanBeing);

int main() {

    humanBeing persona1, persona2;

    struct {
        char name[10];
        int age;
        float salary;
    } person;



    strcpy(person.name, "piero");
    person.age = 25;
    person.salary = 500.20;

    strcpy(persona1.name, "jhonatan");
    persona1.age = 26;
    persona1.salary = 500;

    strcpy(persona2.name, "jhonatan");
    persona2.age = 26;
    persona2.salary = 50;

    printf(" nombre: %s \n edad: %d \n",person.name, person.age);
    printf("\n");
    printf(" nombre: %s \n edad: %d \n",persona1.name, persona1.age);
    printf("\n");

    if(strcmp(persona1.name, persona2.name))
        printf("las dos personas tienen el nombre diferente \n");
    else
        printf("las dos personas tienen el mismo nombre \n");


    if(humansEqual(persona1, persona2))
        printf("las dos personas son la misma \n");
    else
        printf("las dos personas son diferentes \n");

    return 0;
}

int humansEqual(humanBeing person1, humanBeing person2) {
    if(strcmp(person1.name, person2.name))
        return FALSE;
    if(person1.age != person2.age)
        return FALSE;
    if(person1.salary != person2.salary)
        return FALSE;

    return TRUE;
}
