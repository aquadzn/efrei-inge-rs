#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    char buffer;

    int f = open("name.txt", O_WRONLY | O_CREAT, S_IRWXU);
    if (f == -1) {
        perror("creation fichier destinataire impossible");
        exit(1);
    } else {
        char *mon_msg = "william jacques";
        write(f, mon_msg, strlen(mon_msg));
    }

    close(f);

    f = open("name.txt", O_RDONLY);
    if (f == -1) {
        perror("lecture impossible");
        exit(2);
    }

    int dest_file = open("result.txt", O_WRONLY | O_CREAT, S_IRWXU);
    if (dest_file == -1) {
        perror("création impossible");
        exit(3);
    }

    int c = 0;
    int n;
    while ((n = read(f, &buffer, 1)) > 0)
    {
        c++;
    }

    char c_string[10];
    sprintf(c_string, "%d", c);
    write(dest_file, c_string, strlen(c_string));
    printf("%d caractères lu(s).\n", c);

    close(f);
    close(dest_file);

    return 0;
}