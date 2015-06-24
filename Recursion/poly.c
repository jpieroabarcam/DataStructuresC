#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 100

#define MALLOC(p,s) \
    if(!((p) = malloc(s))) {\
        fprintf(stderr, "Memoria insuficiente"); \
        exit(EXIT_FAILURE); \
    }

typedef struct {
    int degree;
    float coef[MAX_TERMS];
} polynomial;

typedef struct {
    float coef;
    int expon;
} polysparce;
polysparce terms[MAX_TERMS];
int avail = 0;

int compare(int a , int b) {
    if(a < b)
        return -1;
    if(a > b)
        return 1;
    else
        return 0;
}

void padd(int startA , int finishA , int startB , int finishB , int *startD , int *finishD);
void attach(float coefficient , int exponent);

int main() {


    int i , startA , startB , finishA , finishB;
    int *startD , *finishD;

    MALLOC(startD,sizeof(int));
    MALLOC(finishD,sizeof(int));

    terms[0].coef = 2;
    terms[0].expon = 1000;

    terms[1].coef = 1;
    terms[1].expon = 0;

    terms[2].coef = 1;
    terms[2].expon = 4;

    terms[3].coef = 10;
    terms[3].expon = 3;

    terms[4].coef = 3;
    terms[4].expon = 2;

    terms[5].coef = 1;
    terms[5].expon = 0;

    startA = 0;
    finishA = 1;
    startB = 2;
    finishB = 5;
    avail = 6;

    padd(startA, finishA , startB , finishB , startD , finishD);


    printf("hello world \n");

    for(i = *startD ; i < *finishD ; i++)
        printf("%f _ %i \n" , terms[i].coef , terms[i].expon);

    free(startD);
    free(finishD);

    return 0;

}

void padd(int startA , int finishA , int startB , int finishB , int *startD , int *finishD) {
    float coefficient;
    *startD = avail;

    while(startA <= finishA && startB <= finishB) {
        switch(compare(terms[startA].expon , terms[startB].expon)) {
        case -1:
            attach(terms[startB].coef , terms[startB].expon);
            startB++;
            break;
        case 0:
            coefficient = terms[startA].coef + terms[startB].coef;
            if(coefficient)
                attach(coefficient , terms[startA].expon);
            startA++;
            startB++;
        case 1:
            attach(terms[startA].coef , terms[startA].expon);
            startA++;

        }
    }
    /*** Add the remaining terms of A(x) */
    for(; startA <= finishA ; startA++)
        attach(terms[startA].coef , terms[startA].expon);
    /*** Add the remaining terms of B(x) */
    for(; startB <= finishB ; startB++)
        attach(terms[startB].coef , terms[startB].expon);

    //error de ejecucion al tener los dos punteros tanto start como finishD
    *finishD = avail-1;
    printf("%i \n" , avail-1);
}

void attach(float coefficient , int exponent) {
    /***add a new term to the polynomial */
    if(avail >= MAX_TERMS) {
        fprintf(stderr , "Too many terms in the polynomial");
        exit(EXIT_FAILURE);
    }
    terms[avail].coef = coefficient;
    terms[avail++].expon = exponent;
}
