#include<stdio.h>
#include<math.h>
#include<time.h>

void printlinea(int *, int);

int main() {
	 int i, res;
	 int n = 5;
    int v[n];

	srand(time(0));

    for(i = 0; i < n; i++) {
        v[i] = rand() % 20 + 1;
    }

	 printlinea(v,n);

    res = maximo_r(v,n);
	 printf("resultado: %d \n", res);

    return 0;
}


int maximo(int v[], int n) {
	int j,x;
	x = v [0];

	for (j = 1; j < n; j++) {
		if (x < v[j])
			x = v[j];
	}
		return x;
}

int maximo_r(int v[], int n) {
	if (n == 1)
		return v[0];
	else {
		int x;
		x = maximo_r(v, n-1);
		if (x > v[n-1])
			return x;
		else
			return v[n-1];

	}
}

void printlinea(int *ptr, int n) {
	int i;
	printf("Contenido de las direcciones: \n");
	for (i = 0; i < n; i++)
		printf("%8u%5d \n",ptr + i, *(ptr + i));
	printf("\n");

	}
