/*C1 kai dexetai kai parametro.*/
#include <stdio.h>
#include <string.h>

int main(int argc, int *argv[])
{
int i, N= atoi( argv[1]);/*Edw pairnei thn timh.*/
float pi= 0.0, W= 1.0/ N;

for(i= 0; i< N; i++)/*Apo 0 mexri kai ton aritmo N poy orisame.*/
  pi+= 4* W/ (1+ (i+ 0.5)* (i+ 0.5)* W* W);
  /*Typos gia ypologismo toy pi.*/

printf("Pi= %f.\n", pi);/*Pare to pi.*/
return 0;
}
