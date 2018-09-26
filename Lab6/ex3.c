#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void action(int signum)
{
    printf("\nInterrupt signal received. Ignoring.\n");
}

int main()
{
    signal(SIGINT, action);
    printf("Waiting for the signal...\n");
    while (1);
}