/*Dhlwnoume biblio8hkes.*/
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{

char name[BUFSIZ];/*Declaration of variables.*/
float pi = 0.0, W = 1.0/N, temp[size];
int i, j, N= atoi(argv[1]), parTest= -1, rank= -1, size= -1, len= -1, range[N], debugg= 1, Ndiv= N/size, rest= N%size, locr[Ndiv];

if(argc== 1|| argc> 2)
  printf("Too many arguments.\n");/*Einai polles metablhtes.*/

MPI_Status status;
parTest= MPI_Init(&argc, &argv);

if(parTest== 1)/*Tsekaroume an apotygxanei h parallhlopoihsh.*/
{
  printf("Parallelization failed.\n");
  MPI_Abort(MPI_COMM_WORLD, 1);
  return 0;
}

MPI_Comm_rank(MPI_COMM_WORLD, &rank);/*Pairnoume to rank.*/
MPI_Comm_size(MPI_COMM_WORLD, &size);/*Pairnoume to size.*/
MPI_Get_processor_name(name, &len);/*Pairnoume to length.*/

if(size< 2)/*Elegxetai an xrhsomopoioyntai toylaxiston 2 epeksargastes.*/
{
printf("Need at least 2 processess.\n");
MPI_Abort(MPI_COMM_WORLD, 1);
return 0;
}

if(rank== 0)  
  for(i= 0; i< N; i++) 
	range[i]= i;

MPI_Scatter(range, Ndiv, MPI_INT, locr, Ndiv, MPI_INT, 0, MPI_COMM_WORLD);/*Kanoyme Scatter.*/

temp[rank]=0.0;

for(j= 0; j< Ndiv; j++)
{
  i=locr[j];
  temp[rank]=  temp[rank]+ 4* W/ (1+ (i+ 0.5)* (i+ 0.5)* W* W);/*Typos gia to prosorhno rank.*/
}


if(rank== 0)
{
  pi= temp[0];
  for(i= 1; i< size; ++i)
  {
    MPI_Recv(&temp[i], 1, MPI_FLOAT, i, 0, MPI_COMM_WORLD, &status);
	pi= pi+ temp[i];/*Typos gia to pi.*/
	printf("Rank= %d received= %f processes= %d running= %f.\n", rank, temp[i], i, pi);/*Typwnoume rank, temp, i kai pi.*/
	}
  }
else if(rank> 0)
{
  printf("Rank= %d sending= %f.\n", rank, temp[rank]);/*Typwnoume rank, prosorino rank.*/
  MPI_Send(&temp[rank], 1, MPI_FLOAT, 0, 0, MPI_COMM_WORLD);
}

MPI_Finalize();/*Termatizoume thn Mpi.*/
	
if(rank== 0 )
  printf("Result= %f.\n", pi);

return 0;
}

void mpiDebugHelper()
{
int x= 0;/*Declaration of variables.*/
char host[256];

gethostname(host, sizeof(host));/*Pairnoyme to onoma tou host.*/
printf("PID %d on host %d.\n", getpid(), host);/*Typwnoume to onoma tou host.*/
fflush(stdout);

while(0== x)
  sleep(5);
}
