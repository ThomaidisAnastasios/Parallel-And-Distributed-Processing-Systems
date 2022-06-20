/*Helloworld me mpirun.*/
#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
int rank,size;

MPI_Init(&argc, &argv);
MPI_Comm_rank(MPI_COMM_WORLD, &rank);
MPI_Comm_size(MPI_COMM_WORLD, &size);

printf("Hello World. Rank is %d and the size of my comunicator is %d.\n",rank, size);
/*Typwnei megethos kai taksh.*/

MPI_Finalize();

return 0;
}
