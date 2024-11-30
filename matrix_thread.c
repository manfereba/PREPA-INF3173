#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N 4


int A[N][N], sum[N];



void *func(void *arg)
// threads function
{
int j;
int*  prow = (int*)arg;
int row = (*prow);
pthread_t tid = pthread_self(); // get thread ID number
//int *int_row = (int*)arg;

//row = *int_row;


// get row number from arg
printf("Thread %d [%lu] computes sum of row %d\n", row, tid, row);
for (j=0; j<N; j++) // compute sum of A[row]in global sum[row]
sum[row] += A[row][j];
printf("Thread %d [%lu] done: sum[%d] = %d\n",row, tid, row, sum[row]);
pthread_exit((void*)0); // thread exit: 0=normal termination
}

int main (int argc, char *argv[])
{
 pthread_t thread[N];
 // thread IDs
 int j, total = 0;
 long  i;
 void* status;
printf("Main: initialize A matrix\n");
for (i=0; i<N; i++){
 sum[i] = 0;
for (j=0; j<N; j++){
 A[i][j] = i*N + j + 1;
 printf("%4d ", A[i][j]);
}
 printf("\n");
}
printf("Main: create %d threads\n", N);
for(i=0; i<N; i++) {
 pthread_create(&thread[i], NULL, func, (void*)i);
}
printf("Main: try to join with threads\n");
for(i=0; i<N; i++) {
 pthread_join(thread[i], &status);
 printf("Main: joined with %ld [%lu]: status=%ls\n",i, thread[i], (int*) status);
}
printf("Main: compute and print total sum: ");
for(i=0; i<N; i++){
 total += sum[i];
}
 printf("tatal = %d\n", total);
 pthread_exit(NULL);
}




