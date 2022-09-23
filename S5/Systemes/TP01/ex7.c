#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

const int N = 20; // taille du buffer

int main() {
    // tentative d’ouverture du fichier.
    // ouverture en écriture seulement
    //  en supposant que le fichier existe.
    int f2 = open("test1.txt", O_WRONLY | O_APPEND);
    
    if (f2 == -1) {
        printf("open for write: failed\n");
        exit(1);
    } else {
        char *mon_msg = "j'aime linux";
        write(f2, mon_msg, strlen(mon_msg));
    }
    
    return 0;
}