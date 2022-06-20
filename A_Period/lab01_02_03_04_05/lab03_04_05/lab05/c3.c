/*C2 me arxikopoihsh MPI_Init.*/
/*t=temporary.*/
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{/*Orismos metablhtwn.*/
char name[BUFSIZ];
float pi=0.0, W= 1.0/ N, tpi= 0.0, rpi= 0.0;
int i, db=1, N= atoi(argv[1]), pC= -1, rank= -1, size= -1, len= -1, Ndiv = -1, scount= 0;
  
MPI_Status status;
MPI_Request request;
MPI_Comm_rank(MPI_COMM_WORLD, &rank);
MPI_Comm_size(MPI_COMM_WORLD, &size);
MPI_Get_processor_name(name, &len);
pC= MPI_Init(&argc, &argv); 

if(pC== 1)/*Ama exei provlhma kleinei.*/
{
  printf("Error.\n");
  MPI_Abort(MPI_COMM_WORLD, 1);
  return 0;
}

if(size< 2)/*Prepei na einai toulaxiston 2.*/
{
  printf("The loops must be at least 2.\n");
  MPI_Abort(MPI_COMM_WORLD, 1);
  return 0;
}

if (rank== 0)/*Gia rank noymero 0.*/ 
{
  Ndiv= N/ (size- 1);

  for(i= 1; i< size; ++i)/*Apo 1 mexri to size.*/
  {
    MPI_Irecv(&rpi, 1, MPI_FLOAT, i, 1, MPI_COMM_WORLD, &request);/*http://mpi.deino.net/mpi_functions/MPI_Irecv.html*/
    MPI_Wait(&request, &status);/*http://mpi.deino.net/mpi_functions/MPI_Wait.html*/
    printf("Process %d value: %f \n", i, rpi);
    pi= pi+ rpi;/*To pi poy eixame +to pi poy lhf8hke.*/
    scount++;
  }

  printf("Pi= %d: after= %f.\n", scount, pi);/*Pare to pi.*/
}
else
{
  Ndiv= N/ (size- 1);/*Ypologizei to megethos tou diasthmatos.*/ 
	tpi= 0.0;/*Orismos toy tpi.*/

	for(i= (((rank- 1)* N)/ Ndiv)+ 1);
	  tpi= tpi+ 4* W/ (1+ (i+ 0.5)* (i+ 0.5)* W* W);/*Typos.*/

	MPI_Isend(&tpi, 1, MPI_FLOAT, 0, 1, MPI_COMM_WORLD, &request);
}

MPI_Finalize();
return 0;
}