#include <stdio.h>     /* printf, fopen */
#include <stdlib.h>     /* exit, EXIT_FAILURE */
#include <string.h>

#define MAX_SIZE 100 /**size of largest string*/

#define MALLOC(p,s) \
    if(!((p) = malloc(s))) {\
        fprintf(stderr, "Memoria insuficiente"); \
        exit(EXIT_FAILURE); \
    }

void strnins(char *s, char *t, int i);
int nfind(char *string, char *pat);

int main() {
     /**forma directa pero no muy usual*/
    //char string1[MAX_SIZE] = {"amobile"}, *s = string1;
    //char string2[MAX_SIZE] = {"uto"}, *t = string2;

    char string1[MAX_SIZE], *s = string1;
    char string2[MAX_SIZE], *t = string2;

    char str[MAX_SIZE], *st = str;
    char pat[MAX_SIZE], *p = pat;

    /**no hay necesidad en caso de que usemos el strcpy*/
    //MALLOC(s,MAX_SIZE * sizeof(char));
    //MALLOC(t,MAX_SIZE * sizeof(char));

    strcpy(s,"amobile");
    strcpy(t,"uto");


    strcpy(p, "aca");
    strcpy(st, "abcabcacab");

    /**no es correcto hacer eso*/
    //s = "amobile";
    //t = "uto";

    strnins(s,t,1);

    printf(s);

    int com = nfind(st,p);
    printf("\n %d \n",com);

    //free(s);
    //free(t);
    return 0;
}


void strnins(char *s, char *t, int i) {
    /**inset string t into string s at position i*/
    char string[MAX_SIZE], *temp = string;

    /**decimos cuanta memoria es necesaria para temp, ambas opciones son correctas.*/
    //memset(temp, 0, MAX_SIZE);
    MALLOC(temp,MAX_SIZE * sizeof(char));

    if (i < 0 && i > strlen(s)) {
        fprintf(stderr, "Position is out of bounds \n");
        exit(EXIT_FAILURE);
    }
    if(!strlen(s))
        strcpy(s,t);
    else if(strlen(t)) {
        strncpy(temp,s ,i);
        strcat(temp, t);
        strcat(temp,(s+i));
        strcpy(s, temp);
    }
    free(temp);
}


int nfind(char *string, char *pat) {
    /**match the last character ig pattern first, and
    then match from the beginning*/
    int i, j, start = 0;
    int lasts = strlen(string) - 1;
    int lastp = strlen(pat) - 1;
    int endmatch = lastp;

    for (i = 0; endmatch <= lasts; endmatch++, start++) {
        if(string[endmatch] == pat[lastp])
        for(j = 0, i = start; j < lastp && string[i] == pat[j]; i++, j++)
        ;
        if(j == lastp)
            return start; /**succesfull*/
    }
    return -1;
}
