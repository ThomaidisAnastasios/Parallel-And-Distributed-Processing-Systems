/*Diavazei timh kai thn stelnei sto epomeno rank. Einai synexeia apo to 3.*/
#include <mpi.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  int rank=0, size=0, len= 0, input= -1, output= -1;
  char buff1[10],char1[10], char2[10], name[BUFSIZ];

  MPI_Status status;
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Get_processor_name(name, &len);

  if(size< 2)
  {
  /*Elegxei an yparxoyn 2 diergasies.*/
  printf("Minimum 2 processes are required.\n");
  MPI_Abort(MPI_COMM_WORLD, 1);
  }

  /*Antigrafoyme ta alfari8mitika stis antoistixes metablhtes.*/
  strcpy(buff1, "A");
  strcpy(char1, "+");
  strcpy(char2, "*");

  if(rank== 0)
    {
      while(input< 0 || input> 99)
      {
        printf("To terminate give an int value between 0 and 99.\n");
        scanf("%d", &input);/*Pairnei mia timh me thn scanf gia na kanei terminate.*/
      }
      
      /*Stelnei meta thn timh sto epomeno rank.*/
      MPI_Send(&input, 1, MPI_INT, rank+ 1, 0, MPI_COMM_WORLD);
      MPI_Recv(&output, 1, MPI_INT, rank+ 1, 1, MPI_COMM_WORLD, &status);
      /*Ayksanei kai allo thn timh.*/
      printf("Rank= %d: Name= %s: Received= %d: Send= %d: CurrentValue= %d \n", rank, name, output, input, input);
    }
    else if(rank== 1)
    {
      MPI_Recv(&input, 1, MPI_INT, rank- 1, 0, MPI_COMM_WORLD, &status);
      output= input+ rank;/*Prosthetoyme sto input to noymero toy rank.*/
      MPI_Send(&output, 1, MPI_INT, rank- 1, 1, MPI_COMM_WORLD);
      printf("Rank= %d: Name= %s: Received= %d: Send= %d \n", rank, name, input, output);
    }

  MPI_Finalize();

  return 0;
}
