#include <stdio.h>
#include <stdlib.h>

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


    element item;
    item.key = 7;
    push(item);

    //printf("%d \n",stack[0].key);

    //pop();
    element item2;
    item2.key = 10;
    push(item2);
printf("%d %d \n",top,capacity);
    item.key = 4;
    push(item);

printf("%d %d \n",top,capacity);
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

    for(i = 0 ;i < 3 ; i++)
        printf("%d \n",stack[i].key);

    free(stack);

    return 0;
}

void push(element item) {
    /**add an item to the global stack*/
    if (top >= capacity)
        stackFull();
    stack[++top] = item;
}

element pop() {
    /**delete and return the top element from the stack*/
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
