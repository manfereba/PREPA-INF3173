#include <pthread.h>
#include <stdio.h>
#include<unistd.h>



void* thread1_function(void* arg) {
    printf("Thread 1 : Exécution...\n");
    sleep(2);  // Simuler du travail
    printf("Thread 1 : Terminé.\n");
    return NULL;
}

void* thread2_function(void* arg) {
    printf("Thread 2 : En attente de thread 1...\n");
    // Attendre que thread 1 soit terminé
    pthread_join(*(pthread_t*)arg, NULL);  // Bloquer ici jusqu'à ce que thread 1 termine
    printf("Thread 2 : Exécution après thread 1.\n");
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    // Créer thread 1
    pthread_create(&thread1, NULL, thread1_function, NULL);
    
    // Créer thread 2, qui attendra que thread 1 termine avant d'exécuter son code
    pthread_create(&thread2, NULL, thread2_function, (void*)&thread1);

    // Attendre que les deux threads terminent
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Tous les threads sont terminés.\n");
    return 0;
}

