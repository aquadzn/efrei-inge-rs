#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    const int MAX = 1000;
    int f1, f2, n;
    char buf[MAX];
    
    // vérification du nombre
    if (argc != 3) {
        fprintf(stderr, "erreur parametres\n");
        exit(1);
    }

    // ouverture readOnly du premier argument
    f1 = open(argv[1], O_RDONLY);
    
    if (f1 == -1) { /* mode lecture */
        perror("ouverture fichier source impossible");
        exit(2);
    }
    
    // ouverture du deuxième argument en écriture et ?
    f2 = open(argv[2], O_WRONLY | O_CREAT | O_APPEND, S_IRWXU);
    if (f2 == -1)
    {
        // 700
        perror("creation fichier destinataire impossible");
        exit(3);
    }

    // lecture, ecriture.
    while ((n = read(f1, buf, MAX)) > 0)
    {
        write(f2, buf, n);
    }
    return 0;
}