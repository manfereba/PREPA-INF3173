#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;  // Mutex global
int shared_resource = 0;  // Ressource partagée entre les threads

// Fonction que chaque thread va exécuter
void* increment(void* arg) {
    for (int i = 0; i < 1000000; i++) {
        pthread_mutex_lock(&mutex);  // Lock le mutex avant d'accéder à la ressource partagée
        shared_resource++;  // Incrémenter la ressource partagée
        pthread_mutex_unlock(&mutex);  // Déverrouiller le mutex après l'accès à la ressource
    }
    return NULL;
}

int main() {
    pthread_t threads[2];  // Déclaration de deux threads

    // Création de deux threads
    for (int i = 0; i < 2; i++) {
        if (pthread_create(&threads[i], NULL, increment, NULL) != 0) {
            perror("pthread_create");
            exit(1);
        }
    }

    // Attendre que les deux threads terminent leur travail
    for (int i = 0; i < 2; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("pthread_join");
            exit(1);
        }
    }

    // Afficher la valeur de la ressource partagée après l'exécution
    printf("Valeur finale de la ressource partagée : %d\n", shared_resource);

    // Détruire le mutex (optionnel si vous utilisez PTHREAD_MUTEX_INITIALIZER)
    pthread_mutex_destroy(&mutex);

    return 0;
}

