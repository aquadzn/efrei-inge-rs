#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

#define MAX_WAIT_SEC 20

int recup_nombre() {
    int n;
    while (n < 2 || n > 10) {
        printf("Combien de processus fils ? : ");
        scanf("%d", &n);
    }
    return n;
}

int main(int argc, char *argv[]) {
    int n = recup_nombre();

    for (int i = 1; i <= n; i++) {
        if (fork() == 0) {
            time_t t;
            srand((int)time(&t) % getpid());
            int sec = (rand() % MAX_WAIT_SEC) + 1;

            sleep(sec);

            for(int j = 0; j < 2; j++) {
                if (fork() == 0) {
                    srand((int)time(&t) % getpid());
                    int sec = (rand() % (MAX_WAIT_SEC / 4)) + 1;
                    sleep(sec);
                    printf("Petit-fils (%d), père: %d\n", getpid(), getppid());
                    exit(1);
                }
            }

            for(int j = 0; j < 2; j++) {
                wait(NULL);
            }

            printf("Fils %d (%d): %dsec\n", i, getpid(), sec);
            exit(0);
        }
    }
    for (int i = 0; i < n; i++) {
        wait(NULL);
    }

    return 0;
}
