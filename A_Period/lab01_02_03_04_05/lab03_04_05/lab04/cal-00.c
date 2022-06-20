/*Stelnei pinaka, lamvanei pinaka gia na ypologizei ta soixeia.*/
/*a=array*/
#include <mpi.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  char name[BUFSIZ];
  int rank, size, len, alen, j= 0;
  float a[4]= {1.0, 2.3, 4.5, 5.9}, b[4], aMax= 0, aS= 0, amin= 10, aMultiplier= 1;
  alen= sizeof(a)/ sizeof(float);/*Orizoyme to mege8os toy alength.*/

  MPI_Status status;
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Get_processor_name(name, &len);

  if(rank== 0)/*Gia rank number= 0.*/
  {/*Stelnei pantou.*/
    MPI_Send(a, sizeof(a), MPI_FLOAT, 1, 1, MPI_COMM_WORLD);/*Sto 1.*/
    MPI_Send(a, sizeof(a), MPI_FLOAT, 2, 2, MPI_COMM_WORLD);/*Sto 2.*/
    MPI_Send(a, sizeof(a), MPI_FLOAT, 3, 3, MPI_COMM_WORLD);/*Sto 3.*/
    MPI_Send(a, sizeof(a), MPI_FLOAT, 4, 4, MPI_COMM_WORLD);/*Sto 4.*/

    MPI_Recv(&aS, sizeof(aS), MPI_FLOAT, 1, 5, MPI_COMM_WORLD, &status);/*Kanei receive apo to 1.*/
    MPI_Recv(&aM, sizeof(aMax), MPI_FLOAT, 2, 6, MPI_COMM_WORLD, &status);/*Kanei receive apo to 2.*/
    MPI_Recv(&am, sizeof(amin), MPI_FLOAT, 3, 7, MPI_COMM_WORLD, &status);/*Kanei receive apo to 3.*/
    MPI_Recv(&aMultiplier, sizeof(aMultiplier), MPI_FLOAT, 4, 8, MPI_COMM_WORLD, &status);/*Kanei receive apo to 4.*/

    printf("Array Si=%f: Array Max=%f: Array min=%f: Array Multiplier=%f.\n", aS, aMax, amin, aMultiplier);
  }
  else if(rank== 1)/*Gia rank number= 1.*/
  {/*Pairnei to a[] kai to petai sto b. Vriskei to synolo.*/
    MPI_Recv(a, sizeof(a), MPI_FLOAT, 1, 1, MPI_COMM_WORLD, &status);
    memcpy(a, b, sizeof(b));

    for(j= 0; j< alen; ++j)/*Apo 0 mexri to mhkos toy a.*/
      aS= aS + b[j];/*Orizei to synolo.*/

    MPI_Send(&aS, sizeof(aS), MPI_FLOAT, 1, 5, MPI_COMM_WORLD);
  }
  else if(rank== 2)/*Gia rank number= 2.*/
  {
    MPI_Recv(a, sizeof(a), MPI_FLOAT, 1, 2, MPI_COMM_WORLD, &status);
    memcpy(a, b, sizeof(b));

    for(j= 0; j< alen; ++j)/*Apo 0 mexri to mhkos toy a.*/
    {
      if (b[i]> aMax)
        aMax= b[j];/*Orizei to maximum.*/
    }
                    /*Mhnyma.*/
    MPI_Send(&aMax, sizeof(aMax), MPI_FLOAT, 1, 6, MPI_COMM_WORLD);
  }
  else if(rank== 3)/*Gia rank number= 3.*/
  {
    MPI_Recv(a, sizeof(a), MPI_FLOAT, 1, 3, MPI_COMM_WORLD, &status);
    memcpy(a, b, sizeof(b));

    for(j= 0; j< alen; ++j)/*Apo 0 mexri to mhkos toy a.*/
    {
      if(b[j]< amin)
        amin= b[j];/*Orizei to minimum.*/
    }

    MPI_Send(&amin, sizeof(amin), MPI_FLOAT, 1, 7, MPI_COMM_WORLD);
  }
  else if(rank== 4)/*Gia rank number= 4.*/
  {
    MPI_Recv(a, sizeof(a), MPI_FLOAT, 1, 4, MPI_COMM_WORLD, &status);
    memcpy(a, b, sizeof(b));
    for (j= 0; j< alen; ++j)/*Apo 0 mexri to mhkos toy a.*/
      aMultiplier= aMultiplier* b[j];/*Vriskei to ginomeno.*/
    MPI_Send(&aMultiplier, sizeof(aMultiplier), MPI_FLOAT, 1, 8, MPI_COMM_WORLD);
  }
  else
    printf("Rank= %d: No changes here=%s.\n", rank, name);

MPI_Finalize();
return 0;
}
