#include <stdlib.h>
#include <unistd.h>
int main(void) {
execlp("cd", "cd ~", NULL);
execlp("ls", "ls -l", NULL);
return EXIT_SUCCESS;
}
