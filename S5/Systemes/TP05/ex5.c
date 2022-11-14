#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void sig_handler(int signum) {
    if (signum == SIGUSR1) {
        printf("MERCI\n");
    }
    if (signum == SIGUSR2) {
        printf("THANKS\n");
    }
    if (signum == SIGINT) {
        printf("\nfin du programme");
        exit(-1);
    }
}

int main() {
    while(1) {
        signal(SIGUSR1, sig_handler);
        signal(SIGUSR2, sig_handler);
        signal(SIGINT, sig_handler);
    }
é
    return 0;
}