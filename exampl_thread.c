#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void* print_message(void* thread_id) {
    long tid = (long)thread_id;
    printf("Bonjour depuis le thread %ld!\n", tid);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;

    for (t = 0; t < NUM_THREADS; t++) {
        printf("Création du thread %ld\n", t);
        rc = pthread_create(&threads[t], NULL, print_message, (void*)t);

        if (rc) {
            printf("Erreur: échec de la création du thread %d\n", rc);
            exit(-1);
        }
    }

    // Attendre que tous les threads terminent
    for (t = 0; t < NUM_THREADS; t++) {
        pthread_join(threads[t], NULL);
    }

    printf("Tous les threads ont terminé.\n");
    return 0;
}

