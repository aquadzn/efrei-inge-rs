#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

const int N = 20; // taille du buffer

int main()
{
    char afilename[12] = "test1.txt";
    char buff[N];

    // tentative d’ouverture du fichier.
    // ouverture en lecture seulement
    int f2 = open(afilename, O_RDONLY);

    if (f2 == -1)
    {
        printf("open for write: failed\n");
        exit(1);
    }
    else
    {
        int nbreal = read(f2, buff, N);
        // lecture de 100 chars au max
        printf("j'ai lu %d chars\n", nbreal);
        printf("Voici les chars lus : %s\n", buff);
        close(f2);
        // bien fermer proprement.
    }
    return 0;
}