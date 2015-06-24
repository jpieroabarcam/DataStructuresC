#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// declare MALLOC macro for self referential

#define MALLOC(p,s) \
    if(!((p) = malloc(s))) {\
        fprintf(stderr, "Memoria insuficiente"); \
        exit(EXIT_FAILURE); \
    }

#define IS_EMPTY(first) (!(first));

typedef struct listNode * listPointer;
typedef struct listNode {
    char data[4];
    listPointer link;
};

int main()
{
    listPointer first = NULL;
    MALLOC(first, sizeof(*first));

    strcpy(first->data,"BAT");
    first->link = NULL;

    printf("%s \n", &first->data );

    printf("Hello world!\n");
    free(first);
    return 0;
}
