#include <stdio.h>
#include <math.h>
#include <time.h>
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

int main() {
	int n, *lista, i;

	srand(time(0));

	scanf("%d",&n);

	if (n < 1) {
		fprintf(stderr, "no puede una lista negativa ni tamanho cero \n");
		exit(EXIT_FAILURE);

	}

	//lista = (int *)malloc(n * sizeof(int));

	MALLOC(lista,n * sizeof(int));
	//CALLOC(lista, n, sizeof(int));

	for (i = 0; i < n; i++) {
		*(lista + i)  = (rand() % 25) + 1;
		printf("num: %d \n",*(lista + i));
	}

	free(lista);

	return 0;
}
