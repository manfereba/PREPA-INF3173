#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h> // Pour sleep()

// Fonction que chaque thread exécutera
void *background_task(void *arg) {
    int thread_num = *(int *)arg;
    free(arg); // Libération de la mémoire allouée
    printf("Thread %d: Démarrage de la tâche en arrière-plan...\n", thread_num);
    sleep(2); // Simule un traitement long
    printf("Thread %d: Tâche terminée.\n", thread_num);
    return NULL;
}

int main() {
    pthread_t threads[5]; // Tableau pour stocker les IDs des threads

    for (int i = 0; i < 5; i++) {
        // Allocation dynamique de l'identifiant du thread
        int *arg = malloc(sizeof(*arg)); // ici on doit utiliser malloc car utiliser int thread_num = *(int *)arg; arg sera inconnu dans cette operation.
       *arg = i;
       
       
        // Création du thread
        if (pthread_create(&threads[i], NULL, background_task, arg) != 0) {
            perror("Échec de la création du thread");
            free(arg); // Nettoyage en cas d'échec
            return 1;
        }

        // Détachement du thread pour éviter d'avoir à le rejoindre
        pthread_detach(threads[i]);
    }

    printf("Tous les threads ont été créés et détachés.\n");
    
    // Attendre un peu avant de quitter pour que les threads terminent leur exécution
    sleep(3);

    return 0;
}

