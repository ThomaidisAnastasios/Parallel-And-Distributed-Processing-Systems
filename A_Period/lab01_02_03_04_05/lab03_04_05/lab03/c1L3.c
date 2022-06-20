/*Elegxos axrhkophshs MPI_Init.*/
#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
int rank, size, error,name_length;;
char processor_name[MPI_MAX_PROCESSOR_NAME];

error= MPI_Init(&argc, &argv); /*Thn arxikopoiei.*/

if(error!= MPI_SUCCESS)/*Edw einai o elegxos.*/
{
printf("Error.\n");
MPI_Abort(MPI_COMM_WORLD, error);
}

MPI_Comm_rank(MPI_COMM_WORLD, &rank);
MPI_Comm_size(MPI_COMM_WORLD, &size);
MPI_Get_processor_name(processor_name, &name_length);

printf("Hello World. Rank is %d and the size of my comunicator is %d.And my processor name is %s.\n",rank, size, processor_name);

MPI_Finalize();
return 0;
}
