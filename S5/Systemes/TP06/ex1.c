#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <time.h>
#include <unistd.h>
int INTERV = 1;

void sig_handler(int signum) {
    if (signum == SIGINT) {
        INTERV *= 2;
    }
    if (signum == SIGTSTP) {
        INTERV /= 2;
    }
    if (signum == SIGQUIT) {
        exit(-1);
    }
}

void printf_middle(char *string) {
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);
    int cols = w.ws_col;
    int rows = w.ws_row;

    int vertl = rows / 2;
    int hortl = 0;
    int stringLength = strlen(string) / 2;

    hortl = (cols - strlen(string)) / 2;

    for (int x = 0; x <= rows; x++) {
        printf("\n");
        if (x == vertl) {
            printf("\n%*s", cols / 2 + stringLength, string);
        }
    }
}

int main() {
    signal(SIGINT, sig_handler);
    signal(SIGTSTP, sig_handler);
    signal(SIGQUIT, sig_handler);

    for (;;) {
        time_t now = time(NULL);
        struct tm tm_now = *localtime(&now);
        char s_now[sizeof "HH:MM:SS\0"];
        strftime(s_now, sizeof s_now, " %H:%M:%S", &tm_now);

        printf("\e[1;1H\e[2J");
        printf_middle(s_now);
        sleep(INTERV);
    }
    return 0;
}