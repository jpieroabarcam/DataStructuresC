#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100 /**maximum stack size*/
typedef struct {
    int key;
    /*other fields*/
} element;
element stack[MAX_STACK_SIZE];
int top = -1;

void push(element item);
element pop();
void stackFull();
element stackEmpty();

int main() {

    element item;
    item.key = 5;
    push(item);

    printf("%d \n",stack[0].key);

    pop();
    item.key = 10;
    push(item);

    printf("%d \n",stack[0].key);

    return 0;
}

void push(element item) {
    /**add an item to the global stack*/
    if (top >= MAX_STACK_SIZE - 1)
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
    fprintf(stderr, "Stack is full, cannot add element");
    exit(EXIT_FAILURE);
}

element stackEmpty() {
    fprintf(stderr, "Stack is empty, cannot get an element");
    exit(EXIT_FAILURE);
}

