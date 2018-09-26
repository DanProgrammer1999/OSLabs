#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>

int main()
{
    int fork_id = fork();

    if (fork_id == 0)
    {
        while (1)
        {
            printf("I'm alive!\n");
            sleep(1);
        }
        exit(0);
    }
    else
    {
        sleep(10);
        kill(fork_id, SIGTERM);
    }
    return 0; 
}