#include <unistd.h>
#include <stdio.h>
int main ( void )
{
        pid_t p ;
	int a = 20;
	// écration d’un fils
switch ( p = fork())
{
	case -1:
        // le fork a echoue
        perror ( "le fork a echoue ! " ) ;
        break ;
	case 0 :
       	// Il s ’ agit du processus fils
        printf(" fils ,avant calcule a=%d le PID %d.\n",a, getpid()) ;
        a += 10;
	printf (" fils pid =  %d avec a+=10  %d.\n",getpid(), a) ;
	break;
	default :
        //Il s’agit du processus pere
        //printf("ici processus pere , l e PID %d.\n",getpid()) ;

	a+=100;
	printf (" pere  %d avec a+=100 %d.\n",getpid(), a) ;
	
	}
	
	printf ("Fin du processus des 2  %d avec a = %d.\n",getpid(), a) ;
	
	return 0;
}


