#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MALLOC(p,s) \
    if(!((p) = malloc(s))) { \
        fprintf(stderr, "Insuficiente Memoria"); \
        exit(EXIT_FAILURE); \
    }

int** make2dArray(int, int);
void free2dArray(int**, int);

int main() {

    int i, j, rows, cols;

    int **lista;

    srand(time(0));

    printf("Ingrese tamaño de filas: \n");
    scanf("%d",&rows);
    printf("Ingrese tamaño de columnas: \n");
    scanf("%d",&cols);

    lista = make2dArray(rows, cols);

    for (i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            lista[i][j] = (rand() % 25) + 1;
            printf(" %d", lista[i][j]);
        }
        printf("\n");
    }

    free2dArray(lista, rows);

    return 0;
}

/** Function: make2dArray
  * Params: rows and cols of the matrix
  * La siguiente funcion crea una matriz dinamica.
 */

int** make2dArray(int rows, int cols) {
    int **lista, i;

    MALLOC(lista, rows* sizeof(int));

    for (i = 0; i < rows; i++) {
        MALLOC(*(lista + i), cols * sizeof(int));
    }

    return lista;
}

/** Function: free2dArray
  * Params: matrix, rows
  * La funcion libera la memoria separada dinamicamente
  * para la matriz.
  */

void free2dArray(int **lista, int rows)
{
    int i;
    for(i = 0; i < rows; i++)
    {
        free(lista[i]);
    }
    free(lista);
}
