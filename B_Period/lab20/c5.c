#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define N 5/*Prosdiorismos N.*/

int main(int argc, char *argv[])
{
double charge, summary;	
int Alpha[10][N], Beta[N], i, j, res[10];/*Dhlwsh metablhtwn.*/

charge= omp_get_wtime();

#pragma omp parallel
res[0]= 0;

for(i= 0; i< N; ++i)
{
  printf("Enter number.\n");
  scanf("%d", &Beta[i]);
}

initialize_array_from_file(Alpha);

#pragma omp parallel for
  for(i= 0; i< 10; ++i)
    for(j= 0; j< N; ++j)
    {
	  #pragma omp critical
	  res[i]+= Alpha[i][j]* Beta[j];
	}

print_results(Alpha, Beta, res);

summary= omp_get_wtime()- charge;
printf("Summary time= %f.\n", summary);

return 0;
}

void initialize_array_from_file(int Alpha[10][N])
{
int k, l;/*Dhlwsh metablhtwn.*/
FILE *fp;

#pragma omp parallel
  fp= fopen("file.dat.\n");

if(!fp)
  printf("Can't open file.\n");

memset(Alpha, 0, sizeof(Alpha));

while(!feof(fp))
  for(k= 0; k< 10; ++k)
    for(l= 0; l< N; ++l)
	  fscanf(fp, "%d", &Alpha[k][l]);

fclose(fp);
}

void print_results(int Alpha[10][N], int Beta[N], int res[10])
{
int x, y;/*Dhlwsh metablhtwn.*/

#pragma omp parallel
  printf("First array.\n");

for(x= 0; x< 10; ++x)
  for(y= 0; y< N; ++y)
	printf("%d\n", Alpha[x][y]);

printf("Vector.\n");

for(x= 0; x< 10; ++x)
  printf("%d \n", res[x]);
}

/*gcc -fopenmp c5.c -o c5*/