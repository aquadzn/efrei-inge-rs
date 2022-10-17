#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t fils[3], petit_fils[2];

    printf("Parent\t\tPID: %d\n", getpid());

    for (int i = 1; i <= 3; i++)
    {
        if ((fils[0] = fork()) == 0)
        {
            if (i == 1)
            {
                for (int j = 1; j <= 2; j++)
                {
                    if ((petit_fils[j] = fork()) == 0)
                    {
                        printf("Petit-fils %d\tPID: %d\tPPID: %d\n", j, getpid(), getppid());
                        exit(0);
                    }
                }

                for (int j = 1; j <= 2; j++)
                {
                    wait(NULL);
                }
            }

            printf("Fils %d\t\tPID: %d\tPPID: %d\n", i, getpid(), getppid());
            exit(0);
        }
    }

    for (int i = 1; i <= 3; i++)
    {
        wait(NULL);
    }

    return 0;
}
