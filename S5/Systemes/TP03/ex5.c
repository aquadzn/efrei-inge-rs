#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t pid1, pid2;
    int pids[2];

    for (int i = 0; i < 2; i++)
    {
        if (i % 2 == 0)
        {
            if ((pid1 = fork()) == 0)
            {
                execlp("ls", "ls", "-l");
                exit(0);
            }
        }
        else
        {
            if ((pid2 = fork()) == 0)
            {
                execlp("ps", "ps", "-l");
                exit(0);
            }
        }
    }

    for (int i = 0; i < 2; i++)
    {
        pids[i] = wait(NULL);
    }

    printf("Premier processus terminé: %d\n", pids[0]);

    return 0;
}