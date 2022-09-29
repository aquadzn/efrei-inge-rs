#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// Constante O à N
#define N 10


int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Utilisation: %s nom_du_fichier_a_creer\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int fd = open(argv[1], O_RDWR | O_CREAT, 0644);
    if (fd == -1) {
        perror("Erreur lors de la création du fichier.");
        exit(EXIT_FAILURE);
    }

    char nums[N] = "0123456789";
    write(fd, nums, N);
    close(fd);

    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("Erreur lors de la lecture du fichier.");
        exit(EXIT_FAILURE);
    }

    // Sans lseek

    char buffer;
    int n, nb;

    printf("Sans lseek:\n");
    while((n = read(fd, &buffer, 1)) > 0) {        
        nb = buffer - '0';
        if (nb % 2 != 0) {
            printf("%d ", nb);
        }
    }
    printf("\n");


    // Avec lseek
    printf("Avec lseek:\n");

    off_t offset = 0;
    // On replace le curseur, actuellement à la fin,
    // au début du fichier 
    lseek(fd, offset, SEEK_SET);
    while (offset < N) {
        read(fd, &buffer, 1);
        nb = buffer - '0';
        if (nb % 2 != 0) {
            printf("%d ", nb);
        }
        offset++;
    }
    printf("\n");

    return 0;
}