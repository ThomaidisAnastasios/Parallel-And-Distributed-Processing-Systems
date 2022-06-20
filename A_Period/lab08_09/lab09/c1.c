/*Lab 9 c1. Meros toy kwdika gia to "peirama" dinetai.*/
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#define C 25000/*Ari8mos sygkroysewn.*/

int main()
{/*Dhlwsh metablhtwn.*/
long int ltime;
float local[C][3], cords[C][3];
int rank, size, i, count=0, sum=0, utime;
ltime=time(NULL);/*Gia tyxaies syntetagmenes.*/
utime=(unsigned int) ltime/2;

MPI_Init(NULL,NULL);/*Ksekinaei thn MPI.*/
MPI_Comm_rank(MPI_COMM_WORLD,&rank);
MPI_Comm_size(MPI_COMM_WORLD,&size);

if(size< 6)
{
  printf("Error.\n");
  MPI_Abort(MPI_COMM_WORLD,1);
}

if(rank== 0)
{
  float cords[C][3];
  srand(utime);/*Random gia xrono.*/

  for(i=0;i<C;i++)
  {/*O ypologismos do8hke. Gia tyxaies syntetagmenes.*/
    cords[i][0]=(float)34*rand()/(RAND_MAX-1);
    cords[i][1]=(float)34*rand()/(RAND_MAX-1);
    cords[i][2]=(float)34*rand()/(RAND_MAX-1);

  }

}

/*Parta se scatter.*/
MPI_Scatter(cords, C/size, MPI_FLOAT, local, C/size, MPI_FLOAT,0,MPI_COMM_WORLD);

for(i=0;i<C/size;i++)
{
  int flag= 1;
  
  /*Elegxos gia ton pinaka local[i][0].*/
  if(local[i][0]< 12|| local[i][0]> 30)
    flag=0;

  /*Elegxos gia ton pinaka local[i][1].*/
  if(local[i][1]< 12|| local[i][1]> 30)
    flag=0;

  /*Elegxos gia ton pinaka local[i][2].*/
  if(local[i][2]< 12|| local[i][2]> 30)
    flag=0;

  if(flag==1)/*Otan to flag einai 1 ayksanoyme to count kata 1.*/
    count++;
}

/*Bazoyme reduce meta thn scatter.*/
MPI_Reduce(&count, &sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

if(rank== 0)
{
  printf("Summary is: %d.\n", sum);/*Typwma gia to synolo.*/
  FILE *fp= fopen("sum_file.txt","a\n");/*Katagrafh sto arxeio.*/
  if(fp!= NULL)
  {
    fprintf(fp, "Exporting sum: %d.\n", sum);
    fclose(fp);
  }
}

MPI_Finalize();/*Termatismos MPI.*/
return 0;
}