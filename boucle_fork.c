#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main ( )
{
/*

for (int i=1; i<=4; i++)
{
pid_t pid = fork();
if (pid != 0) printf("%d\n", pid);
	

}

for (int i=1; i<=4; i++)
{
pid_t pid = fork();
if (pid == 0) break;

else printf("cas pid  %d\n", pid);
}
*/
int status;
for (int i=0; i<5; i++)
{
pid_t p = fork();
if (p < 0) exit(1);
execlp("ls", "ls","-l",NULL);
}

wait(&status);




return 0;
}
