#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MALLOC(p,s) \
    if(!((p) = malloc(s))) {\
        fprintf(stderr, "Memoria insuficiente"); \
        exit(EXIT_FAILURE); \
    }

#define CALLOC(p,n,s) \
    if(!((p) = calloc(n,s))) {\
        fprintf(stderr, "Memoria insuficiente"); \
        exit(EXIT_FAILURE); \
    }

#define REALLOC(p,s) \
    if(!((p) = realloc(p,s))) {\
        fprintf(stderr, "Memoria insuficiente"); \
        exit(EXIT_FAILURE); \
    }

typedef struct {
    int key;
    /**other fields*/
}   element;

void push(element item);
element pop();
void stackFull();
element stackEmpty();

element *stack;
int capacity;
int top;

int main() {

    int i;
    capacity = 1;
    top = -1;

    MALLOC(stack, sizeof(*stack));

/**
    element item;
    item.key = 7;
    push(item);
    */

    //printf("%d \n",stack[0].key);

    //pop();
    /*
    element item2;
    item2.key = 10;
    push(item2);
    printf("%d %d \n",top,capacity);
    element item3;
    item3.key = 4;
    push(item);
    */

    printf("%d %d \n",top,capacity);
    int j=0;
    for(j = 0; j < 10; j++ )
    {
      //srand(time(NULL));
      element item;
      item.key = j;
      push(item);
    }
/*
    item.key = 5;
    push(item);

    item.key = 85;
    push(item);

    item.key = 12;
    push(item);

    item.key = 95;
    push(item);
*/

    for(i = 0 ;i < 10 ; i++)
    {
        printf("%d \n",stack[i].key);
    }

    printf("%d %d \n",top,capacity);


    printf("Se libero la memoria");
    free(stack);

    return 0;
}

void push(element item) {
    /**add an item to the global stack*/
    if (top >= capacity)
    {
        stackFull();
    }
    stack[++top] = item;
    printf("%d %d \n",stack[top].key,capacity);
}

element pop() {
    /**delete and return the top element from the stack*/
    // se encontro un problema con la redireccion de memoria para la pila
    // no inserta el elemento al array redireccionado.
    if (top == -1)
        return stackEmpty(); /*return an error key*/
    return stack[top--];
}

void stackFull() {
    REALLOC(stack, 2*capacity*sizeof(*stack));
    capacity *= 2;
}

element stackEmpty() {
    fprintf(stderr, "Stack is empty, cannot get an element");
    exit(EXIT_FAILURE);
}
