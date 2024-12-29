#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



//comment faire executer un thread apres un evenement en c

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

int event_occurred = 0;  // Variable pour simuler l'événement

// Fonction exécutée par le thread qui attend l'événement
void* thread_function(void* arg) {
    pthread_mutex_lock(&mutex);
    
    // Attendre que l'événement se produise (condition signalée)
    while (!event_occurred) {
        printf("Thread en attente de l'événement...\n");
        pthread_cond_wait(&cond, &mutex);  // Bloque jusqu'à ce que l'événement soit signalé
    }

    // Lorsque l'événement se produit, exécuter le code
    printf("L'événement a eu lieu, le thread reprend son exécution !\n");
    
    pthread_mutex_unlock(&mutex);
    return NULL;
}

// Fonction pour simuler l'événement et signaler les threads
void trigger_event() {
    sleep(2);  // Simuler un délai avant l'événement
    pthread_mutex_lock(&mutex);
    
    // Modifier la variable qui indique que l'événement a eu lieu
    event_occurred = 1;
    printf("L'événement a eu lieu, signalement...\n");
    
    // Signaler aux threads en attente que l'événement est prêt
    pthread_cond_signal(&cond);
    
    pthread_mutex_unlock(&mutex);
}

int main() {
    pthread_t thread;

    // Créer le thread qui attend l'événement
    pthread_create(&thread, NULL, thread_function, NULL);

    // Simuler un événement après un certain délai
    trigger_event();

    // Attendre que le thread termine
    pthread_join(thread, NULL);

    // Nettoyer les ressources
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
    
    return 0;
}

