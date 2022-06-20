/*Helloworld me Mpi.*/
#include <mpi.h>
#include <stdio.h>

main(int argc, char **argv)
{
  MPI_Init(&argc, &argv);
  printf("Hello World from Mpi.\n");
  MPI_Finalize();

return 0;
}
