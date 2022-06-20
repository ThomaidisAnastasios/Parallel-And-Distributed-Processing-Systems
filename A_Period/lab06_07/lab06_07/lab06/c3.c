/*Ypologismos ginomenou enos pinaka seiriaka xwris openmpi.*/
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define N 5/*Thelei 5.*/

int main(int argc, char *argv[])
{
int array[10][N], i, number, j, mn[N], n[N];
srand(time(NULL));

for(i= 0; i< 10; ++i)
{
  for(j= 0; j< N; ++j)
  {
  array[i][j]= 0;/*Thetoume ton pinaka.*/
  array[i][j]= arrayR();/*Fwnazei thn random.*/
  }
}

for(i=0; i< N; ++i)
{
  number=i +1;
  printf("Give an integer number for %d/ %d.\n", number, N);
  scanf("%d", &n[i]);/*Eisagwgh.*/
}

for(i= 0; i< 10; ++i)
{
  mn[i]= 0;/*Mhdenismos.*/

  for(j= 0; j< N; ++j)
  {
    mn[i]= mn[i]+ array[i][j]* n[j];/*Vgazei to pollaplasiamseno apotelesma.*/
  }
}

for(i= 0; i< 10; ++i)
  for(j= 0; j< N; ++j)
    printf("Array %d:%d= %d.\n", i+ 1, j+ 1, array[i][j]);/*Pinakas.*/

for(i= 0; i< N; ++i)
  printf("multi number %d= %d.\n", i+ 1, mn[i]);/*Pollaplasiasmeno.*/

return 0;
}

int arrayR()
{
  return rand()%100;/*Thelei rand.*/
}
