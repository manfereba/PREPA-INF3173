/**** C4.1.c file: compute matrix sum by threads ***/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define N
4
int A[N][N], sum[N];
void *func(void *arg)
// threads function
{
int j, row;
pthread_t tid = pthread_self(); // get thread ID number
row = (int)arg;
// get row number from arg
printf("Thread %d [%lu] computes sum of row %d\n", row, tid, row);
for (j=0; j<N; j++)
// compute sum of A[row]in global sum[row]
sum[row] += A[row][j];
printf("Thread %d [%lu] done: sum[%d] = %d\n",
row, tid, row, sum[row]);
pthread_exit((void*)0); // thread exit: 0=normal termination
}
