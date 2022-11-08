#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t petit_fils[2];
    pid_t fils1, fils2, fils3;

    printf("Parent\t\tPID: %d\n", getpid());

    if ((fils1 = fork()) == 0) {
        for (int j = 1; j <= 2; j++) {
            if ((petit_fils[j] = fork()) == 0) {
                printf("Petit-fils %d\tPID: %d\tPPID: %d\n", j, getpid(), getppid());
                exit(0);
            }
        }

        for (int j = 1; j <= 2; j++) {
            wait(NULL);
        }

        sleep(2);
        printf("Fils 1\t\tPID: %d\tPPID: %d\n", getpid(), getppid());
        exit(0);
    }

    if ((fils2 = fork()) == 0) {
        sleep(1);
        printf("Fils 2\t\tPID: %d\tPPID: %d\n", getpid(), getppid());
        exit(0);
    }

    if ((fils3 = fork()) == 0) {
        sleep(3);
        printf("Fils 3\t\tPID: %d\tPPID: %d\n", getpid(), getppid());
        exit(0);
    }

    for (int i = 0; i < 3; i++) {
        wait(NULL);
    }

    return 0;
}
