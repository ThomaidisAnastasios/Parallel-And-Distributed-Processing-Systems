/*Antegrammeno c1 toy lab10 se c2  me task kai threads.*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define NUM_THREADS 8

char *msg[NUM_THREADS];
void *phello(void *threadarg);

struct task
{/*Pare mia struct.*/
char *msg;
int tasksid, s;
};

struct task task_a[NUM_THREADS];

int main()
{
pthread_t threads[NUM_THREADS];
int i, s= 0, *tasksid[NUM_THREADS];

/*Tyxai geia se tyxaies glwsses.*/
msg[0]= "English: Hello World!";
msg[1]= "French: Bonjour, le monde!";
msg[2]= "Spanish: Hola al mundo";
msg[3]= "Klingon: Nuq neH!";
msg[4]= "German: Guten Tag, Welt!";
msg[5]= "Russian: Zdravstvytye, mir!";
msg[6]= "Japan: Sekai e konnichiwa!";
msg[7]= "Latin: Orbis, te saluto!";

for(i=0; i<NUM_THREADS; i++)/*Einai apo 0 mexri kai ton arithmo twn diergaseiwn.*/
{
  tasksid[i]= (int *) malloc(sizeof(int));/*Pare tis diergasies.*/
  *tasksid[i]= i;
  task_a[i].tasksid= i;
  s+= i+ 1;
  task_a[i].s= s;
  task_a[i].msg= msg[i];
  phello(&task_a[i]);
}

return 0;
}

void *phello(void *threadarg)
{
struct task *my_d= threadarg;

int id= *(int *)threadarg, taskid1;

my_d= (struct task *) threadarg;/*Syndesoume me thn struct.*/
taskid= my_d-> tasksid1;

printf("Thread (%d): %s\n", id, msg[id]);/*Deikse to thread kai to mhnyma.*/
fflush(NULL);

void pthread_exit(void *);
}

