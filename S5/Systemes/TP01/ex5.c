#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    /* Chemin vers le nouveau fichier */
    char *path = argv[1];

    /* Permissions du nouveau fichier */
    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;

    /* Crée le fichier */
    int fd = open(path, O_WRONLY | O_EXCL | O_CREAT, mode);

    if (fd == -1)
    {
        /* Une erreur est survenue, affiche un message et quitte. */
        perror("open");
        return 1;
    }

    close(fd);
    
    return 0;
}