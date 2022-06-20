/*c2 tou 11 synarthsh poy kaleitai apo to c1.*/
/*Mad dinetai sxedon olos o kwdikas.*/
void compute_multiplication(void *t)
{
pthread_t id;
int i, sum= 0, ct;

ct= *(int *)t;
id= pthread_self();
/*Ypologismos toy sum gia olo to euros.*/
/*To euros ksekinaei apo to dotstr.veclen kai teleiwnei sto dotstr.veclen) +dotstr.veclen*/
for(i=ct* dotstr.veclen; i< (ct* dotstr.veclen) +dotstr.veclen; ++i)
{
  sum= sum+ (a[i]* b[i]);/*Emfanish Enhmervtikoy mhnymatos.*/
  printf("Current thread= %d counted from: %d to: %d and sum= %d.\n", id, ct* dotstr.veclen, (ct* dotstr.veclen) + dotstr.veclen, sum);
}	

pthread_mutex_lock(&mutexsum);/*Kleidwnoume to sum gia na topothethsoyme timh. Epeidh h struct einai koinh.*/
dotstr.sum+= sum;/*Enhmerwsh athroismatos.*/
pthread_mutex_unlock(&mutexsum);/*Ksekleidwnoyme to sum gia na einai diathesimo kai gia allo nhma.*/
printf("Current value %f.\n", dotstr.sum);
pthread_exit((void *) 0);
}