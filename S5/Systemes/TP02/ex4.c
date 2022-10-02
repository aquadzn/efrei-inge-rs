#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// Constante O à N
#define N 10

void ecriture_chiffres(char nom_fichier[]) {
    int fd = open(nom_fichier, O_RDWR | O_CREAT, 0644);
    if (fd == -1)
    {
        perror("Erreur lors de la création du fichier.");
        exit(EXIT_FAILURE);
    }

    char nums[N] = "0123456789";
    write(fd, nums, N);
    close(fd);
}

void lecture_sans_lseek(char nom_fichier[]) {
    int fd = open(nom_fichier, O_RDONLY);
    if (fd == -1)
    {
        perror("Erreur lors de la lecture du fichier.");
        exit(EXIT_FAILURE);
    }

    char buffer;
    int n, nb;

    printf("Sans lseek:\n ");
    while ((n = read(fd, &buffer, 1)) > 0)
    {
        nb = buffer - '0';
        if (nb % 2 != 0)
        {
            printf("%d ", nb);
        }
    }

    printf("\n-----------\n");
    close(fd);
}

void lecture_avec_lseek(char nom_fichier[]) {
    int fd = open(nom_fichier, O_RDONLY);
    if (fd == -1)
    {
        perror("Erreur lors de la lecture du fichier.");
        exit(EXIT_FAILURE);
    }

    char buffer;
    int n, nb;

    printf("Avec lseek:\n ");

    // Version hardcodée
    // sachant que le fichier contient 0123456789

    // on récupère le 1 en déplacant le curseur
    // 1 position après le début (SEEK_SET)  
    lseek(fd, 1, SEEK_SET);
    read(fd, &buffer, 1);
    // le curseur passe à la position suivante après le read
    printf("%d ", buffer - '0');
    
    // le curseur est à 2 dans on le déplace à sa position actuelle
    // (SEEK_CUR) + 1 pour avoir 3
    lseek(fd, 1, SEEK_CUR);
    read(fd, &buffer, 1);
    printf("%d ", buffer - '0');
    
    // le curseur est à 4 dans on le déplace à sa position actuelle
    // (SEEK_CUR) + 1 pour avoir 5
    lseek(fd, 1, SEEK_CUR);
    read(fd, &buffer, 1);
    printf("%d ", buffer - '0');
    
    // le curseur est à 6 dans on le déplace à sa position actuelle
    // (SEEK_CUR) + 1 pour avoir 7
    lseek(fd, 1, SEEK_CUR);
    read(fd, &buffer, 1);
    printf("%d ", buffer - '0');

    // le curseur est à 8, on peut le déplacer à la fin
    // (SEEK_END) -1 pour obtenir le 9
    // ==> dernier caractère du fichier ou premier en partant de la fin
    lseek(fd, -1, SEEK_END);
    read(fd, &buffer, 1);
    printf("%d ", buffer - '0');
    
    printf("\n");

    /**
    Version avec une boucle moins compliquée

    off_t offset = 0;
    lseek(fd, offset, SEEK_SET);

    while (offset < N)
    {
        pread(fd, &buffer, 1, offset);
        nb = buffer - '0';
        if (nb % 2 != 0)
        {
            printf("%d ", nb);
        }
        offset++;
    }
    **/

    close(fd);
}


int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Utilisation: %s nom_du_fichier_a_creer\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    ecriture_chiffres(argv[1]);
    lecture_sans_lseek(argv[1]);
    lecture_avec_lseek(argv[1]);

    return 0;
}