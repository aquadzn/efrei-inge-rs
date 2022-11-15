#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void *factorielle(void *nbr) {
    int *n = (int *)nbr;
    int f = 1;
    for (int i = 1; i <= *n; i++)
        f = f * i;

    printf("%d --> %d\n", *n, f);

    return NULL;
}

int main() {
    int nbr, nbr2;
    printf("Entrez un nombre pour calculer sa factorielle: ");
    scanf("%d", &nbr);

    nbr2 = nbr * 2;

    pthread_t tids[2];
    pthread_create(&tids[0], NULL, factorielle, (void *)&nbr);
    pthread_create(&tids[1], NULL, factorielle, (void *)&nbr2);

    pthread_join(*(tids), NULL);
    pthread_join(*(tids + 1), NULL);
    return 0;
}
