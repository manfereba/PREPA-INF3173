#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
int main ( )
{
int i , n=5;
pid_t pid ;

for (i=1;i<n; i++)
{
	if (( pid= fork())==-1 )
	break ;
	if(pid == 0){
	printf ("Processus %d avec pere %d , i=%d\n " , getpid(),getppid(),i) ;
	}

}
	return 0 ;
}
