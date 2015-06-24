#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 101 /* maximum number of terms +1*/
#define MAX_COL 101
 typedef struct {
    int col;
    int row;
    int value;
} term;

term a[MAX_TERMS];
term b[MAX_TERMS];
term d[MAX_TERMS];

void mmult(term [], term [], term []);
void fastTranspose(term [], term []);
void storeSum(term [], int *,int ,int ,int *);
int COMPARE(int ,int );


int main()
{
  int i ;
  /*   | 1 0 0 0 |        | 1 2 3 4 |
   a = | 2 0 0 0 |   b =  | 0 0 0 0 |  a*b = d
       | 3 0 0 0 |        | 0 0 0 0 |
       | 4 0 0 0 |        | 0 0 0 0 |
  */

  a[0].row = 4;a[0].col = 4;a[0].value = 4;
  a[1].row = 0;a[1].col = 0;a[1].value = 1;
  a[2].row = 1;a[2].col = 0;a[2].value = 2;
  a[3].row = 2;a[3].col = 0;a[3].value = 3;
  a[4].row = 3;a[4].col = 0;a[4].value = 4;
  /*a[4].row = 1;a[4].col = 0;a[4].value = 4;
  a[5].row = 1;a[5].col = 1;a[5].value = 5;
  a[6].row = 1;a[6].col = 2;a[6].value = 6;*/

  b[0].row = 4;b[0].col = 4;b[0].value = 4;
  b[1].row = 0;b[1].col = 0;b[1].value = 1;
  b[2].row = 0;b[2].col = 1;b[2].value = 2;
  b[3].row = 0;b[3].col = 2;b[3].value = 3;
  b[4].row = 0;b[4].col = 3;b[4].value = 4;
  //b[4].row = 2;b[4].col = 2;b[4].value = 1;

  //fastTranspose(a,d);

  mmult(a,b,d);
  for(i=1;i<=a[0].row*b[0].col;i++)
    printf(" %2d   %2d     %2d\n",d[i].row,d[i].col,d[i].value);

  //printf("\n\n%d",a[2].row);
  system("PAUSE");
  return 0;
}

void fastTranspose(term a[], term b[])
{
   int rowTerms[MAX_COL], startingPos[MAX_COL];
   int i, j, numCols = a[0].col, numTerms = a[0].value;
   b[0].row = numCols;
   b[0].col = a[0].row;
   b[0].value = numTerms;
   if (numTerms > 0)
   {
       for (i = 0; i < numCols; i++)
           rowTerms[i] = 0;
       for (i = 1; i <= numTerms; i++)
           rowTerms[a[i].col]++;
       startingPos[0] = 1;
       for (i = 1; i < numCols; i++)
           startingPos[i] = startingPos[i-1] + rowTerms[i-1];
       for (i = 1; i <= numTerms; i++)
       {
            j = startingPos[a[i].col]++;
            b[j].row = a[i].col;
            b[j].col = a[i].row;
            b[j].value = a[i].value;
       }
   }
}

void storeSum(term d[], int *totalD,int row,int column,int *sum)
{
     if(*sum)
        if(*totalD<MAX_TERMS)
        {
           d[++*totalD].row = row;
           d[*totalD].col = column;
           d[*totalD].value = *sum;
           *sum = 0;
        }
        else
        {
            fprintf(stderr,"Number of terms in product exceeds %d\n",MAX_TERMS);
            exit(EXIT_FAILURE);
        }
}
int COMPARE(int s,int t)
{
	if(s==t)
		return 0;
	else if(s<t)
		return -1;
	else
		return 1;
}
void mmult(term a[], term b[], term d[])
{
   int i, j, column= 0, totalB = b[0].value, totalD = 0;
   int rowsA = a[0].row, colsA = a[0].col,
   totalA = a[0].value, colsB = b[0].col;
   int rowBegin = 1, row = a[1].row, sum = 0;
//   int newB[MAX_TERMS][3];
   term newB[MAX_TERMS];

   if (colsA != b[0].row)
   {
      fprintf(stderr,"Incompatible matrices\n");
      exit(EXIT_FAILURE);
   }

   fastTranspose(b,newB);
   /* set boundary condition */
   a[totalA+1].row = rowsA;
   newB[totalB+1].row = colsB;
   newB[totalB+1].col = 0;

  for (i = 1; i <= totalA;)
  {
      column = newB[1].row;
    for (j = 1; j <= totalB+1;)
    {/* multiply row of a by column of b */
//    printf("%2d %2d %2d %2d\n",i,totalA,sum,a[i].value*newB[j].value);
       if (a[i].row != row)
       {
          storeSum(d,&totalD,row,column,&sum);
          i = rowBegin;
          for(;newB[j].row==column;j++)
             ;
          column = newB[j].row;
       }
       else if (newB[j].row != column)
       {
            storeSum(d,&totalD,row,column,&sum);
            i = rowBegin;
            column = newB[j].row;
       }
       else switch (COMPARE(a[i].col,newB[j].col))
       {
          case -1:  /* go to next term in a */
              i++; break;
          case 0:  /* add term,go to next term in a and b */
              sum =(a[i++].value*newB[j++].value);
              break;
          case 1:  /* advance to next term in b */
              j++;
        }
    }
    for (;a[i].row==row;i++)
        ;
    rowBegin = i;
    row = a[i].row;
  } /* end of for i<=totalA */
//  d[0].row = rowsA;
//  d [0].col = colsB;
//  d [0].value = totalD;
}
