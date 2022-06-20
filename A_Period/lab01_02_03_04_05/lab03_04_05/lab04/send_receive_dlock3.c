/*Xrhsimopoioyme alles klheis synarthsewn.*/
#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
int rank, count;
double msg1[50], msg2[50];
MPI_Status status;
MPI_Request request;
MPI_Init(&argc, &argv);
MPI_Comm_rank(MPI_COMM_WORLD, &rank);

if(rank== 0)
{/*Pali valame to send prwto apla alla ksame kai tis send kai receive me tis isend kai ireceive.*/
  MPI_Isend(msg1, 50, MPI_DOUBLE, 1, 0, MPI_COMM_WORLD, &request);
  MPI_Irecv(msg2, 10, MPI_DOUBLE, 1, 0, MPI_COMM_WORLD, &request);
}
else if(rank== 1)
{/*Pali valame to send prwto apla alla ksame kai tis send kai receive me tis isend kai ireceive.*/
  MPI_Isend(msg2, 10, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD, &request);
  MPI_Irecv(msg1, 50, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD, &request);
}

MPI_Finalize();
return 0;
}

