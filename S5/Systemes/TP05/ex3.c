#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void sig_handler(int signum) {
    printf("\nTemps de reflexion dépassé\n");
    exit(-1);
}

int main() {
    char choix[12];
    signal(SIGALRM, sig_handler);

    printf("Q1 ? (oui/non) : ");
    alarm(12);
    scanf("%s", choix);

    printf("Q2 ? (oui/non) : ");
    alarm(12);
    scanf("%s", choix);

    printf("Q3 ? (oui/non) : ");
    alarm(12);
    scanf("%s", choix);

    return 0;
}