#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h> // Pour sleep()

// Fonction pour calculer le carré d'un nombre
void *calculate_square(void *arg) {
    int number = *(int *)arg; // Récupérer le nombre
    free(arg); // Libérer la mémoire allouée
    int result = number * number;
    printf("Le carré de %d est %d.\n", number, result);
    return NULL;
}

// Fonction pour calculer le cube d'un nombre
void *calculate_cube(void *arg) {
    int number = *(int *)arg; // Récupérer le nombre
    free(arg); // Libérer la mémoire allouée
    int result = number * number * number;
    printf("Le cube de %d est %d.\n", number, result);
    return NULL;
}

// Fonction pour calculer la somme de plusieurs nombres
void *calculate_sum(void *arg) {
    int *numbers = (int *)arg; // Récupérer le tableau de nombres
    int sum = 0;
    int count = numbers[0]; // Premier élément: nombre d'éléments
    for (int i = 1; i <= count; i++) {
        sum += numbers[i]; // Additionner les nombres
    }
    printf("La somme est %d.\n", sum);
    free(numbers); // Libérer la mémoire allouée
    return NULL;
}

int main() {
    pthread_t threads[5]; // Tableau pour stocker les IDs des threads

    // Créer un thread pour calculer le carré
    for (int i = 1; i <= 3; i++) {
        int *arg = malloc(sizeof(*arg));
        *arg = i; // Passer les nombres 1, 2 et 3
        pthread_create(&threads[i - 1], NULL, calculate_square, arg);
        pthread_detach(threads[i - 1]); // Détacher le thread
    }

    // Créer un thread pour calculer le cube
    for (int i = 1; i <= 3; i++) {
        int *arg = malloc(sizeof(*arg));
        *arg = i; // Passer les nombres 1, 2 et 3
        pthread_create(&threads[i + 2], NULL, calculate_cube, arg);
        pthread_detach(threads[i + 2]); // Détacher le thread
    }

    // Créer un thread pour calculer la somme
    int *sum_arg = malloc(4 * sizeof(int)); // 3 nombres + 1 pour le nombre d'éléments
    sum_arg[0] = 3; // Nombre d'éléments à additionner
    sum_arg[1] = 10; // Premier nombre
    sum_arg[2] = 20; // Deuxième nombre
    sum_arg[3] = 30; // Troisième nombre

    pthread_create(&threads[4], NULL, calculate_sum, sum_arg);
    pthread_detach(threads[4]); // Détacher le thread

    printf("Tous les threads ont été créés et détachés.\n");

    // Attendre un peu avant de quitter pour que les threads terminent leur exécution
    sleep(3);

    return 0;
}

