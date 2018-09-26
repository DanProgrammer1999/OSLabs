#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

static int pipefd[2];

int main()
{
    pipe(pipefd);
    int input_size = 256;
    int fork_id = fork();
    if (fork_id == 0)
    {
        //sleep(1);
        char result[input_size];
        read(pipefd[0], result, input_size);
        printf("Output: %s\n", result);
    }
    else
    {
        char input[] = "Pipe test";
        printf("Input: %s\n", input);
        write(pipefd[1], input, input_size);
    }
}