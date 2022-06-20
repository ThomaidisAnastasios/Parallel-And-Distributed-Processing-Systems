/*Anadiataksh twn klhsewn.*/
#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
  int rank, count;
  double msg1[50], msg2[50];
  MPI_Status status;
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  if(rank== 0)
  {/*Ousiastika pla valame prwta to send kai meta to receive.*/
    MPI_Send(msg1, 50, MPI_DOUBLE, 1, 0, MPI_COMM_WORLD);
    MPI_Recv(msg2, 10, MPI_DOUBLE, 1, 0, MPI_COMM_WORLD, &status);
  }
  else if(rank == 1)
  {/*Ousiastika pla valame prwta to send kai meta to receive.*/
    MPI_Send(msg2, 10, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);
    MPI_Recv(msg1, 50, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD, &status);
  }

  MPI_Finalize();
  return 0;
}
