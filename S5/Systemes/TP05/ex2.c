#include <stdio.h>
#include <unistd.h>

int main() {
    printf("[1] - Backup fichier.txt\n");
    printf("[2] - Modifier fichier.txt\n");
    printf("[3] - Supprimer fichier.txt\n");
    int option;
    printf("Votre choix\n> ");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
        execlp("cp", "cp", "fichier.txt", "fichier.txt.backup", NULL);
        break;
    case 2:
        execlp("nano", "nano", "fichier.txt", NULL);
        break;
    case 3:
        execlp("rm", "rm", "fichier.txt", NULL);
        break;
    default:
        break;
    }
    return 0;
}