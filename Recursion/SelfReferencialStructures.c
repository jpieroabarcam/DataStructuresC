#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define MALLOC(p,s) \
    if(!((p) = malloc(s))) {\
        fprintf(stderr, "Memoria insuficiente"); \
        exit(EXIT_FAILURE); \
    }

/** Declaration of an Self-Referenced Structure, something strange
  * it needs more than a simple declaration in linked list **/

typedef struct list{
    char data;
    struct list *link;
}list;

int main() {

    list item1 , item2 , item3;
    item1.data = '1';
    item2.data = '2';
    item3.data = '3';
    item1.link = item2.link = item3.link = NULL;


    return 0;
}
