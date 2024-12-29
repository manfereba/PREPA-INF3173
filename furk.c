#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>


/* PID des deux poussins. */
/*comprendre le fork*/
int p1;
int p2;
/* Crée 2 poussins.
* Retourne 0 pour la maman, 1 pour le premier poussin et 2 pour le second poussin. */
int furk(void) {
p1 = fork();
p2 = fork();
if (p1 == 0) return 1; // premier poussin
if (p2 == 0) return 2; // second poussin
return 0; // maman poule
}
int main(int argc, char **argv) {
printf("Je suis %d\n", getpid());
int p = furk();
if (p == 0) printf("Mes poussins sont %d et %d\n", p1, p2);
if (p == 1) printf("L'autre poussin est %d\n", p2);
if (p == 2) printf("L'autre poussin est %d\n", p1);
}
