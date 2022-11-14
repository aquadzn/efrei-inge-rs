#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    char **args = malloc((argc - 1) * sizeof(char *));
    for (int i = 0; i < argc - 2; i++) {
        args[i] = malloc(strlen(argv[i + 2]) * sizeof(char));
        strcpy(args[i], argv[i + 2]);
        printf("%s\n", args[i]);
    }

    args[argc - 2] = NULL;

    execv(argv[1], args);

    return 0;
}