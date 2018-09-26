#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void action(int signum)
{
    if (signum == SIGKILL)
    {
        printf("\nThe process is already dead, not much left to say.\n");
    }
    
    if(signum == SIGSTOP)
    {
        printf("\nThis is also not going to be printed out.\n");
    }
    
    if(signum == SIGUSR1)
    {
        printf("\nReceived a signal from user.\n");
    }
}

int main()
{
    signal(SIGKILL, action);
    signal(SIGSTOP, action);
    signal(SIGUSR1, action);
    while (1);
}